#pragma once
#include "controller.h"
#include "viewmenu.h"

class Application
{
private:
	Controller* controller;
	ViewMenu* viewMenu;
public:
	/**
	 * Constructor
	 */
	Application();

	/**
	 * Runs the application
	 */
	void run();
};

