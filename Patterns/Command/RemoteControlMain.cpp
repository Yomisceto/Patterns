
#include "RemoteControl.h"
#include <array>

void LightOn() {
	auto remote = new SimpleRemoteControl;
	auto light = new Light;
	auto lightOn = new LightOnCommand(light);

	remote->setCommand(lightOn);
	remote->buttonPressed();

	delete remote;
	delete light;
	delete lightOn;
}

/** Command pattern test 
  A remote controll with two buttons on and off and 6 slots
  Using Commands objects to execute commands of remote objects */	
void RemoteLoader() {

	// Controller
	RemoteControl remoteControl;
	
	// Remotes 
	Light livingRoomLight("Living Room Light");
	Light kitchenLight("Kitchen Light");
	Stereo stereo("Living Room Stereo");

	// Commands 
	LightOnCommand livingRoomLightOn(&livingRoomLight);
	LightOffCommand livingRoomLightOff(&livingRoomLight);
	LightOnCommand kitchenLightOn(&kitchenLight);
	LightOffCommand kitchenLightOff(&kitchenLight);
	StereoOnWithCDCommand stereoOn(&stereo);
	StereoOffCommand stereoOff(&stereo);

	// Bind commands
	remoteControl.setCommand(0, &livingRoomLightOn, &livingRoomLightOff );
	remoteControl.setCommand(1, &kitchenLightOn, &kitchenLightOff);
	remoteControl.setCommand(2, &stereoOn, &stereoOff);

	// Execute commands
	remoteControl.onButtonPushed(0);
	remoteControl.offButtonPushed(0);
	remoteControl.onButtonPushed(1);
	remoteControl.offButtonPushed(1);
	remoteControl.onButtonPushed(2);
	remoteControl.offButtonPushed(2);

}
void RemoteLoaderWithUndo()
{
	// Controller
	RemoteControlWithUndo remoteControl;

	// Remote
	Light livingRoomLight("Living Room");

	// Commands
	LightOnCommand livingRoomLightOn(&livingRoomLight);
	LightOffCommand livingRoomLightOff(&livingRoomLight);

	// Bind command
	remoteControl.setCommand(0, &livingRoomLightOn, &livingRoomLightOff);

	// Execute commands
	remoteControl.onButtonWasPushed(0);
	remoteControl.offButtonWasPushed(0);
	remoteControl.undoButtonWasPushed();
}
void RemoteLoaderFan()
{
	// Controller
	RemoteControlWithUndo remoteControl;

	// Remote
	CeilingFan ceilingFan("Living Room");

	// Commands
	CeilingFanMediumCommand ceilingFanMedium(&ceilingFan);
	CeilingFanHighCommand ceilingFanHigh(&ceilingFan);
	CeilingFanOffCommand ceilingFanOff(&ceilingFan);

	// Bind commands
	remoteControl.setCommand(0, &ceilingFanMedium, &ceilingFanOff);
	remoteControl.setCommand(1, &ceilingFanHigh, &ceilingFanOff);

	// Execute commands
	remoteControl.onButtonWasPushed(0);
	remoteControl.offButtonWasPushed(0);
	remoteControl.undoButtonWasPushed(); 
	remoteControl.onButtonWasPushed(1);
	remoteControl.undoButtonWasPushed();
}
void RemoteLoaderMacro()
{
	// Remotes
	Light light("Living Room Light");
	Stereo stereo("Living Room Stereo");

	// Controller
	RemoteControlWithUndo remoteControl;

	// Commands
	LightOnCommand lightOn(&light);
	LightOffCommand lightOff(&light);
	StereoOnWithCDCommand stereoOn(& stereo);
	StereoOffCommand stereoOff(&stereo);

	// Macro Commands
	Command* partyOn[] { &lightOn, &stereoOn };
	Command* partyOff[] { &lightOff, &stereoOff };
	MacroCommand partyOnMacro(partyOn, 2);
	MacroCommand partyOffMacro(partyOff, 2);
	
	// Bind Macro Command
	remoteControl.setCommand(0, &partyOnMacro, &partyOffMacro);

	// Execute commands
	remoteControl.onButtonWasPushed(0);
	remoteControl.offButtonWasPushed(0);

	// Stereo should save data to undo correctly
	remoteControl.undoButtonWasPushed();
}

//int main() {
//	RemoteLoaderMacro();
//	RemoteLoaderFan();
//	RemoteLoaderWithUndo();
//	RemoteLoader();
//
//	return 0;
//}