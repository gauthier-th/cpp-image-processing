#include "viewpathinput.h"
#include <iostream>

/**
 * Constructor
 * @param _controller: Application controller
 */
ViewPathInput::ViewPathInput(const std::string& _title, Controller* _controller)
	: View(_title), controller(_controller)
{
	this->controller->addObserver(this);
}

/**
 * Notification function of the view
 */
void ViewPathInput::notify()
{
	if (this->controller->getCurrentScreen() == 0)
		this->display();
}

/**
 * Displays the view
 */
void ViewPathInput::display()
{
	std::string command = "TITLE ";
	std::string titleCommand = command + this->getTitle();
	system(titleCommand.c_str());
	this->clear();
	do {
		std::cout << "Entrez le chemin de l'image :" << std::endl;
		std::string path;
		std::cin >> path;
		this->controller->getImage()->setPath(path);
		this->controller->getImage()->loadImage();
		this->clear();
		if (!this->controller->getImage()->isLoaded())
			std::cout << "Impossible de trouver l'image." << std::endl;
	} while (!this->controller->getImage()->isLoaded());
	this->controller->setScreen(1);
}
