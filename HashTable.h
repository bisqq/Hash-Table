#pragma once

#include <iostream>
#include <string>

using std::string;

class HashTable
{
public:
	//default constructor
	//init the hash table and private variables
	HashTable();

	//constructor
	//creates a hash table to store n items where the value of n is given by the constructor's single integer parameter
	HashTable(int nItems);
	
	//copy constructor
	//creates a deep copy of its HashTable reference parameter
	HashTable(const HashTable& copyHash);

	//destructor
	//de-allocates any dynamic memory
	~HashTable();

	//operator=
	//makes the calling object a deep copy of its HashTable reference parameter
	HashTable& operator=(const HashTable& copyHash);

	//insert
	//inserts a string into the hashtable
	void insert(string strValue);

	//find
	//returns true if its string parameter is in the hash table, returns false if it is not
	bool find(string strValue) const;

	//size
	//returns the number of items stored in the hash table
	int size() const;

	//maxSize
	//returns the size of the hash table’s underlying array
	int maxSize() const;

	//loadfactor
	//returns the load factor of the hash table as a double
	double loadFactor() const;

private:

	//hashtable
	string* hashTable;
	
	//hashtable size
	int hashTableSize;
	
	//value use by h2
	int primeValue;

	//number of elements
	int currentItems;

//==================================================================================
//									helpers											|
//==================================================================================

	//string to int and uses the mod operator
	int hashOne(string value) const;

	// string to int and uses double hashing
	int hashTwo(string value) const;

	//init the table
	void setHashTable();

	//get the prime value
	bool isPrimeNumber(int val) const;
	int getPrimeNumber(int val) const;

	//deep copy helper
	void deepCopy(const HashTable& copyHash);

};