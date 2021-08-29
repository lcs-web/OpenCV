#include<iostream>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>

using namespace std;
using namespace cv;


Mat g_srcimage, g_srcGrayimage, g_dstimage;

Mat g_cannyDetectedEdges;
int g_cannyLowThreshold = 1;

Mat g_sobelGradient_X, g_sobelGradient_Y;
Mat g_sobelAbsGradient_X, g_sobelAbsGradient_Y;
int g_sobelKernelSize = 1;

Mat g_scharrGradient_X, g_scharrGradient_Y;
Mat g_scharrAbsGradient_X, g_scharrAbsGradient_Y;

static void on_Canny(int, void*)
{
	blur(g_srcGrayimage, g_cannyDetectedEdges, Size(3, 3));
	Canny(g_cannyDetectedEdges, g_cannyDetectedEdges, g_cannyLowThreshold, g_cannyLowThreshold * 3, 3);
	g_dstimage = Scalar::all(0);
	g_srcimage.copyTo(g_dstimage, g_cannyDetectedEdges);

	imshow("��Ч��ͼ��Canny��Ե���", g_dstimage);
}
static void on_Sobel(int, void*)
{

	Sobel(g_srcimage, g_sobelGradient_X, CV_16S, 1, 0, (2 * g_sobelKernelSize + 1), 1, 1, BORDER_DEFAULT);
	convertScaleAbs(g_sobelGradient_X, g_sobelAbsGradient_X);

	Sobel(g_srcimage, g_sobelGradient_Y, CV_16S, 0, 1, (2 * g_sobelKernelSize + 1), 1, 1, BORDER_DEFAULT);
	convertScaleAbs(g_sobelGradient_Y, g_sobelAbsGradient_Y);

	addWeighted(g_sobelAbsGradient_X, 0.5, g_sobelAbsGradient_Y, 0.5, 0, g_dstimage);

	imshow("��Ч��ͼ��Sobel��Ե���", g_dstimage);

}

void Scharr()
{
	Scharr(g_srcimage, g_scharrGradient_X, CV_16S, 1, 0, 1, 0, BORDER_DEFAULT);
	convertScaleAbs(g_scharrGradient_X, g_scharrAbsGradient_X);

	Scharr(g_srcimage, g_scharrGradient_Y, CV_16S, 0, 1, 1, 0, BORDER_DEFAULT);
	convertScaleAbs(g_scharrGradient_Y, g_scharrAbsGradient_Y);

	addWeighted(g_scharrAbsGradient_X, 0.5, g_scharrAbsGradient_Y, 0.5, 0, g_dstimage);

	imshow("��Ч��ͼ��Scharr�˲���", g_dstimage);
}

int main()
{
	system("color 5E");
	g_srcimage = imread("12.jpg");
	if (!g_srcimage.data)
	{
		cout << "��ȡͼƬ����" << endl;

	}

	namedWindow("��ԭʼͼ��");
	imshow("��ԭʼͼ��", g_srcimage);

	g_dstimage.create(g_srcimage.size(), g_srcimage.type());

	cvtColor(g_srcimage, g_srcGrayimage, COLOR_BGR2GRAY);

	namedWindow("��Ч��ͼ��Canny��Ե���", WINDOW_AUTOSIZE);
	namedWindow("��Ч��ͼ��Sobel��Ե���", WINDOW_AUTOSIZE);

	createTrackbar("����ֵ��", "��Ч��ͼ��Canny��Ե���", &g_cannyLowThreshold, 120, on_Canny);
	createTrackbar("����ֵ��", "��Ч��ͼ��Sobel��Ե���", &g_sobelKernelSize, 3, on_Sobel);
	on_Canny(0, 0);
	on_Sobel(0, 0);
	Scharr();

	waitKey();
	return 0;
}
