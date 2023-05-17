#pragma once
#include <vector>

// forward declare
class Observer;

/** Observable ducks interface. */
class QuackObservable {
public:
	virtual ~QuackObservable() = default;

	virtual void registerObserver(Observer* observer) = 0;
	virtual void notifyObservers() = 0;
};

/** Implementation of quack observable. */
class Observable : public QuackObservable {
public:
	explicit Observable(QuackObservable* duck) : duck(duck) {}

	void registerObserver(Observer* observer) override { observers.push_back(observer); }
	void notifyObservers() override;
private:
	/** Duck that is being observed. */
	QuackObservable* duck;
	/** Collection of observers that watch. */
	std::vector<Observer*> observers;
};

/** Observer interface. */
class Observer {
public:
	virtual ~Observer() = default;

	virtual void update(QuackObservable* duck) = 0;
};