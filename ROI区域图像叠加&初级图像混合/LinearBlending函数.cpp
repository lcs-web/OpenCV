#include<iostream>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;

int main()
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
	imshow("线性混合示例窗口【效果图】",dstimage);
	
	waitKey();
	return 0;
}
