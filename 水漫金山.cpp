#include<iostream>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/imgproc/imgproc_c.h>

using namespace std;
using namespace cv;

Mat g_srcimage, g_dstimage, g_grayimage, g_maskimage;//����ԭʼͼ��Ŀ��ͼ���Ҷ�ͼ����ģͼ
int g_nFillMode = 1;//��ˮ����ģʽ
int g_nLowDifference = 20, g_nUpDifference = 20;//�������ֵ���������ֵ
int g_nConnectivity = 4;//��ʾfloodFill������ʶ���Ͱ�λ����ֵͨ
int g_bIsColor = true;//�Ƿ�Ϊ��ɫͼ�ı�ʶ������ֵ
bool g_bUseMask = false;//�Ƿ���ʾ��Ĥ���ڵĲ���ֵ
int g_nNewMaskVal = 255;//�µ����»��Ƶ�����ֵ

static void ShowHelpText()
{  
	cout<<endl<<"\t��ӭ������ˮ���ʾ������~"<<endl;
	cout << "\t��������˵��: " << endl
		<< "\t\t�����ͼ������- ������ˮ������" << endl
		<< "\t\t���̰�����ESC��- �˳�����" << endl
		<< "\t\t���̰�����1��-  �л���ɫͼ/�Ҷ�ͼģʽ" << endl
		<< "\t\t���̰�����2��- ��ʾ/������Ĥ����" << endl
		<< "\t\t���̰�����3��- �ָ�ԭʼͼ��" << endl
		<< "\t\t���̰�����4��- ʹ�ÿշ�Χ����ˮ���" << endl
		<< "\t\t���̰�����5��- ʹ�ý��䡢�̶���Χ����ˮ���" << endl
		<< "\t\t���̰�����6��- ʹ�ý��䡢������Χ����ˮ���" << endl
		<< "\t\t���̰�����7��- ������־���ĵͰ�λʹ��4λ������ģʽ" << endl
		<< "\t\t���̰�����8��- ������־���ĵͰ�λʹ��8λ������ģʽ" << endl;
}
static void onMouse(int event, int x, int y, int, void*)
{
	if (event != EVENT_LBUTTONDOWN)
		return;

	Point seed = Point(x, y);
	int LowDifference = g_nFillMode == 0 ? 0 : g_nLowDifference;
	int UpDifference = g_nFillMode == 0 ? 0 : g_nUpDifference;
	int flags = g_nConnectivity + (g_nNewMaskVal << 8) +
		(g_nFillMode == 1 ? CV_FLOODFILL_FIXED_RANGE : 0);

	int b = (unsigned)theRNG() & 255;//�������һ��0~255֮���ֵ
	int g = (unsigned)theRNG() & 255;//�������һ��0~255֮���ֵ
	int r = (unsigned)theRNG() & 255;//�������һ��0~255֮���ֵ
	Rect ccomp;//�����ػ��������С�߽��������

	Scalar newVal = g_bIsColor ? Scalar(b, g, r) : Scalar(r * 0.299 + g * 0.587 + b * 0.114);
	//���ػ��������ص���ֵ�����ǲ�ɫͼģʽ��ȡScalar(b, g, r)�����ǻҶ�ͼģʽ��ȡScalar(r*0.299 + g*0.587 + b*0.114)

	Mat dst = g_bIsColor ? g_dstimage : g_grayimage;//Ŀ��ͼ�ĸ�ֵ
	int area;

	//--------------------��<2>��ʽ����floodFill������-----------------------------
	if (g_bUseMask)
	{
		threshold(g_maskimage, g_maskimage, 1, 128, CV_THRESH_BINARY);
		area = floodFill(dst, g_maskimage, seed, newVal, &ccomp, Scalar(LowDifference, LowDifference, LowDifference),
			Scalar(UpDifference, UpDifference, UpDifference), flags);
		imshow("mask", g_maskimage);
	}
	else
	{
		area = floodFill(dst, seed, newVal, &ccomp, Scalar(LowDifference, LowDifference, LowDifference),
			Scalar(UpDifference, UpDifference, UpDifference), flags);
	}

	imshow("Ч��ͼ", dst);
	cout << area << " �����ر��ػ�\n";
}
 
int main()
{
	//�ı�console������ɫ  
	system("color 2F");

	//����ԭͼ
	g_srcimage = imread("16.jpg");

	if (!g_srcimage.data) { printf("Oh��no����ȡͼƬimage0����~�� \n"); return false; }

	//��ʾ��������
	ShowHelpText();

	g_srcimage.copyTo(g_dstimage);//����Դͼ��Ŀ��ͼ
	cvtColor(g_srcimage, g_grayimage, COLOR_BGR2GRAY);//ת����ͨ����image0���Ҷ�ͼ
	g_maskimage.create(g_srcimage.rows + 2, g_srcimage.cols + 2, CV_8UC1);//����image0�ĳߴ�����ʼ����Ĥmask

	namedWindow("Ч��ͼ", WINDOW_AUTOSIZE);

	//����Trackbar
	createTrackbar("�������ֵ", "Ч��ͼ", &g_nLowDifference, 255, 0);
	createTrackbar("�������ֵ", "Ч��ͼ", &g_nUpDifference, 255, 0);

	//���ص�����
	setMouseCallback("Ч��ͼ", onMouse, 0);

	//ѭ����ѯ����
	while (1)
	{
		//����ʾЧ��ͼ
		imshow("Ч��ͼ", g_bIsColor ? g_dstimage : g_grayimage);

		//��ȡ���̰���
		int c = waitKey(0);
		//�ж�ESC�Ƿ��£������±��˳�
		if ((c & 255) == 27)
		{
			cout << "�����˳�...........\n";
			break;
		}

		//���ݰ����Ĳ�ͬ�����и��ֲ���
		switch ((char)c)
		{
			//������̡�1�������£�Ч��ͼ���ڻҶ�ͼ����ɫͼ֮�以��
		case '1':
			if (g_bIsColor)//��ԭ��Ϊ��ɫ��תΪ�Ҷ�ͼ�����ҽ���Ĥmask����Ԫ������Ϊ0
			{
				cout << "���̡�1�������£��л���ɫ/�Ҷ�ģʽ����ǰ����Ϊ������ɫģʽ���л�Ϊ���Ҷ�ģʽ��\n";
				cvtColor(g_srcimage, g_grayimage, COLOR_BGR2GRAY);
				g_maskimage = Scalar::all(0);	//��mask����Ԫ������Ϊ0
				g_bIsColor = false;	//����ʶ����Ϊfalse����ʾ��ǰͼ��Ϊ��ɫ�����ǻҶ�
			}
			else//��ԭ��Ϊ�Ҷ�ͼ���㽫ԭ���Ĳ�ͼimage0�ٴο�����image�����ҽ���Ĥmask����Ԫ������Ϊ0
			{
				cout << "���̡�1�������£��л���ɫ/�Ҷ�ģʽ����ǰ����Ϊ������ɫģʽ���л�Ϊ���Ҷ�ģʽ��\n";
				g_srcimage.copyTo(g_dstimage);
				g_maskimage = Scalar::all(0);
				g_bIsColor = true;//����ʶ����Ϊtrue����ʾ��ǰͼ��ģʽΪ��ɫ
			}
			break;
			//������̰�����2�������£���ʾ/������Ĥ����
		case '2':
			if (g_bUseMask)
			{
				destroyWindow("mask");
				g_bUseMask = false;
			}
			else
			{
				namedWindow("mask", 0);
				g_maskimage = Scalar::all(0);
				imshow("mask", g_maskimage);
				g_bUseMask = true;
			}
			break;
			//������̰�����3�������£��ָ�ԭʼͼ��
		case '3':
			cout << "������3�������£��ָ�ԭʼͼ��\n";
			g_srcimage.copyTo(g_dstimage);
			cvtColor(g_dstimage, g_grayimage, COLOR_BGR2GRAY);
			g_maskimage = Scalar::all(0);
			break;
			//������̰�����4�������£�ʹ�ÿշ�Χ����ˮ���
		case '4':
			cout << "������4�������£�ʹ�ÿշ�Χ����ˮ���\n";
			g_nFillMode = 0;
			break;
			//������̰�����5�������£�ʹ�ý��䡢�̶���Χ����ˮ���
		case '5':
			cout << "������5�������£�ʹ�ý��䡢�̶���Χ����ˮ���\n";
			g_nFillMode = 1;
			break;
			//������̰�����6�������£�ʹ�ý��䡢������Χ����ˮ���
		case '6':
			cout << "������6�������£�ʹ�ý��䡢������Χ����ˮ���\n";
			g_nFillMode = 2;
			break;
			//������̰�����7�������£�������־���ĵͰ�λʹ��4λ������ģʽ
		case '7':
			cout << "������7�������£�������־���ĵͰ�λʹ��4λ������ģʽ\n";
			g_nConnectivity = 4;
			break;
			//������̰�����8�������£�������־���ĵͰ�λʹ��8λ������ģʽ
		case '8':
			cout << "������8�������£�������־���ĵͰ�λʹ��8λ������ģʽ\n";
			g_nConnectivity = 8;
			break;
		}
	}

	return 0;
}
