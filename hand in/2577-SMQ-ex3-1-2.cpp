/*********************************************************************
    程序名: ex 3-1 and 3-2
    版权:
    作者: 2021212577 沈鸣谦
    日期: 2022-03-09 15:57
    说明:
*********************************************************************/
#include <iostream>
#include <cmath>
using namespace std;

//int main() {
//	double a, b, c, s, area;//定义变量
//	a = 3;
//	b = 5;
//	c = 7;
//	s = (a + b + c) / 2;
//	area = sqrt(s * (s - a) * (s - b) * (s - c));
//	cout << "Area = " << area << endl;
//
//	return 0;
//}

//int main() {
//	double a = 3, b = 5, c = 7;
//	double s = (a + b + c) / 2.0;
//	double area = sqrt(s * (s - a) * (s - b) * (s - c));
//	cout << "Area = " << area << endl;
//
//	return 0;
//}

//int main() {
//	double a = 3, b = 5, c = 7, s;
//	s = (a + b + c) / 2.0;
//	cout << "Area = " << sqrt(s * (s - a) * (s - b) * (s - c)) << endl;
//
//	return 0;
//}

int main() {
	double s = (3 + 5 + 7) / 2.0;
	cout << "Area = " << sqrt(s * (s - 3) * (s - 5) * (s - 7)) << endl;

	return 0;
}