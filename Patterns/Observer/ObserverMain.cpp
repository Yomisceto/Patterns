#pragma once
#include "Weather Station/WeatherDisplays.h"

#define _newline std::cout << std::endl

void WeatherDataCode();

//int main() {
//	
//	WeatherDataCode();
//	return 0;
//}


void WeatherDataCode() {
	WeatherData weatherData;							// subject
	CurrentConditionsDisplay display1(&weatherData);	// observer 1
	CurrentConditionsDisplay display2(&weatherData);	// observer 2
	
	weatherData.UpdateData(80, 80, 80); _newline;		// event - notify observers

	ShortConditionsDisplay shortDisplay(&weatherData);	// observer 3
	
	weatherData.UpdateData(0, 0, 0); _newline;
}