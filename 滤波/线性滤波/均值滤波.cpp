#include<iostream>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>

using namespace std;
using namespace cv;

int main()
{
	Mat image = imread("5.jpg");

	namedWindow("均值滤波【原图】");
	namedWindow("均值滤波【效果图】");

	imshow("均值滤波【原图】", image);

	Mat out;
	blur(image, out, Size(7,7));

	imshow("均值滤波【效果图】", out);

	waitKey();
	return 0;

}
