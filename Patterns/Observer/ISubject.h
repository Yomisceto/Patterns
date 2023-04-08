#ifndef _ISUBJECT_H
#define _ISUBJECT_H

#pragma once
#include "IObserver.h"

/** Publisher */
class ISubject {
public:
	virtual ~ISubject() {};
	virtual void Attach(IObserver* observer) = 0;
	virtual void Detach(IObserver* observer) = 0;
	virtual void Notify() = 0;
};
#endif // !_ISUBJECT_H