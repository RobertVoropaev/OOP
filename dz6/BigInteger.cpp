#include "BigInteger.h"
//Конструктор из числа
BigInteger::BigInteger(long long a) {
	n = 0;
	for (int i = 0; i < 250; i++) m[i] = 0;
	if (a >= 0) signplus = true;//Установка знака
	else {
		signplus = false;
		a *= (-1);//Если отрицательный, то установить знак и дальше считанное число считать как модуль
	}
	while (a != 0) { //Запись числа в массив
		m[n] = a%10;
		a /= 10;
		n++;
	}
}
//Конструктор из строки
BigInteger::BigInteger(const char *st) {
	n = 0;
	for (int i = 0; i < 250; i++) m[i] = 0;
	int l = strlen(st); //Длина считаной строки
	char str[250];
	for (int i = 0; i < l; i++) str[i] = st[i]; //Коприрование в новую строку
	if (str[0] == '-' || str[0] == '+') {//Если указан знак числа, то установить его и удалить из строки
		if (str[0] == '-') signplus = false;
		else signplus = true;
		for (int i = 1; i < l; i++) {
			str[i - 1] = str[i];
		}
		l--;
	}
	else signplus = true;//Если знак не указан - число положительное
	int u = 0; //Количество нулей вначала считанной строки
	for (int i = 0; i < l; i++) {//Подсчет количества нулей
		if (str[i] == '0') u++;
		else break;
	}
	if (u == l) {//Если в строке одни нули, записать как число 0
		signplus = true;
		m[0] = 0;
		n = 1;
	}
	else {//Если нули только вначале числа - удалить их
		for (int i = u; i < l; i++) {
			str[i - u] = str[i];//Смещение строки
		}
		l -= u;//Установка длины
		while (l) {//Запись числа в массив
			m[n] = str[l - 1] - '0';
			n++;
			l--;		
		}
	}
}
//Вывод числа
ostream& operator<<(ostream &stream, const BigInteger &A)
{
	if (!A.signplus) stream << '-'; //Вывести знак, если число орицательное
	for (int i = A.n - 1; i >= 0; i--) stream << A.m[i];
	return stream;
}
//Вывод из потока
istream& operator>>(istream &stream, BigInteger &A) {
	char str[250];// Строка, в которую будут записываться символы
	stream >> str; //Считывание символов
	BigInteger B(str);//
	A = B;
	return stream;
}

int compare(const BigInteger &A,const BigInteger &B) {
	if (A.n > B.n) return 1;//Сравнение длины чисел, если они различны - сразу вернуть большее число
	else if (A.n < B.n) return 2;
	else {
		for (int i = A.n - 1; i > -1; i--) { //Сравнение чисел от старшего разряда 
			if (A.m[i]>B.m[i]) return 1;
			else if (B.m[i] > A.m[i]) return 2;
		}
		return 0;//Если различий не найдено - числа одинаковые
	}
}
BigInteger BigInteger::operator=(const BigInteger &A) {
	signplus = A.signplus;
	n = A.n;
	for (int i = 0; i < 250; i++) {
		m[i] = A.m[i];
	}
	return *this;
}
BigInteger BigInteger::operator+(const BigInteger &A) const {
	BigInteger V;
	V.n = max(A.n, n);
	int r = 0;
	if ((A.signplus&&signplus) || ((!A.signplus) && (!signplus))) {//Если знаки одинаковые - сложить два числа по модулю и установить у модуля тот же знак 
		for (int i = 0; i < V.n; i++) {
			V.m[i] = m[i] + A.m[i] + r;
			if (V.m[i] >= 10) {
				r = 1;
				V.m[i] -= 10;
			}
			else r = 0;
		}
		if (r > 0) {
			V.n++;
			V.m[V.n - 1] = r;
		}
		if (!A.signplus&&!signplus) V.signplus = false;
	}
	else {//Если знаки разные - вычести из большего меньшее и установить знак большего
		int y = compare(*this, A);
		if (y == 1) {//Если первое больше второго
			V.n = n;
			int r = 0;
			for (int i = 0; i < V.n; i++) {
				V.m[i] = m[i] - A.m[i] - r;
				if (V.m[i] < 0) {
					r = 1;
					V.m[i] += 10;
				}
				else r = 0;
			}
			while (V.m[V.n - 1] == 0 && V.n > 1) V.n--;
			V.signplus = signplus;
		}
		else if (y == 2) {//Если второе больше первого
			V.n = A.n;
			int r = 0;
			for (int i = 0; i < V.n; i++) {
				V.m[i] = A.m[i] - m[i] - r;
				if (V.m[i] < 0) {
					r = 1;
					V.m[i] += 10;
				}
				else r = 0;
			}
			while (V.m[V.n - 1] == 0 && V.n > 1) V.n--;
			V.signplus = A.signplus;
		}
		else if (y == 0) {//Число равны - установит ноль
			V.n = 1;
			V.m[0] = 0;
		}
	}
	return V;
}
BigInteger BigInteger::operator-(const BigInteger &A) const {//Поменять знак вычитаемого на противоположный и обрабатывать как сложение
	BigInteger N1 = A;
	if (N1.signplus) N1.signplus = false;
	else N1.signplus = true;
	return *this + N1;
}
BigInteger BigInteger::operator+(long long a) const {
	BigInteger A(a);
	return *this + A;
}
BigInteger BigInteger::operator-(long long a) const {
	BigInteger A(a);
	return *this - A;
}
BigInteger operator+(long long a, const BigInteger &A) {
	BigInteger V(a);
	return V + A;
}
BigInteger operator-(long long a, const BigInteger &A) {
	BigInteger V(a);
	return V - A;
}