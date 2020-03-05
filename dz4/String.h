#pragma once
#include <iostream>
#include <cstring>
#include <string>
using namespace std;
class String {
	char *string;
public:
	String(char *str = "");//Конструктор по умолчанию
	String(int a); //Конструктор с передачей длины строки
	String(const String &obj);//Конструктор копий
	~String(); //Деструктор
	//Конкатенация
	String operator+(String a);
	String operator+(char *str);
	String operator+(char a);
	//Присваивание
	String operator=(String a);
	String operator=(char *str);
	String operator=(char a);
	//Сложение с присваиванием
	String operator+=(String a);
	String operator+=(char *str);
	String operator+=(char a);
	//Повторение
	String operator*(int a);
	String operator*=(int a);
	//Доступ к элементу
	char operator[](int a);
	//Ввод вывод
	friend ostream& operator<<(ostream &stream, String &a);
	friend istream& operator>>(istream &stream, String &a);
	//Дополнительные 
	bool operator==(String a);
	bool operator!=(String a);
};
