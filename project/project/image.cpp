#include "image.h"
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;

Image::Image()
{
	name = "default";
}

std::string Image::getName()
{
	return name;
}

void Image::setName(std::string _name)
{
	name = _name;
}

bool Image::loadImage()
{
	try {
		Mat img = imread(this->name);
		if (img.empty()) {
			return false;
		}
		else {
			namedWindow("image", WINDOW_NORMAL);
			imshow("image", img);
			waitKey(0);
			return true;
		}
	}
	catch (std::exception e) {
		return false;
	}
}

void Image::copy(Image* _image)
{
	
}

void Image::setGaussian(Image* _image)
{
	std::string src = _image->getName();
	//GaussianBlur(src,"",5,5,5,5);		/* N'arrive pas à grérer un string en entrée */
}
