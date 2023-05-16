
#include "RemoteControl.h"

/*
* Remote with UNDO
*/

RemoteControlWithUndo::RemoteControlWithUndo()
{
	for (auto i = 0; i != size_; ++i) {
		onCommands[i] = noCommand;
		offCommands[i] = noCommand;
	}

	undoCommand = noCommand;
}

void RemoteControlWithUndo::setCommand(int slot, Command* onCommand, Command* offCommand)
{
	onCommands[slot] = onCommand;
	offCommands[slot] = offCommand;
}

void RemoteControlWithUndo::onButtonWasPushed(int slot)
{
	onCommands[slot]->execute();
	undoCommand = onCommands[slot];
}

void RemoteControlWithUndo::offButtonWasPushed(int slot)
{
	offCommands[slot]->execute();
	undoCommand = offCommands[slot];
}

