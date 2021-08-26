#include<iostream>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>

using namespace std;
using namespace cv;


int main()
{
	Mat image = imread("10.jpg");
	namedWindow("��ԭͼ��");
	namedWindow("��Ч��ͼ��");
	imshow("��ԭͼ��", image);

	Mat element = getStructuringElement(MORPH_RECT, Size(15, 15));
//	morphologyEx(image, image, MORPH_OPEN, element);
//	morphologyEx(image, image, MORPH_CLOSE, element);
//	morphologyEx(image, image, MORPH_GRADIENT, element);
//	morphologyEx(image, image, MORPH_TOPHAT, element);
//	morphologyEx(image, image, MORPH_BLACKHAT, element);
//	morphologyEx(image, image, MORPH_ERODE, element);
	morphologyEx(image, image, MORPH_DILATE, element);
	imshow("��Ч��ͼ��", image);

	waitKey();
	return 0;
}
