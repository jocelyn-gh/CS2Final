/*ID block
*---------------------------------------------------*
~ Programmer : 	Branden Dye           				~
~ Course     : 	Computer Science 2    				~
~ Lab Section:	 (M && Wes)							~
~ Assignment :	CS2Assignment6						~
~ Compiler   :  g++									~
~ IED        : Visual stuideo 2012					~
~ Date		 : 	Wendsday 11/12/14					~
*---------------------------------------------------*
*/



#pragma once
#ifndef UtilityFuncs_H
#define UtilityFuncs_H

#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <sstream>
#include <fstream>

#include <windows.h>

using namespace std;



const int CENTER = 8;
const int SPACING = 37;
int static Collie = 10;

const int BASECOLOR = 15; //7 Gray 15 White
const int USERCOLOR1 = 11; // Light Blue-teal
const int USERCOLOR2 = 13; // Pink ^\/^

class UtilityFuncs
{
public:
	UtilityFuncs();


	//~UtilityFuncs();

	////////////////////////////////////////////////////// Check int cin function /////////////////////////////////////////////////////////

	static bool IsInt(int &);

	static bool IsDouble(double &);

	////////////////////////////////////////////////////// Check char cin function /////////////////////////////////////////////////////////

	static bool IsChar(char &);

	////////////////////////////////////////////////////// Center function /////////////////////////////////////////////////////////


	static void Center(int wallspacing);

	////////////////////////////////////////////////////// print Decale one function /////////////////////////////////////////////////////////

	static void printDecaleOne(int, string, char, string, int);

	////////////////////////////////////////////////////// Retry function /////////////////////////////////////////////////////////

	static void SubRetry(int &);

	////////////////////////////////////////////////////// Clear screen function /////////////////////////////////////////////////////////

	static void ClearScreen(int);

	////////////////////////////////////////////////////// Ask File Name function /////////////////////////////////////////////////////////

	static void AskFileName(string &);

	////////////////////////////////////////////////////// Open and check file function /////////////////////////////////////////////////////////

	static bool openAndValidateInputFile(ifstream & input, string folder = "/Files/", string ext = ".txt");

	static bool openAndValidateOutputFile(ofstream & input, string folder = "/Files/", string ext = ".txt");

	static bool OpenCheckFile(ifstream &, string, string, string);

	static bool OpenCheckFile2(ifstream &, string);

	////////////////////////////////////////////////////// Split full name function /////////////////////////////////////////////////////////

	static void SplitFullString(string &, string &, string &);

	static void SplitFullString2(string fullstring, string &firststring, string &laststring);

	////////////////////////////////////////////////////// Ask Yes No function /////////////////////////////////////////////////////////

	static int AskYesNoCheck(char);
	static bool AskYesNo(string ynResmStr, string trueInStr, string falseInStr);

	////////////////////////////////////////////////////// Check Number Array function /////////////////////////////////////////////////////////

	static int getNumarray(int innum, int numvec[], int size);


	static void convertToLowerCase(string &);

	static string getLowerCase(string);

	static void convertToUpperCase(string &);

	static void UtilityFuncs::colorText(int inInt);
};
#endif
