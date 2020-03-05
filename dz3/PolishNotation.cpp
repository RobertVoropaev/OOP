#include "PolishNotation.h"
#include "StackList.h"

int PolishNotation(char *str, bool &error) {
	Stack s;
	error = false;
	while (*str) {
		if (*str >= 48 && *str <= 57 && s.getNumber() < 2) s.push(*str-48);
		else if (*str == '+' && s.getNumber() == 2) s.push(s.pop() + s.pop());
		else if (*str == '-' && s.getNumber() == 2) s.push(s.pop() - s.pop());
		else if (*str == '*' && s.getNumber() == 2) s.push(s.pop() * s.pop());
		else if ((*str == '/') && (s.getNumber() == 2) && ((*(str-2)-48) != 0)) s.push(s.pop() / s.pop());
		else {
			error = true;
			break;
		}
		*str++;
	}
	if(s.getNumber()==1) return s.pop();
	else {
		error = true;
		return 0;
	}
}