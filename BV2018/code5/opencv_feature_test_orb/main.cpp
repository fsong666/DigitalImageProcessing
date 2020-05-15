#include <stdio.h>
#include <iostream>
#include "opencv2/core.hpp"
#include "opencv2/features2d.hpp"
#include "opencv2/xfeatures2d.hpp"
#include "opencv2/highgui.hpp"

using namespace std;
using namespace cv;
using namespace cv::xfeatures2d;


/** @function main */
int main(int argc, char* argv[])
{
  //read input images
  Mat img1 = imread("graf1.pgm", IMREAD_GRAYSCALE);
  Mat img2 = imread("graf2.pgm", IMREAD_GRAYSCALE);

//    img1.convertTo(img1, CV_32F, 1 / 255.);
//    img2.convertTo(img2, CV_32F, 1 / 255.);
  //parameters for orb detector
  int   nfeatures = 200;
  float scaleFactor =1.2f;
  int  	nlevels = 8;
   

  // create keypoint and descriptor list
  vector<KeyPoint> kpts1, kpts2;
  Mat desc1, desc2;

  
  //create orb detector,descriptor and matcher
  Ptr<FeatureDetector> detector = ORB::create(nfeatures, scaleFactor, nlevels );
  Ptr<DescriptorExtractor> descriptor = ORB::create();
  Ptr<DescriptorMatcher> matcher = DescriptorMatcher::create ( "BruteForce-Hamming" );

  //detect orb features
  detector->detect(img1, kpts1);
  detector->detect(img2, kpts2); 
  
  //describe orb features
  descriptor->compute(img1, kpts1, desc1);  
  descriptor->compute(img2, kpts2, desc2);


  //match features of img1 and img2
  vector<DMatch> matches;
  matcher->match ( desc1, desc2, matches );


  //-- Draw keypoints
  Mat img1_keypoints;
  drawKeypoints( img1, kpts1, img1_keypoints, Scalar::all(-1), DrawMatchesFlags::DEFAULT );
  

  //-- Show detected (drawn) keypoints
  imshow("Keypoints", img1_keypoints );


  //-- Draw keypoint matches of img1 and img2
  Mat img_match;
  drawMatches ( img1, kpts1, img2, kpts2, matches, img_match );

  //-- Show keypoint matches of img1 and img2
  imshow ( "Matches", img_match );

  
  waitKey(0);

  return 0;
}

