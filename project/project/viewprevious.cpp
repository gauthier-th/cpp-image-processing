#include "viewprevious.h"
#include <iostream>
#include <string>

/**
 * Constructor
 * @param _controller: Application controller
 */
ViewPrevious::ViewPrevious(const std::string& _title, Controller& _controller)
    : View(_title), controller(_controller)
{
    this->controller.addObserver(this);
}

/**
 * Notification function of the view
 */
void ViewPrevious::notify()
{
    if (this->controller.getCurrentScreen() == 11)
        this->display();
}

/**
 * Displays the view
 */
void ViewPrevious::display()
{
    this->controller.getImage()->previous();
    this->controller.setScreen(1);
}
