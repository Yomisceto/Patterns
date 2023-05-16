#ifndef _LIGHT_H
#define _LIGHT_H

#pragma once
#include <iostream>

class Remotes {
public:
	virtual ~Remotes() = default;
	explicit Remotes(const std::string& name) : name_(name) {}
	virtual void on() const { std::cout << name_ << " is turned On" << std::endl; }
	virtual void off() const { std::cout << name_ << " is turned Off" << std::endl; }
private:
	std::string name_;
};

class Light : public Remotes {
public:
	Light() : Remotes("Light") {}
	using Remotes::Remotes;
};

class Stereo : public Remotes {
public:
	Stereo() : Remotes("Stereo") {}
	using Remotes::Remotes;

	void setVolume(int volume) { std::cout << "set volume to " << volume << std::endl; }
	void setCD() { std::cout << "CD is set" << std::endl; }
};

class CeilingFan
{
public:

	CeilingFan(std::string location)
	{
		this->location = location;
		speed = OFF;
	}

	void high()
	{
		std::cout << "Fan is on high speed" << std::endl;
		speed = HIGH;
	}

	void medium()
	{
		std::cout << "Fan is on medium speed" << std::endl;
		speed = MEDIUM;
	}

	void low()
	{
		std::cout << "Fan is on low speed" << std::endl;
		speed = LOW;
	}

	void off()
	{
		std::cout << "Fan is turned off" << std::endl;
		speed = OFF;
	}

	int getSpeed() const
	{
		return speed;
	}

	static const int HIGH = 3;
	static const int MEDIUM = 2;
	static const int LOW = 1;
	static const int OFF = 0;

private:
	std::string location;
	int speed;


};
#endif // !_LIGHT_H