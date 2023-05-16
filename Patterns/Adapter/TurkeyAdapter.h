#pragma once
#include "Turkey.h"
using namespace Adapter;

/** Object adapter - uses composition */
class TurkeyAdapter : public ADuck {
public:
	TurkeyAdapter(ATurkey* turkey_) : turkey(turkey_) {}

	void quack() override { turkey->gobble(); }
	
	/** Turkey makes short fly, so it's need to call it more times */
	void fly() override { for (auto i = 0; i < 5; ++i) { turkey->fly(); } }

private:

	ATurkey* turkey;
};

/** Class adapter - uses inheritance */
class ClassTurkeyAdapter : public ADuck, public AWildTurkey
{
public:
	void quack() override { gobble();}
	void fly() override { /***/ AWildTurkey::fly(); }
};