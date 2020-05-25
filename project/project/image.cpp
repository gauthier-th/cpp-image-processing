#include "image.h"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace cv;

Image::Image()
{
	this->images = std::vector<cv::Mat>();
}

std::string Image::getPath()
{
	return this->path;
}

void Image::setPath(std::string _name)
{
	this->path = _name;
}

void Image::loadImage()
{
	try {
		Mat img;
		img = imread(this->path);
		if (img.empty())
			this->loaded = false;
		else {
			this->setImage(img);
			this->loaded = true;
		}
	}
	catch (std::exception e) {
		this->loaded = false;
	}
}

bool Image::isLoaded()
{
	return this->loaded;
}
Mat Image::getImage()
{
	if (this->images.size() == 0)
		return Mat();
	else
		return this->images[this->images.size() - 1];
}

void Image::setImage(cv::Mat image)
{
	this->images.push_back(image);
}

void Image::previous()
{
	if (this->images.size() > 1)
		this->images.pop_back();
}

void Image::setMedian(int _ksize)
{
	if (_ksize % 2 != 1)
		_ksize = _ksize + 1;
	cv::Mat dst;
	medianBlur(this->getImage().clone(), dst, _ksize);
	this->setImage(dst);
}

void Image::setGaussian(int _ksize)
{
	if (_ksize % 2 != 1)
		_ksize = _ksize + 1;
	cv::Mat dst;
	GaussianBlur(this->getImage().clone(), dst, cv::Size(_ksize, _ksize), 0, 0);
	this->setImage(dst);
}

void Image::setGradient()
{
	int scale = 1;
	int delta = 0;
	int ddepth = CV_16S;

	Mat grad_x, grad_y;
	Mat abs_grad_x, abs_grad_y;

	cv::Mat img = this->getImage();

	/// Gradient X
	Sobel(img, grad_x, ddepth, 1, 0, 3, scale, delta, BORDER_DEFAULT);
	convertScaleAbs(grad_x, abs_grad_x);

	/// Gradient Y
	Sobel(img, grad_y, ddepth, 0, 1, 3, scale, delta, BORDER_DEFAULT);
	convertScaleAbs(grad_y, abs_grad_y);

	/// Total Gradient (approximate)
	addWeighted(abs_grad_x, 0.5, abs_grad_y, 0.5, 0, img);
	
	this->setImage(img);
}

void Image::setDilation(int dilation_type, int dilation_size)
{
	cv::Mat dst;
	Mat element = getStructuringElement(dilation_type, Size(2 * dilation_size + 1, 2 * dilation_size + 1), Point(dilation_size, dilation_size));
	dilate(this->getImage(), dst, element);
	this->setImage(dst);
}

void Image::setErosion(int erosion_type, int erosion_size)
{
	cv::Mat dst;
	Mat element = getStructuringElement(erosion_type, Size(2 * erosion_size + 1, 2 * erosion_size + 1), Point(erosion_size, erosion_size));
	erode(this->getImage(), dst, element);
	this->setImage(dst);
}

void Image::setContours(int thresh)
{
	RNG rng(12345);
	Mat canny_output;
	std::vector<std::vector<Point> > contours;
	std::vector<Vec4i> hierarchy;
	cv::Mat img = this->getImage();

	// Detect edges using canny
	Canny(img, canny_output, thresh, thresh * 2, 3);
	// Find contours
	findContours(canny_output, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE, Point(0, 0));

	// Draw contours
	Mat drawing = Mat::zeros(canny_output.size(), CV_8UC3);
	for (int i = 0; i < contours.size(); i++)
	{
		Scalar color = Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));
		drawContours(drawing, contours, i, color, 2, 8, hierarchy, 0, Point());
	}

	this->setImage(canny_output);
}

void Image::setThreshold(int threshold_type, int threshold_value)
{
	cv::Mat img = this->getImage();
	cvtColor(img, img, COLOR_BGR2GRAY);
	threshold(img, img, threshold_value, 255, threshold_type);
	this->setImage(img);
}

void Image::save(std::string path)
{
	imwrite(path, this->getImage());
}

void Image::display(std::string window_name)
{
	Mat img = this->getImage();
	namedWindow(window_name, WINDOW_AUTOSIZE);
	imshow(window_name, img);
	waitKey(0);
	destroyWindow(window_name);
}