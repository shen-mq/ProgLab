/*********************************************************************
    ������: �ڶ�����ϰ�� 2-7, 2-8, 2-9
    ��Ȩ:
    ����: 2021212577 ����ǫ
    ����: 2022-03-02 16:27
    ˵��:
*********************************************************************/
#include <iostream>
#include <cmath>
using namespace std;

int main() {
	cout << "2-7" << endl;
	cout << 3 * (int)sqrt(34) - sin(6) * 5 << endl;
	cout << cos(2.5f + 4) - 6 * 27L + 100 << endl;
	cout << fabs(-2) + ceil(8.6) + 10 << endl;
	cout << floor(8.6) + round(16.6) + 5 << endl;

	cout << "2-8" << endl;
	cout << sqrt(3.1415927 * 3.1415927 + 1) << endl;
	cout << log(sqrt(2 * 3.1415927 - 1)) / log(5.) << endl;
	cout << exp(sqrt(3.1415927 + 1)) << endl;
	cout << atan(log(2.718281828 + 3.1415927) / log(3)) << endl;
	cout << sqrt((13 - pow(2.24 - 0.24 * 0.24, 2)) / 3.68) << endl;
	cout << log(2 * 3.1415927 * sqrt(13 + 2.718281828)) << endl;

	cout << "2-9" << endl;
	double a = 3, b = 5, c = 7;
	double s;

	s = (a + b + c) / 2;
	cout << "�����ε����Ϊ��" << sqrt(s * (s - a) * (s - b) * (s - c)) << " cm^2";

	return 0;
}
