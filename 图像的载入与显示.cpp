#include<iostream>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>

using namespace cv;

int main()
{
	Mat mymat = imread("Èñö©.jpg");
	namedWindow("¡¾1¡¿¶¯ÂþÍ¼");
	imshow("¡¾1¡¿¶¯ÂþÍ¼", mymat);

	Mat image = imread("Èñö©.jpg");
	Mat logo = imread("2.jpg");
	namedWindow("¡¾2¡¿Ô­»­Í¼");
	imshow("¡¾2¡¿Ô­»­Í¼",image);

	namedWindow("¡¾3¡¿logoÍ¼");
	imshow("¡¾3¡¿logoÍ¼",logo);
	
	Mat imageROI;
	imageROI = image(Rect(800, 350, logo.cols, logo.rows));

	addWeighted(imageROI, 0.5,logo, 0.3, 0.0,imageROI);

	namedWindow("¡¾4¡¿Ô­»­+logoÍ¼");
	imshow("¡¾4¡¿Ô­»­+logoÍ¼", image);

	waitKey();

	return 0;
}
