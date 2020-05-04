#include "view.h"
#include <cstdlib>
#include <iostream>

/**
 * Constructor
 * @param _title: Title of the view
 */
View::View(const std::string& _title)
	:title(_title)
{

}

/**
 * Clears console
 */
void View::clear() const
{
	system("CLS");
}

/**
 * Displays the view
 */
void View::display() const
{
	std::cout << title << std::endl << std::endl;
}

std::string View::getTitle() {
    return title;
}