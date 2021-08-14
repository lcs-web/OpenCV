#include<iostream>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>

using namespace std;
using namespace cv;

int main()
{
	Mat image = imread("5.jpg");
	
	namedWindow("Ë«±ßÂË²¨¡¾Ô­Í¼¡¿");
	namedWindow("Ë«±ßÂË²¨¡¾Ð§¹ûÍ¼¡¿");

	imshow("Ë«±ßÂË²¨¡¾Ô­Í¼¡¿", image);

	Mat out;
	bilateralFilter(image, out, 25,25*2,25/2);

	imshow("Ë«±ßÂË²¨¡¾Ð§¹ûÍ¼¡¿", out);

	waitKey();
	return 0;

}
