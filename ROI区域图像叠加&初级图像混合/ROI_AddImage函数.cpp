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
	
	waitKey();
	return 0;
}
