#pragma once
#include "view.h"
#include "controller.h"

class ViewMenu : public View
{
private:
	Controller* controller;
public:
	ViewMenu(const std::string& _title, Controller* _controller);
	void notify();
	void display();
};