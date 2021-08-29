#include<iostream>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>

using namespace std;
using namespace cv;


#define WINDOW_NAME1 "【程序窗口1】" 
#define WINDOW_NAME2 "【程序窗口2】" 

Mat g_srcimage, g_srcimage1, g_grayimage;
int thresh = 30; 
int max_thresh = 175; 

void on_CornerHarris(int, void*)
{

	Mat dstimage;
	Mat normimage;
	Mat scaledimage;

	dstimage = Mat::zeros(g_srcimage.size(), CV_32FC1);
	g_srcimage1 = g_srcimage.clone();

	cornerHarris(g_grayimage, dstimage, 2, 3, 0.04, BORDER_DEFAULT);
	normalize(dstimage, normimage, 0, 255, NORM_MINMAX, CV_32FC1, Mat());
	convertScaleAbs(normimage, scaledimage);

	for (int j = 0; j < normimage.rows; j++)
	{
		for (int i = 0; i < normimage.cols; i++)
		{
			if ((int)normimage.at<float>(j, i) > thresh + 80)
			{
				circle(g_srcimage1, Point(i, j), 5, Scalar(10, 10, 255), 2, 8, 0);
				circle(scaledimage, Point(i, j), 5, Scalar(0, 10, 255), 2, 8, 0);
			}
		}
	}
	imshow(WINDOW_NAME1, g_srcimage1);
	imshow(WINDOW_NAME2, scaledimage);

}

int main()
{
	system("color 3F");
	g_srcimage = imread("17.jpg");
	if (!g_srcimage.data)
	{ 
		cout << "读取图片错误" << endl;
	}
	imshow("原始图", g_srcimage);
	g_srcimage1 = g_srcimage.clone();
	cvtColor(g_srcimage1, g_grayimage, COLOR_BGR2GRAY);
	namedWindow(WINDOW_NAME1, WINDOW_AUTOSIZE);
	createTrackbar("阈值: ", WINDOW_NAME1, &thresh, max_thresh, on_CornerHarris);
	on_CornerHarris(0, 0);

	waitKey();
	return(0);
}
