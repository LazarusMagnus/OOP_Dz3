#include "Airport.h"
#include"FlightDatabase.h"
#include"Flight.h"
#include"FlightControl.h"
#include<math.h>
using namespace std;

double distance(Airport * a1, Airport * a2){
	return sqrt((a1->x - a2->x)*(a1->x - a2->x) + (a1->y - a2->y)*(a1->y - a2->y));
}

void connect(Airport * a1, Airport * a2){
	if (!connected(a1, a2)) {
		a1->connected.push_back(a2);
		a2->connected.push_back(a1);
	}
}

bool connected(Airport * a1, Airport * a2){
	for (auto it : a1->connected)
		if (it == a2)
			return true;
	return false;
}

Airport::Airport( double x, double y, int numW){
	numOfways = numW;
	this->x = x;
	this->y = y;
	control = new FlightControl(numW);
	control->airport = this;
}

FlightControl * Airport::getFlightControl()
{
	return control;
}

list<Flight*> Airport::getFlightsTo(Airport * dest){
	list<Flight*> letovi = FlightDatabase::getInstance()->getFlightList();
	list<Flight*> rez= list<Flight*>();
	for (auto it : letovi) {
		if (it->getSrcAirport() == this && it->getDestAirport() == dest)
			rez.push_back(it);
	}
	
		return rez;
}
