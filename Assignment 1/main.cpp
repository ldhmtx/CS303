#include "func.h"

void main() {
	//creating the array:
	int const stor = 1000;
	int arr[stor] = { 0 };
	lasfil(arr, stor); //building array
	string m = "Options:\n\nA. Search for a certain number\nB. Change a value at an index\nC. Add a value\nD. Remove a value at an index\n\n>>";
	bool kor = false;
	do { //loop for menu used to run functions
		cout << m;
		char valj;
		cin >> valj;
		switch (valj) {
		case 'A': //searching for a certain number
			int tillbaka;
			tillbaka = sokArr(arr, stor);
			if (tillbaka == 0) { cout << "\n\nNumber not found."; } //if array did not contain that number
			else { cout << "\n\nFound index: " << tillbaka; } //if found, give to user
			kor = true;
			break;
		case 'B': { //changing a value at an index
			andraArrTC(arr);
			kor = true;
			break;
		}
		case 'C': { //adding a value
			forlangaTC(arr, stor);
			kor = true;
			break;
		}
		case 'D': { //removing a value
			radVal(arr, stor);
			kor = true;
			break;
		}
		default: //if input is incorrect
			cout << "That doesn't look right, try again.\n";
			continue; //ask again
		}
	} while (kor == false);

}