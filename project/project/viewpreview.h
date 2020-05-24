#pragma once
#include "view.h"
#include "controller.h";

class ViewPreview : public View
{
private:
	// application controller
	Controller& controller;
public:
	/**
	 * Constructor
	 */
	ViewPreview(const std::string& _title, Controller& _controller);

	/**
	 * Notification function of the view
	 */
	virtual void notify();

	/**
	 * Displays the view
	 */
	virtual void display();
};

