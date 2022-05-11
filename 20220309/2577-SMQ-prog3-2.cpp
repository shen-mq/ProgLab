/*********************************************************************
    程序名: programme 3-2
    版权:
    作者: 2021212577 沈鸣谦
    日期: 2022-03-09 15:57
    说明:
*********************************************************************/
#include <iostream>
#include <cmath>
using namespace std;

int main() {
	double a = 3, b = 4, c = 5, d = 5, theta = 145. / 2 * 3.14159265 / 180 ; //角度转换为弧度制
	double s, area;

	s = (a + b + c + d) / 2;
	area = sqrt((s - a) * (s - b) * (s - c) * (s - d) - a * b * c * d * cos(theta) * cos(theta));

	cout << "四边形的面积为：" << area << endl;

	return 0;
}

