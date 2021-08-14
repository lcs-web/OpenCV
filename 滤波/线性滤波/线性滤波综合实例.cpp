#include<iostream>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>

using namespace std;
using namespace cv;

Mat g_srcimage, g_dstimage1, g_dstimage2, g_dstimage3;
int g_nBoxFilterValue = 3;
int g_nMeanBlurValue = 3;
int g_nGaussianBlurValue = 3;

static void on_BoxFilter(int,void*)
{
	boxFilter(g_srcimage, g_dstimage1, -1, Size(g_nBoxFilterValue + 1, g_nBoxFilterValue + 1));
	imshow("【方框滤波】", g_dstimage1);

}
static void on_MeanBlur(int, void*)
{
	blur(g_srcimage, g_dstimage2, Size(g_nMeanBlurValue + 1, g_nMeanBlurValue + 1));
	imshow("【均值滤波】", g_dstimage2);

}
static void on_GaussianBlur(int, void*)
{
	GaussianBlur(g_srcimage, g_dstimage3, Size(g_nGaussianBlurValue * 2 + 1, g_nGaussianBlurValue * 2 + 1), 0, 0);
	imshow("【高斯滤波】", g_dstimage3);

}
int main()
{
	system("color5E");
	g_srcimage = imread("6.jpg");
	if (!g_srcimage.data)
	{
		cout << "读取图片错误" << endl;

	}
	g_dstimage1 = g_srcimage.clone();
	g_dstimage2 = g_srcimage.clone();
	g_dstimage3 = g_srcimage.clone();

	namedWindow("【原图】", 1);
	imshow("【原图】", g_srcimage);

	namedWindow("【方框滤波】", 1);
	createTrackbar("内核值", "【方框滤波】", &g_nBoxFilterValue, 40, on_BoxFilter);
	on_BoxFilter(g_nBoxFilterValue, 0);

	namedWindow("【均值滤波】", 1);
	createTrackbar("内核值", "【均值滤波】", &g_nMeanBlurValue, 40, on_MeanBlur);
	on_MeanBlur(g_nMeanBlurValue, 0);

	namedWindow("【高斯滤波】", 1);
	createTrackbar("内核值", "【高斯滤波】", &g_nGaussianBlurValue,40, on_GaussianBlur);
	on_GaussianBlur(g_nGaussianBlurValue, 0);

	waitKey();
	return 0;
}
