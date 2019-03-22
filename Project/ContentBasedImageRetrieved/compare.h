#ifndef COMPARE_H
#define COMPARE_H

#include <iostream>
#include <vector>
#include <QString>

#include <opencv2/opencv.hpp>
#include <opencv2/xfeatures2d.hpp>
#include <opencv2/features2d.hpp>

using namespace std;
using namespace cv;
using namespace cv::xfeatures2d;

const int MAX_FEATURE = 500;
const float GOOD_MATCH_PERCENT = 0.15f;
const int thresholdRatio = 3;
const int kernelSize = 5;


double compareImageHist(QString pathSource,QString pathTest,int bin);
double compareImageHist(Mat sourceImage, Mat compareImage);

Mat cannyEdgeDetect(Mat image, int threshold);
double hausdorffDistance(Mat cannySource, Mat cannyCompare);

double compareImageFeature(QString pathSource,QString pathTest,int threshold);


#endif // COMPARE_H
