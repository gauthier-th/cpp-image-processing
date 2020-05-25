#include <string>
#include <vector>
#include <opencv2/opencv.hpp>

class Image
{
private:
	std::string path;
	bool loaded = false;
	std::vector<cv::Mat> images;
	void setImage(cv::Mat image);
public:
	Image();
	std::string getPath();
	void setPath(std::string _path);
	void loadImage();
	bool isLoaded();
	cv::Mat getImage();
	void previous();
	void setMedian(int _ksize);
	void setGaussian(int _ksize);
	void setGradient();
	void setDilation(int dilation_type, int dilation_size);
	void setErosion(int erosion_type, int erosion_size);
	void setContours(int thresh);
	void setThreshold(int threshold_type, int threshold_value);
	void save();
	void display(std::string window_name);
};
