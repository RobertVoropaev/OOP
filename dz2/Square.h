#pragma once
class Square {
	double x, y, side; //Параметры квадрата
	double FieldSideX, FieldSideY;//Размер поля
public:
	Square();//Конструктор
	void move(double deltaX, double deltaY);//Движение
	double getX();//Получить координату по у
	double getY();//Получить координату по х
	double getSide();//Получить радиус
	void scale(double k); // Масштабировать в k раз
	void setFieldSide(double sideX, double sideY);//Установить стороны поля
	void info();//Показать все параметры 
};