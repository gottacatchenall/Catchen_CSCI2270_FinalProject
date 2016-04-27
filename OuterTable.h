/*
Name: Michael Catchen
Final Project
CSCI 2270
ID: 103263812
*/

#ifndef OUTERTABLE_H
#define OUTERTABLE_H
#include <string>
#include "InnerTable.h"
#include <vector>

class OuterTable
{
	public:
		OuterTable();
		~OuterTable();
		void printTableContents();
		void insertOuterHash(std::string name, int year);
		void deleteOuterMovie(std::string name);
		void findOuterMovie(std::string name);
		void printAlphabetical();
		void resetTable();
		void checkCollisions();
		HashElem* addToAlphabeticalLinkedList(HashElem *head, HashElem *newVal);
	private:
		int outerHashValue(std::string x, int s);
		int outerTableSize;
		// Creates an array of type InnerTable with size 10
		InnerTable outside[10];
};

#endif // OUTERTABLE_H
	