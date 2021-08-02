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
	imshow("���Ի��ʾ�����ڡ�Ч��ͼ��",dstimage);
	
	waitKey();
	return 0;
}
