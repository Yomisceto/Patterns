#include "Flock.h"

void Flock::quack()
{
	for (auto quacker : quackers) {
		quacker->quack();
	}
}

void Flock::registerObserver(Observer* observer)
{
	for (auto quacker : quackers) {
		quacker->registerObserver(observer);
	}
}

void Flock::notifyObservers()
{
	// Each Quackable does its own notification, so Flock doesn’t have to worry about it.
}