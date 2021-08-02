#include<iostream>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;

bool ROI_AddImage()
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

//	waitKey();
	return true;
}
bool LinearBlending()
{
	double alphaValue = 0.5;
	double betaValue;
	Mat srcimage1, srcimage2, dstimage;

	srcimage1 = imread("锐雯.jpg");
	srcimage2 = imread("logo.jpg");

	if (!srcimage1.data)
	{
		cout << "读取srcimage1错误！" << endl;

	}
	if (!srcimage2.data)
	{
		cout << "读取srcimage2错误！" << endl;
	}
	betaValue = (1.0 - alphaValue);
	addWeighted(srcimage1, alphaValue, srcimage2, betaValue, 0.0, dstimage);

	namedWindow("线性混合示例窗口【原图】", 1);
	imshow("线性混合示例窗口【原图】", srcimage1);

	namedWindow("线性混合示例窗口【效果图】", 1);
	imshow("线性混合示例窗口【效果图】", dstimage);

//	waitKey();
	return true;
}

bool ROI_LinearBlending()
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

//	waitKey();
	return true;
}

int main()
{
	system("color 5E");
	if (ROI_AddImage() && LinearBlending() && ROI_LinearBlending())
	{
		cout << "恭喜你，得出了你需要的图像!"<<endl;

	}
	waitKey(0);
	return 0;
}
