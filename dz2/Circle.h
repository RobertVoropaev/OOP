#pragma once
class Circle {
	double x, y, r; //Параметры круга
	double FieldSideX, FieldSideY;//Размер поля
public:
	Circle();//Конструктор
	void move(double deltaX, double deltaY);//Движение
	double getX();//Получить координату по у
	double getY();//Получить координату по х
	double getR();//Получить радиус
	void scale(double k); // Масштабировать в k раз
	void setFieldSide(double sideX, double sideY);//Установить стороны поля
	void info();//Показать все параметры 
};