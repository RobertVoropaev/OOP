#pragma once
#include <iostream>
#include <cstring>
#include <string>
using namespace std;
class String {
	char *string;
public:
	String(char *str = "");//����������� �� ���������
	String(int a); //����������� � ��������� ����� ������
	String(const String &obj);//����������� �����
	~String(); //����������
	//������������
	String operator+(String a);
	String operator+(char *str);
	String operator+(char a);
	//������������
	String operator=(String a);
	String operator=(char *str);
	String operator=(char a);
	//�������� � �������������
	String operator+=(String a);
	String operator+=(char *str);
	String operator+=(char a);
	//����������
	String operator*(int a);
	String operator*=(int a);
	//������ � ��������
	char operator[](int a);
	//���� �����
	friend ostream& operator<<(ostream &stream, String &a);
	friend istream& operator>>(istream &stream, String &a);
	//�������������� 
	bool operator==(String a);
	bool operator!=(String a);
};
