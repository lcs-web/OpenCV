#include<iostream>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>

using namespace std;
using namespace cv;

int main()
{
	Mat image = imread("12.jpg"); 
	Mat image1 = image.clone(); 
	Mat image2 = image.clone();
	imshow("【原始图】", image);
	Canny(image, image1, 150,100, 3);
	imshow("【效果图1】", image1);

	Mat dst, edge, gray;
	dst.create(image2.size(), image2.type());
	cvtColor(image2, gray, COLOR_BGR2GRAY);
	blur(gray, edge, Size(3, 3));
	Canny(edge, edge, 3, 9, 3);
	dst = Scalar::all(0);
	image2.copyTo(dst, edge);

	imshow("【效果图2】", dst);

	waitKey();
	return 0;
}
