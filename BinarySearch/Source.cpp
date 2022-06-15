//This program demonstrates the binarySearch function, which 
//performs a binary search on an integer array. 
#include<iostream>
using namespace std;

int binarySearch(const int[], int, int);
const int SIZE = 20;

int main()
{
	int idNums[SIZE] = { 101, 142, 147, 189, 199, 207, 222,
						234, 289, 296, 310, 319, 388, 394,
						417, 429, 447, 521, 536, 600 };
	int results; //To hold the search results 
	int empID;   //To hold an employee ID 

	//Get an employee ID to search for. 
	cout << "Enter the employee ID you wish to search for: ";
	cin >> empID;

	//Search for the ID. 
	results = binarySearch(idNums, SIZE, empID);

	//If results contains -1 the ID was not found. 
	if (results == -1)
		cout << "That number does not exist in the array." << endl;
	else
	{
		//Otherwise results contains the subscript of
		//the specified employee ID in the array. 
		cout << "That ID is found at element " << results;
		cout << " in the array.";
	}

	return 0;
}

int binarySearch(const int idNums[], int SIZE, int empID)
{
	int first = 0,		 //First array element 
		last = SIZE - 1, //Last array element 
		middle,			 //Midpoint of search
		position = -1;   //Position of the search value
	bool found = false;  //Flag

	while (!found && first <= last)
	{
		middle = (first + last) / 2; //Calculate midpoint 
		if (idNums[middle] == empID) //If value is found in midpoint
		{
			found = true;
			position = middle;
		}
		else if (idNums[middle] > empID) //If value is in lower half 
			last = middle - 1;
		else
			first = middle + 1; //If value is in upper half 
	}
	return position;
}