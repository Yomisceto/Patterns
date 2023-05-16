#pragma once
#include "Command.h"
#include <vector>

class SimpleRemoteControl {
public:
	SimpleRemoteControl() = default;

	void setCommand(Command* command) { slot_ = command; }
	void buttonPressed() { slot_->execute(); }
private:
	Command* slot_;
};

/** remote control with six slots */
class RemoteControl {
public:
	RemoteControl() 
	{
		for (auto i = 0; i != size_; ++i) {
			onCommands[i] = noCommand;
			offCommands[i] = noCommand;
		}
	}
	void setCommand(int slot, Command* onCommand, Command* offCommand) {
		onCommands[slot] = onCommand;
		offCommands[slot] = offCommand;
	}

	void onButtonPushed(int slot) const {
		onCommands[slot]->execute();
	}

	void offButtonPushed(int slot) const {
		offCommands[slot]->execute();
	}

	std::ostream& Print(std::ostream& os) {
		os << "\n----- Remote Control -----\n";
		for (int i = 0; i < size_; ++i) {
			os << "[slot " << i << "] " << typeid(onCommands[i]).name() 
				<< " " << typeid(offCommands[i]).name() << std::endl;
		}
		return os;
	}

	~RemoteControl() { delete noCommand; }
private:
	/** Hardcoded six slots */
	int size_ = 6;
	Command* noCommand = new NoCommand();
	Command* onCommands[6];
	Command* offCommands[6];
	//std::vector<Command*> onCommands;
	//std::vector<Command*> offCommands;
};

class RemoteControlWithUndo
{
public:
	RemoteControlWithUndo();
	~RemoteControlWithUndo() { delete noCommand; }

	void setCommand(int slot, Command* onCommand, Command* offCommand);
	void onButtonWasPushed(int slot);
	void offButtonWasPushed(int slot);

	inline void undoButtonWasPushed() { undoCommand->undo(); }


private:
	//
	int size_ = 5;
	Command* onCommands[5];
	Command* offCommands[5];

	Command* noCommand = new NoCommand();
	
	Command* undoCommand;

};
