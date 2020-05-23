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
	void setGaussian();
	void save();
};
