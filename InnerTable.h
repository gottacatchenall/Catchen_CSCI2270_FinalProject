/*
Name: Michael Catchen
Final Project
CSCI 2270
ID: 103263812
*/

#ifndef INNERTABLE_H
#define INNERTABLE_H
#include <string>
#include <vector>

struct HashElem{
	std::string title;
	int year;
	// This pointer is used to alphabetizing the table, not for connecting elements in same array position
	HashElem *next;

	HashElem(){};
	HashElem(std::string in_title, int in_year)
	{
		title = in_title;
		year = in_year;
	}
};

struct TableElem{
	std::vector<HashElem*> list;
};

class InnerTable
{
	public:
		InnerTable();
		~InnerTable(); 
		void insertInnerHash(std::string name, int year);
		HashElem *findInnerMovie(std::string name);
		void deleteInnerMovie(std::string name);
		void printInnerContents();
		HashElem* alphabetizeInner(HashElem *head);
		void resetInnerTable();
		int checkInnerCollisions();
	private:
		int innerHashValue(std::string x, int s);
		int innerTableSize;
		// Creates array of size 10 of TableElem's, each of which 
		// contain a vector that holds HashElem's 
		TableElem inside[10];

};

#endif // INNERTABLE_H
	