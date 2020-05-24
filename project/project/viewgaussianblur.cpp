#include "viewgaussianblur.h"
#include <iostream>
#include <string>

/**
 * Constructor
 * @param _controller: Application controller
 */
ViewGaussianBlur::ViewGaussianBlur(const std::string& _title, Controller& _controller)
    : View(_title), controller(_controller)
{
    this->controller.addObserver(this);
}

/**
 * Notification function of the view
 */
void ViewGaussianBlur::notify()
{
    if (this->controller.getCurrentScreen() == 3)
        this->display();
}

/**
 * Displays the view
 */
void ViewGaussianBlur::display()
{
    std::cout << std::endl << "Merci d'indiquer un entier qui definira l'intensite du filtrage :" << std::endl;
    int c1;
    std::cin >> c1;
    std::cout << std::endl << "Application du filtre en cours..." << std::endl;
    this->controller.getImage()->setGaussian(c1);
    this->controller.setScreen(1);
}
