#pragma once
#include <iostream>
using namespace std;
class Matrix {
protected:
	double **matrix;
	int sizeN, sizeM;
public:
	Matrix(int a, int b); 
	Matrix(const Matrix &obj);
	~Matrix();
	Matrix operator=(const Matrix &A);
	Matrix operator+(const Matrix &A) const;
	Matrix operator+=(const Matrix &A); 
	Matrix operator*(double a) const; 
	Matrix operator*=(double a); 
	Matrix operator/(double a) const; 
	Matrix operator/=(double a); 
	friend Matrix operator*(double a, const Matrix &A);
	Matrix operator*(const Matrix &A) const; 
	Matrix operator*=(const Matrix &A); 
	double operator()(int a, int b) const; 
	friend Matrix tran(const Matrix &A); 
	friend ostream& operator<<(ostream &stream, const Matrix &A); 
	friend istream& operator>>(istream& stream, Matrix &A); 
	bool operator==(const Matrix &A) const;
	bool operator!=(const Matrix &A) const;
};
