


// this has been copied over




#include <iostream>
#include <string>
#include <sstream>
#include "Mammal2.h"						// libraries to be used in the mammal class including inclusion of .h file 
#include <iomanip>

using namespace std;



void Mammal::SetNurse(int nurse) {

	this->nurse = nurse;
}


int Mammal::GetNurse() {

	return nurse;
}

											// accessor and getter functions for the mammal class
void Mammal::SetEggs(int numEggs) {

	this->numEggs = numEggs;
}

int Mammal::GetEggs()
{
	return numEggs;
}



const string Mammal::ToString() {
	ostringstream buffer;
	buffer << GetTrackNumber() << endl
		<< GetAnimalName() << endl
		<< GetAnimalType() << endl					// toString function to access mammal data
		<< GetAnimalSubType() << endl
		<< GetEggs() << endl
		<< GetNurse() << endl;

	return buffer.str();
}

void Mammal::PrintMammal() {
	Animal::PrintAnimal();

	cout << "----------------";								// print function to display mammal data
	cout << "|" << nurse << "            |" << endl;
	cout << "----------------";
	
	



}




