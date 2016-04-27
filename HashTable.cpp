/*
Name: Michael Catchen
Assignment: 12
CSCI 2270
ID: 103263812
*/

#include "HashTable.h"
#include <iostream>
using namespace std;

HashTable::HashTable(){

}
HashTable::~HashTable(){

}

int HashTable::hashSum(std::string x, int s){
	int sum = 0;
	for(int i = 0; i < x.length(); i++){
		sum = sum + x[i];
	}
	return sum % s;
}

void HashTable::insertMovie(std::string name, int year){
	int hashVal = hashSum(name, tableSize);

	HashElem *newval = new HashElem;
	newval->title = name;
	newval->year = year;

	hashTable[hashVal].list.push_back(newval);	
}	

void HashTable::deleteMovie(std::string name){
	int hashVal = hashSum(name, tableSize);
	bool found = false;
	for(int i = 0; i < hashTable[hashVal].list.size(); i++){
		if(name == hashTable[hashVal].list[i]->title){
			hashTable[hashVal].list.erase(hashTable[hashVal].	list.begin()+i);
			found = true;
			break;
		}
	}
	if(!found){
		cout << "not found" << endl;
	}

}

void HashTable::findMovie(std::string name){
	int hashVal = hashSum(name, tableSize);
	bool found = false;
	
	for(int j = 0; j < hashTable[hashVal].list.size(); j++){
		if(hashTable[hashVal].list[j]->title == name){
			cout << hashVal << ":" << hashTable[hashVal].list[j]->title << ":" << hashTable[hashVal].list[j]->year << endl;
			found = true;
		}
	}

	if(!found){
		cout << "not found" << endl;
	}
}

void HashTable::printTableContents(){
	bool empty = true;
	for(int i = 0; i < tableSize; i++){
		if(hashTable[i].list.empty() == false){
			empty = false;
			break;
		}
	}

	if(empty){
		cout << "empty" << endl;
	}

	else{
		for(int i = 0; i < tableSize; i++){
			for(int j = 0; j < hashTable[i].list.size(); j++){
				cout << hashTable[i].list[j]->title << ":" << hashTable[i].list[j]->year << endl;
			}
		}
	}	

}

