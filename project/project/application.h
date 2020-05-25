#pragma once
#include "controller.h"
#include "viewmenu.h"
#include "viewpathinput.h"
#include "viewmedianblur.h"
#include "viewgaussianblur.h"
#include "viewgradient.h"
#include "viewdilation.h"
#include "viewerosion.h"
#include "viewpreview.h"

class Application
{
private:
	Controller* controller;
	ViewMenu* viewMenu;
	ViewPathInput* viewPathInput;
	ViewMedianBlur* viewMedianBlur;
	ViewGaussianBlur* viewGaussianBlur;
	ViewGradient* viewGradient;
	ViewDilation* viewDilation;
	ViewErosion* viewErosion;
	ViewPreview* viewPreview;
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

