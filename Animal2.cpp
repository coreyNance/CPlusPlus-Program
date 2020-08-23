


// This has been copied over




#include <iostream>
#include <string>    // libraries to be used in the animal class
#include <iomanip>
#include <sstream>


#include "Animal2.h"        // include statment for the animal header file.
using namespace std;


Animal::Animal() {

	animalType = " ";
	animalSubType = " ";
	animalName = " ";                 // default constructor for the animal class
	trackNumber = 0;
}

Animal::Animal(string animalName, int trackNumber) {

	this->animalName = animalName;                    //construtor to assign user entered variables with class variables.
	this->trackNumber = trackNumber;

}


void Animal::SetTrackNumber(int trackNumber) {

	this->trackNumber = trackNumber;
}

void Animal::SetAnimalName(string animalName) {
	                                                    // class setter/mutator functions for the animal class
	this->animalName = animalName;
}

void Animal::SetAnimalType(string animalType) {

	this->animalType = animalType;
}

void Animal::SetAnimalSubType(string animalSubType) {

	this->animalSubType = animalSubType;
}

void Animal::SetAnimalEggs(int numEggs)
{
	this->numEggs = numEggs;
}

void Animal::SetAnimalNurse(int nurse)
{
	this->nurse = nurse;
}





int Animal::GetTrackNumber() {

	return trackNumber;
}

string Animal::GetAnimalName() {

	return animalName;
}

string Animal::GetAnimalType() {     // class getter/accessor fuctions for the animal class.

	return animalType;
}

string Animal::GetAnimalSubType() {

	return animalSubType;
}

const string Animal::ToString(){
	ostringstream buffer;
	
	 buffer << trackNumber << endl   // animal class for when I want to access data of the animal class.
	 << animalName << endl
	 << animalType << endl
	 << animalSubType << endl;

	 return buffer.str();
}



void Animal::PrintAnimal() {

	cout << "| " << setw(6) << setfill('0') << trackNumber << "       | ";
	cout << setw(15) << setfill(' ') << left << animalName << "|";
	cout << setw(15) << setfill(' ') << left << animalType << "|";                     // print animal function to display data.
	cout << setw(15) << setfill(' ') << left << animalSubType << "|" << endl;
	cout << "-------------------------------------------------------------------------------";


}


void Animal::PrintValue() {

	cout << "| " << setw(6) << setfill('0') << GetTrackNumber() << "       | ";
	cout << setw(15) << setfill(' ') << left << GetAnimalName() << "| ";				// print value function to display class values
	cout << setw(15) << setfill(' ') << left << GetAnimalType() << "| ";				// to be used inthe theZoo vector.
	cout << setw(15) << setfill(' ') << left << GetAnimalSubType() << "| ";
	cout << setw(15) << setfill(' ') << left << numEggs << "| ";
	cout << setw(13) << setfill(' ') << left << nurse << "|" << endl;
	cout << "--------------------------------------------";
	cout << "-------------------------------------------------------";

}

 

