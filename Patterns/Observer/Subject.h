#ifndef _SUBJECT_H
#define _SUBJECT_H

#pragma once
#include "ISubject.h"
#include <list>

/**  */
class Subject : public ISubject {
public:
	~Subject() override {
		std::cout << "Bye, I was Subject\n";
	}

	void Attach(IObserver* observer) override {
		list_observer_.push_back(observer);
	}

	void Detach(IObserver* observer) override {
		list_observer_.remove(observer);
	}
	
	void Notify() override {
		for (auto it = list_observer_.begin(); it != list_observer_.end(); ++it) {
			(*it)->Update(message_);
		}
	}

	void SetMessage(const std::string& s = "Empty") {
		message_ = s;
		Notify();
	}


private:
	std::list<IObserver*> list_observer_;
	std::string message_;
};
#endif // !_SUBJECT_H