#pragma once

#include <iostream>
#include <list>

using namespace std;

//class implementing a queue

class Queue {
public:
	//adding to the queue
	void enqueue(int val) {
		uppstall.push_back(val);
	}
	//removing from the queue
	int dequeue() {
		if (isEmpty()) { //if already empty
			cout << "Unable to dequeue an empty queue";
			return -1;
		}
		int framsida = uppstall.front();
		uppstall.pop_front(); //removing value we're returning
		return framsida;
	}
	//returns front value (first value entered)
	int front() {
		if (isEmpty()) { //if already empty
			cout << "Unable to dequeue an empty queue";
			return -1;
		}
		return uppstall.front();
	}
	//whether or not empty
	bool isEmpty() { 
		return uppstall.empty();
	}
	//returns size
	size_t size() {
		return uppstall.size();
	}
private: 
	list<int> uppstall; //list queue we use in class
};
