#include <iostream>
#include <vector>
#include <cmath>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;


/*****************************************************/
/***************** Support Function ******************/
/*****************************************************/
//Tinh so luong cuong do diem anh 
int numberOfPixel(Mat image, int intensity)
{
	int result = 0;
	for(int i = 0; i < image.rows; i++)
		for(int j = 0; j < image.cols; j++)
			if (intensity == (int)image.at<uchar>(i,j))
				result++;
	return result;
}

// Lay ra Min Histogram
Mat getMinHistogram(Mat hist1,Mat hist2)
{
	// Chuyen Tu Mat sang Float
	float* arr1 = (float*)hist1.data;
	float* arr2 = (float*)hist2.data;

	float minArr[256];

	// So sanh tung phan tu tron tung Histogram
	for(int i = 0; i <  hist1.cols; i++)
	{
		if(arr1[i] <= arr2[i])
			minArr[i] = arr1[i];
		else
			minArr[i] = arr2[i];
	}

	// Chuyen Histogram Minimum ve thanh Dang Mat
	Mat result(1,256,CV_32FC1);
	memcpy(result.data,minArr,sizeof(float)*256);

	return result;
}

// Tim Histogram luong hoa mau nho nhat
double* getMinHistogram(double* hist1, double* hist2,int gBin)
{
	// Tao mot mang chua HIstogram nho nhat
	double *minArr = new double[gBin];
	for(int i = 0;i<gBin; i++)
		minArr[i] = 0;

	// so sanh tung phan tu cua tung mang Histogram dua vao
	for(int i = 0; i <  gBin; i++)
	{
		if(hist1[i] <= hist2[i])
			minArr[i] = hist1[i];
		else
			minArr[i] = hist2[i];
	}
	return minArr;

}

// Tinh tong tung phan tu cua mot Histogram
float sumOfHistogram(Mat hist)
{
	// Chuyen tu dang Mat sang Float
	float *arr = (float*)hist.data;
	float sum = 0;
	// Bat dau tinh tong
	for(int i = 0; i < hist.cols; i ++)
		sum += arr[i];
	return sum;
}

// Tuong tu nhuw tren nhwung theo luong hoa mau
double sumOfHistogram(double* hist,int gBin)
{
	double sum = 0;
	for(int i = 0; i < gBin; i ++)
		sum += hist[i];
	return sum;
}


/*************************************************************/
/***************** OpenCV Handmade Function ******************/
/*************************************************************/

// CHuyen anh ve dang grayscale
int rgbToGray(Mat srcImg, Mat &dstImg)
{
	if(srcImg.channels() ==1)
	{
		cout << "Error:  Can not convert grayscale Image !!!!" << endl;
		return 1;
	}
	Mat temp(srcImg.rows, srcImg.cols, CV_8UC1); // tao anh  kieu CvType.CV_8UC1 : loai anh xam
	dstImg = temp;
	for (int i = 0; i < srcImg.rows; i++)
	{
		for (int j = 0; j < srcImg.cols; j++)
		{
			int r = srcImg.at<Vec3b>(i, j)[0]; // red channel
			int  g = srcImg.at<Vec3b>(i, j)[1]; // green channel
			int b = srcImg.at<Vec3b>(i, j)[2]; // blue channel
			double gray = r * 0.299 + 0.587*g + 0.114*b; // chuyen tu RGB sang Gray
			dstImg.at<uchar>(i, j) = gray;
		}
	}
	return 0;
}

// Tang do sang cua anh
int adjustBrightness(Mat srcImg, Mat &dstImg, int beta)
{
	//beta : do sang

	for (int i = 0; i < srcImg.rows; i++) // i : so dong
	{
		for (int j = 0; j < srcImg.cols; j++) // j: so cot
		{
			for (int c = 0; c < 3; c++) //c : channels , 3 : so channels (R,G,B)
			{
				dstImg.at<Vec3b>(i,j)[c] = saturate_cast<uchar>(srcImg.at<Vec3b>(i, j)[c] + beta) ;			// beta co gia tri : 0->100
			}
		}
	}
	return 0;
}

//Tang do tuogn phan cua anh
int adjustContrast(Mat srcImg, Mat &dstImg, int alpha)
{
	// alpha : do tuong phan

	for (int i = 0; i < srcImg.rows; i++) // i : so dong
	{
		for (int j = 0; j < srcImg.cols; j++) // j: so cot
		{
			for (int c = 0; c < 3; c++) //c : channels , 3 : so channels (R,G,B)
			{
				dstImg.at<Vec3b>(i, j)[c] = saturate_cast<uchar>(alpha*(dstImg.at<Vec3b>(i, j)[c])) ;		// alpha co gia tri : 1->3
			}
		}
	}
	return 0;
}

// Tao anh am ban 
int transNegative(Mat srcImg, Mat &dstImg)
{
	dstImg = srcImg;
	// truong hop anh xam
	if(srcImg.channels() == 1)
	{
		//tu anh sang chuyen sang anh am ban 
		for (int i = 0; i < dstImg.rows; i++)
		{
			for (int j = 0; j < dstImg.cols; j++)
			{
				//am ban la anh xam co muc do mau (intensity level) thuoc trong đoan[0, 255].
				dstImg.at<uchar>(i, j) = 255 - dstImg.at<uchar>(i, j); //thuat toan dao nguoc do sang cua anh goc 
			}
		}
		return 0;
	}
	// truowng hop anh mau
	else
	{
		//tu anh sang chuyen sang anh am ban 
		for (int i = 0; i < dstImg.rows; i++)
		{
			for (int j = 0; j < dstImg.cols; j++)
			{
				dstImg.at<Vec3b>(i, j)[0] = 255 - dstImg.at<Vec3b>(i, j)[0]; //thuat toan dao nguoc do sang cua anh goc 
				dstImg.at<Vec3b>(i, j)[1] = 255 - dstImg.at<Vec3b>(i, j)[1];
				dstImg.at<Vec3b>(i, j)[2] = 255 - dstImg.at<Vec3b>(i, j)[2];
			}
		}
		return 0;
	}
}

//Chuyen doi Logarit
int transLog(Mat srcImg, Mat &dstImg, int c)
{
	dstImg = srcImg;
	if(srcImg.channels() == 1)
	{
		for (int i = 0; i < dstImg.rows; i++)
		{
			for (int j = 0; j < dstImg.cols; j++)
			{
				dstImg.at<uchar>(i, j) =c*log(1 + (double)dstImg.at<uchar>(i, j)); 
			}
		}
		return 0;
	}
	else
	{
		for (int i = 0; i < dstImg.rows; i++)
		{
			for (int j = 0; j < dstImg.cols; j++)
			{
				dstImg.at<Vec3b>(i, j)[0] = c*log(1+ (double)dstImg.at<Vec3b>(i, j)[0]); 
				dstImg.at<Vec3b>(i, j)[1] = c*log(1+ (double)dstImg.at<Vec3b>(i, j)[1]);
				dstImg.at<Vec3b>(i, j)[2] = c*log(1+ (double)dstImg.at<Vec3b>(i, j)[2]);
			}
		}
		return 0;
	}

}

// chuyen Gamma
int transGamma(Mat srcImg, Mat &dstImg, int c, double gamma)
{
	dstImg = srcImg;
	if(srcImg.channels() == 1)
	{
		for (int i = 0; i < dstImg.rows; i++)
		{
			for (int j = 0; j < dstImg.cols; j++)
			{
				dstImg.at<uchar>(i, j) = saturate_cast<uchar>(c*pow((double)dstImg.at<uchar>(i, j),gamma)); 
			}
		}
		return 0;
	}
	else
	{
		for (int i = 0; i < dstImg.rows; i++)
		{
			for (int j = 0; j < dstImg.cols; j++)
			{
				dstImg.at<Vec3b>(i, j)[0] = saturate_cast<uchar>(c*pow((double)dstImg.at<Vec3b>(i, j)[0],gamma)); 
				dstImg.at<Vec3b>(i, j)[1] = saturate_cast<uchar>(c*pow((double)dstImg.at<Vec3b>(i, j)[1],gamma));
				dstImg.at<Vec3b>(i, j)[2] = saturate_cast<uchar>(c*pow((double)dstImg.at<Vec3b>(i, j)[2],gamma));
			}
		}
		return 0;
	}
}

// Tinh Histogram cho anh
int calcHistogram(Mat srcImg,vector<Mat> &hist)
{
	// Truong hop anh la anh xam
	if(srcImg.channels() == 1)
	{
		// Khai bao mot mang Histogram
		float histogram[256];
		for(int j = 0; j < 256; j++)
			//TIm phan bo mat do
			histogram[j] = numberOfPixel(srcImg,j);

		// Chuyen tu mang sang Mat type
		Mat tempHist(1,256,CV_32FC1);
		memcpy(tempHist.data,histogram,256*sizeof(float));
		// Add Histogram vao Vector 
		hist.push_back(tempHist);
	}
	// Truong hop anh mau
	else
	{
		//Phan tach anh mau thanh ba kenh mau
		Mat bgrImage[3];
		split(srcImg,bgrImage);
		// Voi tung kenh cua anh mau, lam tuong tu nhu anh xam
		for(int i = 0; i < srcImg.channels(); i++)
		{
			float histogram[256];
			for(int j = 0; j < 256; j++)
				histogram[j] = numberOfPixel(srcImg,j);

			Mat tempHist(1,256,CV_32FC1);
			memcpy(tempHist.data,histogram,256*sizeof(float));
			hist.push_back(tempHist);
		}
	}
	return 0;	
}

double compareHist(Mat srcImg1, Mat srcImg2)
{
	// Neu la anh mau thi chuyen ve anh xam de so sanh
	if(srcImg1.channels() != 1)
		rgbToGray(srcImg1,srcImg1);

	if(srcImg2.channels() != 1)
		rgbToGray(srcImg2,srcImg2);

	double result = 0;
	
	// Tao ra hai vector de chua cac Histogram cua tung kenh trong moi anh
	vector <Mat> hist1;
	vector <Mat> hist2;

	// Tinh Histogram cua anh 1
	calcHistogram(srcImg1,hist1);
	//printHist(hist1[0]);	
	// Tinh Histogram cua anh 2
	calcHistogram(srcImg2,hist2);
	//printHist(hist2[0]);

	//Tim Histogram nho nhat trong hai Histogram vua dua vao
	Mat minHist = getMinHistogram(hist1[0],hist2[0]);
	//printHist(minHist);

	// Tinh tong thnah phan cua HIstogram nho nhat
	float sumMinHist = sumOfHistogram(minHist);
	//cout << sumMinHist << endl;

	// TInh tong tung thanh phan cua Histogram cua anh bi so sanh
	float sumTestHist = sumOfHistogram(hist2[0]);
	//cout << sumTestHist << endl;

	//cout <<"this is result: " <<(double)compareHist(minHist,hist2[0],3) << endl;
	
	// Neu nhu ti le la 1 thi hai anh giong nhau
	// neu khac 1 thi do laf ti le khac nhau cua hai anh
	result = sumMinHist / sumTestHist;
	return result;
}

double* calcHistogram(Mat srcImg, int rBin, int gBin, int bBin)
{
	if(srcImg.channels() != 1)
	{
		vector<int> Hist_red(rBin,0);
		vector<int> Hist_green(gBin,0);
		vector<int> Hist_blue(gBin,0);
		for(int i = 0; i < srcImg.rows; i++)
			for(int j = 0; j < srcImg.cols;j++)
			{
				int Red = srcImg.at<Vec3b>(i,j)[0];
				int Green = srcImg.at<Vec3b>(i,j)[1];
				int Blue = srcImg.at<Vec3b>(i,j)[2];

				Hist_red[Red / (256 / rBin)]++;
				Hist_green[Green / (256 /gBin)]++;
				Hist_blue[Blue / (256 / bBin)]++;
			}
	}
	return 0;
}

double* calcHistogram(Mat srcImg, int gBin)
{
	// Neu anh laf anh xam moi thuc hien
	if(srcImg.channels() == 1)
	{
		// Tao mot mang ung voi so luong Bin dua vao
		double* hist_grey = new double[gBin];
		for(int i = 0; i <gBin; i++)
			hist_grey[i] = 0;
		// Tinh mat do phan bo cuar tung diem anh theo Bin
		for(int i = 0; i < srcImg.rows;i++)
			for(int j=0 ; j < srcImg.cols; j++)
			{
				int grey = srcImg.at<uchar>(i,j);
				hist_grey[grey / (256 / gBin)]++;
			}
		return hist_grey;
	}
}

// Tuong tu voi compareHist o tren nhung lan nay al so sanh theo bin 
double compareHist(Mat srcImg1, Mat srcImg2, int gBin)
{
	double result = 0;
	
	double *hist1, *hist2;

	hist1 = calcHistogram(srcImg1,gBin);
	//printHist(hist1[0]);	
	hist2 = calcHistogram(srcImg2,gBin);
	//printHist(hist2[0]);

	double *minHist = getMinHistogram(hist1,hist2,gBin);
	//printHist(minHist);

	double sumMinHist = sumOfHistogram(minHist,gBin);
	//cout << sumMinHist << endl;
	double sumTestHist = sumOfHistogram(hist2,gBin);
	//cout << sumTestHist << endl;

	//cout <<"this is result: " <<(double)compareHist(minHist,hist2[0],3) << endl;
	
	result = sumMinHist / sumTestHist;
	return result;
}


/**************************************************/
/***************** Main Function ******************/
/**************************************************/
int main(int argc, char const *argv[])
{
	if(argc <= 2)
	{
		cout << "Error !!!!" << endl;
	}
	int code = atoi(argv[2]);
	Mat image = imread(argv[1],IMREAD_ANYCOLOR | IMREAD_ANYDEPTH);
	Mat dest;
	switch(code)
	{
		case 1:
		{
			if(argc <=3)
			{
				dest = image;
				rgbToGray(image,dest);
				break;
			}
			else
			{
				rgbToGray(image,dest);
				imwrite(argv[3],dest);
				break;
			}
		}
		
		case 2:
		{
			int brightness = atoi(argv[3]);
			if(argc <=4)
			{
				dest = image;
				adjustBrightness(image,dest,brightness);
				break;
			}
			else
			{
				adjustBrightness(image,image,brightness);
				imwrite(argv[4],dest);
				break;
			}
		}

		case 3:
		{
			int contrast = atoi(argv[3]);
			if(argc <=4)
			{
				dest = image;
				adjustContrast(image,dest,contrast);
				break;
			}
			else
			{
				adjustContrast(image,dest,contrast);
				imwrite(argv[4],dest);
				break;
			}
		}
		break;

		case 4:
		{
			if(argc <=3)
			{
				dest = image;
				transNegative(image,dest);
				break;
			}
			else
			{
				transNegative(image,dest);
				imwrite(argv[3],dest);
				break;
			}
		}

		case 5:
		{
			int parameter = atoi(argv[3]);
			if(argc <= 3)
			{
				dest = image;
				transLog(image,dest,parameter);
			}
			else
			{
				transLog(image,dest,parameter);
				imwrite(argv[3],dest);
			}

		}
		break;

		case 6:
		{
			int parameter1 = atoi(argv[3]);
			double parameter2 = atof(argv[4]);
			if(argc <= 4)
			{
				dest = image;
				transGamma(image,dest,parameter1,parameter2);
			}
			else
			{
				transGamma(image,dest,parameter1,parameter2);
				imwrite(argv[5],dest);
			}

		}
		break;

		case 7:
		{
			dest = image;
			vector<Mat> histogram;
			calcHistogram(image,histogram);
			//printHist(histogram[0]);
			cout << "Size of vector Hist is : " << histogram.size() << endl;;
		}
		break;
		case 8:
		{
			dest = image;
			Mat testImage = imread(argv[3],IMREAD_ANYCOLOR | IMREAD_ANYDEPTH);
			double result = compareHist(image,testImage);
			cout << "Result of Compare: " << result << endl;
		}
		break;
		case 9:
		{
			dest = image;
			int redParam = atoi(argv[3]);
			int greenParam = atoi(argv[4]);
			int blueParam = atoi(argv[5]);
			double *colorHist = calcHistogram(image,redParam,greenParam,blueParam);
		}
		break;
		case 10:
		{
			dest = image;
			int parameter = atoi(argv[3]);
			double *grayscaleHist = calcHistogram(image,parameter);
			// for (int i = 0; i < parameter;i++)
			// 	cout <<grayscaleHist[i] <<endl;
		}
		break;
		case 12:
		{
			dest = image;
			if(argc <=4)
			{
				cout << "Error: Invalid command !!!!" << endl;
				break;
			}
			else
			{
				Mat testImage = imread(argv[3],IMREAD_ANYCOLOR | IMREAD_ANYDEPTH);
				int parameter = atoi(argv[4]);
				double result = compareHist(image,testImage,parameter);
				cout << "Result of Compare: " << result << endl;
				break;
			}
		}

	}

	namedWindow("Display window", WINDOW_AUTOSIZE);
	imshow("Display window", dest);
	waitKey(0);
	return 0;
}
