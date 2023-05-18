#pragma once
#include "Turkey.h"
#include "Duck.h"

/** Object adapter - uses composition */
class TurkeyAdapter : public ADuck {
public:
	explicit TurkeyAdapter(std::shared_ptr<ATurkey> turkey) : turkey(turkey) {}

	void quack() const override { turkey->gobble(); }
	
	/** Turkey makes short fly, so it's need to call it more times */
	void fly() const override { for (auto i = 0; i < 5; ++i) { turkey->fly(); } }

private:
	std::shared_ptr<ATurkey> turkey;
};

/** Class adapter - uses inheritance */
class ClassTurkeyAdapter : public ADuck, public AWildTurkey
{
public:
	void quack() const override { gobble();}
	void fly() const override { for (auto i = 0; i < 5; ++i) { AWildTurkey::fly(); } }
};