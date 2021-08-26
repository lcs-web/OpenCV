#include<iostream>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>

using namespace std;
using namespace cv;

int main()
{
	Mat image=imread("8.jpg");
	namedWindow("ԭͼ");
	namedWindow("����Ч��ͼ");

	imshow("ԭͼ", image);

	Mat element = getStructuringElement(MORPH_RECT, Size(15, 15));
	Mat out;
	dilate(image, out, element);

	imshow("����Ч��ͼ", out);
	waitKey();
	return 0;
}
