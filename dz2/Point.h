#pragma once
class Point {
	double x, y; //Координаты точки
	double FieldSideX, FieldSideY;//Размер поля
public:
	Point();//Конструктор
	void move(double deltaX, double deltaY);//Движение
	double getX();//Получить координату по у
	double getY();//Получить координату по х
	void setFieldSide(double sideX, double sideY);//Установить стороны поля
	void info();//Показать все параметры 
};