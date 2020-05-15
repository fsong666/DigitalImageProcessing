// Example 19-4. Two-dimensional line fitting
#include <opencv2/opencv.hpp>
#include <iostream>
#include <math.h>

using namespace std;
using namespace cv;

int main(int argc, char **argv) {
  Mat img(500, 500, CV_8UC3);
  RNG rng(-1);
  for (;;) {
    char key;
    int i, count = 100;
    int outliers = 0;
    float a = (float)rng.uniform(0., 200.);
    float b = (float)rng.uniform(0., 40.);
    float angle = (float)rng.uniform(0., CV_PI);
    float cos_a = cos(angle), sin_a = sin(angle);
    Point pt1, pt2;
    vector<Point> points(count);
    Vec4f fitted_line;
    float d, t;
    b = MIN(a * 0.3f, b);

    // generate some points that are close to the line
    for (i = 0; i < count - outliers; i++) {
      float x = (float)rng.uniform(-1., 1.) * a;
      float y = (float)rng.uniform(-1., 1.) * b;
      points[i].x = cvRound(x * cos_a - y * sin_a + img.cols / 2);
      points[i].y = cvRound(x * sin_a + y * cos_a + img.rows / 2);
    }

    // generate outlier points
    for (; i < count; i++) {
      points[i].x = rng.uniform(0, img.cols);
      points[i].y = rng.uniform(0, img.rows);
    }


    

    // find the optimal line
    fitLine(points, fitted_line, DIST_L1, 1, 0.001, 0.001);

    // draw the points
    img = Scalar::all(0);
    for (i = 0; i < count; i++)
      circle(img, points[i], 2, Scalar(0, 255, 255),FILLED, 8 , 0);

    // ... and the long enough line to cross the whole image
    d = sqrt((double)fitted_line[0] * fitted_line[0] + (double)fitted_line[1] * fitted_line[1]);
    fitted_line[0] /= d;
    fitted_line[1] /= d;
    t = (float)(img.cols + img.rows);
    pt1.x = cvRound(fitted_line[2] - fitted_line[0] * t);
    pt1.y = cvRound(fitted_line[3] - fitted_line[1] * t);
    pt2.x = cvRound(fitted_line[2] + fitted_line[0] * t);
    pt2.y = cvRound(fitted_line[3] + fitted_line[1] * t);
    line(img, pt1, pt2, Scalar(0, 255, 0), 3, CV_AA, 0);
    imshow("Fit Line", img);
    waitKey(0);

  return 0;
  }
}
