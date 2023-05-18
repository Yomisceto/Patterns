#pragma once
#include <iostream>

/** Turkey class simillar to duck, but has different method name. */
class ATurkey {
public:
	virtual ~ATurkey() = default;

	virtual void gobble() const = 0;
	virtual void fly() const = 0;

};

class AWildTurkey : public ATurkey
{
public:
	void gobble() const override { std::cout << "A Gobble" << std::endl; }
	void fly() const override { std::cout << "A Short Fly - 100m" << std::endl; }
};



