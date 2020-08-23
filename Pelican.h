#ifndef PELICAN_H
#define PELICAN_H						// Defining the header class


#include <iostream>
#include <string>					// Libraries to be used in the whale class with inclusing of Oviparous .h
#include "Oviparous2.h"
using namespace std;


class Pelican : public Oviparous {				// class declaration including inhertance to Oviparous parent class
public:

	const string ToString();						// public  tostring and print declarations.
	void PrintValue();;

private:



};


#endif // !1

