#include<iostream>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>

using namespace std;
using namespace cv;

int main()
{
	Mat image = imread("5.jpg");

	namedWindow("方框滤波【原图】");
	namedWindow("方框滤波【效果图】");

	imshow("方框滤波【原图】", image);

	Mat out;
	boxFilter(image, out, -1, Size(5, 5));

	imshow("方框滤波【效果图】", out);

	waitKey();
	return 0;

}
