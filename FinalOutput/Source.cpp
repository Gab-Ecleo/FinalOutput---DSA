#include<iostream>
#include<iomanip>
#include<map>
using namespace std;

//Global variables
int num[10];

//Functions/Structures

//checks for input validation 
int IntegerChecker() {
	int num;

	while (!(cin >> num)) {
		cout << "Please input the correct value" << endl
			<< ":" ;
		cout << "Please input the correct value" << endl
			<< ":";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

	}
	return num;
}

void RepeatMsg()
{
	int val = 0;
	bool isChoosing = true;

	//print message
	cout << left
		<< "[1]Yes	[2]No" << endl
		<< "Choose Again?: ";


	while (isChoosing)
	{

		val = IntegerChecker();

		if (val < 1 || val > 2)
		{
			cout << "Number out of range.\n";
			cout << "Choose Again?: ";
		}
		else
			break;
	}

	if (val == 2)
		exit(0);
}

void ClearConsole()
{
	cout << "\033[H\033[2J";
	cout.flush();
}

//Switch Array value's positions
void SwapValues(int* fVal, int* sVal)
{
	int placeHolder = *sVal;
	*sVal = *fVal;
	*fVal = placeHolder;
}

//Create a partition inside the array
int Partition(int arr[], int minIndex, int maxIndex, int sortMethod)
{
	//assign pivot
	int pi = arr[maxIndex];

	//instantiate sort method
	bool sortBy;

	int i = minIndex - 1;

	//Check and Compare Values
	for (int j = minIndex; j < maxIndex; j++)
	{
		switch (sortMethod)
		{
		case 1:
			//Ascending
			sortBy = arr[j] <= pi;
			break;
		case 2:
			//Descending
			sortBy = arr[j] >= pi;
			break;
		default:
			break;
		}

		if (sortBy)
		{
			i++;
			SwapValues(&arr[j], &arr[i]);
		}
	}

	//After comparing move Pivot to its correct index
	SwapValues(&arr[i + 1], &arr[maxIndex]);

	//return last pivot assigned
	return i + 1;
}

void SortValues(int arr[], int minIndex, int maxIndex, int sortMethod)
{
	if (minIndex < maxIndex)
	{
		//Assign right Most Value as the first pivot
		int pi = Partition(arr, minIndex, maxIndex, sortMethod);

		//Recursion of Sorting

		//for the right partition, the low values block
		SortValues(arr, minIndex, pi - 1, sortMethod);

		//for the left partion, the high block 
		SortValues(arr, pi + 1, maxIndex, sortMethod);
	}
}

void PrintArray(int arr[], int arrSize)
{
	for (int i = 0; i < arrSize; i++)
	{
		cout << left
			<< setw(4) << arr[i];
	}
	cout << "\n" << endl;
}

//check the number of occurence on the array or if there is an occurence in the array
int NumFreq(int num[], int inputNum) {
	int count = 0;
	for (int i = 0; i < 10; i++) {
		if (num[i] == inputNum) {
			count++;
		}
	}
	return count;
}

//locate the postion of the numbers and print the answer
void SearchInput(int num[], int inputNum) {
	int frequency = NumFreq(num, inputNum);
	int i = 0;
	int location[10];

	if (frequency == 0) {
		cout << "\nThe number is not in the array." << endl;
	}
	else {
		int j = 0;
		for (int i = 0; i < 10; i++) {
			if (num[i] == inputNum) {

				location[j] = i;
				j++;

			}
		}
		cout << "\nthe location of " << inputNum << " is in index ";
		for (int i = 0; i < frequency; i++) {
			cout << location[i] << " ";
		}
	}
}

void CharCount()
{
	string inputString;
	cout << "Enter String Value: ";
	cin >> inputString;
	std::map<char, int> charCount;

	for (char& c : inputString)
	{
		charCount[c]++;
	}

	std::size_t i = 0;

	for (char& c : inputString)
	{
		std::size_t index = inputString.find(c);
		if (index != inputString.npos && (index == i))
		{
			std::cout << c << " - " << charCount.at(c) << std::endl;
		}
		++i;
	}
}

void LinearSearch()
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

	cout << "\nEnter number to be search: ";
	cin >> searchNum;
	SearchInput(num, searchNum);

	cout << endl;
	RepeatMsg();
	ClearConsole();
}

void QuickSort()
{
	int arr[10] = {};
	int sortBy = 1;
	bool isChoosing = true;

	for (int i = 0; i < 10; i++)
	{
		cout << "Enter num[" << i + 1 << "]: ";
		arr[i] = IntegerChecker();
		ClearConsole();
	}

	cout << "Unsorted Array" << endl;
	PrintArray(arr, 10);
	cout << left
		<< "[1] Ascending" << endl
		<< "[2] Descending" << endl
		<< "Sort by: ";

	while (isChoosing)
	{
		sortBy = IntegerChecker();
		if (sortBy < 1 || sortBy > 2)
		{
			cout << "Number out of range please try again.\n";
			cout << "Sort by: ";
		}
		else
			ClearConsole();
		break;
	}

	cout << "Sorted Array" << endl;
	SortValues(arr, 0, 9, sortBy);
	PrintArray(arr, 10);

	RepeatMsg();
	ClearConsole();
}


int main() 
{
	//variables
	bool isChoosing = true;
	int algoIndex = 0;
	int rep = 0;

	while (isChoosing)
	{

		cout << left
			<< "[1] Sort \n"
			<< "[2] Search \n"
			<< "[3] Character Counting \n"
			<< "[4] Exit Program \n";


		cout << "\nChoose an Algorithm: ";
		algoIndex = IntegerChecker();
		ClearConsole();

		switch (algoIndex)
		{
		case 1:

			//Quicksort Algorithm
			QuickSort();
			break;
		case 2:

			//Linear Search Algorithm
			LinearSearch();
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
