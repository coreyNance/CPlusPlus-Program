


// this has been copied



#include <iostream>
#include <string>
#include <sstream>
using namespace std;			// Library inclusions to be used in the child class including .h file
#include "SeaLion.h"
#include <iomanip>




const string SeaLion::ToString() {
	ostringstream buffer;
	buffer << GetTrackNumber() << endl
		<< GetAnimalName() << endl					// to string function to so that child class data can be accessed easier.
		<< GetAnimalType() << endl
		<< GetAnimalSubType() << endl
		<< GetEggs() << endl
		<< GetNurse() << endl;

	return buffer.str();
}


void SeaLion::PrintValue() {

	cout << "| " << setw(6) << setfill('0') << GetTrackNumber() << "       | ";
	cout << setw(15) << setfill(' ') << left << GetAnimalName() << "| ";
	cout << setw(15) << setfill(' ') << left << GetAnimalType() << "| ";			// print value function to display class values 
	cout << setw(15) << setfill(' ') << left << GetAnimalSubType() << "| ";			// to be used inthe theZoo vector.
	cout << setw(15) << setfill(' ') << left << GetEggs() << "| ";
	cout << setw(13) << setfill(' ') << left << GetNurse() << "|" << endl;
	cout << "--------------------------------------------";
	cout << "-------------------------------------------------------";

}

