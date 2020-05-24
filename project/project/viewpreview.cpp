#include "viewpreview.h"
#include <iostream>
#include <string>

/**
 * Constructor
 * @param _controller: Application controller
 */
ViewPreview::ViewPreview(const std::string& _title, Controller& _controller)
    : View(_title), controller(_controller)
{
    this->controller.addObserver(this);
}

/**
 * Notification function of the view
 */
void ViewPreview::notify()
{
    if (this->controller.getCurrentScreen() == 10)
        this->display();
}

/**
 * Displays the view
 */
void ViewPreview::display()
{
    std::cout << std::endl << "Apercu de l'image" << std::endl << "Fermez la fenetre pour continuer..." << std::endl;
    this->controller.getImage()->display("Apercu de l'image");
    this->controller.setScreen(1);
}
