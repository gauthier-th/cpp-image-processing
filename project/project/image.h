#include "controller.h"
#include <string>

class Image : public Controller
{
private:
	std::string name;
	int statut;
public:
	Image();
	std::string getName();
	void setName(std::string _name);
	bool loadImage();
	void copy(Image* _image);
	void setGaussian(Image* _image);
};

