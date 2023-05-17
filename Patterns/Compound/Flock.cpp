#include "Flock.h"

using std::shared_ptr;

void Flock::quack()
{
	for (const shared_ptr<Quackable>& quacker : quackers) {
		quacker->quack();
	}
}

void Flock::registerObserver(Observer* observer)
{
	for (auto it_quacker = quackers.begin(); it_quacker != quackers.end(); ++it_quacker) {
		it_quacker->get()->registerObserver(observer);
	}
}

void Flock::notifyObservers()
{
	// Each Quackable does its own notification, so Flock doesn’t have to worry about it.
}