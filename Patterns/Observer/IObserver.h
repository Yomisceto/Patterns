#pragma once
#include <iostream>
#include <string>

/** Subscriber */
class IObserver {
public:
	virtual ~IObserver() = default;
	/** Universal Update */
	virtual void Update() = 0;
};