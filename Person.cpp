#include "Person.h"
#include"Strategy.h"
#include"Airport.h"
#include"Exception.h"
#include"Ticket.h"
void Passenger::setStrategy(BuyingStrategy * ss){
	strategy = ss;
}

void Passenger::takeMoney(double mm)
{
	double t = money - mm;
	if (t >= 0)
		money = t;
	else
		throw NotEnoughMoney("nema dov novca");
}

void Passenger::giveMoney(double mm)
{
	money += mm;
}

double Passenger::getMoney()
{
	return money;
}

bool Passenger::buyTicket(Airport * src, Airport * dst)
{
	Ticket* t = strategy->findBestTicket(src->getFlightsTo(dst));
	try {
		takeMoney(t->getPrice());
		t->setPassenger(this);
	}
	catch (exception) {
		return false;
	}
	return true;
}

CrewMember::Role CrewMember::getRole()
{
	return role;
}
