#include "filter.h"

/*****************************************************************
*********************** GrayScale Image Support ******************
******************************************************************/


//Usage: calculate the sum of each member in kernel of input image (Grayscale Image)
//---------- image: the Image we need to access
//---------- coefRows: the coefficient number of Rows (the middle position of Rows)
//---------- coefCols: the coefficient number of Columns (the middle position of Columns)
//---------- posRow: the position on the row we need to access in Image
//---------- posCol: the position on the column we need to access in Image
int sumMemInKernel(Mat image, int coefCols, int coefRows, int posRow, int posCol)
{
    // Initialize the sum Variable
    int sum = 0;
    // Visit all the member in Kernel
    for(int i = -coefRows; i <= coefRows; i++)
        for(int j = -coefCols; j <= coefCols; j ++)
            // add each member into the sum
            sum += (int)image.at<uchar>(posRow + i,posCol +j);
    return sum;
}

//Usage: use to get the median values in Kernel (Grayscale Image)
// ---------- image: input image
// ---------- coefRows: the coefficient number of Rows (the middle position of Rows)
// ---------- coefCols: the coefficient number of Cols (the middle opsition of Columns)
//---------- posRow: the position on the row we need to access in Image
//---------- posCol: the position on the column we need to access in Image
int takeMedianValueInKernel(Mat image, int coefRows, int coefCols, int posRow, int posCol)
{
    //create a vector
    vector<int> arr;
    for(int i = -coefRows; i <= coefRows; i++)
        for(int j = -coefCols; j <= coefCols; j ++)
            // add each member into the vector arr
            arr.push_back((int)image.at<uchar>(posRow + i,posCol +j));
    //Sort the vector to get th median values
    sort(arr.begin(),arr.end());
    // Return the median in vector
    return arr[arr.size()/2];
}


//Usage: use to get the max values in Kernel (Grayscale Image)
// ---------- image: input image
// ---------- coefRows: the coefficient number of Rows (the middle position of Rows)
// ---------- coefCols: the coefficient number of Cols (the middle opsition of Columns)
//---------- posRow: the position on the row we need to access in Image
//---------- posCol: the position on the column we need to access in Image
int takeMaxValueInKernel(Mat image, int coefRows, int coefCols, int posRow, int posCol)
{
    // create a variable to determine the max values
    int max = (int)image.at<uchar>(posRow -coefRows,posCol -coefCols);
    for(int i = -coefRows; i <= coefRows; i++)
        for(int j = -coefCols; j <= coefCols; j ++)
            // check each member in kernel
            // If this is greater than max values
            if(max <= (int)image.at<uchar>(posRow + i,posCol +j))
                max = (int)image.at<uchar>(posRow + i,posCol +j);
    // return the max values after visit all the element in kernel
    return max;
}


//Usage: use to get the median values in Kernel (Grayscale Image)
// ---------- image: input image
// ---------- coefRows: the coefficient number of Rows (the middle position of Rows)
// ---------- coefCols: the coefficient number of Cols (the middle opsition of Columns)
//---------- posRow: the position on the row we need to access in Image
//---------- posCol: the position on the column we need to access in Image
int takeMinValueInKernel(Mat image, int coefRows, int coefCols, int posRow, int posCol)
{
    // create a variable to determine the min values
    int min = (int)image.at<uchar>(posRow -coefRows,posCol -coefCols);
    for(int i = -coefRows; i <= coefRows; i++)
        for(int j = -coefCols; j <= coefCols; j ++)
            // check each member in kernel
            // If this is smaller than min values
            if(min >= (int)image.at<uchar>(posRow + i,posCol +j))
                min = (int)image.at<uchar>(posRow + i,posCol +j);
    // return the min values after visit all the element in kernel
    return min;
}

/*****************************************************************
*********************** TrueColor Image Support ******************
******************************************************************/


//Usage: calculate the sum of each member in kernel of input image (True Color Image)
//---------- image: the Image we need to access
//---------- coefRows: the coefficient number of Rows (the middle position of Rows)
//---------- coefCols: the coefficient number of Columns (the middle position of Columns)
//---------- posRow: the position on the row we need to access in Image
//---------- posCol: the position on the column we need to access in Image
//---------- numChannel: the channel number inn True Color Image
int sumMemInKernel(Mat image, int coefCols, int coefRows, int posRow, int posCol,int channelNum)
{
    // Initialize the sum Variable
    int sum = 0;
    // Visit all the member in Kernel
    for(int i = -coefRows; i <= coefRows; i++)
        for(int j = -coefCols; j <= coefCols; j ++)
            // add each member into the sum
            sum += (int)image.at<Vec3b>(posRow + i,posCol +j)[channelNum];
    return sum;
}


//Usage: use to get the median values in Kernel (True Color Image)
// ---------- image: input image
// ---------- coefRows: the coefficient number of Rows (the middle position of Rows)
// ---------- coefCols: the coefficient number of Cols (the middle opsition of Columns)
//---------- posRow: the position on the row we need to access in Image
//---------- posCol: the position on the column we need to access in Image
//---------- numChannel: the channel number inn True Color Image
int takeMedianValueInKernel(Mat image, int coefRows, int coefCols, int posRow, int posCol, int channelNum)
{
    //create a vector
    vector<int> arr;
    for(int i = -coefRows; i <= coefRows; i++)
        for(int j = -coefCols; j <= coefCols; j ++)
        {
            // add each member into the vector arr
            int values = (int)image.at<Vec3b>(posRow + i,posCol +j)[channelNum];
            arr.push_back(values);
        }
    //Sort the vector to get th median values
    sort(arr.begin(),arr.end());
    // Return the median in vector
    return arr[arr.size()/2];
}


//Usage: use to get the max values in Kernel (True Color Image)
// ---------- image: input image
// ---------- coefRows: the coefficient number of Rows (the middle position of Rows)
// ---------- coefCols: the coefficient number of Cols (the middle opsition of Columns)
//---------- posRow: the position on the row we need to access in Image
//---------- posCol: the position on the column we need to access in Image
//---------- numChannel: the channel number inn True Color Image
int takeMaxValueInKernel(Mat image, int coefRows, int coefCols, int posRow, int posCol,int channelNum)
{
    // create a variable to determine the max values
    int max = (int)image.at<Vec3b>(posRow -coefRows,posCol -coefCols)[channelNum];
    for(int i = -coefRows; i <= coefRows; i++)
        for(int j = -coefCols; j <= coefCols; j ++)
            // check each member in kernel
            // If this is greater than max values
            if(max <= (int)image.at<Vec3b>(posRow + i,posCol +j)[channelNum])
                max = (int)image.at<Vec3b>(posRow + i,posCol +j)[channelNum];
    // return the max values after visit all the element in kernel
    return max;
}


//Usage: use to get the median values in Kernel (True Color Image)
// ---------- image: input image
// ---------- coefRows: the coefficient number of Rows (the middle position of Rows)
// ---------- coefCols: the coefficient number of Cols (the middle opsition of Columns)
//---------- posRow: the position on the row we need to access in Image
//---------- posCol: the position on the column we need to access in Image
//---------- numChannel: the channel number inn True Color Image
int takeMinValueInKernel(Mat image, int coefRows, int coefCols, int posRow, int posCol, int channelNum)
{
    // create a variable to determine the min values
    int min = (int)image.at<Vec3b>(posRow -coefRows,posCol -coefCols)[channelNum];
    for(int i = -coefRows; i <= coefRows; i++)
        for(int j = -coefCols; j <= coefCols; j ++)
            // check each member in kernel
            // If this is smaller than min values
            if(min >= (int)image.at<Vec3b>(posRow + i,posCol +j)[channelNum])
                min = (int)image.at<Vec3b>(posRow + i,posCol +j)[channelNum];
    // return the min values after visit all the element in kernel
    return min;
}

/*****************************************************************
*********************** Option Implement *************************
******************************************************************/

//Usage: Create Zero Padding state for Image after reduce noise
//---------- image: input image after reduce noise
//---------- coefRows: same as above
//---------- coefCols: same as above
void zeroPaddingImage(Mat &image,int coefRows, int coefCols )
{
    // If source image is grayscale image
    if(image.channels() == 1)
    {
        // Fill all empty position in image by 0
        // There are 'coefRows' rows are empty
        // There are 'coefCols' collumns are empty

        // With Rows are empty
        for(int i = 0;i < image.cols; i++)
            for(int j = 0;j < coefRows;j++)
            {
                // Set them is 0
                image.at<uchar>(j,i) = 0;
                image.at<uchar>(image.rows-j-1,i) = 0;
            }
        // With Columns are empty
        // At this case, because we have fill some element(i <0) at above so i = coefRows
        for(int i = coefRows;i < image.rows-coefRows; i++)
            for(int j = 0;j < coefCols;j++)
            {
                // Set them is 0
                image.at<uchar>(i,j) = 0;
                image.at<uchar>(i,image.cols-j-1) =0;
            }
    }
    // If source image is true color image
    else
    {
        // Fill all empty position in image by 0
        // There are 'coefRows' rows are empty
        // There are 'coefCols' collumns are empty

        // With Rows are empty
        for(int i = 0;i < image.cols; i++)
            for(int j = 0;j < coefRows;j++)
            {
                // Set them is 0
                image.at<Vec3b>(j,i)[0] = 0;
                image.at<Vec3b>(image.rows-j-1,i)[0] = 0;

                image.at<Vec3b>(j,i)[1] = 0;
                image.at<Vec3b>(image.rows-j-1,i)[1] = 0;

                image.at<Vec3b>(j,i)[2] = 0;
                image.at<Vec3b>(image.rows-j-1,i)[2] = 0;
            }
        // With Columns are empty
        // At this case, because we have fill some element(i <0) at above so i = coefRows
        for(int i = coefRows;i < image.rows-coefRows; i++)
            for(int j = 0;j < coefCols;j++)
            {
                // Set them is 0
                image.at<Vec3b>(i,j)[0] = 0;
                image.at<Vec3b>(i,image.cols-j-1)[0] =0;

                image.at<Vec3b>(i,j)[1] = 0;
                image.at<Vec3b>(i,image.cols-j-1)[1] =0;

                image.at<Vec3b>(i,j)[2] = 0;
                image.at<Vec3b>(i,image.cols-j-1)[2] =0;

            }

    }
}


//Usage: Create Replicate state for Image after reduce noise
//---------- image: input image after reduce noise
//---------- coefRows: same as above
//---------- coefCols: same as above
void replicateImage(Mat &image, int coefRows, int coefCols )
{
    // Fill all empty position in image by the value of image's edge
    // There are 'coefRows' rows are empty
    // There are 'coefCols' collumns are empty

    // If source image is grayscale image
    if(image.channels() ==1)
    {
        // With rows are empty
        for(int i = 0;i < image.cols; i++)
            for(int j = 0;j < coefRows;j++)
            {
                // At the left corner of the Image, all empty element (i<=coefCols) will be same as the left corner
                if(i <= coefCols)
                    image.at<uchar>(j,i) = image.at<uchar>(coefRows,coefCols);
                // At the right corner of the image, all empty element (i>=image.cols - coefCols -1) will be same as the right corner
                else if(i >= image.cols - coefCols -1)
                    image.at<uchar>(j,i) = image.at<uchar>(coefRows,image.cols - coefCols - 1);
                // Normal ones will be same as the element at edge of image (coefRows,i)
                else
                    image.at<uchar>(j,i) = image.at<uchar>(coefRows,i);

            }
        // With columns are empty
        // At this case, because we have fill some element(i <0) at above so i = coefRows
        for(int i = coefRows;i < image.rows-coefRows; i++)
            for(int j = 0;j < coefCols;j++)
            {
                // Same as above
                if(i <= coefRows)
                    image.at<uchar>(i,j) = image.at<uchar>(coefRows,coefCols);
                else if(i >= image.rows - coefRows -1)
                    image.at<uchar>(i,j) = image.at<uchar>(image.rows - coefRows -1, coefCols);
                else
                    image.at<uchar>(i,j) = image.at<uchar>(i,coefCols);
            }
    }
    // If source image is true color image
    else
    {
        // With rows are empty
        for(int i = 0;i < image.cols; i++)
            for(int j = 0;j < coefRows;j++)
            {
                // At the left corner of the Image, all empty element (i<=coefCols) will be same as the left corner
                if(i <= coefCols)
                {
                    image.at<Vec3b>(j,i)[0] = image.at<Vec3b>(coefRows,coefCols)[0];
                    image.at<Vec3b>(j,i)[1] = image.at<Vec3b>(coefRows,coefCols)[1];
                    image.at<Vec3b>(j,i)[2] = image.at<Vec3b>(coefRows,coefCols)[2];
                }
                // At the right corner of the image, all empty element (i>=image.cols - coefCols -1) will be same as the right corner
                else if(i >= image.cols - coefCols -1)
                {
                    image.at<Vec3d>(j,i)[0] = image.at<Vec3b>(coefRows,image.cols - coefCols - 1)[0];
                    image.at<Vec3b>(j,i)[1] = image.at<Vec3b>(coefRows,image.cols - coefCols - 1)[1];
                    image.at<Vec3b>(j,i)[2] = image.at<Vec3b>(coefRows,image.cols - coefCols - 1)[2];

                }
                // Normal ones will be same as the element at edge of image (coefRows,i)
                else
                {
                    image.at<Vec3b>(j,i)[0] = image.at<Vec3b>(coefRows,i)[0];
                    image.at<Vec3b>(j,i)[1] = image.at<Vec3b>(coefRows,i)[1];
                    image.at<Vec3b>(j,i)[2] = image.at<Vec3b>(coefRows,i)[2];
                }

            }
        // With columns are empty
        // At this case, because we have fill some element(i <0) at above so i = coefRows
        for(int i = coefRows;i < image.rows-coefRows; i++)
            for(int j = 0;j < coefCols;j++)
            {
                // Same as above
                if(i <= coefRows)
                {
                    image.at<Vec3b>(i,j)[0] = image.at<Vec3b>(coefRows,coefCols)[0];
                    image.at<Vec3b>(i,j)[1] = image.at<Vec3b>(coefRows,coefCols)[1];
                    image.at<Vec3b>(i,j)[2] = image.at<Vec3b>(coefRows,coefCols)[2];
                }
                else if(i >= image.rows - coefRows -1)
                {
                    image.at<Vec3b>(i,j)[0] = image.at<Vec3b>(image.rows - coefRows -1, coefCols)[0];
                    image.at<Vec3b>(i,j)[1] = image.at<Vec3b>(image.rows - coefRows -1, coefCols)[1];
                    image.at<Vec3b>(i,j)[2] = image.at<Vec3b>(image.rows - coefRows -1, coefCols)[2];
                }
                else
                {
                    image.at<Vec3b>(i,j)[0] = image.at<Vec3b>(i,coefCols)[0];
                    image.at<Vec3b>(i,j)[1] = image.at<Vec3b>(i,coefCols)[1];
                    image.at<Vec3b>(i,j)[2] = image.at<Vec3b>(i,coefCols)[2];
                }
            }
    }
}

/*****************************************************************
*********************** Filter Implement *************************
******************************************************************/


//Usage: reduce noise by average Filter
// w: width of Kernel (odd)
// h: height of Kernel (odd)
// option:
// ----------> 0: use Zero padding
// ----------> 1: use Replicate
int averageFilter(Mat sourceImage, Mat &destinationImage, int w, int h, int option)
{
    // Calculate the number of element in kernel
    int numKernel = w * h;

    // get the coefficient of Kernel's row and column
    int coefRows = h /2;
    int coefCols = w /2;

    // Visit all the element in Source Image
    if(sourceImage.channels() == 1)
        for(int i  = coefRows ; i < sourceImage.rows; i++)
            for(int j = coefCols;j < sourceImage.cols; j++)
            {
                //take the average values to Set them into the Destination Image
                int average = sumMemInKernel(sourceImage,coefCols,coefCols,i,j) / numKernel;
                destinationImage.at<uchar>(i,j) = average;
            }
    else
        for(int i  = coefRows ; i < sourceImage.rows; i++)
            for(int j = coefCols;j < sourceImage.cols; j++)
            {
                //take the average values to Set them into the Destination Image
                int averageRed = sumMemInKernel(sourceImage,coefCols,coefCols,i,j,0) / numKernel;
                int averageBlue = sumMemInKernel(sourceImage,coefCols,coefCols,i,j,1) / numKernel;
                int averageGreen = sumMemInKernel(sourceImage,coefCols,coefCols,i,j,2) / numKernel;

                destinationImage.at<Vec3b>(i,j)[0] = averageRed;
                destinationImage.at<Vec3b>(i,j)[1] = averageBlue;
                destinationImage.at<Vec3b>(i,j)[2] = averageGreen;
            }

    // Get the type of option user want to do
    switch (option)
    {
    // at Case option is 0
    case 0:
        zeroPaddingImage(destinationImage,coefRows,coefCols);
        break;
    // at case option is 1
    case 1:
        replicateImage(destinationImage,coefRows,coefCols);
        break;
    // if the option is not 0 or 1
    default:
        zeroPaddingImage(destinationImage,coefRows,coefCols);
        break;
    }
    return 0;
}


//Usage: reduce noise by order statistic filter
// sourceImage: input image
// destinationImage: output image
// w: width of Kernel (odd)
// h: height of Kernel (odd)
// name:
// ----------> 1: median filter
// ----------> 2: max filter
// ----------> 3: min filter
// option:
// ----------> 0: use Zero padding
// ----------> 1: use Replicate
int orderStatisticFilter(Mat sourceImage, Mat &destinationImage, int w, int h, int name, int option)
{
    // get the coefficient of Kernel's row and column
    int coefRows = h /2;
    int coefCols = w /2;

    // Visit all the element in Source Image
    // If source image is grayscale image
    if(sourceImage.channels() == 1)
    {
        for(int i  = coefRows ; i < sourceImage.rows; i++)
            for(int j = coefCols;j < sourceImage.cols; j++)
            {
                int values;
                switch (name)
                {
                // If user want to get the median values
                case 1:
                    values = takeMedianValueInKernel(sourceImage,coefRows,coefCols,i,j);
                    break;
                // If user want to get the max values
                case 2:
                    values = takeMaxValueInKernel(sourceImage,coefRows,coefCols,i,j);
                    break;
                // If user want to get the min values
                case 3:
                    values = takeMinValueInKernel(sourceImage,coefRows,coefCols,i,j);
                    break;
                // if User's choice is not existed, set the median values is default
                default:
                    values = takeMedianValueInKernel(sourceImage,coefRows,coefCols,i,j);
                    break;
                }
                //take the suitable values to Set them into the Destination Image
                destinationImage.at<uchar>(i,j) = values;
            }
    }
    // If source image is true color image
    else
    {
        int valueRed,valueBlue,valueGreen;
        for(int i  = coefRows ; i < sourceImage.rows; i++)
            for(int j = coefCols;j < sourceImage.cols; j++)
            {
                switch (name)
                {
                // If user want to get the median values
                case 1:
                {
                    valueRed = takeMedianValueInKernel(sourceImage,coefRows,coefCols,i,j,0);
                    valueBlue = takeMedianValueInKernel(sourceImage,coefRows,coefCols,i,j,1);
                    valueGreen = takeMedianValueInKernel(sourceImage,coefRows,coefCols,i,j,2);
                    //cout << "Red: " << valueRed << " Blue: "<< valueBlue << " Green: "<< valueGreen << endl;
                }
                    break;
                // If user want to get the max values
                case 2:
                {
                    valueRed = takeMaxValueInKernel(sourceImage,coefRows,coefCols,i,j,0);
                    valueBlue = takeMaxValueInKernel(sourceImage,coefRows,coefCols,i,j,1);
                    valueGreen = takeMaxValueInKernel(sourceImage,coefRows,coefCols,i,j,2);
                }
                    break;
                // If user want to get the min values
                case 3:
                {
                    valueRed = takeMinValueInKernel(sourceImage,coefRows,coefCols,i,j,0);
                    valueBlue = takeMinValueInKernel(sourceImage,coefRows,coefCols,i,j,1);
                    valueGreen = takeMinValueInKernel(sourceImage,coefRows,coefCols,i,j,2);
                }
                    break;
                // if User's choice is not existed, set the median values is default
                default:
                {
                    valueRed = takeMedianValueInKernel(sourceImage,coefRows,coefCols,i,j,0);
                    valueBlue = takeMedianValueInKernel(sourceImage,coefRows,coefCols,i,j,1);
                    valueGreen = takeMedianValueInKernel(sourceImage,coefRows,coefCols,i,j,2);
                }
                    break;
                }
                //take the suitable values to Set them into the Destination Image
                destinationImage.at<Vec3b>(i,j)[0] = valueRed;
                destinationImage.at<Vec3b>(i,j)[1] = valueBlue;
                destinationImage.at<Vec3b>(i,j)[2] = valueGreen;
            }
    }

    switch (option)
    {
    // at Case option is 0
    case 0:
        zeroPaddingImage(destinationImage,coefRows,coefCols);
        break;
    // at case option is 1
    case 1:
        replicateImage(destinationImage,coefRows,coefCols);
        break;
    // if the option is not 0 or 1
    default:
        zeroPaddingImage(destinationImage,coefRows,coefCols);
        break;
    }
    return 0;
}
