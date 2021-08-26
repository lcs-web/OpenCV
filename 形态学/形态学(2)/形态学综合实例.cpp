#include<iostream>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>

using namespace std;
using namespace cv;

Mat g_srcimage, g_dstimage;
int g_nElementShape = MORPH_RECT;

int g_nMaxIterationNum = 10;
int g_nOpenCloseNum = 0;
int g_nErodeDilateNum = 0;
int g_nTopBlackHatNum = 0;

static void on_OpenClose(int, void*)
{
	int offest = g_nOpenCloseNum - g_nMaxIterationNum;//ƫ����
	int Absolute_offset = offest > 0 ? offest : -offest;//ƫ�����ľ���ֵ

	Mat element = getStructuringElement(g_nElementShape, Size(Absolute_offset * 2 + 1, Absolute_offset * 2 + 1),
		Point(Absolute_offset, Absolute_offset));

	if (offest < 0)
	{
		morphologyEx(g_srcimage, g_dstimage,MORPH_OPEN , element);

	}
	else
	{
		morphologyEx(g_srcimage, g_dstimage,MORPH_CLOSE , element);

	}

	imshow("��������/�����㡿", g_dstimage);

}

static void on_ErodeDilate(int, void*)
{
	int offest = g_nErodeDilateNum - g_nMaxIterationNum;//ƫ����
	int Absolute_offset = offest > 0 ? offest : -offest;//ƫ�����ľ���ֵ

	Mat element = getStructuringElement(g_nElementShape, Size(Absolute_offset * 2 + 1, Absolute_offset * 2 + 1),
		Point(Absolute_offset, Absolute_offset));

	if (offest < 0)
	{
		erode(g_srcimage, g_dstimage, element);

	}
	else
	{
		dilate(g_srcimage, g_dstimage, element);

	}
	imshow("����ʴ/���͡�", g_dstimage);

}
static void on_TopBlackHat(int, void*)
{
	int offest = g_nTopBlackHatNum - g_nMaxIterationNum;//ƫ����
	int Absolute_offset = offest > 0 ? offest : -offest;//ƫ�����ľ���ֵ

	Mat element = getStructuringElement(g_nElementShape, Size(Absolute_offset * 2 + 1, Absolute_offset * 2 + 1),
		Point(Absolute_offset, Absolute_offset));

	if (offest < 0)
	{
		morphologyEx(g_srcimage, g_dstimage, MORPH_TOPHAT, element);

	}
	else
	{
		morphologyEx(g_srcimage, g_dstimage, MORPH_BLACKHAT, element);



	}
	imshow("����ñ/��ñ��", g_dstimage);

}
int main()
{
	system("color 5E");
	g_srcimage = imread("11.jpg");
	if (!g_srcimage.data)
	{
		cout << "��ȡͼƬ����" << endl;

	}
	namedWindow("��ԭͼ��");
	imshow("��ԭͼ��", g_srcimage);

	namedWindow("��������/�����㡿", 1);
	namedWindow("����ʴ/���͡�", 1);
	namedWindow("����ñ/��ñ��", 1);

	g_nOpenCloseNum = 9;
	g_nErodeDilateNum = 9;
	g_nTopBlackHatNum = 2;

	createTrackbar("����ֵ", "��������/�����㡿", &g_nOpenCloseNum, g_nMaxIterationNum * 2 + 1, on_OpenClose);
	createTrackbar("����ֵ", "����ʴ/���͡�", &g_nErodeDilateNum, g_nMaxIterationNum * 2 + 1, on_ErodeDilate);
	createTrackbar("����ֵ", "����ñ/��ñ��", &g_nTopBlackHatNum, g_nMaxIterationNum * 2 + 1, on_TopBlackHat);

	on_OpenClose(g_nOpenCloseNum, 0);
	on_ErodeDilate(g_nErodeDilateNum, 0);
	on_TopBlackHat(g_nTopBlackHatNum, 0);

	waitKey();
	return 0;
}
