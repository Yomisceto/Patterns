#ifndef _SINGLETON_H
#define _SINGLETON_H

#pragma once
#include <string>
#include <iostream>

class Singleton {
public:
	/** Singleton should not have copy/assign */
	Singleton(Singleton& single) = delete;
	Singleton& operator=(Singleton& rhs) = delete;

	static Singleton* GetInstance(const std::string& value);
	void BusinessLogic() const { std::cout << "Doing bussines logic" << std::endl; }

	std::string value() const { return value_; }

protected:
	explicit Singleton(const std::string& value) : value_(value) {}

private:
	static Singleton* singleton_;
	
	std::string value_;
};

Singleton* Singleton::singleton_ = nullptr;

Singleton* Singleton::GetInstance(const std::string& value) {
	if (singleton_ == nullptr) {
		singleton_ = new Singleton(value);
	}
	return singleton_;
}

#endif // _SINGLETON_H