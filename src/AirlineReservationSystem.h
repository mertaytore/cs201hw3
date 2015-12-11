/*
 * AirlineReservationSystem.h
 *
 * 29 July 2015
 * Mert Aytöre
 * 21400923
 * CS201-01 / Summer
 */

#ifndef RESERVATION_H_
#define RESERVATION_H_

#include <string>
#include "Flight.h"
using namespace std;


class AirlineReservationSystem {
public:
	AirlineReservationSystem();
	~AirlineReservationSystem();
	void addFlight( const int flightId, const string fromCity, const string toCity );
	void removeFlight( const int flightId );
	void addPassenger( const int flightId, const string firstName, const string lastName );
	void removePassenger( const int flightId, const string firstName, const string lastName );
	void showFlight( const int flightId ) const;
	void showPassenger( const string firstName, const string lastName ) const;
	void showAllFlights() const;

	Flight* getFlightHead();

private:
	Flight* fHead;
};
#endif
