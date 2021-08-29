#include<iostream>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>

using namespace std;
using namespace cv;


int main()
{
	Mat srcimage = imread("17.jpg",0);
	imshow("ԭʼͼ", srcimage);

	Mat cornerStrength;
	cornerHarris(srcimage, cornerStrength, 2, 3, 0.01);
	Mat harrisCorner;
	threshold(cornerStrength, harrisCorner, 0.00001, 255, THRESH_BINARY);
	imshow("�ǵ����Ķ�ֵЧ��ͼ", harrisCorner);

	waitKey();
	return 0;
}
