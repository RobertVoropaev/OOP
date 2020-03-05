#include <conio.h>
#include "String.h"
#include <locale.h>
using namespace std;
int main() {
	setlocale(LC_ALL, "Russian");
	cout << "Тесты:" << endl << "1: Конструктор" << endl;
	String a;
	cout << a << endl;//Ничего не выводится
	char str[50];
	strcpy_s(str, 50, "Преобразование из Си-строки");
	String b(str);
	cout << b << endl << "2: Конкатенация" << endl;
	a = "Конкате";
	char st[50];
	strcpy_s(st, 50, "нация");
	a += st;
	cout << a << endl << "3: Повторение и присвоение" << endl;
	String c;
	c = a * 3;
	cout << c << endl << "4: Доступ к символам" << endl << c[4] << endl << "5: Сравнение" << endl;
	String f("22");
	String e("22");
	if (f == e) cout << "Строки одинаковые";
	else cout << "Строки разные";
	_getch();
	return 0;
}