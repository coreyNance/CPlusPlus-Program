

// this has been copied over.





#ifndef ANIMAL2_H
#define ANIMAL2_H   // defining the amimal header class


#include <iostream>
#include <string>  // libraries to be used with in animal class
using namespace std;

/* The animal class, which is the parent class to all my other classes.
this class is the top of the triangle then come mammal and oviparous, then
comes each of their child classes.
*/
class Animal {
public:


	void SetTrackNumber(int trackNumber);
	void SetAnimalName(string animalName);  // public setter/mutator functions
	void SetAnimalType(string animalType);
	void SetAnimalSubType(string animalSubType);
	void SetAnimalEggs(int numEggs);
	void SetAnimalNurse(int nurse);

	int GetTrackNumber();
	string GetAnimalName();
	string GetAnimalType();     // public getter/accessor declarations.
	string GetAnimalSubType();

	const string ToString();  // to string and print declarations to allow access to data.
	void PrintAnimal();
	void PrintValue();

	Animal();   // default construter declaration for the amimal class

	Animal(string animalName, int trackNumber); // construter declaration  with animal name and track number.




private:

	string animalType;
	string animalSubType;
	string animalName;    // private variables to be used in the animal class.  
	int trackNumber;
	int nurse;
	int numEggs;



};










#endif // !
