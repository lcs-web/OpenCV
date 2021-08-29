#include<iostream>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>

using namespace std;
using namespace cv;
int main()
{  
	Mat srcimage = imread("13.jpg");
	Mat tmpimage, dstimage1, dstimage2;
	tmpimage = srcimage;
  
	imshow("【原始图】", srcimage);

	resize(tmpimage, dstimage1, Size(tmpimage.cols / 2, tmpimage.rows / 2), (0, 0), (0, 0), 3);
	resize(tmpimage, dstImage2, Size(tmpimage.cols * 2, tmpimage.rows * 2), (0, 0), (0, 0), 3);
  
	imshow("【效果图】之一", dstimage1);
	imshow("【效果图】之二", dstimage2);

	waitKey();
	return 0;
}
