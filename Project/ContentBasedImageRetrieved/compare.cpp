#include "compare.h"

double compareImageHist(QString pathSource, QString pathTest,int bin)
{
    Mat image = imread(pathSource.toUtf8().constData());
    Mat image2 = imread(pathTest.toUtf8().constData());

    int histSize = 256 /bin;
    float range[] = {0,255};
    const float *ranges[] = {range};
    int channel[] =  {0,1,2};

    MatND hist1,hist2;

    calcHist(&image,1,channel,Mat(),hist1,1,&histSize,ranges,true,false);
    normalize(hist1,hist1,0,1,NORM_MINMAX,-1,Mat());

    calcHist(&image2,1,channel,Mat(),hist2,1,&histSize,ranges,true,false);
    normalize(hist2,hist2,0,1,NORM_MINMAX,-1,Mat());


    double result = compareHist(hist1,hist2,3);

    return result;
}

double compareImageHist(Mat sourceImage, Mat compareImage)
{
    int bin = 1;

    int histSize = 256 /bin;
    float range[] = {0,255};
    const float *ranges[] = {range};
    int channel[] =  {0,1,2};

    MatND hist1,hist2;

    calcHist(&sourceImage,1,channel,Mat(),hist1,1,&histSize,ranges,true,false);
    normalize(hist1,hist1,0,1,NORM_MINMAX,-1,Mat());

    calcHist(&compareImage,1,channel,Mat(),hist2,1,&histSize,ranges,true,false);
    normalize(hist2,hist2,0,1,NORM_MINMAX,-1,Mat());


    double result = compareHist(hist1,hist2,3);

    return result;
}



Mat cannyEdgeDetect(Mat image, int threshold)
{
    Mat result,mask;

    GaussianBlur(image, mask, Size(kernelSize,kernelSize),0,0);
    Canny(mask,mask,threshold,threshold * thresholdRatio,kernelSize);

    result = Scalar::all(0);

    image.copyTo(result,mask);
    return result;
}


double hausdorffDistance(Mat cannySource, Mat cannyCompare)
{
    vector<vector<Point>> contourSource, contourCompare;

    findContours(cannySource,contourSource,
        RETR_CCOMP, CHAIN_APPROX_TC89_L1);

    findContours(cannyCompare,contourCompare,
        RETR_CCOMP, CHAIN_APPROX_TC89_L1);

    Ptr<HausdorffDistanceExtractor> h = createHausdorffDistanceExtractor();

    //Ptr<ShapeContextDistanceExtractor> h = createShapeContextDistanceExtractor();
    double distance = h->computeDistance(contourSource[0],contourCompare[0]);

    return distance;

}


double compareImageFeature(QString pathSource,QString pathTest,int threshold)
{
    Mat sourceImage = imread(pathSource.toUtf8().constData(),IMREAD_GRAYSCALE);
    Mat compareImage = imread(pathTest.toUtf8().constData(),IMREAD_GRAYSCALE);

    Mat cannySource = cannyEdgeDetect(sourceImage,threshold);
    Mat cannyCompare = cannyEdgeDetect(compareImage,threshold);

    double distance = compareImageHist(cannySource, cannyCompare);
    return distance;
}
