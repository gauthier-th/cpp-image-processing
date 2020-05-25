#include "viewsave.h"
#include <iostream>
#include <string>

/**
 * Constructor
 * @param _controller: Application controller
 */
ViewSave::ViewSave(const std::string& _title, Controller& _controller)
    : View(_title), controller(_controller)
{
    this->controller.addObserver(this);
}

/**
 * Notification function of the view
 */
void ViewSave::notify()
{
    if (this->controller.getCurrentScreen() == 12)
        this->display();
}

/**
 * Displays the view
 */
void ViewSave::display()
{
    std::cout << std::endl << "Entrez le chemin ou vous souhaitez sauvegarder l'image :" << std::endl;
    std::string path;
    std::cin >> path;
    try {
        this->controller.getImage()->save(path);
    }
    catch (std::exception e) {}
    this->controller.setScreen(1);
}
