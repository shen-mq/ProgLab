/*********************************************************************
    ������: programme 3-2
    ��Ȩ:
    ����: 2021212577 ����ǫ
    ����: 2022-03-09 15:57
    ˵��:
*********************************************************************/
#include <iostream>
#include <cmath>
using namespace std;

int main() {
	double a = 3, b = 4, c = 5, d = 5, theta = 145. / 2 * 3.14159265 / 180 ; //�Ƕ�ת��Ϊ������
	double s, area;

	s = (a + b + c + d) / 2;
	area = sqrt((s - a) * (s - b) * (s - c) * (s - d) - a * b * c * d * cos(theta) * cos(theta));

	cout << "�ı��ε����Ϊ��" << area << endl;

	return 0;
}

