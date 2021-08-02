#include<iostream>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>

using namespace cv;

int main()
{
	Mat mymat = imread("����.jpg");
	namedWindow("��1������ͼ");
	imshow("��1������ͼ", mymat);

	Mat image = imread("����.jpg");
	Mat logo = imread("2.jpg");
	namedWindow("��2��ԭ��ͼ");
	imshow("��2��ԭ��ͼ",image);

	namedWindow("��3��logoͼ");
	imshow("��3��logoͼ",logo);
	
	Mat imageROI;
	imageROI = image(Rect(800, 350, logo.cols, logo.rows));

	addWeighted(imageROI, 0.5,logo, 0.3, 0.0,imageROI);

	namedWindow("��4��ԭ��+logoͼ");
	imshow("��4��ԭ��+logoͼ", image);

	waitKey();

	return 0;
}
