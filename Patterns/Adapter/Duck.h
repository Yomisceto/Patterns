#pragma once
#include <iostream>

/** Simple duck class. */
class ADuck {
public:
	virtual ~ADuck() = default;

	virtual void quack() const = 0;
	virtual void fly() const = 0;
};

class AMallardDuck : public ADuck {
public:
	void quack() const override { std::cout << "A Quack" << std::endl; }
	void fly() const override { std::cout << "A Fly - 500m" << std::endl; }
};

