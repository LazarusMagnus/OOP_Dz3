#ifndef _EXCEPTIONS_H_
#define _EXCEPTIONS_H_

#include <exception>
#include <iostream>
using namespace std;

//...........................date
class DBException : public exception {
public:

	DBException(const char* msg) : exception(msg) { }
};


class MoneyException : public DBException {
public:
	MoneyException(const char* msg) : DBException(msg) {}
};
class NotEnoughMoney : public DBException {
public:
	NotEnoughMoney(const char* msg) : DBException(msg) {}
};

class FlightControlException : public DBException{
public:
	FlightControlException(const char* msg) : DBException(msg) {}
};

class PlaneNotSuitableException : public DBException {
public:
	PlaneNotSuitableException(const char* m) : DBException(m) {}
};

class PlaneNotOnGroundException : public DBException {
public:	PlaneNotOnGroundException(const char* m) : DBException(m) {}
};

class NoFreeRunwayException : public DBException {
public:	NoFreeRunwayException(const char* m) : DBException(m) {}
};

class PlaneNotOnRunwayException : public DBException {
public:	PlaneNotOnRunwayException(const char* m) : DBException(m) {}
};


class PlaneNotReadyException : public DBException {
public:	PlaneNotReadyException(const char* m) : DBException(m) {}
};


class NoCrewException : public DBException {
public:	NoCrewException(const char* m) : DBException(m) {}
};


class PlaneCanNotLandException : public DBException {
public:	PlaneCanNotLandException(const char* m) : DBException(m) {}
};




/*flightdatabase ****************************************************/
class FlightDateBaseException : public DBException {
public:	FlightDateBaseException(const char* msg) : DBException(msg) {}
};

class AirportsNotConnectedException : public DBException {
public:	AirportsNotConnectedException(const char* m) : DBException(m) {}
};

class IdConflictException : public DBException {
public:	IdConflictException(const char* m) : DBException(m) {}
};

class FlightNotInDatabaseException : public DBException {
public:	FlightNotInDatabaseException(const char* msg) : DBException(msg) {}
};












#endif

