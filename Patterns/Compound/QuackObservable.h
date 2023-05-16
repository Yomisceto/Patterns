#pragma once
#include <vector>

class Observer;

class QuackObservable {
public:
	virtual ~QuackObservable() = default;

	virtual void registerObserver(Observer* observer) = 0;
	virtual void notifyObservers() = 0;
};

class Observable : public QuackObservable {
public:
	explicit Observable(QuackObservable* duck) : duck(duck) {}

	void registerObserver(Observer* observer) override { observers.push_back(observer); }
	void notifyObservers() override;
private:
	QuackObservable* duck;
	std::vector<Observer*> observers;
};

class Observer {
public:
	virtual ~Observer() = default;

	virtual void update(QuackObservable* duck) = 0;
};