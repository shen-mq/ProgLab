/*********************************************************************
    ������: prog5-1   surface and volume of a cylinder
    ��Ȩ:
    ����: 2021212577 ����ǫ
    ����: 2022-04-13 16:12
    ˵��:
*********************************************************************/
#include <iostream>
using namespace std;

double surfcyl(double r, double h) {
	/*
	����Բ������������
	:r: Բ���İ뾶
	:h: Բ���ĸ�
	*/
	return 2 * 3.14159265 * r * h + 3.14159265 * r * r * 2;
}

double volcyl(double r, double h) {
	/*
	����Բ���������
	:r: Բ���İ뾶
	:h: Բ���ĸ�
	*/
	return 3.14159265 * r * r * h;
}

int main() {
	cout << surfcyl(1, 1);


	return 0;
}

