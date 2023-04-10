#pragma once
#include "../Observer.h"
#include "IDisplayElement.h"
#include "WeatherData.h"
/** keep displays on purpose in one file, so we don't make a lot of files. */
class CurrentConditionsDisplay : public IObserver, public IDisplayElement {

public:
	explicit CurrentConditionsDisplay(WeatherData& weatherData) 
		: weatherData_(weatherData) { this->weatherData_.Attach(this); }
	void Update() override;

	virtual void Display() override;

protected:
	WeatherData& weatherData_;

	/** parameters to create weather report */
	float humidity_ = 0.f;
	float pressure_ = 0.f;
	float temperature_ = 0.f;
};

void CurrentConditionsDisplay::Update() {
	this->temperature_ = weatherData_.GetTemperature();
	this->humidity_ = weatherData_.GetHumidity();
	this->pressure_ = weatherData_.GetPressure();
	Display();
}

void CurrentConditionsDisplay::Display() {
	std::cout << "Current conditions: " << temperature_
		<< "C degrees, " << humidity_ << "% humidity and " << pressure_ << " pressure" << std::endl;
}

/** Simple display just for an example */
class ShortConditionsDisplay : public CurrentConditionsDisplay {
	void Display() override {
		std::cout << "Current short conditions: " << temperature_ << "C degrees" << std::endl;
	}
};