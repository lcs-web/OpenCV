#include<iostream>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>

using namespace std;
using namespace cv;

int main()
{
	Mat image = imread("5.jpg");

	namedWindow("��˹�˲���ԭͼ��");
	namedWindow("��˹�˲���Ч��ͼ��");

	imshow("��˹�˲���ԭͼ��", image);

	Mat out;
	GaussianBlur(image, out, Size(7,7),0,0);

	imshow("��˹�˲���Ч��ͼ��", out);

	waitKey();
	return 0;

}
