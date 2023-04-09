#ifndef _BEVERAGE_H
#define _BEVERAGE_H

#pragma once
#include <string>

class Beverage {
public:
	explicit Beverage(const std::string& description = "Unknown Beverage") { description_ = description; }
	virtual ~Beverage() = default;
	
	virtual double cost() const = 0;
	virtual std::string getDescription() const { return description_; };
	virtual void setDescription(const std::string& description) { description_ = description; }
private:
	std::string description_;
};



#endif // !_BEVERAGE_H