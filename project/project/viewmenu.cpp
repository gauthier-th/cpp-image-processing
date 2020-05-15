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
	int choice1 = 0;
	std::string name;
	Image* img = new Image();
	while (choice != 9 && img->getStatut() == 0)
	{
		this->clear();
		std::cout << "\t\tMenu" << std::endl << std::endl;
		std::cout << "1. Charger une image" << std::endl << std::endl;
		std::cout << "9. Quitter" << std::endl;
		std::cin >> choice;

		if (choice == 1) {
			this->clear();
			std::cout << "Indiquer le nom de l'image avec son extention :" << std::endl << std::endl;
			std::cin >> name;
			img->setName(name);
			img->loadImage();
		}
	}
	while (choice1 != 9 && img->Image::getStatut() == 1) {
		this->clear();
		std::cout << "\t\tMenu" << std::endl << std::endl;
		std::cout << "1. Filtre Médian" << std::endl;
		std::cout << "2. Filtre Gausien" << std::endl << std::endl;
		std::cout << "3. Calcul du gradient dans une image" << std::endl << std::endl;
		std::cout << "4. Dilatation" << std::endl;
		std::cout << "5. Erosion" << std::endl << std::endl;
		std::cout << "6. Application d'un détecteur de contours" << std::endl << std::endl;
		std::cout << "7. Opératioons de seuillages" << std::endl;
		std::cout << "8. Segmentation par croissance de région" << std::endl << std::endl;
		std::cout << "9. Quitter" << std::endl;
		std::cin >> choice1;
	}
	this->controller->setScreen(choice1);
}