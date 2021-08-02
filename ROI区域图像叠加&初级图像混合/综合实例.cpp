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
		cout << "��ȡsrcimage����" << endl;
	}
	if (!logoimage.data)
	{
		cout << "��ȡlogoimage����" << endl;

	}
	Mat imageROI = srcimage(Rect(800, 350, logoimage.cols, logoimage.rows));

	Mat mask = imread("2.jpg", 0);
	logoimage.copyTo(imageROI, mask);

	namedWindow("����ROIʵ��ͼ�����ʾ������");
	imshow("����ROIʵ��ͼ�����ʾ������", srcimage);

//	waitKey();
	return true;
}
bool LinearBlending()
{
	double alphaValue = 0.5;
	double betaValue;
	Mat srcimage1, srcimage2, dstimage;

	srcimage1 = imread("����.jpg");
	srcimage2 = imread("logo.jpg");

	if (!srcimage1.data)
	{
		cout << "��ȡsrcimage1����" << endl;

	}
	if (!srcimage2.data)
	{
		cout << "��ȡsrcimage2����" << endl;
	}
	betaValue = (1.0 - alphaValue);
	addWeighted(srcimage1, alphaValue, srcimage2, betaValue, 0.0, dstimage);

	namedWindow("���Ի��ʾ�����ڡ�ԭͼ��", 1);
	imshow("���Ի��ʾ�����ڡ�ԭͼ��", srcimage1);

	namedWindow("���Ի��ʾ�����ڡ�Ч��ͼ��", 1);
	imshow("���Ի��ʾ�����ڡ�Ч��ͼ��", dstimage);

//	waitKey();
	return true;
}

bool ROI_LinearBlending()
{
	Mat srcimage3 = imread("1.jpg", 1);
	Mat srcimage4 = imread("2.jpg");

	if (!srcimage3.data)
	{
		cout << "��ȡsrcimage3����" << endl;

	}
	if (!srcimage4.data)
	{
		cout << "��ȡsrcimage4����" << endl;

	}

	Mat imageROI = srcimage3(Rect(800, 350, srcimage4.cols, srcimage4.rows));
	addWeighted(imageROI, 0.5, srcimage4, 0.3, 0.0, imageROI);

	namedWindow("��������ͼ����ʾ������");
	imshow("��������ͼ����ʾ������", srcimage3);

//	waitKey();
	return true;
}

int main()
{
	system("color 5E");
	if (ROI_AddImage() && LinearBlending() && ROI_LinearBlending())
	{
		cout << "��ϲ�㣬�ó�������Ҫ��ͼ��!"<<endl;

	}
	waitKey(0);
	return 0;
}
