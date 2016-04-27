/*
Name: Michael Catchen
Final Project
CSCI 2270
ID: 103263812
*/

#include "InnerTable.h"
#include <iostream>
#include <sstream>
using namespace std;

// Constructor
InnerTable::InnerTable(){
	innerTableSize = 10;
}

// Destructor
InnerTable::~InnerTable(){

}

// Calculates the hash value for the inner hash tables
int InnerTable::innerHashValue(std::string x, int s){
	// Initialize sum to zero and sum up ASCII values of each character in x
	int sum = 0;
	for(int i = 0; i < x.length(); i++){
		sum = sum + x[i];
	}
	// Mod sum by table size to get array index
	return sum % s;
}

// Inserts a value into the inner Hash Table by making a new HashElem and adding it to the vector at that index
void InnerTable::insertInnerHash(std::string name, int year){
	// Calculate inner hash value
	int innerHashVal = innerHashValue(name, innerTableSize);
	// Make new HashElem
	HashElem *newval = new HashElem;
	newval->title = name;
	newval->year = year;
	// Add new HashElem to vector
	inside[innerHashVal].list.push_back(newval);
}

// Find a movie within inner hash table
HashElem* InnerTable::findInnerMovie(std::string name){
	// Calculate inner hash table value
	int innerHashVal = innerHashValue(name,innerTableSize);
	// Iterate through vector at index of innerHashVal, and return HashElem when item with same name as search value is found
	for(int j =0; j < inside[innerHashVal].list.size(); j++){
		if(inside[innerHashVal].list[j]->title == name){
			cout << innerHashVal << ":";
			return inside[innerHashVal].list[j];
		}
	}
	// Only returns NULL if nothing is found
	return NULL;

}

// Deletes a movie from an inner hash table
void InnerTable::deleteInnerMovie(std::string name){
	// Calculate inner hash table hash value
	int innerHashVal = innerHashValue(name,innerTableSize);
	// Set boolean flag to false
	int found = false;

	// Iterate through vector at index of innerHashValue, and if item with same name as delete value is found, delete it
	for(int j =0; j < inside[innerHashVal].list.size(); j++){
		if(inside[innerHashVal].list[j]->title == name){
			inside[innerHashVal].list.erase(inside[innerHashVal].list.begin()+j);
			found = true;
		}
	}
	// If found is never set to true, value was never found so print error
	if(found == false){
		cout << "not found" << endl;
	}
}

// Prints inner hash table contents by iterating through vector at appropriate index
void InnerTable::printInnerContents(){
	// Iterates through entire inner table
	for(int i = 0; i < innerTableSize; i++){
		// If vector at index is not empty...
		if(!inside[i].list.empty()){
			// Iterate through vector and print contents
			for(int j = 0; j < inside[i].list.size(); j++){
				cout << inside[i].list[j]->title << ":" << inside[i].list[j]->year << endl;
			}
		}
	}	
}

// Returns TableElem at given index
TableElem* InnerTable::alphabetizeInner(int j){
	return &inside[j];
}

// Resets next pointers of each element in tree
void InnerTable::resetNextPointers(){
	for(int i = 0; i < innerTableSize; i++){
		// If vector at index is not empty...
		if(!inside[i].list.empty()){
			// Iterate through vector and reset pointer
			for(int j = 0; j < inside[i].list.size(); j++){
				inside[i].list[j]->next = NULL;
			}
		}
	}	
}

// Returns size of inner table
int InnerTable::getInnerTableSize(){
	return innerTableSize;
}

// Iterates through inner table and clears the vector at every index
void InnerTable::resetInnerTable(){
	for(int i=0; i< innerTableSize; i++){
		// Delete all items from vector
		inside[i].list.clear();
	}
}

// Prints out list of number of items at each index in inner array
int InnerTable::checkInnerCollisions(){
	cout << " [";
	int innersum = 0;

	// Iterates through entire inner table
	for(int i=0; i < innerTableSize; i++){
		// If list is non-empty
		if(inside[i].list.size() > 0){
			// Calculates number of collisions at index
			// (Subtracts one because one item alone is not a collision)
			innersum = (inside[i].list.size()-1) + innersum;
		}

		// Prints number of items in vector at index
		// If-Else is for formatting only
		if(i == innerTableSize-1){
			cout << inside[i].list.size();
		}
		else{
			cout << inside[i].list.size() << ",";
		}
	}
	cout << "]" << endl;
	// Returns number of collisions
	return innersum;
}
