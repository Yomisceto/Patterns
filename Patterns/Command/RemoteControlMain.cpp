
#include "RemoteControl.h"

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

	RemoteControl* remoteControl = new RemoteControl;
	
	/** Remotes pointers */
	Light* livingRoomLight = new Light("Living Room Light");
	Light* kitchenLight = new Light("Kitchen Light");
	Stereo* stereo = new Stereo("Living Room Stereo");

	/** Command pointers */
	LightOnCommand* livingRoomLightOn = new LightOnCommand(livingRoomLight);
	LightOffCommand* livingRoomLightOff = new LightOffCommand(livingRoomLight);
	LightOnCommand* kitchenLightOn = new LightOnCommand(kitchenLight);
	LightOffCommand* kitchenLightOff = new LightOffCommand(kitchenLight);
	StereoOnWithCDCommand* stereoOn = new StereoOnWithCDCommand(stereo);
	StereoOffCommand* stereoOff = new StereoOffCommand(stereo);

	remoteControl->setCommand(0, livingRoomLightOn, livingRoomLightOff );
	remoteControl->setCommand(1, kitchenLightOn, kitchenLightOff);
	remoteControl->setCommand(2, stereoOn, stereoOff);

	/** Pushing buttons */
	remoteControl->onButtonPushed(0);
	remoteControl->offButtonPushed(0);
	remoteControl->onButtonPushed(1);
	remoteControl->offButtonPushed(1);
	remoteControl->onButtonPushed(2);
	remoteControl->offButtonPushed(2);

	delete remoteControl;

	delete livingRoomLightOn;
	delete livingRoomLightOff;

	delete kitchenLightOn;
	delete kitchenLightOff;

	delete stereoOn;
	delete stereoOff;

	delete kitchenLight;
	delete stereo;
	delete livingRoomLight;
}
void RemoteLoaderWithUndo()
{
	RemoteControlWithUndo* remoteControl = new RemoteControlWithUndo;
	Light* livingRoomLight = new Light("Living Room");
	LightOnCommand* livingRoomLightOn = new LightOnCommand(livingRoomLight);
	LightOffCommand* livingRoomLightOff = new LightOffCommand(livingRoomLight);

	remoteControl->setCommand(0, livingRoomLightOn, livingRoomLightOff);
	
	remoteControl->onButtonWasPushed(0);
	remoteControl->offButtonWasPushed(0);
	remoteControl->undoButtonWasPushed();

	delete remoteControl;
	delete livingRoomLight;
	delete livingRoomLightOn;
	delete livingRoomLightOff;

}
void RemoteLoaderFan()
{
	RemoteControlWithUndo* remoteControl = new RemoteControlWithUndo;

	CeilingFan* ceilingFan = new CeilingFan("Living Room");

	CeilingFanMediumCommand* ceilingFanMedium = new CeilingFanMediumCommand(ceilingFan);
	CeilingFanHighCommand* ceilingFanHigh = new CeilingFanHighCommand(ceilingFan);
	CeilingFanOffCommand* ceilingFanOff = new CeilingFanOffCommand(ceilingFan);

	remoteControl->setCommand(0, ceilingFanMedium, ceilingFanOff);
	remoteControl->setCommand(1, ceilingFanHigh, ceilingFanOff);

	remoteControl->onButtonWasPushed(0);
	remoteControl->offButtonWasPushed(0);
	remoteControl->undoButtonWasPushed(); 

	remoteControl->onButtonWasPushed(1);
	remoteControl->undoButtonWasPushed(); 

	delete remoteControl;
	delete ceilingFan;
	delete ceilingFanMedium;
	delete ceilingFanHigh;
	delete ceilingFanOff;
}
void RemoteLoaderMacro()
{
	Light* light = new Light("Living Room Light");
	Stereo* stereo = new Stereo("Living Room Stereo");

	LightOnCommand* lightOn = new LightOnCommand(light);
	LightOffCommand* lightOff = new LightOffCommand(light);
	StereoOnWithCDCommand* stereoOn = new StereoOnWithCDCommand(stereo);
	StereoOffCommand* stereoOff = new StereoOffCommand(stereo);

	Command* partyOn[] { lightOn, stereoOn };
	Command* partyOff[] { lightOff, stereoOff };

	MacroCommand* partyOnMacro = new MacroCommand(partyOn, 2);
	MacroCommand* partyOffMacro = new MacroCommand(partyOff, 2);

	RemoteControlWithUndo* remoteControl = new RemoteControlWithUndo;
	remoteControl->setCommand(0, partyOnMacro, partyOffMacro);
	remoteControl->onButtonWasPushed(0);
	remoteControl->offButtonWasPushed(0);

	// Stereo should save data to undo correctly
	remoteControl->undoButtonWasPushed();

	delete remoteControl;
	delete partyOnMacro;
	delete partyOffMacro;
	delete lightOn;
	delete stereoOn;
	delete stereoOff;
	delete lightOff;
	delete light;
	delete stereo;
}

//int main() {
//	RemoteLoaderMacro();
//	//RemoteLoaderFan();
//	//RemoteLoaderWithUndo();
//	//RemoteLoader();
//
//	return 0;
//}