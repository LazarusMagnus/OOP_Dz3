#pragma once
#include<iostream>
#include<list>
#include"Plane.h"
using namespace std;
class Flight;

class Airport;
class SequenceGenerator
{
public:
	SequenceGenerator() { this->ID = 0; }; //samo da prodje test inace promeni da bude jedinstven
	int next() { this->ID++;  return ID; };
	friend class FlightDatabase;

private:
	int ID;

};

class FlightDatabase {
public:
	static FlightDatabase* getInstance() {
		if (Instance == nullptr) { Instance = new FlightDatabase(); }
		return Instance;
	}
	static	void setGenerator(SequenceGenerator*chosen);
	static	SequenceGenerator* getGenerator();
	static void insertFlight(Flight*flight);
	static	void deleteFlight(Flight*flight);
	static list<Flight*> getFlightList();
	static list<Flight*> findBySrcAirport(Airport*src);
	static list<Flight*> findByDestAirport(Airport*dst);
	static list<Flight*> findByPlane(Plane*plane);
	static list<Flight*> findByPlaneStatus(Status status);
	static list<Flight*> findByMaxPrice(double max);
	Flight* createFlight(int id, Airport* src, Airport* dst, Plane*p, double pricePerUnit);
private:
	static FlightDatabase*Instance;
	FlightDatabase() {};
	SequenceGenerator* generator;
	list<Flight*> flights;
};
