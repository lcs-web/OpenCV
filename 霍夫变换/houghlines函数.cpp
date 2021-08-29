#include<iostream>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/imgproc/imgproc_c.h>

using namespace std;
using namespace cv;


int main()
{  
	Mat srcimage = imread("14.jpg");
	Mat midimage, dstimage;

	Canny(srcimage, midimage, 50, 200, 3);
	cvtColor(midimage, dstimage, COLOR_GRAY2BGR);
	vector<Vec2f> lines;
	HoughLines(midimage, lines, 1, CV_PI / 180, 150, 0, 0);

	for (size_t i = 0; i < lines.size(); i++)
	{
		float rho = lines[i][0], theta = lines[i][1];
		Point pt1, pt2;
		double a = cos(theta), b = sin(theta);
		double x0 = a * rho, y0 = b * rho;
		pt1.x = cvRound(x0 + 1000 * (-b));
		pt1.y = cvRound(y0 + 1000 * (a));
		pt2.x = cvRound(x0 - 1000 * (-b));
		pt2.y = cvRound(y0 - 1000 * (a));
		line(dstimage, pt1, pt2, Scalar(55, 100, 195), 1, CV_AA);
	}
	imshow("【原始图】", srcimage);
	imshow("【边缘检测后的图】", midimage);
	imshow("【效果图】", dstimage);

	waitKey();
	return 0;

}
