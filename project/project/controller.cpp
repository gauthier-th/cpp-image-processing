#include "controller.h"

Controller::Controller() : currentScreen(0), img(new Image())
{
}

void Controller::setScreen(const int& idViews)
{
	if (idViews >= 0 && idViews <= 10)
	{
		this->currentScreen = idViews;
		this->notify();
	}
}

int Controller::getCurrentScreen()
{
	return this->currentScreen;
}

Image* Controller::getImage() {
	return this->img;
}