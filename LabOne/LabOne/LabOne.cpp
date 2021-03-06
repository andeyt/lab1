// LabOne.cpp : Defines the entry point for the console application.
//
// Code by Jacob Tuttle
// 
// Lab1: Read a file and output specific numbers in it as well as the count of items.

//Includes and header information
#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	//Prompt user for the name of file
	string fileName;
	cout << "Enter the name of a file for processing." << endl;
	cin >> fileName;

	//open file
	fstream file(fileName);

	//check that the file was opened
	if (file.is_open()) {

		//initialize variables
		int count = 0;
		double first = NULL;
		double second = NULL;
		double secondlast = NULL;
		double last = NULL;
		double input;

		//continue reading until the end of the file
		while (!file.eof()) {

			file >> input;

			//this check prevents an of by one error where the last number is read twice
			if (!file.fail()) {

				//update trailing variables
				count++;
				secondlast = last;
				last = input;

				//set second variable only if first is set
				if (second == NULL && first != NULL) {
					second = input;
				}

				//set first var only the first time through
				if (first == NULL) {
					first = input;
				}
			}
		}

		//output results
		cout << "Count: " << count << endl;
		cout << "First Item: " << first << endl;
		cout << "Second Item: " << second << endl;
		cout << "Second Last Item: " << secondlast << endl;
		cout << "Last Item: " << last << endl;

		//pause system to allow results to be viewed
		system("pause");

		file.close();
	}
	else {
		//Run if the file is unable to be opened
		cout << "Unable to open file. Please try again." << endl;
	}

    return 0;
}

