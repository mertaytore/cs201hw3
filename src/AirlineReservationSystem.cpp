/*
 * AirlineReservationSystem.cpp
 *
 * 7 July 2015
 * Mert Aytöre
 * 21400923
 * CS201-01 / Summer
 */

#include "AirlineReservationSystem.h"
#include "Flight.h"
#include <iostream>
using namespace std;

//constructor
AirlineReservationSystem::AirlineReservationSystem() {
	fHead   = NULL;
}

//destructor
AirlineReservationSystem::~AirlineReservationSystem() {
	if(fHead != NULL){
		Flight* flight = fHead;
		while(flight != NULL){
			Flight* aFlight = flight;
			flight = flight -> getNextFlight();
			delete aFlight;
		}
	}
}

//methods start here
void AirlineReservationSystem::addFlight( const int flightId, const string fromCity, const string toCity ){
	bool exist = false;
	int idCheck = -1;
	Flight* current = getFlightHead();

	while(current != NULL && !exist){
		if(current->getFlightId() == flightId)
			exist = true;
		else if(current -> getFlightId() < flightId)
			idCheck = current -> getFlightId();

		current = current -> getNextFlight();
	}

	if(exist)
		cout << "Flight already exists!" << endl;

	//whole work is done here
	else{
		Flight* newFlight = new Flight(flightId, fromCity, toCity);

		//if there is none, add to head
		if( idCheck == -1){
			if(fHead == NULL)
				fHead = newFlight;
			else{
				newFlight->setNextFlight(fHead);
				fHead = newFlight;
			}
		}

		//else add after the closest
		else{
			current = fHead;
			while(current -> getFlightId() != idCheck){
				if(current -> getNextFlight() != NULL)
					current = current -> getNextFlight();
			}
			if(current -> getFlightId() == idCheck){
				newFlight -> setNextFlight(current -> getNextFlight());
				current -> setNextFlight(newFlight);
				current -> getNextFlight() -> setPreviousFlight(newFlight);
				newFlight->setPreviousFlight(current);
			}
		}
	}
}

void AirlineReservationSystem::removeFlight( const int flightId ){
	Flight* current = fHead;
	bool check = false;


	if(current != NULL)
		while(current != NULL && !check){
			if(current -> getFlightId() == flightId){

				/*Flight::Passenger* aPassenger = current -> getHeadPassenger();
				if(aPassenger != NULL){
					Flight::Passenger* passenger = aPassenger;
					while(passenger != NULL){
						aPassenger = passenger;
						passenger = passenger -> pNext;
						delete aPassenger;
					}
				}*/


				Flight* next = current -> getNextFlight();
				Flight* prev = current -> getPreviousFlight();

				if(prev == NULL)
					fHead = next;
				else
					prev -> setNextFlight(next);

				current -> setNextFlight(NULL);
				check = true;
				delete current;
			}
			else{
				Flight* prev = current -> getPreviousFlight();
				prev = current;
				current = current -> getNextFlight();
			}

		}

	if(!check)
		cout << "Flight id not found" << endl;
}

void AirlineReservationSystem::addPassenger( const int flightId, const string firstName, const string lastName ){
	bool check = false;
	Flight* current = fHead;

	while(current != NULL && !check){
		if(current->getFlightId() == flightId)
			check = true;
		if(!check)
			current = current->getNextFlight();
	}

	if(!check)
		cout << "No existing flight id" << endl;
	else
		current -> addPassenger(firstName, lastName);
}

void AirlineReservationSystem::removePassenger( const int flightId, const string firstName, const string lastName ){
	bool check = false;
	Flight* current = fHead;

	while(current != NULL && !check){
		if(current->getFlightId() == flightId)
			check = true;
		if(!check)
			current = current->getNextFlight();
	}

	if(!check)
		cout << "No existing flight id" << endl;
	else
		current -> removePassenger(firstName, lastName);
}

void AirlineReservationSystem::showFlight( const int flightId ) const{
	Flight* current = fHead;
	bool found = false;

	while(current != NULL && !found){
		if(current->getFlightId() == flightId)
			found = true;
		else
			current = current -> getNextFlight();
	}

	if(found){
		cout << "Flight " << current -> getFlightId() <<
				": from " << current -> getFlightFrom() <<
				" to " << current -> getFlightTo() << endl;

		//gets the current's head
		Flight::Passenger* currentP = current -> getHeadPassenger();

		while(currentP != NULL){
			cout << currentP -> firstName << " " << currentP -> lastName << endl;
			currentP = currentP->pNext;
		}
		cout << endl;
	}
	if(!found)
		cout << "No existing flight id"<<endl;
}

void AirlineReservationSystem::showPassenger( const string firstName, const string lastName ) const{
	Flight* currentF = fHead;
	Flight::Passenger* currentP;

	cout << "Flights for " << firstName << " " << lastName << endl;

	while(currentF != NULL){
		currentP = currentF -> getHeadPassenger();

		while(currentP != NULL){
			//string comparison
			if(currentP->firstName.compare(firstName) == 0 && currentP->lastName.compare(lastName) == 0)
				cout << "Flight " << currentF -> getFlightId() <<
				": from " << currentF -> getFlightFrom() <<
				" to " << currentF -> getFlightTo() << endl;
			currentP = currentP -> pNext;
		}
		currentF = currentF->getNextFlight();
	}
	cout << endl;
}

void AirlineReservationSystem::showAllFlights() const{
	Flight* current = fHead;
	while(current != NULL){
		cout << "Flight " << current->getFlightId() <<
				": from " << current->getFlightFrom() <<
				" to " << current -> getFlightTo() << endl;
		Flight::Passenger* currentP = current->getHeadPassenger();

		while(currentP != NULL){
			cout<<currentP->firstName<<" "<<currentP->lastName<<endl;
			currentP = currentP->pNext;
		}
		cout<<endl;
		current = current->getNextFlight();
	}
}

//custom function
Flight* AirlineReservationSystem::getFlightHead()
{
	return fHead;
}
