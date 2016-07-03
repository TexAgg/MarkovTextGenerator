#include <iostream>
#include <fstream>
#include "Markov.h"

using namespace std;

int main(int argc, char ** argv) 
{
	cout << "Howdy" << endl;
	cout << "The file input was " << argv[1] << ".\n" << endl;
	string filename = argv[1];

	// Read file
	ifstream infile;
	infile.open(filename);
	// http://stackoverflow.com/a/2602060/5415895
	string str((istreambuf_iterator<char>(infile)), istreambuf_iterator<char>());
	cout << str;

	matt::Markov mark = matt::Markov(str);
}