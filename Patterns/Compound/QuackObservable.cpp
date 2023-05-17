#include "QuackObservable.h"

void Observable::notifyObservers()
{
	for (auto observer : observers) {
		observer->update(duck);
	}
}
