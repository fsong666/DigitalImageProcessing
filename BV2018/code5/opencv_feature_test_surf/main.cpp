#include <stdio.h>
#include <iostream>
#include "opencv2/core.hpp"
#include "opencv2/features2d.hpp"
#include "opencv2/xfeatures2d.hpp"
#include "opencv2/highgui.hpp"

using namespace cv;
using namespace cv::xfeatures2d;


/** @function main */
int main(int argc, char* argv[])
{
  //read input image
  Mat img = imread("lena.jpg",IMREAD_GRAYSCALE);
   


  //-- Step 1: Detect the keypoints using SURF Detector
  int minHessian = 200;

  Ptr<SURF> detector = SURF::create( minHessian );

  std::vector<KeyPoint> keypoints;

  detector->detect( img, keypoints );
  

  //-- Draw keypoints
  Mat img_keypoints;

  drawKeypoints( img, keypoints, img_keypoints, Scalar::all(-1), DrawMatchesFlags::DEFAULT );
  

  //-- Show detected (drawn) keypoints
  imshow("Keypoints", img_keypoints );
  
  waitKey(0);

  return 0;
}

