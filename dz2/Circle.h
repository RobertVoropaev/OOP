#pragma once
class Circle {
	double x, y, r; //��������� �����
	double FieldSideX, FieldSideY;//������ ����
public:
	Circle();//�����������
	void move(double deltaX, double deltaY);//��������
	double getX();//�������� ���������� �� �
	double getY();//�������� ���������� �� �
	double getR();//�������� ������
	void scale(double k); // �������������� � k ���
	void setFieldSide(double sideX, double sideY);//���������� ������� ����
	void info();//�������� ��� ��������� 
};