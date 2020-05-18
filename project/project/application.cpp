#include "application.h"

/**
 * Constructor
 */
Application::Application()
{
	this->controller = new Controller();
	this->viewMenu = new ViewMenu("Traitement d'image", this->controller);
	this->viewPathInput = new ViewPathInput("Sélection de l'image", this->controller);
}

/**
 * Runs the application
 */
void Application::run()
{
	this->controller->notify();
}
