# Catchen_CSCI2270_FinalProject

#Project Summary
I made an extension to assignment 12 that implements more functionality into the hash table we already built. I changed the hash table we made into a 'hash table of hash tables', which uses two different hash functions to put a movie in a location, thus reducing the number of collisions. This project includes new methods to print out all items in the hash table alphabetically, as well as load in data from a movie database textfile. It also includes methods to reset the database by deleting all items from it, and a way to view new the number of collisions in the table.

# Running this project
This project can be run by downloading the following files: FinalProject.cpp, InnerTable.h, InnerTable.cpp, OuterTable.h, OuterTable.cpp, and movieList.txt. These files should be compiled and the program should then be run with the commandline argument 'movieList.txt'.

An example of compiling with G++ and running the code in Linux would be the following:
  $ g++ FinalProject.cpp InnerTable.h InnerTable.cpp OuterTable.h OuterTable.cpp
  $ ./a.out movieList.txt

Once the program is running a main menu appears which gives the user various options.

# Dependencies 
This program requires a text file with the same formatting as movieList.txt as a command argument in order to load movies from a database (Menu option 4). Otherwise, this requires no dependencies.

#System Requirements

This program will work on Linux Ubuntu or xubuntu, or Macintosh (Basically any UNIX based OS).

#Group Members
Just myself.

#Contributors
Connor Ott gave me the idea of using a linked list to alphabetize the movies.

#Open Issues/Bugs
None at this time.

