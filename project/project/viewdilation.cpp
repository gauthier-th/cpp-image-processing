#include "viewdilation.h"
#include <iostream>
#include <string>

/**
 * Constructor
 * @param _controller: Application controller
 */
ViewDilation::ViewDilation(const std::string& _title, Controller& _controller)
    : View(_title), controller(_controller)
{
    this->controller.addObserver(this);
}

/**
 * Notification function of the view
 */
void ViewDilation::notify()
{
    if (this->controller.getCurrentScreen() == 5)
        this->display();
}

/**
 * Displays the view
 */
void ViewDilation::display()
{
    std::cout << std::endl;
    std::cout << "Types de dilatations :" << std::endl;
    std::cout << "    1. Rectangulaire" << std::endl;
    std::cout << "    2. En croix" << std::endl;
    std::cout << "    3. Circulaire" << std::endl;
    std::cout << std::endl << "Merci d'indiquer le type de dilatation (1, 2 ou 3) :" << std::endl;
    int c1;
    std::cin >> c1;
    int dilation_type;
    if (c1 == 2)
        dilation_type = cv::MORPH_CROSS;
    else if (c1 == 3)
        dilation_type = cv::MORPH_ELLIPSE;
    else
        dilation_type = cv::MORPH_RECT;

    std::cout << "Merci d'indiquer un entier qui definira l'intensite de la dilatation :" << std::endl;
    int dilation_size;
    std::cin >> dilation_size;

    std::cout << std::endl << "Application du filtre en cours..." << std::endl;
    this->controller.getImage()->setDilation(dilation_type, dilation_size);
    this->controller.setScreen(1);
}
