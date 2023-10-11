#include "linked.h"
template<typename Item_Type>


//default constructor, list is empty
Single_Linked_List<Item_Type>::Single_Linked_List()
{
	head = nullptr;
	tail = nullptr;
	num_items = 0;
}

//add item to front of list
template<typename Item_Type>
void Single_Linked_List<Item_Type>::push_front(Item_Type b)
{
	if (head == nullptr) { //if list is empty
		Node* huv = new Node; 
		head = huv;
		head->data = b;
		head->nextPtr = nullptr;
		num_items++;
		tail = head; //since list only has one, head is also tail
		return;
	}
	//if nodes already exist in the list:
	Node* huv = new Node; 
	huv->data = b;
	huv->nextPtr = head;
	head = huv;
	num_items++;
	return;

}

//add to back of list
template<typename Item_Type>
void Single_Linked_List<Item_Type>::push_back(Item_Type b)
{
	if (head == nullptr) {//if list is empty
		Node* nu = new Node;
		nu->data = b;
		nu->nextPtr = nullptr;
		head = nu;
		tail = nu; //head and tail are same value
		num_items++;
		return;
	}
	//if not empty
	Node* ryg = new Node;
	ryg->data = b;
	ryg->nextPtr = nullptr;
	tail->nextPtr = ryg;
	tail = ryg; //set tail to new data
	num_items++;
}
//delete head node
template<typename Item_Type>
void Single_Linked_List<Item_Type>::pop_front()
{
	if (empty()) { return; } //cannot remove from empty list
	Node* t = head;
	head = head->nextPtr;
	delete t; //freeing up memory from old head
	if (head == nullptr) { tail = nullptr; } //if now empty, tail is also null
	num_items--;
	return;
}

//remove back value
template<typename Item_Type>
void Single_Linked_List<Item_Type>::pop_back()
{
	if (empty()) { return; } //cannot remove from empty list
	if (head == tail) { //if only one value in list, empty list
		delete tail; //free up memory
		head = nullptr;
		tail = nullptr;
		num_items--;
		return;
	}
	Node* h = head;
	while (h->nextPtr != tail) { //finding value before the tail to make it the tail
		h = h->nextPtr;
	}
	delete tail;
	tail = h;
	tail->nextPtr = nullptr;
	num_items--;
	return;
}
//returning the front value
template<typename Item_Type>
Item_Type Single_Linked_List<Item_Type>::front()
{
	if (empty()) { //if list is empty
		throw runtime_error("List is empty!");
	}
	return head->data;
}
//returning back value
template<typename Item_Type>
Item_Type Single_Linked_List<Item_Type>::back()
{
	if (empty()) { //if list is empty
		throw runtime_error("List is empty!"); 
	}
	return tail->data;
}
//determine whether anything exists in the list
template<typename Item_Type>
bool Single_Linked_List<Item_Type>::empty()
{
	if (head == nullptr) { return true; }
	return false;
}
//insert a node at a given index
template<typename Item_Type>
void Single_Linked_List<Item_Type>::insert(size_t ind, const Item_Type& item)
{
	if (num_items <= ind) { push_back(item); } //if out of range, add to the end
	else if (ind == 0) { push_front(item); } //if at the front, use previous function
	else { //if index exists
		Node* nu = new Node;
		nu->data = item;
		Node* it = head;
		for (size_t i = 1; i < ind; i++) { //find node before given index
			it = it->nextPtr;
		}
		nu->nextPtr = it->nextPtr;
		it->nextPtr = nu;
		num_items++;
	}
	return;
}
//remove a node from a given index
template<typename Item_Type>
bool Single_Linked_List<Item_Type>::remove(size_t ind)
{
	if (ind >= num_items) { return pop_back(); } //if index out of range, remove from end
	if (ind == 0) { pop_front(); } //if removing from front
	else { //if index is in range
		Node* it = head;
		for (size_t i = 1; i < ind; i++) { //find node before given index
			it = it->nextPtr;
		}
		Node* dele = it->nextPtr;
		it->nextPtr = dele->nextPtr;
		delete dele;
		num_items--;
	}
	return true;
}

//return the index of a specific node given its data
template<typename Item_Type>
size_t Single_Linked_List<Item_Type>::find(const Item_Type& item)
{
	Node* sok = head;
	size_t i = 0;
	while (sok != nullptr) { //while not at end, starting from head, iterate through checking if found
		if (sok->data == item) {
			return i;
		}
		sok = sok->nextPtr;
		i++;
	}
	return -1; //if not found
}

//displaying for the user
template<typename Item_Type>
void Single_Linked_List<Item_Type>::print_list() {
	cout << "\nThe current list:";
	for (Node* skriv = head; skriv != nullptr; skriv = skriv->nextPtr) {
		cout << skriv->data << " ";
	}
	cout << "\n";
	return;
}