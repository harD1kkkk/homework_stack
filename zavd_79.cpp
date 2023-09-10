// zavd_79.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
#include "List.h"

void putNodeToTail(List*& head, int value) {
	List* n = new List(value);

	if (head == nullptr)
	{
		head = n;
		return;
	}

	List* temp = new List();

	temp = head;

	while (temp->next != nullptr)
	{
		temp = temp->next;
	}
	temp->next = n;
}
void display(List*& head) {
	List* temp = new List();
	temp = head;

	while (temp != nullptr)
	{
		cout << temp->value << " ";

		temp = temp->next;
	}
}


int countNegative(List* head) {
	List* temp = new List();
	temp = head;

	int neggative = 0;

	while (temp != nullptr)
	{
		if (temp->value < 0)
		{
			neggative++;
		}
		temp = temp->next;
	}
	return neggative;
}

void removeElement(List*& head, int toRemove) {
	if (head->value == toRemove)
	{
		head = head->next;
	}

	List* temp = new List();
	temp = head;

	while (temp->next != nullptr)
	{
		if (temp->next->value == toRemove && temp->next->next == nullptr)
		{
			temp->next = nullptr;
			break;
		}

		if (temp->next->value == toRemove)
		{
			temp->next = temp->next->next;
		}

		temp = temp->next;
	}
}

void incrementValue(List* head, int increment) {
	List* temp = new List();
	temp = head;

	while (temp != nullptr)
	{
		temp->value += increment;
		temp = temp->next;
	}
}

void inputElements(List*& head, int after, int input) {
	List* temp = new List();
	temp = head;

	while (temp != nullptr)
	{
		if (temp->value == after)
		{
			temp->next = new List(input, temp->next);

		}
		temp = temp->next;
	}
}


int main()
{
	srand(time(NULL));
	List* list = new List();

	for (int i = 1; i < 10; i++)
	{
		putNodeToTail(list, rand() % 10 + 1);
		putNodeToTail(list, rand() % (10 + 1) * -1);
	}

	cout << "List of numbers: " << endl;
	display(list);	
	cout << endl;

	cout << "Number of negative values: ";
	cout << countNegative(list) << endl;

	int num = 0;
	cout << "Enter how much to enlarge the element ";
	cin >> num;
	cout << endl;
	incrementValue(list, num);
	display(list); 
	cout << endl;

	int remove;
	cout << "Enter number to remove: "; 
	cin >> remove;

	cout << "Removed element is: " << remove << endl;
	removeElement(list, remove);
	display(list); 
	cout << endl;

	int input = 0;
	int after = 0;

	cout << "Enter number to input: "; 
	cin >> input;

	cout << "Enter after number: "; 
	cin >> after;

	inputElements(list, after, input);
	display(list);
}