#include <conio.h>
#include "String.h"
#include <locale.h>
using namespace std;
int main() {
	setlocale(LC_ALL, "Russian");
	cout << "�����:" << endl << "1: �����������" << endl;
	String a;
	cout << a << endl;//������ �� ���������
	char str[50];
	strcpy_s(str, 50, "�������������� �� ��-������");
	String b(str);
	cout << b << endl << "2: ������������" << endl;
	a = "�������";
	char st[50];
	strcpy_s(st, 50, "�����");
	a += st;
	cout << a << endl << "3: ���������� � ����������" << endl;
	String c;
	c = a * 3;
	cout << c << endl << "4: ������ � ��������" << endl << c[4] << endl << "5: ���������" << endl;
	String f("22");
	String e("22");
	if (f == e) cout << "������ ����������";
	else cout << "������ ������";
	_getch();
	return 0;
}