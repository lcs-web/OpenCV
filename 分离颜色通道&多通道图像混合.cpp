#include<iostream>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>


using namespace std;
using namespace cv;

bool MultiChannelBlending()
{
	Mat srcimage;
	Mat logoimage;
	vector<Mat>channels;
	//蓝色通道
	Mat imageBlueChannel;

	logoimage = imread("2.jpg", 0);
	srcimage = imread("1.jpg");

	if (!logoimage.data)
	{
		cout << "读取logoimage错误" << endl;
		return false;

	}
	if (!srcimage.data)
	{
		cout << "读取srcimage错误" << endl;
		return false;
	}

	split(srcimage, channels);
	imageBlueChannel = channels.at(0);
	addWeighted(imageBlueChannel(Rect(800, 350, logoimage.cols, logoimage.rows)), 1.0, logoimage,
		0.5, 0, imageBlueChannel(Rect(800, 350, logoimage.cols, logoimage.rows)));
	merge(channels, srcimage);

	namedWindow("<1>原画+蓝色通道");
	imshow("<1>原画+蓝色通道", srcimage);
//绿色通道
	Mat imageGreenChannel;

	logoimage = imread("2.jpg", 0);
	srcimage = imread("1.jpg");

	if (!logoimage.data)
	{
		cout << "读取logoimage错误" << endl;
		return false;

	}
	if (!srcimage.data)
	{
		cout << "读取srcimage错误" << endl;
		return false;
	}

	split(srcimage, channels);
	imageGreenChannel = channels.at(1);
	addWeighted(imageGreenChannel(Rect(800, 350, logoimage.cols, logoimage.rows)), 1.0, logoimage,
		0.5, 0, imageGreenChannel(Rect(800, 350, logoimage.cols, logoimage.rows)));
	merge(channels, srcimage);

	namedWindow("<2>原画+绿色通道");
	imshow("<2>原画+绿色通道", srcimage);
//红色通道
	Mat imageRedChannel;

	logoimage = imread("2.jpg", 0);
	srcimage = imread("1.jpg");

	if (!logoimage.data)
	{
		cout << "读取logoimage错误" << endl;
		return false;

	}
	if (!srcimage.data)
	{
		cout << "读取srcimage错误" << endl;
		return false;
	}

	split(srcimage, channels);
	imageRedChannel = channels.at(2);
	addWeighted(imageRedChannel(Rect(800, 350, logoimage.cols, logoimage.rows)), 1.0, logoimage,
		0.5, 0, imageRedChannel(Rect(800, 350, logoimage.cols, logoimage.rows)));
	merge(channels, srcimage);

	namedWindow("<3>原画+红色通道");
	imshow("<3>原画+红色通道", srcimage);

}
int main()
{
	system("color5E");
	if (MultiChannelBlending())
	{
		cout << "恭喜你，得到了需要混合的图像" << endl;

	}
	waitKey();
	return 0;
}

