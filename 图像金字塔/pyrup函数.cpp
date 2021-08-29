#include<iostream>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>

using namespace std;
using namespace cv;

int main()
{
	Mat srcimage = imread("13.jpg");
	Mat tmpimage, dstimage;
	tmpimage = srcimage;
	imshow("【原始图】", srcimage);

	pyrUp(tmpimage, dstimage, Size(tmpimage.cols * 2, tmpimage.rows * 2));  
	imshow("【效果图】", dstimage);

	waitKey();
	return 0;
}
