#include "image.h"
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

Image::Image()
{
	name = "default";
	statut = 0;
}

std::string Image::getName()
{
	return name;
}

int Image::getStatut()
{
	return statut;
}

void Image::setName(std::string _name)
{
	name = _name;
	statut = 1;
}

void Image::loadImage()
{
	std::string address = "C:\Users\Tom\Pictures\test.png";
	Mat img = imread(address);			/* Ne fonctionne pas */
	namedWindow("image", WINDOW_NORMAL);
	imshow("image", img);
	waitKey(0);
}

void Image::copy(Image* _image)
{
	
}

void Image::setGaussian(Image* _image)
{
	std::string src = _image->getName();
	GaussianBlur(src,"",5,5,5,5);		/* N'arrive pas à grérer un string en entrée */
}
