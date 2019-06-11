#pragma once
#include<iostream>
#include<list>

using namespace std;

class Passenger;
class CrewMember;

enum Status{
	READY, ONFLIGHT, FINISHED
};

class Plane
{
public:
	Plane(int num);
	Status getStatus();
	void setStatus(Status st);
	//exceptions 
	void addPassenger(Passenger* P);
	void clearPassenger();
	void addCrewMember(CrewMember* C);
	void clearCrewMember();
	bool isTherePilot();
	bool isThereCopilot();
	list<Passenger*> getlistPass();
	list<CrewMember*> getlistCrew();


private:
	int numOfSeats;
	bool therePilot;
	bool thereCopilot;
	Status status;
	list<Passenger*> listPass;
	list<CrewMember*> listCrew;
};
