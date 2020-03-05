#include "StackList.h"

Stack::Stack() {
	head = 0;
}

struct Stack::element{
	int value;
	element *next;
};

void Stack::push(int a) {
	element *temp = new element;
	temp->value = a;
	temp->next = head;
	head = temp;
	n++;
}

int Stack::pop() {
	element *temp;
	int a = head->value;
	temp = head->next;
	delete head;
	head = temp;
	n--;
	return a;
}

int Stack::getNumber() {
	return n;
}