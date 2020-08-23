

// this has been copied over





#include <iostream>
#include <string>
#include <sstream>			// libraries to be used in the mammal class including inclusion of .h file 
#include "Oviparous2.h"
using namespace std;





void Oviparous::SetEggs(int numEggs) {

	this->numEggs = numEggs;
}


int Oviparous::GetEggs() {

	return numEggs;
}											// accessor and getter functions for the Oviparous class



void Oviparous::SetNurse(int nurse) {

	this->nurse = nurse;
}


int Oviparous::GetNurse() {

	return nurse;
}


const string Oviparous::ToString() {
	ostringstream buffer;
	buffer << GetTrackNumber() << endl
		<< GetAnimalName() << endl
		<< GetAnimalType() << endl				// toString function to access Oviparous data
		<< GetAnimalSubType() << endl
		<< GetEggs() << endl
		<< GetNurse() << endl;

	return buffer.str();
}


void Oviparous::PrintOviparous() {
	PrintAnimal();										// print function to display Oviparous data
	cout << "Egg Amount: " << numEggs << endl;
	cout << "Is Nursing: " << nurse << endl;


}



