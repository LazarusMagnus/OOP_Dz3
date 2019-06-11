#include "FlightControl.h"
#include"FlightDatabase.h"
#include "Plane.h"
#include"Exception.h"
FlightControl::FlightControl(int & noRunways)
{
	for (int i = 0; i < noRunways; i++)
		Runways.push_back(nullptr);
}

void FlightControl::setOnRunway(Plane * targetPlane)
{	
	if (targetPlane->getStatus() == ONFLIGHT)
		throw PlaneNotOnGroundException("u vazduhu");

	for (auto it : Runways)
		if (it == nullptr) {
			it = targetPlane;
			targetPlane->setStatus(READY);
			//kako da znam za koji let da ukrcavam putnike?

			return;
		}
	throw NoFreeRunwayException("s");
}

void FlightControl::removeFromRunway(Plane * targetPlane)
{
	for(auto it: Runways)
		if (it == targetPlane) {
			it->setStatus(FINISHED);
			it = nullptr;
			return;
		}
	throw PlaneNotOnRunwayException("df");
}

void FlightControl::allowTakeOff(Plane * p)
{
	if (!(p->isThereCopilot()) || !(p->isTherePilot()) || (p->getlistCrew().size() < 7))
		throw NoCrewException("da");
	if (p->getStatus() != READY)
		throw NoCrewException("ste");
	p->setStatus(ONFLIGHT);
}

void FlightControl::allowLanding(Plane * targetPlane)
{	
	bool full = true;
	for (auto it : Runways)
		if (it == nullptr)
			full = false;
	if (full)
		throw PlaneCanNotLandException("nema piste");
	if (targetPlane->getStatus() != ONFLIGHT)
		throw PlaneCanNotLandException("nije u vazduhu");
	targetPlane->setStatus(FINISHED);
	//treba uništiti karte
	targetPlane->clearPassenger();
}
