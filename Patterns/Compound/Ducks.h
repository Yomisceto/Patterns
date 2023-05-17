#pragma once
#include <iostream>
#include "Quackable.h"
#include "QuackObservable.h"

/** Base of the duck. */
class BaseDuck : public Quackable {
public:
	// Constructor creates empty implementation of QuackObservable
	BaseDuck() : observable(std::make_unique<Observable>(this)) { };

	// Observers
	void registerObserver(Observer* observer) override { observable->registerObserver(observer); }
	void notifyObservers() override { observable->notifyObservers(); }
private:
	/** QuackObservable implementation is delegated to this object. 
	    It can be also just inherited from implementation. */
	std::unique_ptr<Observable> observable;
};

/** Types of Ducks just overload quack method. 
	Notify and output can be united in one object in this simple quack implementation. */
class MallardDuck : public BaseDuck {
public:
	void quack() override { notifyObservers(); std::cout << "Quack" << std::endl; }
};

class RedheadDuck : public BaseDuck {
public:
	void quack() override { notifyObservers(); std::cout << "Quack" << std::endl; }
};

class DuckCall : public BaseDuck {
public:
	void quack() override { notifyObservers(); std::cout << "Kwak" << std::endl; }
};

class RubberDuck : public BaseDuck {
public:
	void quack() override { notifyObservers(); std::cout << "Squeack" << std::endl; }
};