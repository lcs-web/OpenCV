#include<iostream>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>

using namespace std;
using namespace cv;

Mat src_image, dst_image1, dst_image2, dst_image3, dst_image4, dst_image5;
int g_nBoxFilterValue = 6;
int g_nMeanBlurValue = 10;
int g_nGaussianBlurValue = 6;
int g_nMedianBlurValue = 10;
int g_nBilaterFilterValue = 10;

static void on_BoxFilter(int, void*)
{
	boxFilter(src_image, dst_image1, -1, Size(g_nBoxFilterValue + 1, g_nBoxFilterValue + 1));
	imshow("【方框滤波】", dst_image1);

}
static void on_MeanBlur(int, void*)
{
	blur(src_image, dst_image2, Size(g_nMeanBlurValue + 1, g_nMeanBlurValue + 1));
	imshow("【均值滤波】", dst_image2);

}
static void on_GaussianBlur(int, void*)
{
	GaussianBlur(src_image, dst_image3, Size(g_nGaussianBlurValue * 2 + 1, g_nGaussianBlurValue * 2 + 1), 0, 0);
	imshow("【高斯滤波】", dst_image3);

}
static void on_MedianBlur(int, void*)
{
	medianBlur(src_image, dst_image4, g_nMedianBlurValue * 2 + 1);
	imshow("【中值滤波】", dst_image4);

}
static void on_BilaterFilter(int, void*)
{
	bilateralFilter(src_image, dst_image5, g_nBilaterFilterValue, g_nBilaterFilterValue * 2, g_nBilaterFilterValue / 2);
	imshow("【双边滤波】", dst_image5);

}

int main()
{
	system("color 5E");
	src_image = imread("7.jpg");

	dst_image1 = src_image.clone();
	dst_image2 = src_image.clone();
	dst_image3 = src_image.clone();
	dst_image4 = src_image.clone();
	dst_image5 = src_image.clone();

	namedWindow("【方框滤波】");
	createTrackbar("内核值", "【方框滤波】", &g_nBoxFilterValue, 50, on_BoxFilter);
	on_BoxFilter(g_nBoxFilterValue, 0);

	namedWindow("【均值滤波】");
	createTrackbar("内核值", "【均值滤波】", &g_nMeanBlurValue, 50, on_MeanBlur);
	on_MeanBlur(g_nMeanBlurValue, 0);

	namedWindow("【高斯滤波】");
	createTrackbar("内核值", "【高斯滤波】", &g_nGaussianBlurValue, 50, on_GaussianBlur);
	on_GaussianBlur(g_nGaussianBlurValue, 0);

	namedWindow("【中值滤波】");
	createTrackbar("内核值", "【中值滤波】", &g_nMedianBlurValue, 50,on_MedianBlur);
	on_MedianBlur(g_nMedianBlurValue, 0);

	namedWindow("【双边滤波】");
	createTrackbar("内核值", "【双边滤波】", &g_nBilaterFilterValue, 50, on_BilaterFilter);
	on_BilaterFilter(g_nBilaterFilterValue, 0);

	waitKey();
	return 0;

}

