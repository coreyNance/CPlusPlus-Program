

// this has been copied


#include <iostream>
#include <string>
#include <sstream>				// Library inclusions to be used in the child class including .h file
#include <iomanip>
using namespace std;
#include "Bat.h"




const string Bat::ToString() {
	ostringstream buffer;
	buffer << GetTrackNumber() << endl
	<< GetAnimalName() << endl
	<< GetAnimalType() << endl						// to string function to so that child class data can be accessed easier.
	<< GetAnimalSubType() << endl
	<< GetEggs() << endl
	<< GetNurse() << endl;

	return buffer.str();
}


void Bat:: PrintValue() {

	cout << "| " << setw(6) << setfill('0') << GetTrackNumber() << "       | ";
	cout << setw(15) << setfill(' ') << left << GetAnimalName() << "| ";				// print value function to display class values
	cout << setw(15) << setfill(' ') << left << GetAnimalType() << "| ";				// to be used inthe theZoo vector.
	cout << setw(15) << setfill(' ') << left << GetAnimalSubType() << "| ";
	cout << setw(15) << setfill(' ') << left << GetEggs() << "| ";
	cout << setw(13) << setfill(' ') << left << GetNurse() << "|" << endl;
	cout << "--------------------------------------------";
	cout << "-------------------------------------------------------";

}

