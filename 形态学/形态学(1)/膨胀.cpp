#include<iostream>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>

using namespace std;
using namespace cv;

int main()
{
	Mat image=imread("8.jpg");
	namedWindow("原图");
	namedWindow("膨胀效果图");

	imshow("原图", image);

	Mat element = getStructuringElement(MORPH_RECT, Size(15, 15));
	Mat out;
	dilate(image, out, element);

	imshow("膨胀效果图", out);
	waitKey();
	return 0;
}
