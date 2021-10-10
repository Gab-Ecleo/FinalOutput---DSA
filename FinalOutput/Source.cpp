#include<iostream>;
#include<iomanip>;
using namespace std;

//Global variables

//Functions/Structures

//Methods
int main() 
{
	//variables
	bool isChoosing = true;
	int algoIndex;

	while (isChoosing) 
	{
		cout << left
			<< "[1] Sort \n"
			<< "[2] Search \n"
			<< "[3] Character Counting \n"
			<< "[4] Exit Program \n";


		cout << "Choose an Algorithm: ";	
		for (;;) 
		{
			if (cin >> algoIndex)
				break;
			else {
				cout << "Invalid Input, please try again."
					<< endl
					<< "Choose an Algorithm: ";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
		}

		switch (algoIndex)
		{
		case 1:

			//Quicksort Algorithm

			break;
		case 2:

			//Linear Search Algorithm

			break;

		case 3:

			//Character Counting Algorithm

			break;
		
		case 4:

			cout << "Program Ending Thank you...." << endl;
			isChoosing = false;

			break;

		default:

			cout << "Number out of range. Please choose again" << endl;

			break;
		}
	}
}