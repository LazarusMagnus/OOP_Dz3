#ifndef _STRATEGY_
#define _STRATEGY_
#include<iostream>
#include<list>
using namespace std;

class Ticket;
class Flight;

class BuyingStrategy {
public:
	BuyingStrategy() {};
	virtual Ticket* findBestTicket(list<Flight*> list)=0;

private:

};
//fali set pass
class CheapTicketStrategy : public BuyingStrategy
{
public:
	CheapTicketStrategy() {};
	Ticket* findBestTicket(list<Flight*> list);
};

class ExpensiveTicketStrategy : public BuyingStrategy {
public:
	ExpensiveTicketStrategy() {};
	Ticket* findBestTicket(list<Flight*> list);
};


class AverageTicketStrategy {
public:
	AverageTicketStrategy() {};
	Ticket* findBestTicket(list<Flight*> list);
};


#endif // !_STRATEGY_
