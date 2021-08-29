#include<iostream>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/imgproc/imgproc_c.h>

using namespace std;
using namespace cv;

Mat g_srcimage, g_dstimage, g_midimage;
vector<Vec4i> g_lines;
int g_nthreshold = 100;

static void on_HoughLines(int, void*)
{
	Mat dstimage = g_dstimage.clone();
	Mat midimage = g_midimage.clone();

	vector<Vec4i> mylines;
	HoughLinesP(midimage, mylines, 1, CV_PI / 180, g_nthreshold + 1, 50, 10);

	for (size_t i = 0; i < mylines.size(); i++)
	{
		Vec4i l = mylines[i];
		line(dstimage, Point(l[0], l[1]), Point(l[2], l[3]), Scalar(23, 180, 55), 1, CV_AA);
	}
	imshow("【效果图】", dstimage);
}
int main()
{
	system("color 3F");
	g_srcimage = imread("14.jpg");
	imshow("【原始图】", g_srcimage);

	namedWindow("【效果图】");
	createTrackbar("值", "【效果图】", &g_nthreshold, 200, on_HoughLines);
	Canny(g_srcimage, g_midimage, 50, 200, 3);
	cvtColor(g_midimage, g_dstimage, COLOR_GRAY2BGR);
	on_HoughLines(g_nthreshold, 0);
	HoughLinesP(g_midimage, g_lines, 1, CV_PI / 180, 80, 50, 10);
	imshow("【效果图】", g_dstimage);

	waitKey();
	return 0;

}

