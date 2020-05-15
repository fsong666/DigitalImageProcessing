#include <opencv2/imgcodecs.hpp>
#include <opencv2/opencv.hpp>
#include <vector>


using namespace cv;
using namespace std;






/////////////////////////////////////////////////////////////////////////////
// Main function
/////////////////////////////////////////////////////////////////////////////

int main(int argc, char* argv[]) {
    
    //input image
    Mat input_image = (Mat_<uchar>(16, 16) <<
     	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 255, 255, 255, 255, 255, 255, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 255, 255, 255, 255, 255, 255, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 255, 255, 255, 255, 255, 255, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 255, 255, 255, 255, 255, 255, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 255, 255, 255, 255, 255, 255, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 255, 255, 255, 255, 255, 255, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 255, 255, 255, 255, 255, 255, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,	
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,	
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
        );

    Mat kernel_H1 = (Mat_<int>(3, 3) <<
         0,  1,  0,
        -1,  1,  1,
        -1, -1,  0);
    Mat kernel_H2 = (Mat_<int>(3, 3) <<
         0,  1,  0,
         1,  1, -1,
         0, -1, -1);
    Mat kernel_H3 = (Mat_<int>(3, 3) <<
         0, -1, -1,
         1,  1, -1,
         0,  1,  0);
    Mat kernel_H4 = (Mat_<int>(3, 3) <<
        -1, -1,  0,
        -1,  1,  1,
         0,  1,  0);

    Mat kernel_Y1 = (Mat_<int>(3, 1) <<
         -1,  
          1,
          0);
    Mat kernel_Y2 = (Mat_<int>(3, 1) <<
          0,
          1,  
         -1);
    Mat kernel_X1 = (Mat_<int>(1, 3) <<
        -1, 1 ,0);
    Mat kernel_X2 = (Mat_<int>(1, 3) <<
         0, 1, -1);

    Mat output_image, H[4];

    morphologyEx(input_image, H[0], MORPH_HITMISS, kernel_H1);
    morphologyEx(input_image, H[1], MORPH_HITMISS, kernel_H2);
    morphologyEx(input_image, H[2], MORPH_HITMISS, kernel_H3);
    morphologyEx(input_image, H[3], MORPH_HITMISS, kernel_H4);
	output_image = H[0];
//    bitwise_or(H[0], H[1], output_image);
//    bitwise_or(H[2], output_image, output_image);
//    bitwise_or(H[3], output_image, output_image);

    const int rate = 40;
    resize(input_image, input_image, Size(), rate, rate, INTER_NEAREST);
    imshow("Original", input_image);
    moveWindow("Original", 0, 200);
    resize(output_image, output_image, Size(), rate, rate, INTER_NEAREST);
    imshow("Hit or Miss", output_image);
    moveWindow("Hit or Miss", 800, 200);
    cvWaitKey(0); // wait for keyboard input before program stops to show the image

    return 0;
}
