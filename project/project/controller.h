#pragma once
#include "subject.h"

class Controller: public Subject
{
private:
	int currentScreen;
public:
	Controller();
	void setScreen(const int& idViews);
	int getCurrentScreen();
};