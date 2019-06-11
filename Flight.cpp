#include "Flight.h"
#include"Ticket.h"
#include"Airport.h"
int Flight::getId()
{
	return ID;
}

Airport * Flight::getSrcAirport()
{
	return srcAirport;
}

Airport * Flight::getDestAirport()
{
	return dstAirport;
}

Plane * Flight::getPlane()
{
	return plane;
}

double Flight::getPrice(){
	double p= distance(srcAirport, dstAirport);
	return p * pricePerUnit;
}

Ticket * Flight::createTicket()
{
	Ticket* t = new Ticket(getPrice());
	listOfTicketsSold.push_back(t);
	return  t;
}
