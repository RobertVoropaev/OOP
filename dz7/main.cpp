#include "DynamicArray.h"
#include <iostream>
#include <locale.h>
#include <conio.h>
using namespace std;
int main() {
	setlocale(LC_ALL, "Russian");
	cout << "Создание целочисленного значения на 10 элементов и с авторасширением на 10 элементов при переполении" << endl;
	DinamicArray<int> A(10, 10);
	cout << "Добавление элементов: ";
	for (int i = 0; i < 10; i++) {
		cout << i << " ";
		A.push_back(i);
	}
	cout << endl << "size: " << A.size() << " capacity: " << A.capacity() << endl << "Добавление ещё одного элемента: 10" << endl;
	A.push_back(10);
	cout << "size: " << A.size() << " capacity: " << A.capacity() << endl << "11 элемент массива равен " << A[10];
	_getch();
	return 0;
}