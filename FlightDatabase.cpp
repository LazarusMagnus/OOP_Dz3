#include "FlightDatabase.h"
#include"Flight.h"
#include"Airport.h"
#include"Exception.h"

FlightDatabase*FlightDatabase::Instance = nullptr;

void FlightDatabase::setGenerator(SequenceGenerator * gen){
	getInstance()->generator =new SequenceGenerator();
}

SequenceGenerator * FlightDatabase::getGenerator()
{
	return getInstance()->generator;
}

void FlightDatabase::insertFlight(Flight * flight)
{
	if (!connected(flight->getDestAirport(), flight->getSrcAirport()))
		throw AirportsNotConnectedException("nisu pov");
	getInstance()->flights.push_back(flight);
}

list<Flight*> FlightDatabase::getFlightList()
{
	return getInstance()->flights;
}
list<Flight*> FlightDatabase::findBySrcAirport(Airport * src)
{
	list<Flight*> rez = list<Flight*>();
	for (auto it : getInstance()->flights)
		if (it->srcAirport == src)
			rez.push_back(it);
	return rez;
}
list<Flight*> FlightDatabase::findByDestAirport(Airport * dst)
{
	list<Flight*> rez = list<Flight*>();
	for (auto it : getInstance()->flights)
		if (it->dstAirport == dst)
			rez.push_back(it);
	return rez;
}
list<Flight*> FlightDatabase::findByPlane(Plane * p)
{
	list<Flight*> rez = list<Flight*>();
	for (auto it : getInstance()->flights)
		if (it->plane==p)
			rez.push_back(it);
	return rez;
}
list<Flight*> FlightDatabase::findByPlaneStatus(Status s)
{
	list<Flight*> rez = list<Flight*>();
	for (auto it : getInstance()->flights)
		if (it->plane->getStatus() == s)
			rez.push_back(it);
	return rez;
}
list<Flight*> FlightDatabase::findByMaxPrice(double max)
{
	list<Flight*> rez = list<Flight*>();
	for (auto it : getInstance()->flights)
		if (it->getPrice() <= max)
			rez.push_back(it);
	return rez;
}
Flight * FlightDatabase::createFlight(int id, Airport * src, Airport * dst, Plane * p, double pricePerUnit)
{
	return new Flight(id,src,dst,p,pricePerUnit);
}
//list<Flight*> FlightDatabase::flights = list<Flight*>();
//SequenceGenerator FlightDatabase::generator = SequenceGenerator();