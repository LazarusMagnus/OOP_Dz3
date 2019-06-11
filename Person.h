#ifndef _PERSON_
#define _PERSON_
#include<string>
#include<iostream>
#include<list>
#include<exception>
#include"Strategy.h"

//class BuyingStrategy;
//class CheapTicketStrategy;
class Airport;

using namespace std;

class Person
{
public:
	Person(string ii, string pp) {
		firstName = ii;
		lastName = pp;
	}
private:
	string firstName, lastName;
};


class Passenger : public Person {
public:
	Passenger(string ime, string prezime, double mm) :Person(ime, prezime), money(mm) {
		strategy = new CheapTicketStrategy();
	};
	void setStrategy(BuyingStrategy* ss);
	//baca exception
	void takeMoney(double mm);
	void giveMoney(double mm);
	double getMoney();
	bool buyTicket(Airport* src, Airport* dst);

private:
	double money;
	BuyingStrategy* strategy;
};
class CrewMember :public Person {
public:
	enum Role {
		pilot, copilot, other
	};
	CrewMember(string ime, string prezime, Role r) :Person(ime, prezime), role(r) {};
	Role getRole();
private:
	Role role;
};

//class NotEnoughMoney: public exception
//{
//public:
//	NotEnoughMoney(const char* msg) : exception(msg) { };
//};


#endif // !_PERSON_

