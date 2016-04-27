/*
Name: Michael Catchen
Assignment: 12
CSCI 2270
ID: 103263812
*/

#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <string>
#include <vector>

struct HashElem{
	std::string title;
	int year;
	

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

class HashTable
{
	public:
		HashTable();
		~HashTable();
		void printTableContents();
		void setNull();
		void insertMovie(std::string name, int year);
		void deleteMovie(std::string name);
		void findMovie(std::string name);
	private:
		int hashSum(std::string x, int s);
		int tableSize = 10;
		TableElem hashTable[10];

};

#endif // HASHTABLE_H
	