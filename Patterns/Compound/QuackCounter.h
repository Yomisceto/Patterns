#pragma once
#include "Quackable.h"
#include <memory> 

/** Duck decorator
    that wraps it to an object that can also count total number of quacks made. */
class QuackCounter : public Quackable {
public:
	explicit QuackCounter(std::shared_ptr<Quackable> duck) : duck(duck) { }
	QuackCounter(QuackCounter&&) = delete;
	QuackCounter(const QuackCounter&) = delete;

	void quack() override { duck->quack(); ++numberOfQuacks; }

	/** Observer methods */ 
	void notifyObservers() override { duck->notifyObservers(); }
	void registerObserver(Observer* observer) override { duck->registerObserver(observer); }

	static int getQuacks() { return numberOfQuacks; }
private:
	/** Wraps a quackable duck. */
	std::shared_ptr<Quackable> duck;

	/** Saves total number of all ducks quacked. */
	static int numberOfQuacks;
};

int QuackCounter::numberOfQuacks = 0;