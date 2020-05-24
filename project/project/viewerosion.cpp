#include "viewerosion.h"
#include <iostream>
#include <string>

/**
 * Constructor
 * @param _controller: Application controller
 */
ViewErosion::ViewErosion(const std::string& _title, Controller& _controller)
    : View(_title), controller(_controller)
{
    this->controller.addObserver(this);
}

/**
 * Notification function of the view
 */
void ViewErosion::notify()
{
    if (this->controller.getCurrentScreen() == 4)
        this->display();
}

/**
 * Displays the view
 */
void ViewErosion::display()
{
    /** TO DO **/
}
