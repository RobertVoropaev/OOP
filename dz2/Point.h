#pragma once
class Point {
	double x, y; //���������� �����
	double FieldSideX, FieldSideY;//������ ����
public:
	Point();//�����������
	void move(double deltaX, double deltaY);//��������
	double getX();//�������� ���������� �� �
	double getY();//�������� ���������� �� �
	void setFieldSide(double sideX, double sideY);//���������� ������� ����
	void info();//�������� ��� ��������� 
};