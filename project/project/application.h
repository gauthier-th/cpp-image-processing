#pragma once
#include "controller.h"
#include "viewmenu.h"
#include "viewpathinput.h"
#include "viewmedianblur.h"
#include "viewgaussianblur.h"
#include "viewgradient.h"
#include "viewdilatation.h"
#include "viewerosion.h"

class Application
{
private:
	Controller* controller;
	ViewMenu* viewMenu;
	ViewPathInput* viewPathInput;
	ViewMedianBlur* viewMedianBlur;
	ViewGaussianBlur* viewGaussianBlur;
	ViewGradient* viewGradient;
	ViewDilatation* viewDilatation;
	ViewErosion* viewErosion;
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

