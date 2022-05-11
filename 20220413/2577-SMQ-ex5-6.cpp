/*********************************************************************
    程序名: ex5-6
    版权:
    作者: 2021212577 沈鸣谦
    日期: 2022-04-13 16:12
    说明:
*********************************************************************/
#include <iostream>
#include <cmath>
using namespace std;

double scircle(double radius) {
	double area = 3.14159265 * radius * radius;
	return area;
}

double srect(double a, double b) {
	return a * b;
}

void prtStars() {
	cout << "********************" << endl;
//	return;
}

int main() {
	double s;
	prtStars();

	s = scircle(2.4);
	cout << "s = " << s << endl;
	s = scircle(2.4 + sin(1.57));
	cout << "s = " << s << endl;
	cout << scircle(1.5 + 2.4) << endl;

	double r = 1.5;
	s = scircle(r);
	cout << "s = " << s << endl;
	cout << scircle(2 * r) << endl;

	prtStars();
	s = srect(3.5, 4.2);
	cout << "s = " << s << endl;
	s  = srect(3 * sin(2.), 5 * cos(5.2));
	cout << "s = " << s << endl;

	double length = 3.5, width = 4.2;
	s = srect(length, width);
	cout << "s = " << s << endl;
	cout << "s = " << srect(length, width) << endl;

	prtStars();

	return 0;
}

