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
	//��ɫͨ��
	Mat imageBlueChannel;

	logoimage = imread("2.jpg", 0);
	srcimage = imread("1.jpg");

	if (!logoimage.data)
	{
		cout << "��ȡlogoimage����" << endl;
		return false;

	}
	if (!srcimage.data)
	{
		cout << "��ȡsrcimage����" << endl;
		return false;
	}

	split(srcimage, channels);
	imageBlueChannel = channels.at(0);
	addWeighted(imageBlueChannel(Rect(800, 350, logoimage.cols, logoimage.rows)), 1.0, logoimage,
		0.5, 0, imageBlueChannel(Rect(800, 350, logoimage.cols, logoimage.rows)));
	merge(channels, srcimage);

	namedWindow("<1>ԭ��+��ɫͨ��");
	imshow("<1>ԭ��+��ɫͨ��", srcimage);
//��ɫͨ��
	Mat imageGreenChannel;

	logoimage = imread("2.jpg", 0);
	srcimage = imread("1.jpg");

	if (!logoimage.data)
	{
		cout << "��ȡlogoimage����" << endl;
		return false;

	}
	if (!srcimage.data)
	{
		cout << "��ȡsrcimage����" << endl;
		return false;
	}

	split(srcimage, channels);
	imageGreenChannel = channels.at(1);
	addWeighted(imageGreenChannel(Rect(800, 350, logoimage.cols, logoimage.rows)), 1.0, logoimage,
		0.5, 0, imageGreenChannel(Rect(800, 350, logoimage.cols, logoimage.rows)));
	merge(channels, srcimage);

	namedWindow("<2>ԭ��+��ɫͨ��");
	imshow("<2>ԭ��+��ɫͨ��", srcimage);
//��ɫͨ��
	Mat imageRedChannel;

	logoimage = imread("2.jpg", 0);
	srcimage = imread("1.jpg");

	if (!logoimage.data)
	{
		cout << "��ȡlogoimage����" << endl;
		return false;

	}
	if (!srcimage.data)
	{
		cout << "��ȡsrcimage����" << endl;
		return false;
	}

	split(srcimage, channels);
	imageRedChannel = channels.at(2);
	addWeighted(imageRedChannel(Rect(800, 350, logoimage.cols, logoimage.rows)), 1.0, logoimage,
		0.5, 0, imageRedChannel(Rect(800, 350, logoimage.cols, logoimage.rows)));
	merge(channels, srcimage);

	namedWindow("<3>ԭ��+��ɫͨ��");
	imshow("<3>ԭ��+��ɫͨ��", srcimage);

}
int main()
{
	system("color5E");
	if (MultiChannelBlending())
	{
		cout << "��ϲ�㣬�õ�����Ҫ��ϵ�ͼ��" << endl;

	}
	waitKey();
	return 0;
}

