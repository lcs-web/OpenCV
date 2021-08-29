#include<iostream>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>

using namespace std;
using namespace cv;

#define WINDOW_NAME "【程序窗口】"	

Mat g_srcimage, g_dstimage, g_tmpimage;

static void ShowHelpText()
{
	cout<<"\t\t\t欢迎来到OpenCV图像金字塔和resize示例程序~"<<endl;
	cout << "\t\t按键操作说明: " << endl;
	cout << "\t\t键盘按键【ESC】或者【Q】- 退出程序" << endl;
	cout << "\t\t键盘按键【1】或者【W】- 进行基于【resize】函数的图片放大" << endl;
	cout << "\t\t键盘按键【2】或者【S】- 进行基于【resize】函数的图片缩小" << endl;
	cout << "\t\t键盘按键【3】或者【A】- 进行基于【pyrUp】函数的图片放大" << endl;
	cout << "\t\t键盘按键【4】或者【D】- 进行基于【pyrDown】函数的图片缩小" << endl;
}

int main()
{
	
	system("color 2F");

	ShowHelpText();

	g_srcimage = imread("12.jpg");
	if (!g_srcimage.data)
	{ 
		cout << "读取图片错误" << endl;
	}

	namedWindow(WINDOW_NAME, WINDOW_AUTOSIZE);
	imshow(WINDOW_NAME, g_srcimage);

	g_tmpimage = g_srcimage;
	g_dstimage = g_tmpimage;

	int key = 0;

	while (1)
	{
		key = waitKey(9);

		switch (key)
		{
			
		case 27:
			return 0;
			break;

		case 'q':
			return 0;
			break;
 
		case 'a':
			pyrUp(g_tmpimage, g_dstimage, Size(g_tmpimage.cols * 2, g_tmpimage.rows * 2));
			cout << ">检测到按键【A】被按下，开始进行基于【pyrUp】函数的图片放大：图片尺寸×2 " << endl;
			break;

		case 'w':
			resize(g_tmpimage, g_dstimage, Size(g_tmpimage.cols * 2, g_tmpimage.rows * 2));
			cout << ">检测到按键【W】被按下，开始进行基于【resize】函数的图片放大：图片尺寸×2 " << endl;
			break;

		case '1':
			resize(g_tmpimage, g_dstimage, Size(g_tmpimage.cols * 2, g_tmpimage.rows * 2));
			cout << ">检测到按键【1】被按下，开始进行基于【resize】函数的图片放大：图片尺寸×2 " << endl;
			break;

		case '3': 
			pyrUp(g_tmpimage, g_dstimage, Size(g_tmpimage.cols * 2, g_tmpimage.rows * 2));
			cout << ">检测到按键【3】被按下，开始进行基于【pyrUp】函数的图片放大：图片尺寸×2" << endl;
			break;
	
		case 'd': 
			pyrDown(g_tmpimage, g_dstimage, Size(g_tmpimage.cols / 2, g_tmpimage.rows / 2));
			cout << ">检测到按键【D】被按下，开始进行基于【pyrDown】函数的图片缩小：图片尺寸/" << endl;
			break;

		case  's': 
			resize(g_tmpimage, g_dstimage, Size(g_tmpimage.cols / 2, g_tmpimage.rows / 2));
			cout << ">检测到按键【S】被按下，开始进行基于【resize】函数的图片缩小：图片尺寸/2" << endl;
			break;

		case '2':
			resize(g_tmpimage, g_dstimage, Size(g_tmpimage.cols / 2, g_tmpimage.rows / 2), (0, 0), (0, 0), 2);
			cout << ">检测到按键【2】被按下，开始进行基于【resize】函数的图片缩小：图片尺寸/2" << endl;
			break;

		case '4': 
			pyrDown(g_tmpimage, g_dstimage, Size(g_tmpimage.cols / 2, g_tmpimage.rows / 2));
			cout << ">检测到按键【4】被按下，开始进行基于【pyrDown】函数的图片缩小：图片尺寸/2" << endl;
			break;
		}

		imshow(WINDOW_NAME, g_dstimage);

		g_tmpimage = g_dstimage;
	}

	return 0;
}
