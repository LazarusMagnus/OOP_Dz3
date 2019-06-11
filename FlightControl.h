#ifndef _FLIGHTCONTROL_H_
#define _FLIGHTCONTROL_H_
#include <list>
#include <vector>
#include<exception>
using namespace std;
class Plane;
class Airport;
class FlightControl
{
public:
	FlightControl(int& noRunways);
	//~FlightControl();
	//exceptions PlaneNotSuitableException
	void setOnRunway(Plane*targetPlane);
	void removeFromRunway(Plane*targetPlane);
	void allowTakeOff(Plane* p);
	void allowLanding(Plane*targetPlane);
	list<Plane*> readyForTakeOff();
	list<Plane*> readyForLanding();
	vector<Plane*> getRunways();
private:
	vector<Plane*> Runways;
	Airport* airport;
	friend class Airport;

};
//class NoFreeRunwayException : public exception{};
//class PlaneNotSuitableException : public exception {};
//class  PlaneNotOnGroundException : public exception {};
//class  PlaneNotOnRunwayException : public exception {};
//
//class  PlaneNotReadyException : public exception {};
//class  NoCrewException : public exception {};

#endif