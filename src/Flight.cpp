/*
 * Flight.cpp
 *
 * 7 July 2015
 * Mert Aytöre
 * 21400923
 * CS201-01 / Summer
 */
#include "Flight.h"
#include <iostream>
using namespace std;

//constructor
Flight::Flight(const int flightId, const string fromCity, const string toCity ) {
	this->flightId = flightId;
	this->fromCity = fromCity;
	this->toCity   = toCity;
	fNext 		   = NULL;
	fPrev 		   = NULL;
	pHead 	 	   = NULL;
}

//destructor
Flight::~Flight(){
	//checks if the list is empty or not
	if(pHead != NULL){
		Passenger* passenger = pHead;
		while(passenger != NULL){
			Passenger* anotherPassenger = passenger;
			passenger = passenger -> pNext;
			delete anotherPassenger;
		}
	}
}

//methods start here
void Flight::addPassenger(const string firstName, const string lastName){
	if(pHead == NULL){
		pHead = new Passenger;
		pHead -> pNext = NULL;
		pHead->firstName = firstName;
		pHead->lastName = lastName;
	}
	else{
		bool sameName = false;
		Passenger* current = pHead;

		while(current -> pNext != NULL && !sameName){
			if(firstName.compare(current -> firstName) == 0 && lastName.compare(current -> lastName) == 0)
				sameName = true;
			current = current -> pNext;
		}

		if(sameName)
			cout << "Person with name " << firstName << " " << lastName << " already exists." << endl;
		else{
			current->pNext = new Passenger;
			current-> pNext -> pNext = NULL;
			current->pNext->firstName = firstName;
			current->pNext->lastName = lastName;
		}
	}
}

void Flight::removePassenger(const string firstName, const string lastName){
	Passenger* prevP = NULL;
	Passenger* aPassenger = pHead;
	bool check = false;

	while(aPassenger != NULL && !check){
		if(aPassenger -> firstName.compare(firstName) == 0 && aPassenger -> lastName.compare(lastName) == 0){

			Flight::Passenger* nextP = aPassenger->getNext();

			if(prevP == NULL)
				pHead = nextP;
			else
				prevP->setNext(nextP);

			aPassenger->setNext(NULL);
			check = true;
			delete aPassenger;
		}

		if(!check){
			prevP = aPassenger;
			aPassenger = aPassenger->getNext();
		}
	}

	if(!check)
		cout<<"No existing passenger"<<endl;
}


bool Flight::isEmpty(){
	return (pHead == NULL);
}

//setter functions
void Flight::setNextFlight(Flight* next){
	this->fNext = next;
}

void Flight::setPreviousFlight(Flight* prev){
	this->fPrev = prev;
}

void Flight::setCities(string fromCity, string toCity){
	this->fromCity = fromCity;
	this->toCity = toCity;
}

void Flight::setFlightId(int id){
	this-> flightId = id;
}

void Flight::setHeadPassenger(Flight::Passenger* head){
	pHead = head;
}

void Flight::Passenger::setNext(Passenger* nextP){
	this->pNext = nextP;
}

//getter functions
string Flight::getFlightFrom(){
	return this-> fromCity;
}

Flight* Flight::getNextFlight(){
	return fNext;
}

Flight* Flight::getPreviousFlight(){
	return fPrev;
}

string Flight::getFlightTo(){
	return this-> toCity;
}

int Flight::getFlightId(){
	return this->flightId;
}

Flight::Passenger* Flight::getHeadPassenger(){
	return pHead;
}

Flight::Passenger* Flight::Passenger::getNext(){
	return pNext;
}

