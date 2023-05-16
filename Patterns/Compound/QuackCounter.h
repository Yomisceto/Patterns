#pragma once
#include "Quackable.h"

// Add to ducks decorator 
class QuackCounter : public Quackable {
public:
	explicit QuackCounter(Quackable* duck, bool toClean = false) : duck(duck), clean(toClean) { }

	void quack() override { duck->quack(); ++numberOfQuacks; }

	static int getQuacks() { return numberOfQuacks; }

	~QuackCounter() override { if (clean) delete duck; }\

	// Observer
	void registerObserver(Observer* observer) override { duck->registerObserver(observer); }
	void notifyObservers() override { duck->notifyObservers(); }

private:
	// wraps a quackable duck
	Quackable* duck;
	// saves total number of all ducks quacked
	static int numberOfQuacks;
    //
	bool clean;
};

int QuackCounter::numberOfQuacks = 0;