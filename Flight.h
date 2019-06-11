#pragma once
class Airport;
class Ticket;
class Plane;
#include<list>
using namespace std;
class Flight {
public:
	
	//~Flight();
	int getId();
	Airport *getSrcAirport(); 
	Airport* getDestAirport();
	Plane* getPlane();
	double getPrice();
	friend class FlightDatabase;
	Ticket *createTicket();
private:
	Flight();
	int ID;
	Airport*srcAirport;
	Airport*dstAirport;
	Plane* plane;
	double pricePerUnit;
	list<Ticket*> listOfTicketsSold;


	Flight(int ID, Airport*fromAirport, Airport*toAirport, Plane*plane, double&pricePerUnit) :srcAirport(), dstAirport() {
		this->srcAirport = fromAirport; this->dstAirport = toAirport;
		this->plane = plane;	this->pricePerUnit = pricePerUnit;
		this->ID = ID;
	}
};

