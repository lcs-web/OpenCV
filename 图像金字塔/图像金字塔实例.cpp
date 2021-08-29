#include<iostream>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>

using namespace std;
using namespace cv;

#define WINDOW_NAME "�����򴰿ڡ�"	

Mat g_srcimage, g_dstimage, g_tmpimage;

static void ShowHelpText()
{
	cout<<"\t\t\t��ӭ����OpenCVͼ���������resizeʾ������~"<<endl;
	cout << "\t\t��������˵��: " << endl;
	cout << "\t\t���̰�����ESC�����ߡ�Q��- �˳�����" << endl;
	cout << "\t\t���̰�����1�����ߡ�W��- ���л��ڡ�resize��������ͼƬ�Ŵ�" << endl;
	cout << "\t\t���̰�����2�����ߡ�S��- ���л��ڡ�resize��������ͼƬ��С" << endl;
	cout << "\t\t���̰�����3�����ߡ�A��- ���л��ڡ�pyrUp��������ͼƬ�Ŵ�" << endl;
	cout << "\t\t���̰�����4�����ߡ�D��- ���л��ڡ�pyrDown��������ͼƬ��С" << endl;
}

int main()
{
	
	system("color 2F");

	ShowHelpText();

	g_srcimage = imread("12.jpg");
	if (!g_srcimage.data)
	{ 
		cout << "��ȡͼƬ����" << endl;
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
			cout << ">��⵽������A�������£���ʼ���л��ڡ�pyrUp��������ͼƬ�Ŵ�ͼƬ�ߴ��2 " << endl;
			break;

		case 'w':
			resize(g_tmpimage, g_dstimage, Size(g_tmpimage.cols * 2, g_tmpimage.rows * 2));
			cout << ">��⵽������W�������£���ʼ���л��ڡ�resize��������ͼƬ�Ŵ�ͼƬ�ߴ��2 " << endl;
			break;

		case '1':
			resize(g_tmpimage, g_dstimage, Size(g_tmpimage.cols * 2, g_tmpimage.rows * 2));
			cout << ">��⵽������1�������£���ʼ���л��ڡ�resize��������ͼƬ�Ŵ�ͼƬ�ߴ��2 " << endl;
			break;

		case '3': 
			pyrUp(g_tmpimage, g_dstimage, Size(g_tmpimage.cols * 2, g_tmpimage.rows * 2));
			cout << ">��⵽������3�������£���ʼ���л��ڡ�pyrUp��������ͼƬ�Ŵ�ͼƬ�ߴ��2" << endl;
			break;
	
		case 'd': 
			pyrDown(g_tmpimage, g_dstimage, Size(g_tmpimage.cols / 2, g_tmpimage.rows / 2));
			cout << ">��⵽������D�������£���ʼ���л��ڡ�pyrDown��������ͼƬ��С��ͼƬ�ߴ�/" << endl;
			break;

		case  's': 
			resize(g_tmpimage, g_dstimage, Size(g_tmpimage.cols / 2, g_tmpimage.rows / 2));
			cout << ">��⵽������S�������£���ʼ���л��ڡ�resize��������ͼƬ��С��ͼƬ�ߴ�/2" << endl;
			break;

		case '2':
			resize(g_tmpimage, g_dstimage, Size(g_tmpimage.cols / 2, g_tmpimage.rows / 2), (0, 0), (0, 0), 2);
			cout << ">��⵽������2�������£���ʼ���л��ڡ�resize��������ͼƬ��С��ͼƬ�ߴ�/2" << endl;
			break;

		case '4': 
			pyrDown(g_tmpimage, g_dstimage, Size(g_tmpimage.cols / 2, g_tmpimage.rows / 2));
			cout << ">��⵽������4�������£���ʼ���л��ڡ�pyrDown��������ͼƬ��С��ͼƬ�ߴ�/2" << endl;
			break;
		}

		imshow(WINDOW_NAME, g_dstimage);

		g_tmpimage = g_dstimage;
	}

	return 0;
}
