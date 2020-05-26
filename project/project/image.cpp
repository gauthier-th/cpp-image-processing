#include "image.h"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace cv;

/**
 * Constructor
 */
Image::Image()
{
	this->images = std::vector<cv::Mat>();
}

/**
 * Get Image Path
 */
std::string Image::getPath()
{
	return this->path;
}

/**
 * Set Image Path
 * @param _name: Image Path
 */
void Image::setPath(std::string _name)
{
	this->path = _name;
}

/**
 * Load Image by checking the path
 */
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

/**
 * To set the statut of image loading
 */
bool Image::isLoaded()
{
	return this->loaded;
}

/**
 * Get Image
 */
Mat Image::getImage()
{
	if (this->images.size() == 0)
		return Mat();
	else
		return this->images[this->images.size() - 1];
}

/**
 * Set a new Image 
 */
void Image::setImage(cv::Mat image)
{
	this->images.push_back(image);
}

/**
 * Set the latest version of Image 
 */
void Image::previous()
{
	if (this->images.size() > 1)
		this->images.pop_back();
}

/**
 * Set a blur Median
 * @param _ksize: Intensity of blur
 */
void Image::setMedian(int _ksize)
{
	if (_ksize % 2 != 1)
		_ksize = _ksize + 1;
	cv::Mat dst;
	medianBlur(this->getImage().clone(), dst, _ksize);
	this->setImage(dst);
}

/**
 * Set a blur Gaussian
 * @param _ksize: Intensity of blur
 */
void Image::setGaussian(int _ksize)
{
	if (_ksize % 2 != 1)
		_ksize = _ksize + 1;
	cv::Mat dst;
	GaussianBlur(this->getImage().clone(), dst, cv::Size(_ksize, _ksize), 0, 0);
	this->setImage(dst);
}

/**
 * Calculates the gradient and applies it to the Image
 */
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

/**
 * Set a dilation on Image
 * @param dilation_type: Type of dilatation (rectangular/cross/circular)
 * @param dilation_size: Size of dilatation
 */
void Image::setDilation(int dilation_type, int dilation_size)
{
	cv::Mat dst;
	Mat element = getStructuringElement(dilation_type, Size(2 * dilation_size + 1, 2 * dilation_size + 1), Point(dilation_size, dilation_size));
	dilate(this->getImage(), dst, element);
	this->setImage(dst);
}

/**
 * Set a erosion on Image
 * @param erosion_type: Type of erosion (rectangular/cross/circular)
 * @param erosion_size: Size of erosion
 */
void Image::setErosion(int erosion_type, int erosion_size)
{
	cv::Mat dst;
	Mat element = getStructuringElement(erosion_type, Size(2 * erosion_size + 1, 2 * erosion_size + 1), Point(erosion_size, erosion_size));
	erode(this->getImage(), dst, element);
	this->setImage(dst);
}

/**
 * Find contours on Image
 * @param thresh: Precision of contours
 */
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

/**
 * Set a threshold on Image
 * @param threshold_type: Type of threshold (binary/inverse binary/truncated threshold/zero threshold/inverse zero threshold)
 * @param threshold_size: Size of threshold
 */
void Image::setThreshold(int threshold_type, int threshold_value)
{
	cv::Mat img = this->getImage();
	cvtColor(img, img, COLOR_BGR2GRAY);
	threshold(img, img, threshold_value, 255, threshold_type);
	this->setImage(img);
}

/**
 * Set a watershed on Image
 * @param randomColors: True == RandomColors or False == Black and White
 */
void Image::setWatershed(bool randomColors)
{
	cv::Mat src = this->getImage();

	// Create a kernel that we will use to sharpen our image
	Mat kernel = (Mat_<float>(3, 3) <<
		1, 1, 1,
		1, -8, 1,
		1, 1, 1); // an approximation of second derivative, a quite strong kernel
	// do the laplacian filtering as it is
	// well, we need to convert everything in something more deeper then CV_8U
	// because the kernel has some negative values,
	// and we can expect in general to have a Laplacian image with negative values
	// BUT a 8bits unsigned int (the one we are working with) can contain values from 0 to 255
	// so the possible negative number will be truncated
	Mat imgLaplacian;
	filter2D(src, imgLaplacian, CV_32F, kernel);
	Mat sharp;
	src.convertTo(sharp, CV_32F);
	Mat imgResult = sharp - imgLaplacian;
	// convert back to 8bits gray scale
	imgResult.convertTo(imgResult, CV_8UC3);
	imgLaplacian.convertTo(imgLaplacian, CV_8UC3);
	// Create binary image from source image
	Mat bw;
	cvtColor(imgResult, bw, COLOR_BGR2GRAY);
	threshold(bw, bw, 40, 255, THRESH_BINARY | THRESH_OTSU);
	//imshow("Binary Image", bw);
	// Perform the distance transform algorithm
	Mat dist;
	distanceTransform(bw, dist, DIST_L2, 3);
	// Normalize the distance image for range = {0.0, 1.0}
	// so we can visualize and threshold it
	normalize(dist, dist, 0, 1.0, NORM_MINMAX);
	// Threshold to obtain the peaks
	// This will be the markers for the foreground objects
	threshold(dist, dist, 0.4, 1.0, THRESH_BINARY);
	// Dilate a bit the dist image
	Mat kernel1 = Mat::ones(3, 3, CV_8U);
	dilate(dist, dist, kernel1);
	// Create the CV_8U version of the distance image
	// It is needed for findContours()
	Mat dist_8u;
	dist.convertTo(dist_8u, CV_8U);
	// Find total markers
	std::vector<std::vector<Point> > contours;
	findContours(dist_8u, contours, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
	// Create the marker image for the watershed algorithm
	Mat markers = Mat::zeros(dist.size(), CV_32S);
	// Draw the foreground markers
	for (size_t i = 0; i < contours.size(); i++)
	{
		drawContours(markers, contours, static_cast<int>(i), Scalar(static_cast<int>(i) + 1), -1);
	}
	// Draw the background marker
	circle(markers, Point(5, 5), 3, Scalar(255), -1);
	// Perform the watershed algorithm
	watershed(imgResult, markers);
	Mat mark;
	markers.convertTo(mark, CV_8U);
	bitwise_not(mark, mark);
	// Create the result image
	Mat dst = Mat::zeros(markers.size(), CV_8UC3);
	// Generate random colors
	std::vector<Vec3b> colors;
	for (size_t i = 0; i < contours.size(); i++)
	{
		int b, g, r;
		if (randomColors) {
			b = theRNG().uniform(0, 256);
			g = theRNG().uniform(0, 256);
			r = theRNG().uniform(0, 256);
		}
		else {
			b = 255;
			g = 255;
			r = 255;
		}
		colors.push_back(Vec3b((uchar)b, (uchar)g, (uchar)r));
	}
	// Fill labeled objects
	for (int i = 0; i < markers.rows; i++)
	{
		for (int j = 0; j < markers.cols; j++)
		{
			int index = markers.at<int>(i, j);
			if (index > 0 && index <= static_cast<int>(contours.size()))
			{
				dst.at<Vec3b>(i, j) = colors[index - 1];
			}
		}
	}

	this->setImage(dst);
}

/**
 * Save last Image
 * @param path: Path out of Image
 */
void Image::save(std::string path)
{
	imwrite(path, this->getImage());
}

/**
 * Diplay Image
 * @param window_name: Name of the window
 */
void Image::display(std::string window_name)
{
	Mat img = this->getImage();
	namedWindow(window_name, WINDOW_AUTOSIZE);
	imshow(window_name, img);
	waitKey(0);
	destroyWindow(window_name);
}