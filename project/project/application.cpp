#include "application.h"

/**
 * Constructor
 */
Application::Application()
{
	this->controller = new Controller();
	this->viewMenu = new ViewMenu("Traitement d'image", this->controller);
	this->viewPathInput = new ViewPathInput("Selection de l'image", this->controller);
	this->viewMedianBlur = new ViewMedianBlur("Filtre median", *this->controller);
	this->viewGaussianBlur = new ViewGaussianBlur("Filtre gaussien", *this->controller);
	this->viewGradient = new ViewGradient("Calcule de gradient", *this->controller);
	this->viewDilation = new ViewDilation("Dilatation", *this->controller);
	this->viewContours = new ViewContours("Contours", *this->controller);
	this->viewThreshold = new ViewThreshold("Operations de seuillage", *this->controller);
	this->viewPrevious = new ViewPrevious("Operation precedente", *this->controller);
	this->viewPreview = new ViewPreview("Apercu de l'image", *this->controller);
}

/**
 * Runs the application
 */
void Application::run()
{
	this->controller->notify();
}
