#include "application.h"

/**
 * Constructor
 */
Application::Application()
{
	this->controller = new Controller();
	this->viewMenu = new ViewMenu("Traitement d'image", this->controller);
}

/**
 * Runs the application
 */
void Application::run()
{
	this->controller->notify();
}
