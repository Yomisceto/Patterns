#ifndef _OBSERVER_H
#define _OBSERVER_H

#pragma once
#include "IObserver.h"
#include "Subject.h"

class Observer : public IObserver {
public:
	explicit Observer(Subject&);

	Observer(const Observer&) = delete;
	Observer& operator=(const Observer&) = delete;

	~Observer() override {
		std::cout << "bye, I was Observer - " << this->number_ << std::endl;
	}
	void RemoveFromList();
	void Print();
	void Update() override; 

private:
	Subject &subject_;
	std::string message_;
	static unsigned index_;
	int number_;
};

unsigned Observer::index_ = 0;

Observer::Observer(Subject& subject) : subject_(subject) {
	this->subject_.Attach(this);
	++index_;
	std::cout << "hi, I'm the Observer - " << index_ << std::endl;
	this->number_ = Observer::index_;
}

void Observer::Update() {
	message_ = subject_.GetMessage();
	Observer::Print();
}

void Observer::RemoveFromList() {
	subject_.Detach(this);
}

void Observer::Print() {
	std::cout << "Observer " << this->number_
		<< " : a new message is --> " << this->message_ << std::endl;
}


#endif // !_OBSERVER_H
