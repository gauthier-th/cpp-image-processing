#pragma once
#include <vector>
#include "observer.h"

class Subject
{
private:
	//Collection of observers
	std::vector<Observer*> observers;
public:
	/**
	 * Constructor
	 */
	Subject();

	/**
	 * Adds an observer to the collection
	 * @param observer: Observer to add
	 */
	void addObserver(Observer* observer);

	/**
	 * Notifies all the observers of the subject
	 */
	void notify();
};

