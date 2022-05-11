/*********************************************************************
    程序名: prog5-1   surface and volume of a cylinder
    版权:
    作者: 2021212577 沈鸣谦
    日期: 2022-04-13 16:12
    说明:
*********************************************************************/
#include <iostream>
using namespace std;

double surfcyl(double r, double h) {
	/*
	计算圆柱的外表面积。
	:r: 圆柱的半径
	:h: 圆柱的高
	*/
	return 2 * 3.14159265 * r * h + 3.14159265 * r * r * 2;
}

double volcyl(double r, double h) {
	/*
	计算圆柱的体积。
	:r: 圆柱的半径
	:h: 圆柱的高
	*/
	return 3.14159265 * r * r * h;
}

int main() {
	cout << surfcyl(1, 1);


	return 0;
}

