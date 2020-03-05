#pragma once
class Stack {
	int top;//Индекс последнего элемента в массиве
	int stack[2];//Стек
public:
	Stack();//Конструктор
	void push(int a);//Положить в стек
	int pop();//Достать из стека
	int getNumber();//Получить число элелементов
};