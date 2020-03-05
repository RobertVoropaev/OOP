#include "StackArray.h" 

Stack::Stack() {
	for (int i = 0; i < 2; i++) stack[i] = 0;
	top = -1;
}

void Stack::push(int a) {
		top++;
		stack[top] = a;
}
int Stack::pop() {
		int k = stack[top];
		stack[top] = 0;
		top--;
		return k;
}
int Stack::getNumber() {
	return top + 1;
}
