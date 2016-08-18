/*
	Main.cpp
	This is the main interface for the application.
*/

#include <iostream>
#include <fstream>
#include "Markov.h"
#include "Utility.h"

using namespace std;

int main(int argc, char ** argv) 
{
	if (argc < 2) 
	{
		// Insufficient arguments
		cout << "Usage: ./main + <filename>";
		return 1;
	}

	cout << "Howdy!" << endl;
	cout << "The file input was " << argv[1] << ".\n" << endl;
	string filename = argv[1];

	// Read file
	ifstream infile;
	infile.open(filename);
	// http://stackoverflow.com/a/2602060/5415895
	string str((istreambuf_iterator<char>(infile)), istreambuf_iterator<char>());
	//cout << str;

	matt::Markov mark = matt::Markov(str,1);
	cout << mark.generate() << endl;
}