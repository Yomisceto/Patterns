#pragma once
#include <iostream>

class Subject {
public:
	virtual void Request() const = 0;

	virtual ~Subject() = default;
};

// Example
class RealSubject : public Subject {
public:
	void Request() const override { std::cout << "Real Subject handling" << std::endl; }
};

class Proxy : public Subject {
private:
	RealSubject* real_subject_;

	bool CheckAccess() const {
		// check real access
		std::cout << "Proxy: Checking access" << std::endl;
		return true;
 	}
	void LogAccess() const {
		std::cout << "Proxy: Logging time access" << std::endl;
	}

public:
	Proxy(RealSubject* real_subject) : real_subject_(new RealSubject(*real_subject)) {}
	
	~Proxy() { delete real_subject_; }

	void Request() const override {
		if (this->CheckAccess())
		{
			this->real_subject_->Request();
			this->LogAccess();
		}
	}
};
