#include<iostream>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>

using namespace std;
using namespace cv;

int main()
{
	Mat image = imread("5.jpg");
	
	namedWindow("˫���˲���ԭͼ��");
	namedWindow("˫���˲���Ч��ͼ��");

	imshow("˫���˲���ԭͼ��", image);

	Mat out;
	bilateralFilter(image, out, 25,25*2,25/2);

	imshow("˫���˲���Ч��ͼ��", out);

	waitKey();
	return 0;

}
