#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

#include <iostream>

using namespace cv;
using namespace std;



int main ( int, char** argv )
{


    // Declare the output variables
    Mat dst, drawing;
   
    //Declare parameters
    int thresh = 100;
    int max_thresh = 255;
    RNG rng(12345);





    // Loads an image
    Mat src = imread( "Shapes.jpg", IMREAD_GRAYSCALE ); 
    //Mat src = imread( "Haus.png", IMREAD_GRAYSCALE );

    // Check if image is loaded fine
    if(src.empty()){
        return -1;
    }
    // Edge detection
    Canny(src, dst, 50, 200, 3);

    // Find contours
    vector<vector<Point> > contours;
    vector<Vec4i> hierarchy;

    findContours( dst, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0, 0) );

    // Draw contours
    drawing = Mat::zeros( dst.size(), CV_8UC3 );
    for( int i = 0; i< contours.size(); i++ )
    {
       Scalar color = Scalar( rng.uniform(0, 255), rng.uniform(0,255), rng.uniform(0,255) );
       drawContours( drawing, contours, i, color, 2, 8, hierarchy, 0, Point() );
    }



    // Show in a window
    imshow( "Source", src); 
    imshow( "Contours", drawing );

    // Wait and Exit
    waitKey();
    return 0;
}
