#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include "HashTable.h"


using std::vector;
using std::sort;
using std::unique;
using std::swap;


vector<string> extraLetter(const HashTable& dict, string word)
{
	//create a vector of strings
	vector<string> vec;

	//if the word is in the dictionary insert it into the vector and return
	if (dict.find(word)) 
	{ 
		vec.push_back(word); 
		return vec;
	}

	/*
	
	it uses a for loop and iterators to iterate through the each letter of the word,
	and then it uses that to see if it's in the hash table. After that it sorts the vector
	and erases duplicates
	
	*/
	for (auto i = word.begin(); i != word.end(); i++)
	{
		const string BGN = { word.begin(), i };
		const string ED = { i + 1, word.end() };

		if (dict.find(BGN + ED))
		{
			vec.push_back(BGN + ED);
		}
	}

	sort(vec.begin(), vec.end());
	vec.erase(unique(vec.begin(), vec.end()), vec.end());

	return vec;
}

vector<string> transposition(const HashTable& dict, string word)
{
	//create a vector of strings
	vector<string> vec;

	//if the word is in the dictionary insert it into the vector and return
	if (dict.find(word))
	{
		vec.push_back(word);
		return vec;
	}
	
	/*
	
	a standard loop that loops through each index of the string, it then creates a substring copy,
	calls swap to swap the current and next index then uses that to find it in the hash table. If it exists
	then is adds it to the hashtable, sorts it and erases duplicate values

	*/

	int i = 0;
	while (i < word.size())
	{
		string letter = word.substr(0, word.size());
		swap(letter[i], letter[i + 1]);
		i++;

		if (dict.find(letter))
		{
			vec.push_back(letter);
		}
	}

	sort(vec.begin(), vec.end());
	vec.erase(unique(vec.begin(), vec.end()), vec.end());

	return vec;
}


vector<string> missingSpace(const HashTable& dict, string word)
{
	//create a vector of strings
	vector<string> vec;

	//if the word is in the dictionary insert it into the vector and return
	if (dict.find(word))
	{
		vec.push_back(word);
		return vec;
	}

	/*
	
	it uses a for loop and iterators to iterate through the each letter of the word, as it
	goes through each index of the string it adds a space and then it uses that to see if it's in the hash table. 
	After that it sorts the vector and erases duplicates
	
	*/

	for (auto i = word.begin(); i != word.end(); i++)
	{
		const string BGN = { word.begin(), i + 1};
		const string ED = { i + 1, word.end() };

		if (dict.find(BGN) && dict.find(ED))
		{
			vec.push_back(BGN + " " + ED);
		}
	}

	sort(vec.begin(), vec.end());
	vec.erase(unique(vec.begin(), vec.end()), vec.end());

	return vec;
}

vector<string> missingLetter(const HashTable& dict, string word)
{
	//create a vector of strings
	vector<string> vec;

	//if the word is in the dictionary insert it into the vector and return
	if (dict.find(word))
	{
		vec.push_back(word);
		return vec;
	}

	/*
	
	it uses a for loop and iterators to iterate through the each letter of the word, as it
	goes through each index of the string it adds a letter with a letter from the alphabet string varaible
	and then it uses that to see if it's in the hash table. After that it sorts the vector and erases duplicates
	
	*/


	string alphabet = "abcdefghijklmnopqrstuvwxyz";

	for (auto i = word.begin(); i != word.end(); i++)
	{
		const string BGN = { word.begin(), i + 1};
		const string ED = { i + 1, word.end() };

		for (auto j: alphabet)
		{
			string str(1, j);

			if (dict.find(BGN + str + ED))
			{
				vec.push_back(BGN + str + ED);
			}

		}
		
	}

	sort(vec.begin(), vec.end());
	vec.erase(unique(vec.begin(), vec.end()), vec.end());

	return vec;
}

vector<string> incorrectLetter(const HashTable& dict, string word)
{
	//create a vector of strings
	vector<string> vec;

	//if the word is in the dictionary insert it into the vector and return
	if (dict.find(word))
	{
		vec.push_back(word);
		return vec;
	}

	/*

	it uses a for loop and iterators to iterate through the each letter of the word, as it
	goes through each index of the string it removes a letter and replaces it with a letter from the alphabet string varaible
	and then it uses that to see if it's in the hash table. After that it sorts the vector and erases duplicates

	*/

	string alphabet = "abcdefghijklmnopqrstuvwxyz";

	for (auto i = word.begin(); i != word.end(); i++)
	{
		const string BGN = { word.begin(), i };
		const string ED = { i + 1, word.end() };

		for (auto j : alphabet)
		{
			string str(1, j);

			if (dict.find(BGN + str + ED))
			{
				vec.push_back(BGN + str + ED);
			}

		}

	}

	sort(vec.begin(), vec.end());
	vec.erase(unique(vec.begin(), vec.end()), vec.end());

	return vec;
}