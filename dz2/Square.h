#pragma once
class Square {
	double x, y, side; //��������� ��������
	double FieldSideX, FieldSideY;//������ ����
public:
	Square();//�����������
	void move(double deltaX, double deltaY);//��������
	double getX();//�������� ���������� �� �
	double getY();//�������� ���������� �� �
	double getSide();//�������� ������
	void scale(double k); // �������������� � k ���
	void setFieldSide(double sideX, double sideY);//���������� ������� ����
	void info();//�������� ��� ��������� 
};