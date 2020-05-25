#include "viewcontours.h"
#include <iostream>
#include <string>

/**
 * Constructor
 * @param _controller: Application controller
 */
ViewContours::ViewContours(const std::string& _title, Controller& _controller)
    : View(_title), controller(_controller)
{
    this->controller.addObserver(this);
}

/**
 * Notification function of the view
 */
void ViewContours::notify()
{
    if (this->controller.getCurrentScreen() == 7)
        this->display();
}

/**
 * Displays the view
 */
void ViewContours::display()
{
    std::cout << std::endl << "Merci d'indiquer un entier qui definira la précision de la détection de contours :" << std::endl;
    int thresh;
    std::cin >> thresh;
    std::cout << std::endl << "Application du filtre en cours..." << std::endl;
    this->controller.getImage()->setContours(thresh);
    this->controller.setScreen(1);
}
