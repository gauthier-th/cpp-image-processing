#pragma once
#include "subject.h"
#include "image.h"

class Controller: public Subject
{
private:
	int currentScreen;
	Image* img;
public:
	Controller();
	void setScreen(const int& idViews);
	int getCurrentScreen();
	Image* getImage();
};