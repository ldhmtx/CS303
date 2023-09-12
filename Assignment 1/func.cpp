#include "func.h"


//function reading in the file and building array with file's values
void lasfil(int arr[], int stor)
{
	ifstream iFil;
	iFil.open("input.txt");

	//for intended size of array 
	for (int i = 0; i < stor; i++) {
		if (!(iFil >> arr[i])) { //so long as there are values to be taken in
			break;
		}
	}
}

//function to search for a particular value in the array
int sokArr(int arr[], int stor)
{
	cout << "\nGive a value to search for >>";
	int upptakt;
	cin >> upptakt;
	//for size of array
	for (int i = 0; i < stor; i++) {
		if (arr[i] == upptakt) { //if we found the given number
			return i;
		}
	}
	return 0; //if not found
}

//function to change a specific index and return new value
int andraArr(int arr[])
{
	int i, ny = 0;
	cout << "\nGive an index to change >>";
	cin >> i;
	int gamle = arr[i]; //saving the old value for user
	cout << "\nGive a new value >>";

	cin >> ny;
	arr[i] = ny; //saving new value for user
	cout << "Old: " << gamle << "\n" << "New: " << ny << endl;
	return ny;
}

//function to add additional values to the end of the array
void forlanga(int arr[], int stor)
{
	cout << "\nGive an integer to add to the array >>";
	int lagg;
	cin >> lagg;
	for (int i = 0; i < stor; i++) { //for the size of the array
		if (arr[i] == 0) { //if position empty
			arr[i] = lagg;
			cout << "Added to index " << i; //update user
			return;
		}
	}
	cout << "Could not add " << lagg; //if not able to add
	return;
}

//function to delete value at any given index
void radVal(int arr[], int stor)
{
	do {
		cout << "\nGive an index to remove >>";
		int radera;
		cin >> radera;
		if (arr[radera] != 0) { //if given index has a value
			arr[radera] = 0;
			cout << "\nDone";
			break;
		}
		else { //if no value to remove
			cout << "\nIndex already empty";
		}
	} while (true);
}

//try/catch functions:


//function to change a specific index and return new value
int andraArrTC(int arr[])
{
	string badval = "Must be a number.\n", negative = "Cannot enter a number less than zero.\n";
	int i, ny = 0;
	cout << "\nGive an index to change ";
	do {
		try {
			cout << ">> ";
			cin >> i;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				throw runtime_error(badval);
			}
			//if negative number
			else if (i < 1) {
				throw runtime_error(negative);
			}
			break;
		}
		catch (runtime_error e) {
			cout << e.what() << endl;
		}
	} while (true);
	int gamle = arr[i]; //saving the old value for user
	cout << "\nGive a new value ";
	do {
		try {
			cout << ">> ";
			cin >> ny;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				throw runtime_error(badval);
			}
			//if negative number
			else if (ny < 1) {
				throw runtime_error(negative);
			}
			break;
		}
		catch (runtime_error e) {
			cout << e.what() << endl;
		}
	} while (true);
	arr[i] = ny; //saving new value for user
	cout << "Old: " << gamle << "\n" << "New: " << ny << endl;
	return ny;
}

//function to add additional values to the end of the array
void forlangaTC(int arr[], int stor)
{
	string badval = "Must be a number.\n", negative = "Cannot enter a number less than zero.\n";
	cout << "\nGive an integer to add to the array >>";
	int lagg;
	do {
		try {
			cin >> lagg;
			//if bad input:
			if (cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				throw runtime_error(badval);
			}
			//if negative number
			else if (lagg < 1) {
				throw runtime_error(negative);
			}
			//exit function
			break;
		}
		//giving user error
		catch (runtime_error e) {
			cout << e.what() << endl;
		}
	} while (true);
	for (int i = 0; i < stor; i++) { //for the size of the array
		if (arr[i] == 0) { //if position empty
			arr[i] = lagg;
			cout << "Added to index " << i; //update user
			return;
		}
	}
	cout << "Could not add " << lagg; //if not able to add
	return;
}
