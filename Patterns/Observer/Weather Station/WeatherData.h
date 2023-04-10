#ifndef _WEATHER_DATA_H
#define _WEATHER_DATA_H

#pragma once
#include "../ISubject.h"
#include <list>

class WeatherData : public ISubject{
public:
	WeatherData() = default;

	~WeatherData() override = default;

	/** Inherited via ISubject */
	void Attach(IObserver* observer) override;
	void Detach(IObserver* observer) override;
	void Notify() override;

	void UpdateData(float, float, float);

	float GetTemperature() const { return temperature_; }
	float GetHumidity() const { return humidity_; }
	float GetPressure() const { return pressure_; }

private:
	std::list<IObserver*> observers_;

	/** parameters to create weather report */
	float temperature_;
	float humidity_;
	float pressure_;
};
void WeatherData::Detach(IObserver* observer) {
	observers_.remove(observer);
}

void WeatherData::Attach(IObserver* observer) {
	observers_.push_back(observer);
}
void WeatherData::Notify() {
	for (auto const observer : observers_) observer->Update();
}
void WeatherData::UpdateData(float temperature, float humidity, float pressure) {
	temperature_ = temperature;
	humidity_ = humidity;
	pressure_ = pressure;
	Notify();
}
#endif // !_WEATHER_DATA_H

