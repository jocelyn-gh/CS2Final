#pragma once
#ifndef WordList_H
#define WordList_H


#include <string>
#include <fstream>

#include "linkedlistinterface.h"

using namespace std;

class WordList
{

private:
	/**
	*Stores the word from text file
	*/
	string word;
	/**
	*Stores the line numbers (as integers) on which the Word is found
	*/
	SinglyLinkedList<int>  lineNumList;
	//Add any other data members as per your need.

public:

	//********* Default Constructor/Destructor *********\\


	WordList();
	/**
	*Virtual destructor
	*/
	virtual ~WordList();


	//********* Accessor Functions *********\\

	string getWord();

	const SinglyLinkedList<int> getList();

	//********* Mutator Function *********\\	

	void setWord(string W);

	void setList(SinglyLinkedList<int> L);


	//**** Friend Functions ****\\	


	/**
	*Reads data from the file or keyboard to fill the WordList object
	*/
	friend istream & operator >>(istream & in, WordList& WL)
	{
		in >> WL.word;
		in >> WL.lineNumList;
	}
	/**
	*Writes data to the file or to screen to print the WordList object
	*/
	friend ostream & operator <<(ostream & out, const WordList& WL)
	{
		out << "The word is: " << WL.word << " :: " << WL.lineNumList << endl;
		return out;
	}

	friend bool  operator == (const WordList& WLl, const WordList& WLr)
	{
		//return ((WLl.word == WLr.word) && (WLl.lineNumList == WLr.lineNumList));
		return (WLl.word == WLr.word);
	}

	friend bool  operator != (const WordList& WLl, const WordList& WLr)
	{
		//return ((WLl.word == WLr.word) && (WLl.lineNumList == WLr.lineNumList));
		return (WLl.word != WLr.word);
	}

	friend bool  operator > (const WordList& WLl, const WordList& WLr)
	{
		//return ((WLl.word > WLr.word) && (WLl.lineNumList > WLr.lineNumList));
		return (WLl.word > WLr.word);

	}

	friend bool  operator < (const WordList& WLl, const WordList& WLr)
	{
		//return ((WLl.word < WLr.word) && (WLl.lineNumList < WLr.lineNumList));
		return (WLl.word < WLr.word);

	}

	//friend ostream & operator >= (const WordList& WLl, const WordList& WLr);

	//friend ostream & operator <= (const WordList& WLl, const WordList& WLr);

};
#endif