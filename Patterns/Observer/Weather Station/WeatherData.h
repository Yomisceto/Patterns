#pragma once
#include "../ISubject.h"
#include <list>

/** Weather Data that should be observed. */
class WeatherData : public ISubject{
public:
	WeatherData() = default;

	~WeatherData() override = default;

	/** Inherited via ISubject */
	void Attach(IObserver* observer) override;
	void Detach(IObserver* observer) override;
	void Notify() override;

	void UpdateData(float temperature, float humidity, float pressure);

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


