#pragma once
template <class T>
class DinamicArray {
	T *m;
	unsigned int Size, AutoPlus, n;
public:
	DinamicArray(unsigned int a = 100,unsigned int b = 100);
	DinamicArray(const DinamicArray &obj);
	~DinamicArray();
	int size() const { return n; }
	int capacity() const { return Size; }
	void push_back(const T &a);
	T &operator[](unsigned int a);
};
template <class T>
DinamicArray<T>::DinamicArray(unsigned int a,unsigned int b) {
	Size = a;
	AutoPlus = b;
	n = 0;
	m = new T[Size];
	for (int i = 0; i < Size; i++) m[i] = 0;
}
template <class T>
DinamicArray<T>::DinamicArray(const DinamicArray &obj) {
	Size = obj.Size;
	AutoPlus = obj.AutoPlus;
	n = obj.n;
	m = new T[Size];
	for (int i = 0; i < SIze; i++) m[i] = obj.m[i];
}
template <class T>
DinamicArray<T>::~DinamicArray() {
	delete[] m;
}
template <class T>
void DinamicArray<T>::push_back(const T &a) {
	if (n >= Size) {
		T *h;
		h = m;
		Size += AutoPlus;
		m = new T[Size];
		for (int i = 0; i < Size - AutoPlus; i++) m[i] = h[i];
		delete[] h;
		for (int i = Size - AutoPlus; i < Size; i++) m[i] = 0;
		m[n] = a;
	}
	else {
		m[n] = a;
	}
	n++;
}
template <class T>
T &DinamicArray<T>::operator[](unsigned int a) {
	if (a < Size) return m[a];
}

