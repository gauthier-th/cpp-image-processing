#include "image.h"
#include <iostream>

using namespace cv;

Image::Image()
{
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
		this->img = imread(this->path);
		if (this->img.empty())
			this->loaded = false;
		else {
			/*namedWindow("image", WINDOW_NORMAL);
			imshow("image", this->img);
			waitKey(0);*/
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
	return this->img;
}

void Image::copy()
{
	
}

void Image::setMedian(int _ksize)
{
	if (_ksize % 2 != 1)
		_ksize = _ksize + 1;
	cv::Mat dst;
	medianBlur(this->getImage().clone(), this->img, _ksize);
}

void Image::setGaussian(int _ksize)
{
	if (_ksize % 2 != 1)
		_ksize = _ksize + 1;
	GaussianBlur(this->getImage().clone(), this->img, cv::Size(_ksize, _ksize), 0, 0);
}

void Image::setGradient()
{
	int scale = 1;
	int delta = 0;
	int ddepth = CV_16S;

	Mat grad_x, grad_y;
	Mat abs_grad_x, abs_grad_y;

	/// Gradient X
	Sobel(this->img, grad_x, ddepth, 1, 0, 3, scale, delta, BORDER_DEFAULT);
	convertScaleAbs(grad_x, abs_grad_x);

	/// Gradient Y
	Sobel(this->img, grad_y, ddepth, 0, 1, 3, scale, delta, BORDER_DEFAULT);
	convertScaleAbs(grad_y, abs_grad_y);

	/// Total Gradient (approximate)
	addWeighted(abs_grad_x, 0.5, abs_grad_y, 0.5, 0, this->img);

}

void Image::setDilation(int dilation_type, int dilation_size)
{
	Mat element = getStructuringElement(dilation_type, Size(2 * dilation_size + 1, 2 * dilation_size + 1), Point(dilation_size, dilation_size));
	dilate(this->img, this->img, element);
}

void Image::setErosion(int erosion_type, int erosion_size)
{
	Mat element = getStructuringElement(erosion_type, Size(2 * erosion_size + 1, 2 * erosion_size + 1), Point(erosion_size, erosion_size));
	erode(this->img, this->img, element);
}

void Image::save()
{
	imwrite("./Image.jpg", this->img);
}

void Image::display(std::string window_name)
{
	namedWindow(window_name, WINDOW_AUTOSIZE);
	imshow(window_name, this->img);
	waitKey(0);
	destroyWindow(window_name);
}