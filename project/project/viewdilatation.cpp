#include "viewdilatation.h"
#include <iostream>
#include <string>

/**
 * Constructor
 * @param _controller: Application controller
 */
ViewDilatation::ViewDilatation(const std::string& _title, Controller& _controller)
    : View(_title), controller(_controller)
{
    this->controller.addObserver(this);
}

/**
 * Notification function of the view
 */
void ViewDilatation::notify()
{
    if (this->controller.getCurrentScreen() == 4)
        this->display();
}

/**
 * Displays the view
 */
void ViewDilatation::display()
{
    /** TO DO **/
}
