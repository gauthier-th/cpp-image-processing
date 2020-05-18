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
	if (this->controller->getCurrentScreen() == 1)
		this->display();
}

void ViewMenu::display()
{
	std::string command = "TITLE ";
	std::string titleCommand = command + this->getTitle();
	system(titleCommand.c_str());
	int choice = 0;
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
		std::string input;
		std::cin >> input;
		try {
			choice = std::stoi(input);
		}
		catch (std::exception e) {
			choice = 0;
		}

	}
	this->controller->setScreen(choice + 1);
}