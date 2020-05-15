#include "controller.h"

Controller::Controller() : currentScreen(0)
{
}

void Controller::setScreen(const int& idViews)
{
	if (idViews >= 0 && idViews <= 9)
	{
		this->currentScreen = idViews;
		this->notify();
	}
}

int Controller::getCurrentScreen()
{
	return this->currentScreen;
}
