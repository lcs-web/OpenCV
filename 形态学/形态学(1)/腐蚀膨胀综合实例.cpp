#include<iostream>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>

using namespace std;
using namespace cv;

Mat g_srcimage, g_dstimage;
int g_nTrackbarNumer = 0;
int g_nStructElementSize = 3;

void process()
{
	Mat element = getStructuringElement(MORPH_RECT, Size(2 * g_nStructElementSize + 1, 2 * g_nStructElementSize + 1),
		Point(g_nStructElementSize, g_nStructElementSize));
	if (g_nTrackbarNumer == 0)
	{
		erode(g_srcimage, g_dstimage, element);

	}
	else
	{
		dilate(g_srcimage, g_dstimage, element);

	}
	imshow("¡¾Ð§¹ûÍ¼¡¿", g_dstimage);
}
void on_TrackbarNumChange(int, void*)
{
	process();

}
void on_ElementSizeChange(int, void*)
{
	process();

}

int main()
{
	system("color 5E");
	g_srcimage = imread("9.jpg");
	if (!g_srcimage.data)
	{
		cout << "¶ÁÈ¡Í¼Æ¬Ê§°Ü" << endl;

	}
	namedWindow("¡¾Ô­Í¼¡¿");
	imshow("¡¾Ô­Í¼¡¿", g_srcimage);

	process();
	
	createTrackbar("¸¯Ê´/ÅòÕÍ", "¡¾Ð§¹ûÍ¼¡¿", &g_nTrackbarNumer, 1, on_TrackbarNumChange);
	createTrackbar("ÄÚºË³ß´ç", "¡¾Ð§¹ûÍ¼¡¿", &g_nStructElementSize, 21, on_ElementSizeChange);


	waitKey();
	return 0;
}
