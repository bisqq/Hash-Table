#include "HashTable.h"


HashTable::HashTable()
{
	//init the table size
	hashTableSize = 101;

	//call the function to set the rest of the table
	setHashTable();
}


HashTable::HashTable(int nItems)
{
	// set the table size to 2n prime > arraySize/2
	hashTableSize = getPrimeNumber(2 * nItems);

	//call the function to set the rest of the table
	setHashTable();
}


HashTable::HashTable(const HashTable& copyHash)
{
	//call deep copy function
	deepCopy(copyHash);
}


HashTable::~HashTable()
{
	//delete the table
	delete[] hashTable;
}


HashTable& HashTable::operator=(const HashTable& copyHash)
{
	//if not itself
	if (this != &copyHash)
	{
		//delete the table
		delete[] hashTable;
		//call deeap copy function
		deepCopy(copyHash);
	}

	return *this;
}


void HashTable::insert(string strValue)
{
	//if the value exists return and don't insert
	if (find(strValue)) { return; }

	//call the h1 and h2 functions
	int index = hashOne(strValue);
	int next = hashTwo(strValue);

	//loop as long as the spot is not empty
	while (hashTable[index] != "")
	{
		//find an index in the circular table
		index = (index + next) % hashTableSize;
	}

	//assign the value to that index
	hashTable[index] = strValue;

	//increase the table size
	currentItems++;

	//if the table size load is greater than 0.67 
	if (loadFactor() > 0.67)
	{
		//store the orginal table size
		int tempSize = hashTableSize;

		//create a hash table object
		HashTable newHashTable(hashTableSize);

		//loop through the orginal table size
		for (int i = 0; i < tempSize; i++)
		{
			//if it's not empty
			if (hashTable[i] != "")
			{
				//call the insert function to insert the old values into the new table
				newHashTable.insert(hashTable[i]);
			}
		}
		//assign the old table to the new table
		*this = newHashTable;
	}
}


bool HashTable::find(string strValue) const
{
	//call h1 and h2
	int index = hashOne(strValue);
	int next = hashTwo(strValue);

	//loop as long as the index is not empty
	while (hashTable[index] != "")
	{
		//if the index value is the same as the param return true
		if (hashTable[index] == strValue) 
		{ 
			return true;
		}

		//otherwise find the next index in the circular table
		index = (index + next) % hashTableSize;
	}

	//otherwise if it does not exist in the table return false
	return false;
}


int HashTable::size() const
{
	//return the number of elements
	return currentItems;
}


int HashTable::maxSize() const
{
	//return the table size
	return hashTableSize;
}


double HashTable::loadFactor() const
{
	//return the loadFactor
	return (currentItems * 1.0) / (hashTableSize * 1.0);
}


/*
________________________________________________________
														|
						HELPERS							|
________________________________________________________|

*/


int HashTable::hashOne(string value) const
{
	// starting index
	int index = 0;

	//using horners method
	for (int i = 0; i < value.size(); i++)
	{
		index = (index * 32 + (value[i] - 96)) % hashTableSize;
	}

	//return the index
	return index;
}



int HashTable::hashTwo(string value) const
{
	//start index
	int res = 0;

	//using horners method
	for (int i = 0; i < value.size(); i++)
	{
		res = (res * 32 + (value[i] - 96)) % primeValue;
	}

	//return the porbe value
	return primeValue - res;
}


void HashTable::setHashTable()
{
	//set the prime
	primeValue = getPrimeNumber(hashTableSize / 2);

	//create a new table
	hashTable = new string[hashTableSize];

	//set the number of elements
	currentItems = 0;
}


bool HashTable::isPrimeNumber(int n) const
{
	//set starting points
	bool isPrime = true;
	int i = 2;

	//loop through finding the prime value that is > n/2
	while (i <= (n/2) && isPrime)
	{
		if (n % i == 0) { isPrime = false; }

		i++;
	}

	return isPrime;
}


int HashTable::getPrimeNumber(int n) const
{
	//loop to find the prime
	n++;

	while (!isPrimeNumber(n)) { n++; }
	
	//return the prime
	return n;
}


void HashTable::deepCopy(const HashTable& copyHash)
{
	//copy the table size, number of elements, and prime value
	hashTableSize = copyHash.maxSize();
	currentItems = copyHash.size();
	primeValue = copyHash.primeValue;

	//set the new table size
	hashTable = new string[hashTableSize];

	//copy the values
	for (int i = 0; i < hashTableSize; i++)
	{
		hashTable[i] = copyHash.hashTable[i];
	}
}