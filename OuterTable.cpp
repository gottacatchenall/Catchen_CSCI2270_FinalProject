/*
Name: Michael Catchen
Final Project
CSCI 2270
ID: 103263812
*/

#include "OuterTable.h"
#include <iostream>
using namespace std;

// Constructor
OuterTable::OuterTable(){
	outerTableSize = 10;
}

// Destructor
OuterTable::~OuterTable(){

}

// Calculates hash value for outer hash table
int OuterTable::outerHashValue(std::string x, int s){
	// Initialize val to 0
	int val = 0;

	// From first character in x to next to last character, square ASCII 
	// value of current index and add it to next index squared, and add to value
	for(int i = 0; i < x.length() - 1; i++){
		int temp = (x[i])^2 + (x[i+1])^2;
		val = temp + val;
	}
	// Mod value with table size to give index in hash table
	return val % s;	
}

// Inserts movie into the outer hash table by passing it to appropriate inner table
void OuterTable::insertOuterHash(std::string name, int year){
	// Calculates outer hash value for movie
	int hashVal = outerHashValue(name, outerTableSize);
	// Passes movie info to inner hash table at index of calculated outer hash table value
	outside[hashVal].insertInnerHash(name,year);
}

// Calculates outer hash value for input, then searches inner hash table at 
// that index and outputs found movie
void OuterTable::findOuterMovie(std::string name){
	// Calculates outer hash value for movie
	int hashVal = outerHashValue(name, outerTableSize);
	// Searches inner table at index of outer hash value for the movie
	HashElem *returnVal = outside[hashVal].findInnerMovie(name);

	// If return is not null, then movie was found and outputs data
	if(returnVal != NULL){
		cout << hashVal << ":" << returnVal->title << ":" << returnVal->year << endl;
	}
	else{
		cout << "not found" << endl;
	}
}

// Deletes a movie by finding appropriate inner hash table and then calling method to remove it
void OuterTable::deleteOuterMovie(std::string name){
	// Calculates outer hash value for movie
	int hashVal = outerHashValue(name, outerTableSize);
	// Calls method on inner hash table at appropriate index to delete movie
	outside[hashVal].deleteInnerMovie(name);
}

// Interates through all inner hash tables and calls method to print contents
void OuterTable::printTableContents(){
	for(int i = 0; i < outerTableSize; i++){
		outside[i].printInnerContents();
	}
}

void OuterTable::printAlphabetical(){
	HashElem* head = NULL;

	for(int i = 0; i < outerTableSize; i++){
		head = outside[i].alphabetizeInner(head);
	}

	HashElem *temp = head;
	while(temp != NULL){
		cout << temp->title << endl;
		temp = temp->next;
	}
	// dear god reset the pointers or you're screwed
}


// Iterates through each inner hash table and calls method to delete all contents
void OuterTable::resetTable(){
	for(int i = 0; i < outerTableSize; i++){
		outside[i].resetInnerTable();
	}
}

// Iterates through each inner table and calls method to count collisions, and sums and prints total collisions 
void OuterTable::checkCollisions(){
	int sum = 0;
	for(int i = 0; i < outerTableSize; i++){
		cout << "Outer Hash Value = " << i << ": ";	
		// Stores number of collisions in Val
		int val = outside[i].checkInnerCollisions();
		// Adds val to sum
		sum = sum + val;
 	}
 	// Prints total collisions
 	cout << "Total collisions: " << sum << endl;
}
