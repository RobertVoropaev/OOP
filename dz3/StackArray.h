#pragma once
class Stack {
	int top;//������ ���������� �������� � �������
	int stack[2];//����
public:
	Stack();//�����������
	void push(int a);//�������� � ����
	int pop();//������� �� �����
	int getNumber();//�������� ����� �����������
};