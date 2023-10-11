#pragma once

#include <iostream>
#include <string>


using namespace std;

template <typename Item_Type> //template to accomodate any data type

//class to build the linked list
class Single_Linked_List {
private: 
	struct Node { //the nodes for which each value will be created upon
		Item_Type data;
		Node* nextPtr;
	};
	Node* head;
	Node* tail;
	size_t num_items; //total size of linked list for iterating
public:
	Single_Linked_List(); //default constructor
	void push_front(Item_Type); //add given value to the front
	void push_back(Item_Type b); //add given value to the back
	void pop_front(); //delete the head value
	void pop_back(); //delete the tail value
	Item_Type front(); //return the head
	Item_Type back();// return the tail
	bool empty(); //return whether or not the list is empty
	void insert(size_t ind, const Item_Type& item); //at a given index, insert a data value. If index is not found, insert at end
	bool remove(size_t ind); //remove a value at a given index
	size_t find(const Item_Type& item); //find a given value in the list. return -1 if not found
	void print_list(); //chronologically display the list to the user
	
};