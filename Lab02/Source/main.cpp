#include "filter.h"

int main(int argc, char *argv[])
{
    /*****************************************************************/
    /***************** Read the Path of Source Image *****************/
    /*****************************************************************/
    // Read path to image from Command
    Mat image = imread(argv[1],IMREAD_ANYDEPTH | IMREAD_ANYCOLOR);
    // If path to image is not existed
    if(!image.data)
    {
        cout << "No data entered, please enter the path to an image file " << endl;
        return -1;
    }


    /**************************************************************
    ****************** Read and handling Exception ****************
    ******************** the command's code number ****************
    ***************************************************************/
    // Read the code of command
    if(argc < 3)
    {
        cout << "Cannot find the code number!!!!!!" << endl;
        return -1;
    }
    int code = atoi(argv[2]);
    code = 3;

    if(code < 1 || code >3)
    {
        cout << "Cannot find the code number!!!!!!" << endl;
        return -1;
    }


    /**************************************************************
    ****************** Read and handling Exception ****************
    ***************** the command's parameter number **************
    ***************************************************************/
    // Read the Parameter of Command
    int widthKernel = atoi(argv[3]);
    int heightKernel = atoi(argv[4]);
    int option,name;
    float sigma;

    // Check the number of command parameter to set suitable image parameter
    switch (argc)
    {
    case 6:
        option = atoi(argv[5]);
        break;
    case 7:
    {
        if(code == 2)
        {
            sigma = atof(argv[5]);
            option = atoi(argv[6]);
        }
        else
        {
            name = atoi(argv[5]);
            option = atoi(argv[6]);
        }
    }
        break;
    default:
        break;
    }


    /****************************************************************
     *************** Handling the output and determine **************
     ******************** the command need to do ********************
     ****************************************************************/
    // Create a Matrix is same as input image matrix to store destination image
    Mat dest(image.rows,image.cols,image.type());

    // Do the command followed by code number
    switch (code)
    {
    case 1:
        averageFilter(image,dest,widthKernel,heightKernel,option);
        break;
    case 3:
        orderStatisticFilter(image,dest,widthKernel,heightKernel,name,option);
        break;
    default:
        cout << "Cannot find the code number!!!!!!"<< endl;
        break;
    }

    // Show image
    namedWindow("Demo Windows",WINDOW_AUTOSIZE);
    imshow("Demo Windows",dest);
    waitKey(0);
    return 0;
}
