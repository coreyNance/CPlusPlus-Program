
#include <iostream>
#include <vector>
#include <string>     //  libraries to be used in this program.
#include <fstream>

#include "Whale.h" 
#include "SeaLion.h"
#include "Bat.h"
#include "Crocodile.h"    // Include statments to be able to use the information from the child classes.
#include "Goose.h"
#include "Pelican.h"
#include "Oviparous2.h"
#include "Animal2.h"
using namespace std;

//void GenerateData();
void AddAnimal(vector<Animal*>&);
void DisplayMenu(vector<Animal*>&);                 // function declarations so I can store the functions below main.
void SaveDataToFile(ofstream&, vector<Animal*>&);
void RemoveAnimal(vector<Animal*>& theZoo);
void LoadDataFromFile(ifstream& inFS, string &fileNum);


int main()
{
	vector<Animal*> theZoo;  // theZoo vector to store all the aniaml object pointers into

	ofstream zooFile;  // ofstream variable zooFile so that data can be saved to the file for later use.

	int userInput;   //  input variable user Input to be used in this menu.

	ifstream inFS;    // ifstream variable as well as a storage variable to store the strings read from the file.
	string fileNum;    



	/* This first operation is the creation of the user menu.  This menu
	first displays the menu for the user to pick from.  Each menu number is 
	assocatied with a switch statment that then calls a fuction to do 
	what the user is looking to do. */

	cout << "***************** User Menu *****************" << endl;
	cout << "Load Animal Data: 1" << endl;
	cout << "Generate Data: 2" << endl;
	cout << "Display Animal Data: 3" << endl;
	cout << "Add Record: 4" << endl;
	cout << "Delete Record: 5" << endl;
	cout << "Save Animal Data: 6" << endl;



	/* Here is the swicth statment.  This statement has each case linked 
	to a function that it will call based on the user input.  Its also attached to
	a do while statment, so that it can repeat the task until the user enters 7 to quit.*/

	do {

		cout << "Please enter selection or 7 to quit" << endl;
		cin >> userInput;


		switch (userInput) {
		case 1:
			LoadDataFromFile(inFS, fileNum);  // call to fuction to load data from a file.
			break;

		case 2:
			//GenerateData();  // call to function to generate data from the java file.
			break;

		case 3:
			DisplayMenu(theZoo);  // call to fuction to display the information stored in theZoo vector.
			break;

		case 4:
			AddAnimal(theZoo);   // call to the fuction to add each animal to theZoo vector.
			break;

		case 5:
			RemoveAnimal(theZoo);   // call to the fuction to remove animal based on vector location.
			break;

		case 6:
			SaveDataToFile(zooFile, theZoo);  // call to the fuction to be able save the info from theZoo vector to a file.
			break;
		case 7:
			cout << "Program end" << endl;   // statement to end program.
			break;
		default:
			cout << "Error, Please Enter a number from 1-7" << endl; // default statment just incase user enters a wrong number.
			break;
		}
	} while (userInput != 7);

	return 0;

}




/*void GenerateData()               //DO NOT TOUCH CODE IN THIS METHOD
{
	JavaVM* jvm;                      // Pointer to the JVM (Java Virtual Machine)
	JNIEnv* env;                      // Pointer to native interface
															 //================== prepare loading of Java VM ============================
	JavaVMInitArgs vm_args;                        // Initialization arguments
	JavaVMOption* options = new JavaVMOption[1];   // JVM invocation options
	options[0].optionString = (char*)"-Djava.class.path=";   // where to find java .class
	vm_args.version = JNI_VERSION_1_6;             // minimum Java version
	vm_args.nOptions = 1;                          // number of options
	vm_args.options = options;
	vm_args.ignoreUnrecognized = false;     // invalid options make the JVM init fail
																		 //=============== load and initialize Java VM and JNI interface =============
	jint rc = JNI_CreateJavaVM(&jvm, (void**)&env, &vm_args);  // YES !!
	delete options;    // we then no longer need the initialisation options.
	if (rc != JNI_OK) {
		// TO DO: error processing...
		cin.get();
		exit(EXIT_FAILURE);
	}
	//=============== Display JVM version =======================================
	cout << "JVM load succeeded: Version ";
	jint ver = env->GetVersion();
	cout << ((ver >> 16) & 0x0f) << "." << (ver & 0x0f) << endl;

	jclass cls2 = env->FindClass("ZooFileWriter");  // try to find the class
	if (cls2 == nullptr) {
		cerr << "ERROR: class not found !";
	}
	else {                                  // if class found, continue
		cout << "Class MyTest found" << endl;
		jmethodID mid = env->GetStaticMethodID(cls2, "createZooFile", "()V");  // find method
		if (mid == nullptr)
			cerr << "ERROR: method void createZooFile() not found !" << endl;
		else {
			env->CallStaticVoidMethod(cls2, mid);                      // call method
			cout << endl;
		}
	}


	jvm->DestroyJavaVM();
	cin.get();
}*/
		

/* The AddAnimal function, this was one of the hardest functions to make.  
This is the fuction that is called when user picks add record.  Within this fuction,
the user input is recorded, then stored into the child class that is picked. Then a pointer is 
stored in the vector that points towards the print fuction of that child class.*/

void AddAnimal(vector<Animal*>& theZoo)
{


	unsigned int i;
	int trackNumber, eggs;
	string animalName, animalType, animalSubType;  // instance variables to be used in this function.
	int nurse;
	char userInput;

	Animal* AnimalPtr = nullptr;
	Mammal* MammalPtr = nullptr;
	Oviparous* OviparousPtr = nullptr;  // pointer creations to be used for the vector.
	Bat* BatPtr = nullptr;
	Crocodile* CrocodilePtr = nullptr;
	Goose* GoosePtr = nullptr;
	Pelican* PelicanPtr = nullptr;
	SeaLion* SeaLionPtr = nullptr;
	Whale* WhalePtr = nullptr;



	/* Here is a series of do while loops and try catch statements to make sure 
	user input follows the guidelines requested by the client.  The try/catch catches the 
	problem and the do while loop keeps looping until the correct input in put in.*/

	do {
		do {
			try {
				cout << "Track Number:" << endl;
				cin >> trackNumber;
				cin.ignore();									// checks trackNumber to make sure its not a negative number and its 6 digits.
				if ((trackNumber < 0) || (trackNumber > 1000000)) { // or less.
					throw runtime_error("Input Please enter postive number no more than 6 digits");
				}
			}
			catch (runtime_error& excpt) {				
				cout << excpt.what() << endl;   
				cout << "Enter new value." << endl;    
			}
		} while ((trackNumber < 0) || (trackNumber > 1000000));   // while loop to keep doing task until proper input is entered.

		do {
			try {
				cout << "Animal Name:" << endl;
				getline(cin, animalName);
				//cin.ignore();
				if (animalName.length() > 15) {
					throw runtime_error("Input has two many Characters.");
				}
			}																	// try/ catch to make sure input doesnt exceed 15 characters
			catch (runtime_error& excpt) {									
				cout << excpt.what() << endl;
				cout << "Enter name no more than 15 characters including spaces." << endl;
			}
		} while (animalName.length() > 15);						// While loop to keep asking until character count is 15 or less

		do {
			try {
				cout << "Number of Eggs:" << endl;
				cin >> eggs;
				cin.ignore();
				if (eggs < 0) {							// try/catch to make sure number entered isnt less than 0
					throw runtime_error("Input Error");
				}
			}
			catch (runtime_error& excpt) {
				cout << excpt.what() << endl;
				cout << "Please Enter a number 0 or greater." << endl;
			}
		} while (eggs < 0);								// while loop to keep asking while input is less than 0

		do {
			try {
				cout << "Enter 1 if Nursing, 0 if not:" << endl;
				cin >> nurse;
				cin.ignore();
				if ((nurse > 1) || (nurse < 0)) {
					throw runtime_error("Input Error");
				}													// try/catch to make sure input is only 1 or 0
			}
			catch (runtime_error& excpt) {
				cout << excpt.what() << endl;
				cout << "Please enter 1 if nursing, 0 if not." << endl;
			}
		} while ((nurse > 1) || (nurse < 0));					// while loop to keep asking until input is either 1 or 0

		do {
			try {
				cout << "Animal Type Mammal or Oviparous:" << endl;
				cin >> animalType;
				cin.ignore();
				if ((animalType != "Oviparous") && (animalType != "oviparous") &&
					(animalType != "Mammal") && (animalType != "mammal")) {
					throw runtime_error("Input Error");
				}
			}																// try catch to make sure only one of two animal types are entered.
			catch (runtime_error& excpt) {
				cout << excpt.what() << endl;
				cout << "Please enterr Mammal or Oviparous only." << endl;
			}
		} while ((animalType != "Oviparous") && (animalType != "oviparous") &&  // while loop to keep asking until proper input is entered.
			(animalType != "Mammal") && (animalType != "mammal"));



		/*  This next really huge code is how the program decides which class to use. 
		First based on animal type, the program will either go to Oviparous or 
		Mammal.  Then within those if statements, I put in another nested if statement while
		do a try/catch to make sure user inputs are valid.  from there based on user input 
		the program will either print Crocodile, Goose or Pelican, or Bat, Whale, or SealLion.
		Once that is picked then the program sets the Pointer to set the name, track number 
		as well as nursing or if it has eggs or not.*/

		if ((animalType == "Oviparous") || (animalType == "oviparous")) {

			do {
				try {
					cout << "Animal Sub-type Crocodile, Goose, or Pelican:" << endl;
					cin >> animalSubType;
					cin.ignore();														// try catch to make sure one of three subtypes are entered.
					if ((animalSubType != "Crocodile") && (animalSubType != "crocodile") &&
						(animalSubType != "Goose") && (animalSubType != "goose") &&
						(animalSubType != "Pelican") && (animalSubType != "pelican")) {
						throw runtime_error("Input Error");
					}
				}
				catch (runtime_error& excpt) {
					cout << excpt.what() << endl;
					cout << "Please enter Crocodile, Goose, or Pelican. " << endl;
				}
			} while ((animalSubType != "Crocodile") && (animalSubType != "crocodile") &&
				(animalSubType != "Goose") && (animalSubType != "goose") &&        // while loop to keep asking until proper input is entered.
				(animalSubType != "Pelican") && (animalSubType != "pelican"));
		
			if ((animalSubType == "Crocodile") || (animalSubType == "crocodile")) {
				CrocodilePtr = new Crocodile();
				CrocodilePtr->SetAnimalName(animalName);
				CrocodilePtr->SetTrackNumber(trackNumber);
				CrocodilePtr->SetAnimalType(animalType);      // if statement to set Pointer to crocodile class based on inputs from user.
				CrocodilePtr->SetAnimalSubType(animalSubType);
				CrocodilePtr->SetNurse(nurse);
				CrocodilePtr->SetEggs(eggs);
				theZoo.push_back(CrocodilePtr);
			}
			else if ((animalSubType == "Goose") || (animalSubType == "goose")) {
				GoosePtr = new Goose();
				GoosePtr->SetAnimalName(animalName);
				GoosePtr->SetTrackNumber(trackNumber);
				GoosePtr->SetAnimalType(animalType);
				GoosePtr->SetAnimalSubType(animalSubType);   // if/else statment to set Pointer to goose class based on inputs from user
				GoosePtr->SetNurse(nurse);
				GoosePtr->SetEggs(eggs);
				theZoo.push_back(GoosePtr);
			}
			else if ((animalSubType == "Pelican") || (animalSubType == "pelican")) {
				PelicanPtr = new Pelican();
				PelicanPtr->SetAnimalName(animalName);
				PelicanPtr->SetTrackNumber(trackNumber);     // if/else statement to set Pointer to Pelican class based on inputs from user.
				PelicanPtr->SetAnimalType(animalType);
				PelicanPtr->SetAnimalSubType(animalSubType);
				PelicanPtr->SetNurse(nurse);
				PelicanPtr->SetEggs(eggs);
				theZoo.push_back(PelicanPtr);
			}
			else {
				cout << "Animal not one of three." << endl;  // else statement incase input isnt one of the three.
			}

		}
		else if ((animalType == "Mammal") || (animalType == "mammal")) {
			eggs = 0;													// here eggs is set to 0 no matter what is entered.
																		// because mammals dont lay eggs.
			do {
				try {
					cout << "Animal Sub-type Bat, Whale, or SeaLion:" << endl;
					cin >> animalSubType;
					cin.ignore();												// another try/catch to validate user input.
					if ((animalSubType != "Bat") && (animalSubType != "bat") &&
						(animalSubType != "Whale") && (animalSubType != "whale") &&
						(animalSubType != "SeaLion") && (animalSubType != "seaLion") &&
						(animalSubType != "Sealion") && (animalSubType != "sealion")) {
						throw runtime_error("Input Error");
					}
				}
				catch (runtime_error& excpt) {
					cout << excpt.what() << endl;
					cout << "Please enter Bat, Whale, or SeaLion. " << endl;
				}
			} while ((animalSubType != "Bat") && (animalSubType != "bat") &&  // while loop set to keep going until proper input is entered.
				(animalSubType != "Whale") && (animalSubType != "whale") &&
				(animalSubType != "SeaLion") && (animalSubType != "seaLion") &&
				(animalSubType != "Sealion") && (animalSubType != "sealion"));


				if ((animalSubType == "Bat") || (animalSubType == "bat")) {
				BatPtr = new Bat();
				BatPtr->SetAnimalName(animalName);
				BatPtr->SetTrackNumber(trackNumber);					// if bat is selected this is setting the Bat pointer to class functions.
				BatPtr->SetAnimalType(animalType);
				BatPtr->SetAnimalSubType(animalSubType);
				BatPtr->SetNurse(nurse);
				theZoo.push_back(BatPtr);
			}
			else if ((animalSubType == "Whale") || (animalSubType == "whale")) {
				WhalePtr = new Whale();
				WhalePtr->SetAnimalName(animalName);
				WhalePtr->SetTrackNumber(trackNumber);						// setting pointer to whale class if whale is selected.
				WhalePtr->SetAnimalType(animalType);
				WhalePtr->SetAnimalSubType(animalSubType);
				WhalePtr->SetNurse(nurse);
				theZoo.push_back(WhalePtr);
			}
			else if ((animalSubType == "SeaLion") || (animalSubType == "seaLion")) {
				SeaLionPtr = new SeaLion();
				SeaLionPtr->SetAnimalName(animalName);
				SeaLionPtr->SetTrackNumber(trackNumber);					// setting pointer to SeaLion class is SeaLion is selected.
				SeaLionPtr->SetAnimalType(animalType);
				SeaLionPtr->SetAnimalSubType(animalSubType);
				SeaLionPtr->SetNurse(nurse);
				theZoo.push_back(SeaLionPtr);
			}
			else {
				cout << "Animal not one of three." << endl;
			}
		}
		else {
			cout << "Animal Type not found" << endl;   // output statements within else statemets to let the user know they need to enter 
													   //something different
		}


		cout << endl;

		cout << "Enter Y to continue or any other key to cancel" << endl;  // asking user if they want to keep going.
		cin >> userInput;

	} while ((userInput == 'y') || (userInput == 'Y')); // while loop to keep going while user enters y

}

	

/* This function first takes input from theZoo vector and then outputs the vector elements
to the console.
*/
void DisplayMenu(vector<Animal*>& theZoo) {
	int i; // variable to be used by the for loop


	// output statments to create the header menu.
	cout << "---------------------------------------------------------------------------------------------------" << endl;
	cout << "| Track #      | Name           | Type           | Sub-type       | Eggs           | Nurse        |" << endl;
	cout << "---------------------------------------------------------------------------------------------------" << endl;


	for (i = 0; i < theZoo.size(); ++i) {
		theZoo.at(i)->PrintValue(); // for loop to retrieve the values from the vector pointers.
		cout << endl;
	}

}

/*This funcion is used to save data to a file.
I have zooFile as well as theZoo vector as parameters.*/
void SaveDataToFile(ofstream& zooFile, vector<Animal*>& theZoo) {

	zooFile.open("zooFile.txt");
												// if statement to check and make sure the file is open
	if (!zooFile.is_open()) {
		cout << "Could not open file myoutfile.txt." << endl;

	}
	for (int i = 0; i < theZoo.size(); i++) {		// for loop to loop through vector elements and write to a file.
		zooFile << theZoo.at(i)->ToString() << endl;
			}

	zooFile.close(); // to close the file after program is done writing to it.
}


/* this fucntion allows for elements to be deleted from the vector.
With vector theZoo as a parameter.*/
void RemoveAnimal(vector<Animal*>& theZoo)
{
	int animalCount; // variables to be used in this function.
	int element;

	animalCount = theZoo.size();
	if (animalCount > 0) {
		cout << "Enter Track Number to be deleted (0-" << (animalCount - 1) <<  // if statement to check is vector size is greater than 0.
			", or -1 to skip deletion: ";
		cin >> element;							// user input to delete contents from vector element.
		if (element >= 0) {
			theZoo.erase(theZoo.begin() + element);
			cout << "Entry #" << element << " deleted." << endl;
		}
	}
	else {
		cout << endl << "There are no entries to delete." << endl;  // statement if vector is empty.
	}
}

	

	
	/* this function loads data from a file 
	which inFS and fileNum are arguments to be used in the function.*/
	void LoadDataFromFile(ifstream &inFS, string &fileNum) {



		cout << "Opening file zooFile.txt." << endl;
		inFS.open("zooFile.txt");					// method to open file
													
		if (!inFS.is_open()) {							// to check if file is open
			cout << "Could not open file myfile.txt." << endl;
			
		}

		
		cout << "Reading and printing numbers." << endl;

		while (!inFS.eof()) {
			inFS >> fileNum;						// while loop to output file infomation until it reaches the end.
			if (!inFS.fail()) {
				cout << "num: " << fileNum << endl;
			}
		}

		cout << "Closing file zooFile.txt." << endl;

		
		inFS.close();							// method to close the file.


		

	}



	
	

