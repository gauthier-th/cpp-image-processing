#include <string>
#include <iostream>
#include "viewmenu.h"

ViewMenu::ViewMenu(const std::string& _title, Controller* _controller): View(_title)
{
	this->controller = _controller;
	this->controller->addObserver(this);
}

void ViewMenu::notify()
{
	if (this->controller->getCurrentScreen() == 0)
		this->display();
}

void ViewMenu::display()
{
	std::string command = "TITLE ";
	std::string titleCommand = command + this->getTitle();
	system(titleCommand.c_str());
	int choice = 0;
	std::string name;
	Image* img = new Image();
	bool imageLoaded = false;
	this->clear();
	do {
		std::cout << "Entrez le chemin de l'image :" << std::endl;
		std::cin >> name;
		img->setName(name);
		imageLoaded = img->loadImage();
		this->clear();
		if (!imageLoaded)
			std::cout << "Impossible de trouver l'image." << std::endl;
	} while (!imageLoaded);
	choice = 0;
	while (choice != 9) {
		this->clear();
		std::cout << "\t\tMenu" << std::endl << std::endl;
		std::cout << "1. Filtre Median" << std::endl;
		std::cout << "2. Filtre Gausien" << std::endl << std::endl;
		std::cout << "3. Calcul du gradient dans une image" << std::endl << std::endl;
		std::cout << "4. Dilatation" << std::endl;
		std::cout << "5. Erosion" << std::endl << std::endl;
		std::cout << "6. Application d'un detecteur de contours" << std::endl << std::endl;
		std::cout << "7. Operations de seuillages" << std::endl;
		std::cout << "8. Segmentation par croissance de region" << std::endl << std::endl;
		std::cout << "9. Quitter" << std::endl;
		std::cin >> choice;
	}
	this->controller->setScreen(choice);
}