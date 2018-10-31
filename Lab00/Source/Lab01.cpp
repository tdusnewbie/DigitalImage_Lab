#include <opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <string.h>
#include <iostream>

using namespace cv;

int main(int argc, char** argv )
{
    // Check the number of parameter
    if (argc < 2)
    {
    	printf("No Image Data.\n");
    	return -1;
    }
   	// Read the Image from Second Parameter
    Mat image = imread( argv[1], 1 );

    // If there are three parameter, This program requires converts an image from one color space to another
    if (argc == 3 && strcmp(argv[2],"--swap") == 0)
    	// Use cvtColor to converts an image from one color space to another.
    	cvtColor(image,image,COLOR_BGR2GRAY);
    
    // If There are four parameter, This program requires change brightness or constract of image
    else if(argc == 4)
    {
    	// If Third Parameter is change bright
    	if(strcmp(argv[2],"--change-bright") == 0)
    	{
    		// use method convertTo in Mat Class
    		// to change bias(B) in g(x) = A*f(x) + B
    		double bias; // Control the brightness of image
    		bias = atof(argv[3]) *10;
    		// -1 is the output matrix will have the same type as the input.
    		image.convertTo(image,-1,1,bias);
    	}
    	// Same as above, If the third parameter is change constract
    	if(strcmp(argv[2],"--change-contract")==0)
    	{
    		double gain; // Control the constract of image
    		gain = atof(argv[3]);
    		image.convertTo(image,-1,gain,0);
    	}
    }
    if ( !image.data )
    {	
        printf("No image data \n");
        return -1;
    }
    // Set the Window's name
    namedWindow("Display Image", WINDOW_AUTOSIZE );
    // Show the Image in the Window having the name is set above
    imshow("Display Image", image);

    waitKey(0);

    return 0;
}