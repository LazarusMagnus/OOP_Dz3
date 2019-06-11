#include"Person.h"
#include"Airport.h"
#include"Flight.h"
#include"FlightControl.h"
#include"FlightDatabase.h"
#include"Plane.h"
#include"Strategy.h"
#include"Exception.h"

void test() {

	// X, Y, brojPisti - redosled parametara u konstruktoru klase Airport
	Airport* A = new Airport(20, 10, 5);
	Airport* B = new Airport(10, 20, 3);

	connect(A, B);

	if (!connected(A, B)) throw DBException("Greska u povezivanju aerodroma!");

	// Metodu za dohvatanje jedine baze leta u sistemu nazvati getInstance
	FlightDatabase::getInstance()->setGenerator(new SequenceGenerator());

	Plane* plane1 = new Plane(100);
	Plane* plane2 = new Plane(100);
	// {pilot, copilot, other} treba da bude 'enum' u klasi CrewMember
	CrewMember* cm1 = new CrewMember("Pilot", "Pilotic", CrewMember::pilot);
	CrewMember* cm2 = new CrewMember("Kopilot", "Kopilotic", CrewMember::copilot);
	CrewMember* cm3 = new CrewMember("Marko", "Markovic", CrewMember::other);
	CrewMember* cm4 = new CrewMember("Anic", "Anic", CrewMember::other);
	CrewMember* cm5 = new CrewMember("Sara", "Saric", CrewMember::other);
	CrewMember* cm6 = new CrewMember("Nikola", "Nikolic", CrewMember::other);
	CrewMember* cm7 = new CrewMember("Stefana", "Stefanovic", CrewMember::other);
	CrewMember* cm8 = new CrewMember("Uros", "Urosevic", CrewMember::other);
	plane1->addCrewMember(cm1); plane1->addCrewMember(cm2); plane1->addCrewMember(cm3); plane1->addCrewMember(cm4);
	plane1->addCrewMember(cm5); plane1->addCrewMember(cm6); plane1->addCrewMember(cm7); plane1->addCrewMember(cm8);

	CrewMember* cm9 = new CrewMember("Pilotka", "Pilotic", CrewMember::pilot);
	CrewMember* cm10 = new CrewMember("Kopilotka", "Kopilotic", CrewMember::copilot);
	CrewMember* cm11 = new CrewMember("Mara", "Maric", CrewMember::other);
	CrewMember* cm12 = new CrewMember("Anko", "Ankovic", CrewMember::other);
	CrewMember* cm13 = new CrewMember("Stefan", "Stefanovic", CrewMember::other);
	CrewMember* cm14 = new CrewMember("Nikolina", "Nikolic", CrewMember::other);
	CrewMember* cm15 = new CrewMember("Sarko", "Saric", CrewMember::other);
	CrewMember* cm16 = new CrewMember("Una", "Unic", CrewMember::other);
	plane2->addCrewMember(cm1); plane2->addCrewMember(cm2); plane2->addCrewMember(cm3); plane2->addCrewMember(cm4);
	plane2->addCrewMember(cm5); plane2->addCrewMember(cm6); plane2->addCrewMember(cm7); plane2->addCrewMember(cm8);

	Flight* flight1 = FlightDatabase::getInstance()->createFlight(FlightDatabase::getInstance()->getGenerator()->next(), A, B, plane1, 1);
	FlightDatabase::getInstance()->insertFlight(flight1);
	Flight* flight2 = FlightDatabase::getInstance()->createFlight(FlightDatabase::getInstance()->getGenerator()->next(), A, B, plane2, 2);
	FlightDatabase::getInstance()->insertFlight(flight2);

	if (FlightDatabase::getInstance()->getFlightList().size() != 2) throw DBException("Greska u bazi!");
	if (A->getFlightsTo(B).size() != 2) throw DBException("Greska u dohvatanju letova!");

	Passenger* p1 = new Passenger("Milica", "Milicevic", 100);
	p1->setStrategy(new CheapTicketStrategy());
	Passenger* p2 = new Passenger("Petar", "Petrovic", 100);
	p2->setStrategy(new ExpensiveTicketStrategy());

	if (!p1->buyTicket(A, B)) throw DBException("Greska u kupovini karte!");
	if (!p2->buyTicket(A, B)) throw DBException("Greska u kupovini karte!");

	// Dodati metodu getMoney() u klasu Passenger
	if (p1->getMoney() <= p2->getMoney()) throw DBException("Greska u strategiji kupovine!");

	// Dodati metodu getFlightControl() u klasu Airport
	A->getFlightControl()->setOnRunway(plane1);
	A->getFlightControl()->allowTakeOff(plane1);
	B->getFlightControl()->allowLanding(plane1);

	cout << "Uspesno je prosao test!" << endl;

}
int main() {
	
	test();
	
}