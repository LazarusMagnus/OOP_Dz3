#include "Strategy.h"
#include"Flight.h"
Ticket * CheapTicketStrategy::findBestTicket(list<Flight*> list){
	Flight* min=list.front();
	for (auto it : list) {
		if (min->getPrice() > it->getPrice())
			min = it;
	}
	Ticket* karta = min->createTicket();
	return karta;

	
}

Ticket * ExpensiveTicketStrategy::findBestTicket(list<Flight*> list)
{
	Flight* max = list.front();
	for (auto it : list) {
		if (max->getPrice() < it->getPrice())
			max = it;
	}
	Ticket* karta = max->createTicket();

	return karta;


}

Ticket * AverageTicketStrategy::findBestTicket(list<Flight*> list)
{
	Flight* min = list.front();
	double sum=0;
	for (auto it : list)
		sum += it->getPrice();
	for (auto it : list) {
		if ((min->getPrice()-sum) > (it->getPrice()-sum))
			min = it;
	}
	Ticket* karta = min->createTicket();

	return karta;


}
