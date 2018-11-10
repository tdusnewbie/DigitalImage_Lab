    #ifndef FILTER_H
#define FILTER_H

#include <iostream>
#include <algorithm>
#include <vector>
#include <opencv4/opencv2/highgui.hpp>
#include <opencv4/opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

int sumMemInKernel(Mat image, int coefCols, int coefRows, int posRow, int posCol);
int sumMemInKernel(Mat image, int coefCols, int coefRows, int posRow, int posCol, int channelNum);

int takeMedianValueInKernel(Mat image, int coefRows, int coefCols, int posRow, int posCol);
int takeMaxValueInKernel(Mat image, int coefRows, int coefCols, int posRow, int posCol);
int takeMinValueInKernel(Mat image, int coefRows, int coefCols, int posRow, int posCol);

int takeMedianValueInKernel(Mat image, int coefRows, int coefCols, int posRow, int posCol,int channelNum);
int takeMaxValueInKernel(Mat image, int coefRows, int coefCols, int posRow, int posCol,int channelNum);
int takeMinValueInKernel(Mat image, int coefRows, int coefCols, int posRow, int posCol,int channelNum);

void replicateImage(Mat &image, int coefRows, int coefCols );
void zeroPaddingImage(Mat &image,int coefRows, int coefCols );

int averageFilter(Mat sourceImage, Mat &destinationImage, int w, int h, int option);
int orderStatisticFilter(Mat sourceImage, Mat &destinationImage, int w, int h, int name, int option);

#endif // FILTER_H
