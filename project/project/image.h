#include <string>
#include <opencv2/opencv.hpp>

class Image
{
private:
	std::string path;
	bool loaded = false;
	cv::Mat img;
public:
	Image();
	std::string getPath();
	void setPath(std::string _path);
	void loadImage();
	bool isLoaded();
	cv::Mat getImage();
	void copy();
	void setMedian(int _ksize);
	void setGaussian(int _ksize);
	void setGradient();
	void setDilation(int dilation_type, int dilation_size);
	void setErosion(int erosion_type, int erosion_size);
	void save();
	void display(std::string window_name);
};
