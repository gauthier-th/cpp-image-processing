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
	while (choice != 9)
	{
		this->clear();
		std::cout << "Menu" << std::endl << std::endl;
		std::cout << "\t\t9. Quitter" << std::endl;
		std::cin >> choice;
	}
	this->controller->setScreen(choice);
}