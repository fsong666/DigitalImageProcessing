#include <opencv2/opencv.hpp>
#include <vector>


using namespace cv;
using namespace std;


void SaltAndPepper(cv::Mat &image, int n)
{
    for(int k=0;k<n;k++)
    {
        int i=rand()%image.cols;
        int j=rand()%image.rows;
        
        
        image.at<cv::Vec3b>(j, i)[0] = 255;
        image.at<cv::Vec3b>(j, i)[1] = 255;
        image.at<cv::Vec3b>(j, i)[2] = 255;
    }
    for(int k=0;k<n;k++)
    {
        int i=rand()%image.cols;
        int j=rand()%image.rows;
        
        image.at<cv::Vec3b>(j, i)[0] = 0;
        image.at<cv::Vec3b>(j, i)[1] = 0;
        image.at<cv::Vec3b>(j, i)[2] = 0;
    }
}


/////////////////////////////////////////////////////////////////////////////
// Main function
/////////////////////////////////////////////////////////////////////////////

int main(int argc, char* argv[]) {
    
    //read input image
    Mat img = imread("lena.jpg");
    Mat img_gray, img_out;
    cvtColor(img, img_gray, COLOR_BGR2GRAY);

    //Distort image with Salt and Pepper noise
    Mat img_dist = img.clone(); 
    SaltAndPepper(img_dist, 5000);

    //Filter the image
    Mat img_filtered;
    Mat img_filtered2;
    Mat img_filtered3;
    Mat img_filtered4;

    blur(img_dist,img_filtered2,Size(7,7));
    GaussianBlur(img_dist,img_filtered4,Size(5,5),0,0);
    medianBlur(img_dist,img_filtered,7); 
    hconcat(img_dist, img_filtered, img_out);

    Sobel(img_gray, img_filtered3, CV_8UC1, 1, 1, 3, 1);
   // hconcat(img_gray, img_filtered, img_out);
    //show input and output image
    imshow("medianbBlur", img_out);
    imshow("gaussfilter", img_filtered4);
    imshow("blurfilter", img_filtered2);
    imshow("sobel", img_filtered3);
    cvWaitKey(0); // wait for keyboard input before program stops to show the image

    return 0;
}
