#include<iostream>
#include<iomanip>
#include <map>
using namespace std;

//Global variables
int num[10];
//Functions/Structures


int IntegerChecker() {
	int num;

	while (!(cin >> num)) {
		cout << "You have entered wrong input. Enter a value: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

	}
	return num;
}

int SearchInput(int num[], int  inputNum) {
	for (int i = 0; i < 10; i++) {
		if (num[i] == inputNum) {
			return i;
		}
	}
	return -1;
}
void CharCount()
{
	string inputString;
    cout<<"Enter String Value: ";
    cin>>inputString;
    std::map<char, int> charCount;
    
    for(char &c: inputString)
    {
        charCount[c]++;
    }
    
	std::size_t i = 0;

    for(char &c: inputString)
    {
        std::size_t index = inputString.find(c);
        if(index != inputString.npos && (index == i))
		{
         std::cout << c <<" - " << charCount.at(c)<<std::endl;
        }
        ++i;
    }
}

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
		algoIndex = IntegerChecker();
		/*for (;;) 
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
		}*/

		switch (algoIndex)
		{
		case 1:

			//Quicksort Algorithm

			break;
		case 2:

			//Linear Search Algorithm
		{
			//input the value
			for (int i = 0; i < 10; i++) {
				if (i + 1 == 1) {
					cout << "Enter 1st number: ";
					num[i] = IntegerChecker();
				}
				else if (i + 1 == 2) {
					cout << "Enter 2nd number: ";
					num[i] = IntegerChecker();
				}
				else if (i + 1 == 3) {
					cout << "Enter 3rd number: ";
					num[i] = IntegerChecker();
				}
				else if (i + 1 > 3) {
					cout << "Enter " << i + 1 << "th number: ";
					num[i] = IntegerChecker();
				}
			}

			int searchNum;
			char repeat;

			cout << "\nEnter number to be search: ";
			cin >> searchNum;
			int location = SearchInput(num, searchNum);

			if (location == -1) {
				cout << "\nThe number is not in the array." << endl;
			}
			else {
				cout << "\nthe location of " << searchNum << " is in index " << location << endl;
			}
			cout << "do you want to repeat again?  [Y] yes or [N] no" << endl;
			cin >> repeat;
		}
			break;

		case 3:

			//Character Counting Algorithm
			CharCount();
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