/*********************************************************************
    程序名: ex4-3
    版权:
    作者: 2021212577 沈鸣谦
    日期: 2022-03-30 16:03
    说明:
*********************************************************************/
#include <iostream>
#include <cmath>
using namespace std;

int main() {
	double x, x1, x2;

	cout << "Please input x: ";
	cin >> x;
	if (x == 0) {
		cout << "cubic root of " << x << " is：" << x;
		return 0;
	}

	x2 = x;
	do {
		x1 = x2;
		x2 = (2.*x1 + x / (x1 * x1)) / 3.;
		cout << x2 << endl;
	} while (fabs((x2 - x1) / x1) >= 1e-6);
	cout << "cubic root of " << x << " is：" << x2;
	return 0;
}
