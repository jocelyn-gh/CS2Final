#include "UtilityFuncs.h"

/*ID block
*---------------------------------------------------*
~ Programmer : 	Jocelyn             				~
~ Course     : 	Computer Science 2    				~
~ Lab Section:	(M && Wes)							~
~ Assignment :	CS2Assignment6						~
~ IED        :  Visual stuideo 2012					~
~ Date		 : 	Wendsday 11/12/14					~
*---------------------------------------------------*
*/

UtilityFuncs::UtilityFuncs()
{
}


//UtilityFuncs::~UtilityFuncs()
//{
//}


////////////////////////////////////////////////////// Check cin function /////////////////////////////////////////////////////////

bool UtilityFuncs::IsInt(int &inputint)
{
	string stringtemp;
	// Colors
	//HANDLE hConsole;
	//hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	// Colors

	//SetConsoleTextAttribute(hConsole, USERCOLOR1);
	getline(cin, stringtemp);
	//SetConsoleTextAttribute(hConsole, BASECOLOR);

	stringstream myStream(stringtemp);
	if (myStream >> inputint)
		return true;
	else
		return false;

	//ClearScreen(2);
	//Center(CENTER);
	//cout << "Bad input, integers only." << endl;
	return false;
}


////////////////////////////////////////////////////// Check cin function /////////////////////////////////////////////////////////

bool UtilityFuncs::IsDouble(double &inputD)
{
	string stringtemp;
	getline(cin, stringtemp);


	stringstream myStream(stringtemp);
	if (myStream >> inputD)
		return true;
	else
		return false;

	return false;
}
////////////////////////////////////////////////////// Check cin function /////////////////////////////////////////////////////////
bool UtilityFuncs::IsChar(char &inchar)
{
	string stringtemp;

	getline(cin, stringtemp);

	if (stringtemp.length() == 1)
	{
		inchar = stringtemp[0];
		return true;
	}
	else
		return false;

	//ClearScreen(2);
	//Center(CENTER);
	//cout << "Bad input, characters only." << endl;
	return false;
}


////////////////////////////////////////////////////// Center function /////////////////////////////////////////////////////////
void UtilityFuncs::Center(int wallspacing)
{
	cout << setw(wallspacing) << "";
}

////////////////////////////////////////////////////// print Decale one function /////////////////////////////////////////////////////////
void UtilityFuncs::printDecaleOne(int wallspacing, string start, char fill, string end, int length)
{

	cout << setw(wallspacing) << "" << setw(length) << setfill(fill) << start << end << setfill(' ') << endl;
}

////////////////////////////////////////////////////// Retry function /////////////////////////////////////////////////////////
void UtilityFuncs::SubRetry(int &retrys)
{
	Center(CENTER);
	cout << "You have " << retrys << " many retrys left, please try again.";
	ClearScreen(2);
	retrys--;
}

////////////////////////////////////////////////////// Clear screen function /////////////////////////////////////////////////////////
void UtilityFuncs::ClearScreen(int ammout)
{
	cout << string(ammout, '\n');
}
////////////////////////////////////////////////////// Ask File Name function /////////////////////////////////////////////////////////
void UtilityFuncs::AskFileName(string &filename)
{
	getline(cin, filename);
	filename = filename + ".txt";
}

////////////////////////////////////////////////////// Open and check file function /////////////////////////////////////////////////////////
/*
bool UtilityFuncs::OpenCheckFile(ifstream &filein, string fileName)
{

	filein.open(fileName.c_str());

	if (filein.fail())
	{
		Center(CENTER);
		cout << "file : " << fileName << " was not there." << endl;
		filein.close();
		return false;
	}
	else
	{
		Center(CENTER);
		cout << "file : " << fileName << " was opned." << endl;
		return true;
	}

}
*/

////////////////////////////////////////////////////// Split full name function /////////////////////////////////////////////////////////
void UtilityFuncs::SplitFullString(string &fullstring, string &firststring, string &laststring)
{
	int separator;

	separator = fullstring.find(", ");
	firststring = fullstring.substr(separator + 2, 50);
	laststring = fullstring.substr(0, separator);
	fullstring = firststring + " " + laststring;
}

void UtilityFuncs::SplitFullString2(string fullString, string &firstString, string &lastString)
{
	int separator;

	separator = fullString.find(" ");
	if(separator==-1)
	{
		firstString=fullString;
		return;
	}
	firstString = fullString.substr(0, separator);
	lastString = fullString.substr(separator + 1, 50);
}

////////////////////////////////////////////////////// Ask Yes No function /////////////////////////////////////////////////////////
int UtilityFuncs::AskYesNoCheck(char inChar)
{
	switch (inChar)
	{
	case'y':
	case'Y':
		return true;
		break;

	case'n':
	case'N':
		return false;
		break;

	default:
		return -1;
		break;
	}

return -1;

}


bool UtilityFuncs::AskYesNo(string ynResmStr, string trueInStr, string falseInStr)
{
	while(true)
	{
	char tempchar;
	//Colors
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	// Colors

	SetConsoleTextAttribute(hConsole, USERCOLOR1);
	cout << ynResmStr;
	SetConsoleTextAttribute(hConsole, BASECOLOR);
	cout << " (Y/N): ";

	if (!IsChar(tempchar))
	{
		ClearScreen(2);
		Center(CENTER);
		cout << "Bad input, characters only." << endl;
	}
	else
	{
		ClearScreen(2);
		Center(CENTER);
		switch (AskYesNoCheck(tempchar))
		{
		case -1:
			cout << "not a valid option." << endl;
			break;
		case 0:
			cout << falseInStr << endl;
			return false;
			break;
		case 1:
			cout << trueInStr << endl;
			return true;
			break;
		}
	}
	}
cout << "Error" << endl;
return false;
}

////////////////////////////////////////////////////// Check Number Array function /////////////////////////////////////////////////////////

int UtilityFuncs::getNumarray(int innum, int numvec[], int size)
{
	int found = 0;
	for (int i = 0; i<size; i++)
	{
		if (innum == numvec[i])
			found++;
	}
	return found;
}

/*
////////////////////////////////////////////////////// Check Number vector function /////////////////////////////////////////////////////////
int UtilityFuncs::getNumvector(int innum, vector<int> numvec)
{
	int found = 0, size = numvec.capacity();
	for (int i = 0; i<size; i++)
	{
		if (innum == numvec[i])
			found++;
	}
	return found;
}
*/

bool UtilityFuncs::openAndValidateInputFile(ifstream & input, string folder, string ext)
{
	bool done = false, choice;
	string InFile, file;
	int menuchoice;	

	//Loop to get the name of a file that truly exists
	// and check that file is not empty.

	while (!done)
	{
		choice = false;

		menuchoice = -1;

		
		cout << setw(Collie) << "" << "||-------------------------------------------------------||" << endl;
		cout << setw(Collie) << "" << "||-------------------------------------------------------||" << endl;
		cout << setw(Collie) << "" << "||  Select an option to open a .txt file.                ||" << endl;
		cout << setw(Collie) << "" << "||                                                       ||" << endl;
		cout << setw(Collie) << "" << "||  1) Full path of data file                            ||" << endl;
		cout << setw(Collie) << "" << "||  2) Just name of file in the 'File' folder            ||" << endl;
		cout << setw(Collie) << "" << "||  3) Exit                                              ||" << endl;
		cout << setw(Collie) << "" << "||                                                       ||" << endl;
		cout << setw(Collie) << "" << "||-------------------------------------------------------||" << endl;
		cout << setw(Collie) << "" << "You would kike to : ";
		
		input.clear();
		cin.sync();

		if (!UtilityFuncs::IsInt(menuchoice))
		{
			UtilityFuncs::ClearScreen(2);
			UtilityFuncs::Center(CENTER);
			cout << "Bad input, integers only." << endl;
			menuchoice = -1;
		}


		cout << setw(Collie) << "" << "||-------------------------------------------------------||" << endl;
		switch (menuchoice)
		{
		case -1:
			break;

		case 1:
			input.clear();
			cout << "Please input the full path of the data file to be read : ";
			cin.sync();
			getline(cin, InFile);
			cout << "The file name entered is : " << InFile << endl;		
			choice = true;
			break;

		case 2:

			input.clear();
			cout << "Please input the name of the data file to be read : ";
			cin.sync();
			getline(cin, file);
			InFile = folder.c_str()+ file + ext.c_str();
			cout << "The file name entered is : " << file + ext << endl;		
			choice = true;
			break;

		case 3:
			cout << "Exiting"<<endl;
			done = true;
			break;


		default:
			Center(CENTER);
			cout << "not a valid option, please try again." << endl;
			break;
		}

		if (choice)
		{	
			input.open(InFile.c_str());

			if (input.fail())
			{
				cout << "The file does not exist.\n";
				return false;
			}
			else
			{
				input.peek();//peek at the input file

				if (input.eof())//If file is empty then the function eof() returns true
				{
					cout << "The file has no data in it\n";				
					input.close();
					return false;
				}
				else
					return true;
			}
		}
	}
	return false;
}



bool UtilityFuncs::openAndValidateOutputFile(ofstream & output, string folder, string ext)
{
	bool done = false, choice;
	string InFile, file;
	int menuchoice;

while (!done)
{
		choice = false;

		menuchoice = -1;

		cout << setw(Collie) << "" << "||-------------------------------------------------------||" << endl;
		cout << setw(Collie) << "" << "||-------------------------------------------------------||" << endl;
		cout << setw(Collie) << "" << "||  Select an option  to open a .txt file.               ||" << endl;
		cout << setw(Collie) << "" << "||                                                       ||" << endl;
		cout << setw(Collie) << "" << "||  1) Full path of data file                            ||" << endl;
		cout << setw(Collie) << "" << "||  2) Just name of file in the 'File' folder            ||" << endl;
		cout << setw(Collie) << "" << "||  3) Exit                                              ||" << endl;
		cout << setw(Collie) << "" << "||                                                       ||" << endl;
		cout << setw(Collie) << "" << "||-------------------------------------------------------||" << endl;
		cout << setw(Collie) << "" << "You would kike to : ";

		output.clear();
		cin.sync();
		if (!UtilityFuncs::IsInt(menuchoice))
		{
			UtilityFuncs::ClearScreen(2);
			UtilityFuncs::Center(CENTER);
			cout << "Bad input, integers only." << endl;
			menuchoice = -1;
		}

		cout << setw(Collie) << "" << "||-------------------------------------------------------||" << endl;
		switch (menuchoice)
		{
		case -1:
			break;

		case 1:
			output.clear();
			cout << "Please input the full path of the data file to be read : ";
			cin.sync();
			getline(cin, InFile);
			cout << "The file name entered is : " << InFile << endl;
			choice = true;
			break;

		case 2:

			output.clear();
			cout << "Please input the name of the data file to be read : ";
			cin.sync();
			getline(cin, file);
			InFile = folder.c_str() + file + ext.c_str();
			cout << "The file name entered is : " << file + ext << endl;
			choice = true;
			break;

		case 3:
			cout << "Exiting" << endl;
			return false;
			break;

		default:
			Center(CENTER);
			cout << "not a valid option, please try again." << endl;
			break;
		}

		if (choice)
		{
			output.open(InFile.c_str());

			if (output.fail())
			{
				cout << "The file failed to create.\n";
				return false;
			}
			else
				return true;
			/*
			else
			{
				output.peek();//peek at the input file

				if (output.eof())//If file is empty then the function eof() returns true
				{
					cout << "The file has no data in it\n";
					done = false;
					output.close();
				}
				else
					done = true;
			}
			*/
		}
	}
	output<<fixed<<showpoint<<setprecision(2);
return false;
}










////////////////////////////////////////////////////// Open and check file function /////////////////////////////////////////////////////////

bool UtilityFuncs::OpenCheckFile(ifstream &fIn, string filePath, string fileName, string ext)
{
	string str = filePath.c_str();
	str += fileName.c_str();
	str += ext.c_str();

	//fileinout.open("Files.txt");
	fIn.open(filePath.c_str());

	if (fIn.fail())
	{
		cout << "file : " << fileName << " was not there." << endl;
		fIn.close();
		return false;
	}
	else
	{
		cout << "file : " << fileName << " was opned." << endl;
		return true;
	}

}

////////////////////////////////////////////////////// Open and check file function /////////////////////////////////////////////////////////

bool UtilityFuncs::OpenCheckFile2(ifstream &fIn, string filePath)
{

	fIn.open(filePath.c_str());

	if (fIn.fail())
	{
		cout << "file : " << filePath << " was not there." << endl;
		fIn.close();
		return false;
	}
	else
	{
		cout << "file : " << filePath << " was opned." << endl;
		return true;
	}

}


void UtilityFuncs::convertToLowerCase(string & str)
{
	string lower = "";
	for (unsigned int i = 0; i < str.length(); i++)
	{
		lower += (tolower(str[i]));
	}

	str = lower;
}


string UtilityFuncs::getLowerCase(string str)
{
	string lower = "";
	for (unsigned int i = 0; i < str.length(); i++)
	{
		lower += (tolower(str[i]));
	}

	return lower;
}

void UtilityFuncs::convertToUpperCase(string & str)
{
	string uper = "";
	for (unsigned int i = 0; i < str.length(); i++)
	{
		uper += (toupper(str[i]));
	}

	str = uper;
}


void UtilityFuncs::colorText(int inInt)
{
	//Colors
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	// Colors
	SetConsoleTextAttribute(hConsole, inInt);
}
