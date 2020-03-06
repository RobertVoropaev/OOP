#include "String.h"
//Конструктор по умолчанию/преобразования из Си-строки
String::String(char *str) {
	int n = strlen(str) + 1;
	string = new char[n];
	strcpy_s(string, n, str);
}
//Конструктор строки заданой длины
String::String(int a) {
	string = new char[a + 1];
	strcpy_s(string, 1, "");
}
//Конструктор копирования
String::String(const String &obj) {
	int n = strlen(obj.string)+1;
	string = new char[n];
	strcpy_s(string, n, obj.string);
}
//Деструктор
String::~String() {
	delete[]string;
}
//Конкатенация
String String::operator+(String a) {
	int n = strlen(string) + strlen(a.string) + 1;
	String t(n);
	strcpy_s(t.string, n, string);
	strcat_s(t.string, n, a.string);
	return t;
}
String String::operator+(char *str) {
	int n = strlen(string) + strlen(str) + 1;
	String t(n);
	strcpy_s(t.string, n, string);
	strcat_s(t.string, n, str);
	return t;
}
String String::operator+(char a) {
	int n = strlen(string) + 1;
	String t(n);
	char str[2] = { a, 0 };
	strcpy_s(t.string, n, string);
	strcat_s(t.string, n, str);
	return t;
}
//Присваивание
String String::operator=(String a) {
	char *m;
	m = string;
	int n = strlen(a.string) + 1;
	string = new char[n];
	delete[]m;
	strcpy_s(string, n, a.string);
	return *this;
}
String String::operator=(char *str) {
	char *m;
	m = string;
	int n = strlen(str) + 1;
	string = new char[n];
	delete[]m;
	strcpy_s(string, n, str);
	return *this;
}
String String::operator=(char a) {
	char str[2] = { a, 0 };
	char *m;
	m = string;
	int n = strlen(str) + 1;
	string = new char[n];
	delete[]m;
	strcpy_s(string, n, str);
	return *this;
}
//Cложение с присваиванием
String String::operator+=(String a) {
	char *m;
	m = string;
	int n = strlen(string) + strlen(a.string) + 1;
	string = new char[n];
	strcpy_s(string, n, m);
	delete[] m;
	strcat_s(string, n, a.string);
	return *this;
}
String String::operator+=(char *str) {
	char *m;
	m = string;
	int n = strlen(string) + strlen(str) + 1;
	string = new char[n];
	strcpy_s(string, n, m);
	delete[] m;
	strcat_s(string, n, str);
	return *this;
}
String String::operator+=(char a) {
	char str[2] = { a, 0 };
	char *m;
	m = string;
	int n = strlen(string) + strlen(str) + 1;
	string = new char[n];
	strcpy_s(string, n, m);
	delete[] m;
	strcat_s(string, n, str);
	return *this;
}
//Повторение
String String::operator*(int a) {
	int n = strlen(string)*a + 1;
	String t(n);
	for (int i = 1; i <= a; i++) {
		strcat_s(t.string, n, string);
	}
	return t;
}
String String::operator*=(int a) {
	int n = strlen(string)*a + 1;
	char *str = new char[n];
	strcpy_s(str, n, string);
	char *m = string;
	string = new char[n];
	delete[] m;
	strcpy_s(string, n, str);
	for (int i = 1; i < a; i++) {
		strcat_s(string, n, str);
	}
	return *this;
}
//Вывод отдельного символа
char String::operator[](int a) {
	return string[a];
}
//Вывод из потока
ostream& operator<<(ostream &stream, String &a)
{
	stream << a.string;
	return stream;
}
//Ввод в поток
istream& operator>>(istream &stream, String &a) {
	char m[100000];
	stream >> m;
	int n = strlen(m) + 1;
	a.string = new char[n];
	strcpy_s(a.string, n, m);
	return stream;
}
//Сравнение
bool String::operator==(String a) {
	if (strcmp(string, a.string)) return false;
	else return true;
}
bool String::operator!=(String a) {
	if (strcmp(string, a.string)) return true;
	else return false;
}
