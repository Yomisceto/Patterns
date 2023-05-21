#include "WeatherData.h"

void WeatherData::Attach(IObserver* observer)
{
	observers_.push_back(observer);
}

void WeatherData::Detach(IObserver* observer)
{
	observers_.remove(observer);
}

void WeatherData::Notify() {
	for (auto const observer : observers_) {
		observer->Update();
	}
}

void WeatherData::UpdateData(float temperature, float humidity, float pressure) {
	temperature_ = temperature;
	humidity_ = humidity;
	pressure_ = pressure;
	Notify();
}
