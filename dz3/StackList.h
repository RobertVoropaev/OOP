#pragma once
class Stack {
	struct element;//��������� ��������� ������
	element *head;//��������� �� ��������� �������
	int n;//����� ���������
public:
	Stack();//�����������
	void push(int a);//�������� � ����
	int pop();//������� �� �����
	int getNumber();//�������� ����� ���������
};