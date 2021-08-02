#include<iostream>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>


using namespace std;
using namespace cv;

int main()
{
	Mat srcimage3 = imread("1.jpg", 1);
	Mat srcimage4 = imread("2.jpg");

	if (!srcimage3.data)
	{
		cout << "读取srcimage3错误！" << endl;

	}
	if (!srcimage4.data)
	{
		cout << "读取srcimage4错误！" << endl;

	}

	Mat imageROI = srcimage3(Rect(800, 350, srcimage4.cols, srcimage4.rows));
	addWeighted(imageROI, 0.5, srcimage4, 0.3, 0.0, imageROI);

	namedWindow("区域线性图像混合示例窗口");
	imshow("区域线性图像混合示例窗口", srcimage3);

	waitKey();
	return 0;
}
