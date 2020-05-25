#include "controller.h"
#include "viewmenu.h"
#include "viewpathinput.h"
#include "viewmedianblur.h"
#include "viewgaussianblur.h"
#include "viewgradient.h"
#include "viewdilation.h"
#include "viewerosion.h"
#include "viewpreview.h"
#include "viewcontours.h"

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
	ViewContours* viewContours;
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

