#include<iostream>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/imgproc/types_c.h>
#include<opencv2/imgproc/imgproc_c.h>

using namespace std;
using namespace cv;

int g_nContrastValue=80;
int g_nBrightValue=80;
Mat g_srcimage;
Mat g_dstimage;

static void ContrastAndBright(int, void*)
{
	namedWindow("原始图窗口", 1);
	for (int y = 0; y < g_srcimage.rows; y++)
	{
		for (int x = 0; x < g_srcimage.cols; x++)
		{
			for (int c = 0; c < 3; c++)
			{
				g_dstimage.at<Vec3b>(y, x)[c] = saturate_cast<uchar>((g_nContrastValue * 0.01)
					* (g_srcimage.at<Vec3b>(y, x)[c]) + g_nBrightValue);
			}
		}
	}
	imshow("原始图窗口", g_srcimage);
	imshow("效果图窗口", g_dstimage);

}
int main()
{
	system("color 5F");
	g_srcimage = imread("4.jpg");
	if (!g_srcimage.data)
	{
		cout << "读取图像错误" << endl;
		return false;
	}
	g_dstimage = Mat::zeros(g_srcimage.size(), g_srcimage.type());
	namedWindow("效果图窗口", 1);
	
	createTrackbar("对比度：", "效果图窗口", &g_nContrastValue, 300, ContrastAndBright);
	createTrackbar("亮度", "效果图窗口", &g_nBrightValue, 200, ContrastAndBright);

	ContrastAndBright(g_nContrastValue, 0);
	ContrastAndBright(g_nBrightValue, 0);

	waitKey();
	return 0;

}
