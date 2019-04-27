#include<iostream>
#include<opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main() {
	Mat src,gray_src;
	src = imread("f://tp//cat.jpg");
	if (src.empty()) {
		cout << "can not load image " << endl;
		return -1;
	}
	namedWindow("1", WINDOW_AUTOSIZE);
	imshow("1", src);

	cvtColor(src, gray_src, COLOR_BGR2GRAY);
	namedWindow("2", WINDOW_AUTOSIZE);
	imshow("2", gray_src);

	int hight = gray_src.rows;
	int width = gray_src.cols;
	//µ¥Í¨µÀ
	for (int row = 0; row < hight; row++) {
		for (int col = 0; col < width; col++) {
			int gray = gray_src.at<uchar>(row, col);
			gray_src.at<uchar>(row, col) = 255 - gray;
		}
	}
	
	Mat dst;
	dst.create(src.size(), src.type());
	hight = src.rows;
	width = src.cols;
	int nc = src.channels();
	for (int row = 0; row < hight; row++) {
		for (int col = 0; col < width; col++) {
			if (nc == 1) {
				cout << "can not load image111111111111 " << endl;
				int gray = gray_src.at<uchar>(row, col);
				gray_src.at<uchar>(row, col) = 255 - gray;
			}
			else if(nc == 3)
			{
				cout << "can not load image 22222222222" << endl;
				double b = src.at<Vec3d>(row, col)[0];
				double g = src.at<Vec3d>(row, col)[1];
				double r = src.at<Vec3d>(row, col)[2];
				src.at<Vec3d>(row, col)[0] = 255 - b;
				src.at<Vec3d>(row, col)[1] = 255 - g;
				src.at<Vec3d>(row, col)[2] = 255 - r;
			}
		}
	}


	namedWindow("3", WINDOW_AUTOSIZE);
	imshow("3", gray_src);
	waitKey(0);
	return 0;
}