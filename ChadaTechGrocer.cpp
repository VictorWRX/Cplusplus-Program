#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <map>
using namespace std;


/*
* Victor Gomez
* Assignment: Project 3 Chada Tech
* 02/19/2023
* Instructor Cemal Tepe
*/



int main() {

	// Variables
	list<string> foods;
	map<string, int> groceryList;
	map<string, string> groceryListHistogram;
	string food;
	ifstream inFS;
	ofstream outFS;
	string input;
	int n = 0;
	char q = 'c';
	int menuOpt = 0;
	map<string, int>::iterator it;
	map<string, string>::iterator it1;


	// Opening file CS210_Project_Three_Input_File.txt
	cout << "Opening file CS210_Project_Three_Input_File.txt" << endl;
	inFS.open("CS210_Project_Three_Input_File.txt");

	// If could not open file error message
	if (!inFS.is_open()) {
		cout << "Could not open file CS210_Project_Three_Input_File.txt" << endl;
		return 1;
	}

	// while loop to read and push back names of food
	// to there vectors and store them for later
	while (!inFS.eof()) {
		inFS >> food;
		foods.push_back(food);


	}

	// Close file CS210_Project_Three_Input_File.txt
	inFS.close();

	// for each loop that goes through and adds to the value of the key if another key found
	for (string& foodName : foods) {

		it = groceryList.find(foodName);

		if (it != groceryList.end()) {
			it->second++;
		}

		else {
			groceryList.insert(make_pair(foodName, 1));
		}
	}

	//Open and create new file frequency.dat
	outFS.open("frequency.dat");

	// If could not create file error message
	if (!outFS.is_open()) {
		cout << "Could not creat file frequency.dat" << endl;
		return 1;
	}

	// for loop to take what is in the map
	// and output on frequency.dat
	for (it = groceryList.begin(); it != groceryList.end(); ++it)
	{
		outFS << it->first << " " << groceryList.at(it->first) << endl;
	}

	// close the file after writing all the data
	outFS.close();

	cout << "MENU:" << endl;
	cout << "Option 1 (Enter item name and get quantity in list)" << endl;
	cout << "Option 2 (List with amount of item in list)" << endl;
	cout << "Option 3 (histogram of grocery list)" << endl;
	cout << "Option 4 (Quit)" << endl;

	// While menu loop
	while (q != 'q') {

		cout << endl;
		cout << "Please enter the number of the Option you wish to use. (Example 1, 2, 3, or 4)" << endl;
		cin >> menuOpt;
		cout << endl;
		// Option 1
		if (menuOpt == 1) {
			
			//Input what key you wish to look up
			//Outputs value in gorceryList map
			cout << "Please enter an item to look up:" << endl;
			cin >> input;
			cout << endl << groceryList.at(input) << endl;

		}
		//Option 2
		else if (menuOpt == 2) {

			// for loop that outputs map key and value
			for (it = groceryList.begin(); it != groceryList.end(); ++it)
			{
				cout << it->first << " " << groceryList.at(it->first) << endl;
			}
		}
		//Option 3
		else if (menuOpt == 3) {

			// for each loop that goes through and adds '*' to the value of the key when same key found
			for (string& foodName : foods) {

				it1 = groceryListHistogram.find(foodName);

				if (it1 != groceryListHistogram.end()) {
					it1->second += "*";
				}

				else {
					groceryListHistogram.insert(make_pair(foodName, "*"));
				}
			}

			// Output groceryListHistogram map with for loop
			for (it1 = groceryListHistogram.begin(); it1 != groceryListHistogram.end(); ++it1)
			{
				cout << it1->first << " " << groceryListHistogram.at(it1->first) << endl;
			}

		}
		//Option 4
		else if (menuOpt == 4) {

			//Quits program and says Bye!!!
			cout << "BYE!!!" << endl;
			q = 'q';
		}
		//Error, if wrong int put in
		else if (menuOpt <= 0 || menuOpt >= 5) {
			cout << "Please Enter a valid option." << endl;
		}


	}

	return 0;
}