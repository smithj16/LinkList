#include<iostream>
#include"Linkedlist.h"
#include<list>

using namespace std;

int main()
{

	LinkedList x;
	x.PushBack(9);
	cout << x;
	x.PushBack(14);
	cout << x;
	x.PushBack(1);
	cout << x;
	x.PushBack(3);
	cout << x;
	x.PushBack(17);
	cout << x;
	x.PopBack();
	cout << x;
	x.PopBack();
	cout << x;
	x.PopBack();
	cout << x;
	x.PopBack();
	cout << x;

	x.insert(1, 2);
	cout << x;
	x.erase(1);
	cout << x;
	x.PushBack(3);
	x.PushBack(10);
	x.PushBack(5);
	x.reverse();
	cout << x;
	cout << x.find(5) << endl; 
	cout << x.size() << endl; 

	system("pause");
	return 0;
}
