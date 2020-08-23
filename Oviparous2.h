#ifndef OVIPAROUS2_H
#define OVIPAROUS2_H					// defining the Oviparous class header file



// this has been copied over




#include "Animal2.h"						// library inclusion of the parent class.


class Oviparous : public Animal {			// class declaration including inhertance to animal parent class

public:

	void SetEggs(int numEggs);
	int GetEggs();									// public setter/accessor and getter/mutator declarations.
	void SetNurse(int nurse);
	int GetNurse();

	const string ToString();				// public  tostring and print Oviparous declarations.
	void PrintOviparous();

private:
	int numEggs;			// private variables that are needed to use in the toString.
	int nurse;


};



#endif


