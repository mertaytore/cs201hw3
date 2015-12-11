//============================================================================
// Name        : HW3.cpp
// Author      : Mert Aytore
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

#include "AirlineReservationSystem.h"

int main() {
    AirlineReservationSystem ars;

        ars.addFlight(123,"Ankara","Istanbul");
        ars.addFlight(189,"Istanbul","Ankara");
        ars.addFlight(250,"Ankara","Izmir");
        ars.addFlight(265,"Izmir","Istanbul");
        ars.addFlight(123,"Istanbul","Ankara"); //should show warning
        ars.showAllFlights();

        ars.removeFlight(265);
        ars.removeFlight(123);
        ars.removeFlight(123);  //has already deleted
        ars.removeFlight(120); //nothing found with this name
        ars.showAllFlights();

        cout<<"Starting again"<<endl;
        AirlineReservationSystem ars2;
        ars2.addFlight(123,"Ankara","Istanbul");
        ars2.addFlight(189,"Istanbul","Ankara");
        ars2.addFlight(250,"Ankara","Izmir");
        ars2.addFlight(265,"Izmir","Istanbul");

        ars2.addPassenger( 123, "Selim", "Aksoy" );
    ars2.addPassenger( 189, "Selim", "Aksoy" );
        ars2.addPassenger( 265, "Noushin", "Faramarzi" );
        ars2.addPassenger( 265, "John", "Smith" );
        ars2.addPassenger( 123, "Jane", "Doe" );
        ars2.addPassenger( 189, "John", "Smith" );
        ars2.addPassenger( 123, "Hamzeh", "Ahangari" );
        ars2.addPassenger( 265, "Nabil", "Abubakir" );




        ars2.showAllFlights();

        ars2.addPassenger( 120, "Nabil", "Abubakir" ); //no such a flight Id
        ars2.addPassenger( 189, "Selim", "Aksoy" );  //Has already added
    ars2.addPassenger( 123, "Noushin", "Faramarzi" );
        ars2.showAllFlights();


        ars2.showFlight(123);
        ars2.showFlight(10); //show warning no such a flight Id

        ars2.showPassenger("Selim","Aksoy");
        ars2.showPassenger("Gokhan","Akcay"); // show no such a passenger

        ars2.removePassenger(123, "Selim", "Aksoy" );
        ars2.removePassenger(123, "Hamzeh", "Abubakir" );  //show warning no such passenger
        ars2.removePassenger(110, "Hamzeh", "Ahangari" );  //no such a flight
        ars2.removePassenger(265, "John", "Smith" );
        ars2.removePassenger(265, "Noushin", "Faramarzi" );


        ars2.showFlight(110);//no such flight
        ars2.showFlight(123);
        ars2.showFlight(123);

    ars2.removeFlight(250);
    ars2.removeFlight(123);
        ars2.addFlight(110,"Izmir","Istanbul");
        ars2.addFlight(150,"Istanbul","Izmir");
        ars2.addPassenger( 111, "Selim", "Aksoy" );
        ars2.addPassenger( 150, "Selim", "Aksoy" );
        ars2.addPassenger( 150, "Noushin", "Faramarzi" );
        ars2.addPassenger( 150, "Noushin", "Faramarzi" );        // has already added
        ars2.showAllFlights();

    return 0;
}
