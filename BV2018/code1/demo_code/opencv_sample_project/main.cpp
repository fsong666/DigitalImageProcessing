#include <opencv2/opencv.hpp>

using namespace cv;


/////////////////////////////////////////////////////////////////////////////
// Main function
/////////////////////////////////////////////////////////////////////////////

int main(int argc, char* argv[]) {
    
    //read input image
    Mat img = imread("lena.jpg");
    
    
    //convert inpur image to grayscale
    Mat gray;
    cvtColor( img, gray, CV_RGB2GRAY );
    
    //write grayscale image into file
    imwrite("output.jpg", gray);
    
    //show converted image
    imshow("output_window", gray);
    cvWaitKey(0); // wait for keyboard input before program stops to show the image

    return 0;
}
