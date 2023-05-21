#include "WeatherDisplays.h"

void CurrentConditionsDisplay::Update() {
	this->temperature_ = weatherData_->GetTemperature();
	this->humidity_ = weatherData_->GetHumidity();
	this->pressure_ = weatherData_->GetPressure();
	Display();
}

void CurrentConditionsDisplay::Display() {
	std::cout << "Current conditions: " << temperature_
		<< "C degrees, " << humidity_ << "% humidity and " << pressure_ << " pressure" << std::endl;
}