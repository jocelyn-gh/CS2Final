/*ID block
*---------------------------------------------------*
~ Programmer : 	Jocelyn               				~
~ Course     : 	Computer Science 2    				~
~ Lab Section:	 (M && Wes)							~
~ Assignment :	CS2Assignment6						~
~ IED        : Visual stuideo 2012					~
~ Date		 : 	Wendsday 11/12/14					~
*---------------------------------------------------*
*/
/*


                -'''''-.
             .'      #  `.
            :             :
           :   #           :
           :      /|      :
            :   =//   #  :
             `./ |     .'
           (   /  ,|...-'
            \/^\/||   
            /~  `''~`` `
     __/  -'/  --._ |'__
   /________/--  -` ~|'

		|=Collie Tech=|

*/



#include <string>
#include <ostream>
//#include <fstream>
//#include <iostream>
//#include <iomanip>

#include <windows.h>

#include "UtilityFuncs.h"

#include "iterator.h"
#include "WordList.h"

//#include "Stack.h"
//#include "Employee.h"



using namespace std;

//const int BASECOLOR = 15; //7 Gray 15 White
//const int USERCOLOR1 = 11; // Light Blue-teal
//const int USERCOLOR2 = 13; // Pink ^\/^


void printCollieMenu1();
void buildTree(ifstream &fIn, BinarySearchTree<WordList> &WL_BST);
string cleanString(string token);



void printCollieMenu1()
{

	//Colors
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	// Colors

	int Collie = 10, spacing = 10;

	SetConsoleTextAttribute(hConsole, BASECOLOR);
	cout << setw(Collie) << "" << "  " << endl;
	cout << setw(Collie) << "" << "||---------------------------------------------------------||" << endl;
	cout << setw(Collie) << "" << "||";
	SetConsoleTextAttribute(hConsole, USERCOLOR1);
	cout << "" << "                  Math time!      ";
	SetConsoleTextAttribute(hConsole, BASECOLOR);  cout << "                       ||" << endl;
	cout << setw(Collie) << "" << "||                                                         ||" << endl;
	cout << setw(Collie) << "" << "||                 -'''''-.                                ||" << endl;
	cout << setw(Collie) << "" << "||              .'      #  `.                              ||" << endl;
	cout << setw(Collie) << "" << "||             :             :                             ||" << endl;
	cout << setw(Collie) << "" << "||            :   #           :                            ||" << endl;
	cout << setw(Collie) << "" << "||            :      /|       :                            ||" << endl;
	cout << setw(Collie) << "" << "||             :   =//   #   :                             ||" << endl;
	cout << setw(Collie) << "" << "||              `./ |      .'                              ||" << endl;
	cout << setw(Collie) << "" << "||           (   /  ,|...-'                                ||" << endl;
	cout << setw(Collie) << "" << "||            \\//^\\//||                                    ||" << endl;
	cout << setw(Collie) << "" << "||           /~  `''~`` `                                  ||" << endl;
	cout << setw(Collie) << "" << "||       __ / -'/  --._ |'__                               ||" << endl;
	cout << setw(Collie) << "" << "||      / ________ / -- - ` ~| '                           ||" << endl;
	cout << setw(Collie) << "" << "||                                                         ||" << endl;
	cout << setw(Collie) << "" << "||   /Enter the menu item of choice and press enter key\\   ||" << endl;
	cout << setw(Collie) << "" << "||                                                         ||" << endl;
	cout << setw(Collie) << "" << "||  1) Input wordlist from file and count occernces.       ||" << endl;
	cout << setw(Collie) << "" << "||  2) Print wordlist out to file.                         ||" << endl;
	cout << setw(Collie) << "" << "||  3) Search for word.                                    ||" << endl;
	cout << setw(Collie) << "" << "||  4) Exit                                                ||" << endl;
	cout << setw(Collie) << "" << "||                                                         ||" << endl;
	cout << setw(Collie) << "" << "||---------------------------------------------------------||" << endl;

	SetConsoleTextAttribute(hConsole, BASECOLOR);

}
string stripString(string inString)
{
	string cleanedString;
	for (size_t i = 0; i < inString.length(); i++)
	{

		if (!isalpha(inString[i]))
		{
			inString[i] = ' ';
		}

			cleanedString += tolower(inString[i]);
		
	}
	return cleanedString;
}






void buildTree(ifstream &fIn, BinarySearchTree<WordList> &WL_BST)
{
	size_t lineNumber = 0;
	while (fIn.peek() != EOF) //grabs entire line
	{
		string line;
		getline(fIn, line);

		if (line != "" &&  line != "\t")//If the string is nothing it will be nothing and dimissed
		{
			line = stripString(line);
		}
		

		lineNumber++;
		istringstream is(line);

		string token;
		


		if (line != "" &&  line != "\t") //If the word is nothing it will be nothing and dimissed
		{
			while (is.peek() != EOF) //Grabs one word
			{

				is >> token;


				WordList tempWordList;
				tempWordList.setWord(token);



				if (WL_BST.contains(tempWordList)) //Check if the word exists
				{
					// if (!(WL_BST.get(tempWordList)->contents.getList().contains(lineNumber))) //Check if the word allready on this line
					// {
					SinglyLinkedList<int>  tempLineNumList = WL_BST.get(tempWordList)->contents.getList();
					tempLineNumList.addRear(lineNumber);
					WL_BST.get(tempWordList)->contents.setList(tempLineNumList);
					//}
				}
				else //If word dosen't exist it is added in alphabetical order to the binary search tree
				{
					SinglyLinkedList<int>  tempLineNumList;
					tempLineNumList.addFront(lineNumber);
					tempWordList.setList(tempLineNumList);

					///////////////////////////////////////////////////////////////////////////////////////////////////////////////
					WL_BST.add(tempWordList);////////////////////////////Most of the work right here
					///////////////////////////////////////////////////////////////////////////////////////////////////////////////

					//WL_BST.get(tempWordList)->left
				}

			}
		}
	}


}



int main()
{
	printCollieMenu1();
	UtilityFuncs::ClearScreen(5);

	{
		

		ifstream fIn;
		ofstream fOut;
		BinarySearchTree<WordList> WL_BST;
		string folder = "Files/", ext = ".txt";

		bool flagLoop = true, isWordList = false;
		int	menuchoice = -1;



		UtilityFuncs::ClearScreen(100);
		while (flagLoop)
		{

			printCollieMenu1();
			UtilityFuncs::ClearScreen(5);
			UtilityFuncs::Center(CENTER);
			cout << setw(SPACING) << "Please slect a choice" << ": ";


			if (!UtilityFuncs::IsInt(menuchoice))
			{
				UtilityFuncs::ClearScreen(2);
				UtilityFuncs::Center(CENTER);
				cout << "Bad input, integers only." << endl;
				menuchoice = -1;
			}

			switch (menuchoice)
			{
			case 1:
			{

					  do
					  {
						  if (UtilityFuncs::openAndValidateInputFile(fIn, folder, ext))
						  {
							  cout << "This program will read words from an input file and store in an linklist" << endl << endl;
						  }
							  break;


					  } while (true);





					  buildTree(fIn, WL_BST);
					
					  fIn.close();
					  isWordList = true;
					//  WL_BST.printPostorder(cout);
					  break;
			}

			case 2:
				if (!isWordList)
				{
					cout << "\n" << setw(SPACING) << "Please create a expression using option 1 before using this option." << endl;
					break;
				}

				cout << "This program will write the word and the lines it occurs on into a file." << endl << endl;
				if (UtilityFuncs::openAndValidateOutputFile(fOut, folder, ext))
				{
					WL_BST.printInorder(fOut);
					break;
				}

				break;

				/*

				*/

			case 3:
			{
					  string searchString;

					  cout << "Input the word you would like to search for: ";
					  getline(cin, searchString);
					  cin.sync();

					  WordList tempSearchWordList;
					  tempSearchWordList.setWord(searchString);

					  if (WL_BST.contains(tempSearchWordList))
					  {
						  cout << "The word " << searchString << " exists on lines " << WL_BST.get(tempSearchWordList)->contents.getList() << ".";

					  }
					  else
					  {
						  cout << "The word " << searchString << "does no exist.";
					  }
					  break;
			}


					  /*

					  */
		
			case 4:
					  UtilityFuncs::ClearScreen(5);
					  UtilityFuncs::Center(CENTER);
					  if (UtilityFuncs::AskYesNo("Are you shure you want to exit?", "Exiting", "Not exiting"))
					  {
						  flagLoop = false;
						  break;
					  }

					  break;
				/*
				Please slect a choice: 4

				Are you shure you want to Exit? (Y/N): Y
				*/

			default:
				UtilityFuncs::Center(CENTER);
				cout << "not a valid option, please try again." << endl;
				break;
			}

		}










	}
	return 0;
}