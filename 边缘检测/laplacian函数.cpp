#include<iostream>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>

using namespace std;
using namespace cv;


int main()
{

	Mat src, src_gray, dst, abs_dst;  
	src = imread("12.jpg"); 

	imshow("��ԭʼͼ��ͼ��Laplace�任", src);

	GaussianBlur(src, src, Size(3, 3), 0, 0, BORDER_DEFAULT);
	cvtColor(src, src_gray, COLOR_RGB2GRAY);
	Laplacian(src_gray, dst, CV_16S, 3, 1, 0, BORDER_DEFAULT);
	convertScaleAbs(dst, abs_dst);

	imshow("��Ч��ͼ��ͼ��Laplace�任", abs_dst);

	waitKey();
	return 0;
}
