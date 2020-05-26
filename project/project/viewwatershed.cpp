#include "viewwatershed.h"
#include <iostream>
#include <string>

/**
 * Constructor
 * @param _controller: Application controller
 */
ViewWatershed::ViewWatershed(const std::string& _title, Controller& _controller)
    : View(_title), controller(_controller)
{
    this->controller.addObserver(this);
}

/**
 * Notification function of the view
 */
void ViewWatershed::notify()
{
    if (this->controller.getCurrentScreen() == 9)
        this->display();
}

/**
 * Displays the view
 */
void ViewWatershed::display()
{
    std::cout << std::endl << "Voulez-vous appliquer des couleurs aléatoires aux segments ? (oui/non)" << std::endl;
    std::string input;
    std::cin >> input;
    std::cout << std::endl << "Application du filtre en cours..." << std::endl;
    this->controller.getImage()->setWatershed(input == "oui");
    this->controller.setScreen(1);
}
