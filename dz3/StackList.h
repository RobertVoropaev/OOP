#pragma once
class Stack {
	struct element;//Структура элементов списка
	element *head;//Указатель на последний элемент
	int n;//Число элементов
public:
	Stack();//Конструктор
	void push(int a);//Положить в стек
	int pop();//Достать из стека
	int getNumber();//Получить число элементов
};