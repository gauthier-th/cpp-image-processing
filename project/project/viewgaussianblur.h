#include "view.h"
#include "controller.h";

class ViewGaussianBlur : public View
{
private:
	// application controller
	Controller& controller;
public:
	/**
	 * Constructor
	 */
	ViewGaussianBlur(const std::string& _title, Controller& _controller);

	/**
	 * Notification function of the view
	 */
	virtual void notify();

	/**
	 * Displays the view
	 */
	virtual void display();
};

