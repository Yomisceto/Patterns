#pragma once
#include "IDisplayElement.h"
#include "WeatherData.h"

/** Base display of weather. */
class CurrentConditionsDisplay : public IObserver, public IDisplayElement {

public:
	explicit CurrentConditionsDisplay(WeatherData* weatherData) 
		: weatherData_(weatherData) { this->weatherData_->Attach(this); }

	void Update() override;
	void Display() override;

protected:
	float getTemperature() const { return temperature_; }

private:
	WeatherData* weatherData_;

	/** parameters to create weather report */
	float humidity_ = 0.f;
	float pressure_ = 0.f;
	float temperature_ = 0.f;
};

/** Simple display just for an example. */
class ShortConditionsDisplay : public CurrentConditionsDisplay {

	using CurrentConditionsDisplay::CurrentConditionsDisplay;

	void Display() override {
		std::cout << "Current short conditions: " << getTemperature() << "C degrees" << std::endl;
	}
};