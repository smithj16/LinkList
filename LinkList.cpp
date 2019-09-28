#pragma once
#include"LinkedList.h"
#include<iostream>

using namespace std;

LinkedList::LinkedList()
	:head(nullptr)
{
	//nothing here
}

LinkedList :: ~LinkedList()
{
	Node * current = head;
	while (current != nullptr)
	{
		Node * next = current->next;
		delete current;
		current = next;
	}
	head = nullptr;
}

bool LinkedList::Empty()
{
	return (head == nullptr);
}

void LinkedList::PushBack(double value)
{
	Node * node = new Node;
	node->value = value;
	node->next = nullptr;

	if (Empty())
	{
		node->previous = nullptr;
		head = node;

	}

	else
	{
		Node*current = head;
		while (current->next != nullptr)
		{
			current = current->next;
		}
		current->next = node;
		node->previous = current;
	}
}
void LinkedList::PopBack()
{
	Node* current = head;
	while (current->next != nullptr)
	{
		current = current->next;
	}
	if (current->previous != nullptr)
	{

		current->previous->next = nullptr;
	}
	else
	{
		head = nullptr;
	}

	delete current;
}
ostream& operator << (ostream& ostr, const LinkedList& rhs)
{
	Node * current = rhs.head;
	while (current != nullptr)
	{
		ostr << current->value << " ";
		current = current->next;
	}
	ostr << endl;
	return ostr;
}

int LinkedList::size()
{
	Node *p1;
	int count = 0;

	if (Empty() == true)
	{
		return count;
	}

	else
	{
		p1 = head;

		while (p1->next)
		{
			p1 = p1->next;
			++count;
		}
		return count + 1;
	}

}

void LinkedList::insert(int index, double value)
{
	Node* prev = new Node;
	Node* curr = new Node;
	Node* newNode = new Node;
	newNode->number = value;

	int position = 0;   // moves through out the list
	curr = head;      

	if (head != NULL) //list isnt empty
	{
		while (curr->next != NULL && position != index)
		{
			prev = curr;
			curr = curr->next;
			position++;
		}
		if (index == 0) //add at head
		{
			head = newNode;
			newNode->next = curr;
		}
		else if (curr->next == NULL && index == position + 1) 
		{
			PushBack(value);
		}
		else if (index > position + 1)
		{
			PushBack(value);
		}

		else // add node into correct position
		{
			prev->next = newNode;
			newNode->next = curr;
		}
	}
	else //list is empty
	{
		head = newNode;
		newNode->next = NULL;
	}

}

void LinkedList::erase(int index)
{
	Node* current1 = new Node;
	Node* prev1 = new Node;
	Node* newNode = new Node;

	int position = 0;   // Traverses through the list
	current1 = head;      // current points to head;

	if (head != NULL)
	{
		while (current1->next != NULL && position != index)
		{
			prev1 = current1;
			current1 = current1->next;
			position++;
		}
		if (index == 0) //delete the head
		{
			current1 = current1->next;
			delete head;
			head = current1;

		}
		else if (current1->next == NULL && index == position + 1) //delete the last node
		{
			PopBack();
		}
		else if (index > position + 1)
			cout << "nothing to erase " << endl;

		else
		{
			prev1->next = current1->next;
			delete current1;
		}
	}
	else
	{
		return;
	}
}

int LinkedList::find(int value)
{
	int count = 0, find = -1;
	Node *p = new Node;
	p = head;
	while (!Empty())
	{
		if (p->number = value)
		{
			find = count;
			break;
		}
		else
		{
			p = p->next;
			++count;
		}
	}
	return find;
}

void LinkedList::reverse()
{
	if (head == NULL)
	{
		return;
	}

	Node *prev = NULL, *current = NULL, *next = NULL;
	current = head;
	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}

	head = prev;
}

