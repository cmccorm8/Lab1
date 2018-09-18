//Chance McCormick
//Cosc 2030
//Lab 1
//9/17/18


#include<iostream>
#include<fstream>
#include<string>

using std::ifstream;
using std::string;
using std::getline;
using std::cin;
using std::cout;
using std::cerr;
using std::endl;

int main()
{
	string inName;
	ifstream inFile;

	bool finished = false;

	double firstInt;
	double secInt;
	double lastInt;
	double secLast;
	double temp = 0;
	double temp2 = 0;
	double x = 0;
	int counter = 0;
	cout << "Please Enter a filename." << endl;

	while (!finished)								// Prompts the user for an input of a valid filename
													// if the input is not valid repeats until user inputs a valid filename
	{
		cin >> inName;

		inFile.open(inName);

		if (inFile.is_open())
		{
			finished = true;
		}

		if (!inFile.is_open())
		{
			cerr << "Could Not Open: " << inName << endl;
			cout << "Please Enter a filename." << endl;
			inFile.close();
			inFile.clear();
			finished = false;
		}


	}

	while (!(inFile.fail()))							
	{
		
		while (inFile >> x)		// reads each number of the file and stores it in x
		{


			counter++;

			if (counter == 1)
			{
				firstInt = x;
			}
			if (counter == 2)
			{
				secInt = x;
			}

			temp2 = temp;					// sets temp2 to the current value of temp, which is the value of x from the previous iteration of the loop
			temp = x;						//sets temp to the value of x as x currently is through the current iteration of the loop
		}									//therefor temp is set to the final number of the file while temp2 is set to the second to last number
	}
	secLast = temp2;
	lastInt = x;
	inFile.close();

	cout << "\nThe count is: " << counter << endl;
	cout << "The first number is: " << firstInt << endl;
	cout << "The second number is: " << secInt << endl;
	cout << "The second to last number is: " << secLast << endl;
	cout << "The last number is: " << lastInt << endl;


	system("pause");
	return 0;
}