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
    
    //Distort image with Salt and Pepper noise
    SaltAndPepper(img, 5000);

    Mat img2x; 
    resize(img, img2x, Size(), 2.0, 2.0);

    Mat imgf, imgf2x;

    double t1 = (double)getTickCount();
    medianBlur(img,imgf,7);
    t1 = ((double)getTickCount() - t1)/getTickFrequency();
    cout << "time1: " << t1*1000 << "ms" << endl;  

    double t2 = (double)getTickCount();
    medianBlur(img2x,imgf2x,7);
    t2 = ((double)getTickCount() - t2)/getTickFrequency();// f = ... /s
    cout << "time2: " << t2*1000 << "ms" << endl;  

    //write grayscale image into file
    imwrite("output.jpg", imgf);
    
    //show converted image
    imshow("output_window", imgf);
    cvWaitKey(0); // wait for keyboard input before program stops to show the image

    return 0;
}
