#ifndef _IOBSERVER_H
#define _IOBSERVER_H

#pragma once
#include <iostream>
#include <string>

/** Subscriber */
class IObserver {
public:
	virtual ~IObserver() {};
	/** Universal Update */
	virtual void Update() = 0;
};
#endif // !_IOBSERVER_H