#pragma once
#include "Remotes.h"

/**
* Default Commands
*/
class Command {
public:
	virtual ~Command() = default;
	virtual void execute() = 0;
	virtual void undo() = 0;
};

class NoCommand : public Command {
public:
	explicit NoCommand() = default;
	void execute() override { std::cout << "No Command Binded" << std::endl; }
	void undo() override { std::cout << "No Undo Binded" << std::endl; }
};


/**
* Macro Commands
*/
class MacroCommand : public Command
{
public:
	MacroCommand(Command* commands[], unsigned amount) : commands_(commands), size(amount) {}
	
	void execute() override
	{
		for (unsigned i = 0; i < size; ++i)
		{
			commands_[i]->execute();
		}
	}
	void undo() override
	{
		for (unsigned i = 0; i < size; ++i)
		{
			commands_[i]->undo();
		}
	}
private:
	Command** commands_;
	unsigned size;
};


/**
* Light Commands
*/
class LightOnCommand : public Command {
public:
	explicit LightOnCommand(Light* light) : light_(light) {}
	void execute() override {
		light_->on();
	}
	void undo() override {
		light_->off();
	}
private:
	Light* light_;
};

class LightOffCommand : public Command {
public:
	explicit LightOffCommand(Light* light) : light_(light) {}
	void execute() override {
		light_->off();
	}
	void undo() override {
		light_->on();
	}
private:
	Light* light_;
};

/**
* Stereo Commands
*/
class StereoOnWithCDCommand : public Command {
public:
	explicit StereoOnWithCDCommand(Stereo* stereo) : stereo_(stereo) {}
	void execute() override {
		stereo_->on();
		stereo_->setCD();
		stereo_->setVolume(10);
	}
	void undo() override {
		stereo_->off();
	}
private:
	Stereo* stereo_;
};

class StereoOffCommand : public Command {
public:
	explicit StereoOffCommand(Stereo* stereo) : stereo_(stereo) {}
	void execute() override {
		stereo_->off();
	}
	void undo() override {
		stereo_->on();
	}
private:
	Stereo* stereo_;
};

/**
* Ceiling Fan Commands
*/
class CeilingFanHighCommand : public Command
{
public:
	CeilingFanHighCommand(CeilingFan* ceilingFan) : ceilingFan_(ceilingFan), prevSpeed(-1) {};

	void execute() override
	{
		prevSpeed = ceilingFan_->getSpeed();
		ceilingFan_->high();
	}

	void undo() override
	{
		switch (prevSpeed)
		{
		case ceilingFan_->HIGH: ceilingFan_->high(); break;
		case ceilingFan_->MEDIUM: ceilingFan_->medium(); break;
		case ceilingFan_->LOW: ceilingFan_->low(); break;
		case ceilingFan_->OFF: ceilingFan_->off(); break;
		default: break;
		}
	}

private:
	CeilingFan* ceilingFan_;
	int prevSpeed;

};

class CeilingFanMediumCommand : public Command
{
public:
	CeilingFanMediumCommand(CeilingFan* ceilingFan) : ceilingFan_(ceilingFan), prevSpeed(-1) {};

	void execute() override
	{
		prevSpeed = ceilingFan_->getSpeed();
		ceilingFan_->medium();
	}

	void undo() override
	{
		switch (prevSpeed)
		{
		case ceilingFan_->HIGH: ceilingFan_->high(); break;
		case ceilingFan_->MEDIUM: ceilingFan_->medium(); break;
		case ceilingFan_->LOW: ceilingFan_->low(); break;
		case ceilingFan_->OFF: ceilingFan_->off(); break;
		default: break;
		}
	}

private:
	CeilingFan* ceilingFan_;
	int prevSpeed;

};

class CeilingFanLowCommand : public Command
{
public:
	CeilingFanLowCommand(CeilingFan* ceilingFan) : ceilingFan_(ceilingFan), prevSpeed(-1) {};

	void execute() override
	{
		prevSpeed = ceilingFan_->getSpeed();
		ceilingFan_->low();
	}

	void undo() override
	{
		switch (prevSpeed)
		{
		case ceilingFan_->HIGH: ceilingFan_->high(); break;
		case ceilingFan_->MEDIUM: ceilingFan_->medium(); break;
		case ceilingFan_->LOW: ceilingFan_->low(); break;
		case ceilingFan_->OFF: ceilingFan_->off(); break;
		default: break;
		}
	}

private:
	CeilingFan* ceilingFan_;
	int prevSpeed;

};

class CeilingFanOffCommand : public Command
{
public:
	CeilingFanOffCommand(CeilingFan* ceilingFan) : ceilingFan_(ceilingFan), prevSpeed(-1) {};

	void execute() override
	{
		prevSpeed = ceilingFan_->getSpeed();
		ceilingFan_->off();
	}

	void undo() override
	{
		switch (prevSpeed)
		{
		case ceilingFan_->HIGH: ceilingFan_->high(); break;
		case ceilingFan_->MEDIUM: ceilingFan_->medium(); break;
		case ceilingFan_->LOW: ceilingFan_->low(); break;
		case ceilingFan_->OFF: ceilingFan_->off(); break;
		default: break;
		}
	}

private:
	CeilingFan* ceilingFan_;
	int prevSpeed;

};