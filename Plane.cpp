#include "Plane.h"
#include"Person.h"

Plane::Plane(int num)
{
	numOfSeats = num;
	listCrew = list<CrewMember*>();
	listPass = list<Passenger*>();
}

Status Plane::getStatus()
{
	return status;
}

void Plane::setStatus(Status st){
	status = st;
}

void Plane::addPassenger(Passenger * P)
{
	if (listPass.size() == numOfSeats)
		throw;
	listPass.push_back(P);
}

void Plane::clearPassenger()
{
	listPass.clear();
}

void Plane::addCrewMember(CrewMember * C)
{
	if (isThereCopilot() && C->getRole()==CrewMember::copilot)
		return;
	if (isTherePilot() && C->getRole() == CrewMember::pilot)
		return;
	listCrew.push_back(C);

	if (C->getRole() == CrewMember::copilot)
		thereCopilot = true;
	if (C->getRole() == CrewMember::pilot)
		therePilot = true;
}

void Plane::clearCrewMember()
{
	listCrew.clear();
}

bool Plane::isTherePilot()
{
	return therePilot;
}

bool Plane::isThereCopilot()
{
	return thereCopilot;
}

list<Passenger*> Plane::getlistPass()
{
	return listPass;
}

list<CrewMember*> Plane::getlistCrew()
{
	return listCrew;
}
