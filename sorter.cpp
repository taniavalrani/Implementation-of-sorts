

#include <iostream>
#include <vector>
#include <fstream>
#include <sortAlgs.h>
#include <string>

using namespace std;

// declaration for function to validate the command line 
bool validate(string algo, string output);
int main(int argc, char *argv[])
{
	// all the function declarations that are used in main
	vector<int> myVector;
	string to_sort;
	int convert;
	string algo;
	string output;
	string filename;
	unsigned int size;
	bool run;
	// if there aren't enough or too many command line arguments
	// we know that program can't run
	if((argc < 3) or (argc > 4))
	{
		run = false;
	}
	// if the number of command line arguments are right we need to
	// check if the arguments are valid
	else
	{
		algo = argv[1];
		output = argv[2];
		run = validate(algo, output);
	}
	// error message if program can't start
	// exits program
	if(run == false)
	{
		cerr << "Usage: sorter sortAlg outputMode [filename]" << endl;
		cerr << "where: sortAlg is -s1, -s2, or -s3" << endl;
		cerr << "and outputMode is --print or --save" << endl;
		exit(1);
	}
	// if there are four arguements and we are running to program
	// we know the fourth argument is a file name, so we need to
	// open the file
	if((argc == 4) and (run == true))
	{
		// file i/o to open to file
		filename = argv[3];
		ifstream infile;
		infile.open(filename);
		if(infile.fail())
		{
			cerr << "Cannot open " << filename << endl;
			exit(1);
		}
		
		// convert from string to int and put it into vector
		while(getline(infile, to_sort))
		{
			convert = stoi(to_sort);
			myVector.push_back(convert);
		}
		infile.close();
	}
	// otherwise take input from cin
	else
	{
		filename = "cin";
		// while not at the end of file, read from cin
		// convert to an int, and put it into the vector
		while(!cin.eof())
		{
			getline(cin, to_sort);
			if(cin.eof())
			{
				break;
			}
			convert = stoi(to_sort);
			myVector.push_back(convert);
		}
	}
	// check the size of the vector
	size = myVector.size();

	// depending on what algorithm the user specifies
	// call the relevant sort
	if(algo == "-s1")
	{
		insertionSort(myVector);
	}
	else if(algo == "-s2")
	{
		mergeSort(myVector);
	}
	else
	{
		quickSort(myVector);
	}

	// depending on what output mode the user specifies
	// uses the specified output method.
	if(output == "--print")
	{
		// iterated through vector and prints each element
		// on a new line
		for(unsigned int i = 0; i < size; i++)
		{
			cout << myVector[i] << endl;
		}
	}
	if(output == "--save")
	{
		
		// cast the unsigned in to a signed int
		int signedSize = (int) size;
		// change the int to a string so i can concatenate 
		// for the file name
		string size_string = to_string(signedSize);
		// create a new file name
		string new_filename = filename + "_" + algo + 
		"_" + size_string + "_sorted";
		// create new file
		ofstream outf(new_filename);
		// checks if creating it failed
		if(outf.fail())
		{
			exit(1);
		}
		// writes to the file
		for(unsigned int i = 0; i < size; i++)
		{
			outf << myVector[i] << endl;
		}
		outf.close();
	}

	
}

// function to check if command line arguments are valid
bool validate(string algo, string output)
{
	if((algo == "-s1") or (algo == "-s2") or (algo == "-s3"))
	{
		if((output == "--print") or (output == "--save"))
		{
			return true;
		}
	}
	return false;
	
	
}