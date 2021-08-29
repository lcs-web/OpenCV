#include<iostream>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/imgproc/imgproc_c.h>

using namespace std;
using namespace cv;

int main()
{
	Mat srcimage = imread("14.jpg");
	Mat midimage, dstimage;

	Canny(srcimage, midimage, 50, 200, 3);
	cvtColor(midimage, dstimage, CV_GRAY2BGR);
	vector<Vec4i> lines;
	HoughLinesP(midimage, lines, 1, CV_PI / 180, 80, 50, 10);

	for (size_t i = 0; i < lines.size(); i++)
	{
		Vec4i l = lines[i];
		line(dstimage, Point(l[0], l[1]), Point(l[2], l[3]), Scalar(186, 88, 255), 1, CV_AA);
	}
 
	imshow("【原始图】", srcimage);
	imshow("【边缘检测后的图】", midimage);
	imshow("【效果图】", dstimage);

	waitKey();
	return 0;
}
