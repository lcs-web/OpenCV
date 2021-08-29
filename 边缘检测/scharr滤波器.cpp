#include<iostream>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>

using namespace std;
using namespace cv;


int main()
{
	Mat grad_x, grad_y;
	Mat abs_grad_x, abs_grad_y, dst;
	Mat src = imread("12.jpg");
	imshow("��ԭʼͼ��Scharr�˲���", src);

	Scharr(src, grad_x, CV_16S, 1, 0, 1, 0, BORDER_DEFAULT);
	convertScaleAbs(grad_x, abs_grad_x);
	imshow("��Ч��ͼ�� X����Scharr", abs_grad_x);

	Scharr(src, grad_y, CV_16S, 0, 1, 1, 0, BORDER_DEFAULT);
	convertScaleAbs(grad_y, abs_grad_y);
	imshow("��Ч��ͼ��Y����Scharr", abs_grad_y);

	addWeighted(abs_grad_x, 0.5, abs_grad_y, 0.5, 0, dst);
	imshow("��Ч��ͼ���ϲ��ݶȺ�Scharr", dst);

	waitKey();
	return 0;
}
