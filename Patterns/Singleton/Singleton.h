#ifndef _SINGLETON_H
#define _SINGLETON_H

#pragma once
#include <string>
#include <iostream>

/** Only one instance of object is possible.
	Constructor is protected, so user can't create object manually. */
class Singleton {
public:
	/** User can create object only by a static fucntion. */
	static Singleton* GetInstance(const std::string& value);

	/** Singleton should not have copy/assign */
	Singleton(Singleton& single) = delete;
	Singleton& operator=(Singleton& rhs) = delete;


	void BusinessLogic() const { std::cout << "Doing bussines logic" << std::endl; }

	std::string value() const { return value_; }

protected:
	explicit Singleton(const std::string& value) : value_(value) {}

private:
	/** Save pointer to that one instance. Memory can be not managed for now, as it's static member. */
	static Singleton* singleton_;
	/** Wrapped value by singleton. */
	std::string value_;
};

Singleton* Singleton::singleton_ = nullptr;

/** returns current instance if its already was created. */
Singleton* Singleton::GetInstance(const std::string& value) {
	if (singleton_ == nullptr) {
		singleton_ = new Singleton(value);
	}
	return singleton_;
}

#endif // _SINGLETON_H