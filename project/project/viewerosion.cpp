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
    std::cout << std::endl;
    std::cout << "Types d'erosions :" << std::endl;
    std::cout << "    1. rectangulaire" << std::endl;
    std::cout << "    2. en croix" << std::endl;
    std::cout << "    3. circulaire" << std::endl;
    std::cout << std::endl << "Merci d'indiquer le type d'erosions (1, 2 ou 3) :" << std::endl;
    int c1;
    std::cin >> c1;
    int erosion_type;
    if (c1 == 2)
        erosion_type = cv::MORPH_CROSS;
    else if (c1 == 3)
        erosion_type = cv::MORPH_ELLIPSE;
    else
        erosion_type = cv::MORPH_RECT;

    std::cout << "Merci d'indiquer un entier qui definira l'intensite de l'erosions :" << std::endl;
    int erosion_size;
    std::cin >> erosion_size;

    std::cout << std::endl << "Application du filtre en cours..." << std::endl;
    this->controller.getImage()->setDilation(erosion_type, erosion_size);
    this->controller.setScreen(1);
}
