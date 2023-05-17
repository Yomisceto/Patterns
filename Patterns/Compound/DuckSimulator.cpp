#include "Ducks.h"
#include "Goose.h"
#include "Quackable.h"
#include "QuackCounter.h"
#include "DuckFactory.h"
#include "Flock.h"
#include "Quackologist.h"
#include <memory>

void simulate(AbstractDuckFactory* duckFactory);
void simulate(Quackable* quackable);

int main(void)
{
	AbstractDuckFactory* factory = new CountingDuckFactory();
	simulate(factory);
	delete factory;
	return 0;
}

void simulate(AbstractDuckFactory* duckFactory) {
	
	Quackable* mallardDuckCounter = duckFactory->createMallardDuck();
	Quackable* redheadDuckCounter = duckFactory->createRedheadDuck();
	Quackable* duckCallCounter	  = duckFactory->createDuckCall();
	Quackable* rubberDuckCounter  = duckFactory->createRubberDuck();

	Goose goose;
	GooseAdapter gooseAdapter(&goose);
	Quackable* gooseDuckCounter = new QuackCounter(&gooseAdapter);

	std::cout << "Duck Simulator: With Goose Adapter" << std::endl;

	Flock flockOfDucks;
	//flockOfDucks.add(mallardDuckCounter);
	//flockOfDucks.add(redheadDuckCounter);
	//flockOfDucks.add(duckCallCounter);
	//flockOfDucks.add(rubberDuckCounter);
	flockOfDucks.add(gooseDuckCounter);

	Quackologist quackologist;
	flockOfDucks.registerObserver(&quackologist);

	simulate(&flockOfDucks);

	std::cout << "The ducks quacked " << QuackCounter::getQuacks() << " times" << std::endl;

	delete mallardDuckCounter;
	delete redheadDuckCounter;
	delete duckCallCounter;
	delete rubberDuckCounter;
	delete gooseDuckCounter;
}
void simulate(Quackable* quackable)
{
	quackable->quack();
}