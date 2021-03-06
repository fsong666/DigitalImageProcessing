#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main ( int, char** argv )
{
  Mat src, dst;
  Mat kernel;
  Point anchor;
  double delta;
  int ddepth;
  int kernel_size;
  const char* window_name = "filter2D Demo";
  src = imread( "lena.jpg", IMREAD_COLOR ); // Load an image
  if( src.empty() )
    { return -1; }
  anchor = Point( -1, -1 );
  delta = 0;
  ddepth =CV_8UC3;
  int ind = 0;
 
  // Default Kernel
//  kernel_size = 11; 
 // kernel = Mat::ones( kernel_size, kernel_size, CV_32F )/ (float)(kernel_size*kernel_size);//mittelwert

  // Default 3x3 Kernel mit Skalierung
  kernel_size = 3; 
  float s= kernel_size  * kernel_size ;
  Matx33f own_kernel(1.0/s, 1.0/s, 1.0/s,
                     1.0/s, 1.0/s, 1.0/s,
                     1.0/s, 1.0/s, 1.0/s)i
	Matx33f kernel1(1.2, 245.2, 3.4,
					1.2,  21.2, 1.2,
					2.2,  66.3, 214.34
					 );        
	kernel1 =kernel1 * (1.0 /100000);
  filter2D(src, dst, ddepth , own_kernel, anchor, delta, BORDER_DEFAULT );
  imshow( window_name, dst );
	cout <<"src.depth()=" <<src.depth()<<" src.type()="<<src.type() <<endl;
	cout << dst.at<cv::Vec3f>(2,2)<<endl;
	cout << dst.type()<<endl;
	cout << dst.depth()<<endl;
  waitKey(0);
  return 0;
}
