#include<iostream>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>

using namespace std;
using namespace cv;

int main()
{
	Mat image = imread("5.jpg");

	namedWindow("高斯滤波【原图】");
	namedWindow("高斯滤波【效果图】");

	imshow("高斯滤波【原图】", image);

	Mat out;
	GaussianBlur(image, out, Size(7,7),0,0);

	imshow("高斯滤波【效果图】", out);

	waitKey();
	return 0;

}
