#include "Ducks.h"
#include "Goose.h"
#include "Quackable.h"
#include "QuackCounter.h"
#include "DuckFactory.h"
#include "Flock.h"
#include "Quackologist.h"
#include <memory>

// Simulate ducks behaviour taking different factories
void simulate(AbstractDuckFactory* duckFactory);
// Simulate any Quackable behaviour
void simulate(Quackable* quackable);

//int main(void)
//{
//	// Factory with counter ducks
//	std::unique_ptr<AbstractDuckFactory> factory(std::make_unique<CountingDuckFactory>());
//	
//	simulate(factory.get());
//	
//	return 0;
//}

void simulate(AbstractDuckFactory* duckFactory) {
	
	// observer
	Quackologist quackologist;

	// observable flock
	Flock flockOfDucks;

	// creating counter ducks with factory
	std::shared_ptr<Quackable> mallardDuckCounter(duckFactory->createMallardDuck());
	std::shared_ptr<Quackable> redheadDuckCounter(duckFactory->createRedheadDuck());
	std::shared_ptr<Quackable> duckCallCounter(duckFactory->createDuckCall());
	std::shared_ptr<Quackable> rubberDuckCounter(duckFactory->createRubberDuck());

	// note that goose is not a duck but thanks to adapter it's possible
	std::shared_ptr<Quackable> gooseDuckCounter(std::make_shared<GooseAdapter>(std::make_shared<Goose>()));
		
	std::cout << "Duck Simulator: With Goose Adapter" << std::endl;

	// filling flock
	flockOfDucks.add(mallardDuckCounter);
    flockOfDucks.add(redheadDuckCounter);
	flockOfDucks.add(duckCallCounter);
	flockOfDucks.add(rubberDuckCounter);
	flockOfDucks.add(gooseDuckCounter);

	// register observer for all ducks and simulate behaviour
	flockOfDucks.registerObserver(&quackologist);
	simulate(&flockOfDucks);

	// shows number of quacks.
	std::cout << "The ducks quacked: " << QuackCounter::getQuacks() << " times" << std::endl;
}

void simulate(Quackable* quackable)
{
	quackable->quack();
}