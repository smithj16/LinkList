#pragma once
//things are by default public in a struct 
#include<iostream>
using namespace std;

struct Node
{
	Node * previous;
	double value;
	Node * next;
	int number;

};


class LinkedList
{
public:
	// default constructor 
	LinkedList();
	// destructor
	~LinkedList();
	// Is Empty List?
	bool Empty();
	// PushBack
	void PushBack(double value);
	// PopBack
	void PopBack();
	// Operator << 
	friend ostream& operator << (ostream& ostr, const LinkedList & rhs);
	// return list size
	int size();
	// insert a value into the list 
	void insert(int index, double value);
	// erase a value in the list
	void erase(int index);
	// return index of the location of the value
	int find(int value);
	// reverse the order of the list 
	void reverse();
	
private:
	Node * head;

};
