#pragma once
#include<iostream>
#include <list>
class Flight;
class FlightControl;
class Airport
{
public:
	Airport( double x, double y,int numW);
	//~Airport();
	friend double distance(Airport* a1, Airport* a2);
	friend void connect(Airport* a1, Airport* a2);
	friend bool connected(Airport* a1, Airport* a2);
	FlightControl* getFlightControl();
	std::list<Flight*> getFlightsTo(Airport*dest);
private:
	double x, y;
	std::list<Airport*> connected;
	int numOfways;
	FlightControl* control;
	friend class FlightControl;
};

//bool connected(Airport * a1, Airport * a2);
