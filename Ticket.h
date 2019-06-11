#ifndef _TICKET_
#define _TICKET_

class Passenger;
class Ticket {
public:
	double getPrice() {
		return price;
	}
	void setPassenger(Passenger*p) {
		pass = p;
	}

private:
	double price;
	Passenger* pass;
	friend class Flight;

	Ticket(double p) {
		price = p;
		pass = nullptr;
	}
};

#endif