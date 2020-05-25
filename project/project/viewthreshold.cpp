#include "viewthreshold.h"
#include <iostream>
#include <string>

/**
 * Constructor
 * @param _controller: Application controller
 */
ViewThreshold::ViewThreshold(const std::string& _title, Controller& _controller)
    : View(_title), controller(_controller)
{
    this->controller.addObserver(this);
}

/**
 * Notification function of the view
 */
void ViewThreshold::notify()
{
    if (this->controller.getCurrentScreen() == 8)
        this->display();
}

/**
 * Displays the view
 */
void ViewThreshold::display()
{
    /* 0: Binary
       1: Binary Inverted
       2: Threshold Truncated
       3: Threshold to Zero
       4: Threshold to Zero Inverted */
    std::cout << std::endl;
    std::cout << "Types de seuillage :" << std::endl;
    std::cout << "    1. Binaire" << std::endl;
    std::cout << "    2. Binaire inverse" << std::endl;
    std::cout << "    3. Seuil tronque" << std::endl;
    std::cout << "    4. Seuil a zero" << std::endl;
    std::cout << "    5. Seuil a zero inverse" << std::endl;
    std::cout << std::endl << "Merci d'indiquer le type de seuillage (1, 2, 3, 4 ou 5) :" << std::endl;
    int threshold_type;
    std::cin >> threshold_type;

    std::cout << "Merci d'indiquer un entier qui definira l'intensite du traitement :" << std::endl;
    int threshold_value;
    std::cin >> threshold_value;
    if (threshold_value % 2 == 0)
        threshold_value++;

    std::cout << std::endl << "Application du filtre en cours..." << std::endl;
    this->controller.getImage()->setThreshold(threshold_type - 1, threshold_value);
    this->controller.setScreen(1);
}
