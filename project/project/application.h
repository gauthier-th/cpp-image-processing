#include "controller.h"
#include "viewmenu.h"
#include "viewpathinput.h"
#include "viewmedianblur.h"
#include "viewgaussianblur.h"
#include "viewgradient.h"
#include "viewdilation.h"
#include "viewerosion.h"
#include "viewcontours.h"
#include "viewthreshold.h"
#include "viewprevious.h"
#include "viewpreview.h"
#include "viewsave.h"

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
	ViewThreshold* viewThreshold;
	ViewPrevious* viewPrevious;
	ViewPreview* viewPreview;
	ViewSave* viewSave;
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

