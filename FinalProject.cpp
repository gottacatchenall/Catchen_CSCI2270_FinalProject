/*
Name: Michael Catchen
Final Project
CSCI 2270
ID: 103263812
*/

#include <iostream>
#include "InnerTable.h"
#include "OuterTable.h"
#include <fstream>
#include <sstream>

using namespace std;

// Display Main Menu
int dispMainMenu(){
	int resp = -1;
	// While response isn't a valid option, keep asking
	while(resp != 1 && resp != 2 && resp != 3 && resp != 4 && resp != 5 && resp != 6 && resp != 7 && resp != 8 && resp != 9){
		cout << "======Main Menu======" << endl;
		cout << "1. Insert movie" << endl;
		cout << "2. Delete movie" << endl;
		cout << "3. Find movie" << endl;
		cout << "4. Add movie database to hash table" << endl;
		cout << "5. Print table contents (no order)" << endl;
		cout << "6. Print table contents (alphabetical)" << endl;
		cout << "7. Reset Database" << endl;
		cout << "8. Check Number of Collisions" << endl;
		cout << "9. Quit" << endl; 

		cin >> resp;
	}

	return resp;
}

int main(int argc, char*argv[]){
	int resp = -1;
	// Initialize outer hash table
	OuterTable hash;

	// While response isn't option to quit
	while(resp != 9){
		// Get user input from menu
		resp = dispMainMenu();

		// Insert Movie
		if(resp == 1){
			// Get title
			string title, two;
			cout << "Enter title:" << endl;
			cin >> title;
            getline(cin,two);
            title = title + two;

            // Get Year
            int year;
			cout << "Enter year:" << endl;
			cin >> year;

			// Send to outer hash table to be added
			hash.insertOuterHash(title, year); 
		}

		// Delete Movie
		else if(resp == 2){
			// Get title
			string one, two;
			cout << "Enter title:" << endl;
			cin >> one;
			getline(cin,two);
			one = one + two;
			// Send to outer hash table to delete
			hash.deleteOuterMovie(one);
		}

		// Find Movie
		else if(resp == 3){
			// Get title
			string one, two;
			cout << "Enter title:" << endl;
			cin >> one;
			getline(cin,two);
			one = one + two;

			// Send to outer hash table to be searched for
			hash.findOuterMovie(one);
		}

		// Add movie database to hash table
		else if(resp == 4){
			// Get filename as a command line argument
			string file = argv[1];
			// Initiliaze variables to be used during file parsing
			string line, item, title;
			int year;

			// Create file stream
			ifstream movieFile;
			// Open file
			movieFile.open(file);

			// If file opens successfully...
			if(movieFile.good()){
				// Go line by line in file and store data in string line
				while(getline(movieFile, line)){
					// Initialize item counter to 0
					int counter = 0;
					// Create stringstream from line
					stringstream lineSS(line);

					// Parse line by comma, store in string item
					while(getline(lineSS,item,',')){
						// If counter is 0, item is the title
						if(counter == 0){
							title = item;
						}
						// If counter is 1, item is year
						else if(counter ==1){
							// Convert string to int and store in year
							stringstream tempint(item);
							tempint >> year;
						}
						// Increment Counter
						counter++;
					}
					// Add current line data to outer hash table
					hash.insertOuterHash(title,year);
				}
			}
		}
		else if(resp == 5){
			// Call outer hash table method to print all contents
			hash.printTableContents();
		}
		else if(resp == 6){
			//hash.printAlphabetical();
		}
		else if(resp == 7){
			// Call method on outer hash table to reset all data
			hash.resetTable();
		}
		else if(resp == 8){
			// Call method on outer hash table to display and count collisions
			hash.checkCollisions();
		}

	}
	cout << "Goodbye!" << endl;
	return 0;
}
