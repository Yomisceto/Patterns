#pragma once
#include <iostream>
#include "QuackObservable.h"
#include "Quackable.h"

class BaseDuck : public Quackable {
public:
	BaseDuck() : observable(new Observable(this)) {};

	~BaseDuck() override { delete observable; }

	
	// Observer
	void registerObserver(Observer* observer) override { observable->registerObserver(observer); }
	void notifyObservers() override { observable->notifyObservers(); }

private:
	Observable* observable;
};

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