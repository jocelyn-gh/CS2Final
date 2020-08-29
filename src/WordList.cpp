#include "WordList.h"




//********* Default Constructor/Destructor *********\\


WordList::WordList()
{
	lineNumList.addFront(0);
}

/**
*Virtual destructor
*/
WordList::~WordList()
{
}



//********* Accessor Functions *********\\

string WordList::getWord()
{
	return word;
}

const SinglyLinkedList<int> WordList::getList()
{
	return lineNumList;
}

//********* Mutator Function *********\\	

void WordList::setWord(string W)
{
	word = W;
}

void WordList::setList(SinglyLinkedList<int> L)
{
	lineNumList = L;
}