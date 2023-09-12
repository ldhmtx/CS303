#pragma once
#include <iostream>
#include <fstream>
#include <limits>
#include <stdexcept>
#include <string>

using namespace std;

//Question 1:

//function reading in the file and building array with file's values
void lasfil(int arr[], int stor);

//function to search for a particular value in the array
int sokArr(int arr[], int stor);

//function to change a specific index and return new value
int andraArr(int arr[]);

//function to add additional values to the end of the array
void forlanga(int arr[], int stor);

//function to delete value at any given index
void radVal(int arr[], int stor);

//Question 2:

//function to change a specific index and return new value
int andraArrTC(int arr[]);

//function to add additional values to the end of the array
void forlangaTC(int arr[], int stor);