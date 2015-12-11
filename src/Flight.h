/*
 * Flight.h
 *
 * 7 July 2015
 * Mert Aytöre
 * 21400923
 * CS201-01 / Summer
 */
#ifndef FLIGHT_H_
#define FLIGHT_H_

#include <string>
using namespace std;

class Flight {
public:
	struct Passenger {
		string firstName;
		string lastName;
		Passenger* pNext;
		Passenger* getNext();
		void setNext(Passenger* next);
	};

	Flight( const int flightId, const string fromCity, const string toCity );
	~Flight();

	//necessary functions
	void 	addPassenger(const string firstName, const string lastName);
	void 	removePassenger(const string firstName, const string lastName);

	bool 	isEmpty();

	//setter functions
	void 	setNextFlight(Flight* next);
	void 	setPreviousFlight(Flight* prev);
	void 	setCities(string fromCity, string toCity);
	void 	setFlightId(int id);
	void	setHeadPassenger(Passenger* head);

	//getter functions
	string 		getFlightFrom();
	Flight* 	getNextFlight();
	Flight*		getPreviousFlight();
	string 		getFlightTo();
	int 		getFlightId();
	Passenger*  getHeadPassenger();

private:
	int 	flightId;

	string 	fromCity;
	string 	toCity;

	Flight* fNext;
	Flight* fPrev;

	Passenger* pHead;
};
#endif
