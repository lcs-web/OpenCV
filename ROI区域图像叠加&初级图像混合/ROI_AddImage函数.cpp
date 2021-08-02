#include<iostream>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;

int main()
{
	Mat srcimage = imread("1.jpg");
	Mat logoimage = imread("2.jpg");
	if (!srcimage.data)
	{
		cout << "读取srcimage错误！" << endl;
	}
	if (!logoimage.data)
	{
		cout << "读取logoimage错误！" << endl;

	}
	Mat imageROI = srcimage(Rect(800, 350, logoimage.cols, logoimage.rows));

	Mat mask = imread("2.jpg", 0);
	logoimage.copyTo(imageROI, mask);

	namedWindow("利用ROI实现图像叠加示例窗口");
	imshow("利用ROI实现图像叠加示例窗口", srcimage);
	
	waitKey();
	return 0;
}
