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
		if (this->img.empty()) {
			this->loaded = false;
		}
		else {
			namedWindow("image", WINDOW_NORMAL);
			imshow("image", this->img);
			waitKey(0);
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

void Image::setGaussian()
{
	// std::string src = _image->getName();
	// GaussianBlur(src,"",5,5,5,5);		/* N'arrive pas à grérer un string en entrée */
}
