#include<iostream>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/imgproc/imgproc_c.h>

using namespace std;
using namespace cv;


int main()
{ 
	Mat srcimage = imread("15.jpg");
	Mat midimage, dstimage;

	imshow("【原始图】", srcimage);

	cvtColor(srcimage, midimage, CV_BGR2GRAY);
	GaussianBlur(midimage, midimage, Size(9, 9), 2, 2);
	vector<Vec3f> circles;
	HoughCircles(midimage, circles, CV_HOUGH_GRADIENT, 1.5, 10, 200, 100, 0, 0);

	for (size_t i = 0; i < circles.size(); i++)
	{
		Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
		int radius = cvRound(circles[i][2]);
		circle(srcimage, center, 3, Scalar(0, 255, 0), -1, 8, 0);
		circle(srcimage, center, radius, Scalar(155, 50, 255), 3, 8, 0);
	}
	imshow("【效果图】", srcimage);
	waitKey();
	return 0;
}
