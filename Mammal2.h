

// this has been copied over



#ifndef MAMMAL2_H
#define MAMMAL2_H					// defining the mammal class header file

#include "Animal2.h"				// library inclusion of the parent class.

class Mammal : public Animal {     // class declaration including inhertance to animal parent class

public:

	void SetEggs(int numEggs);
	int GetEggs();
	void SetNurse(int nurse);   // public setter/accessor and getter/mutator declarations.
	int GetNurse();

	const string ToString();  // public  tostring and print mammal declarations.
	void PrintMammal();



	int nurse;
	int numEggs;  // private variables that are needed to use in the toString.


};







#endif // !MAMMAL_H


