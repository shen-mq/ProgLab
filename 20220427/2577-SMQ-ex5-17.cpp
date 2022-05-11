/*********************************************************************
    程序名: ex5-17
    版权:
    作者: 2021212577 沈鸣谦
    日期: 2022-04-27 16:17
    说明:
*********************************************************************/
#include <iostream>
using namespace std;

double dexp1(int n) {
	return n == 0 ? 1 : 2.718281828 * dexp1(n - 1);
}

double dexp(int n) {
	return n >= 0 ? dexp1(n) : 1 / dexp(-n);
}

double dexploop(int n) {
	double x = 2.718281828, d = 1;
	int i;
	if (n < 0) {
		n = -n;
		x = 1 / x;
	}
	for (i = 0; i < n; i++) {
		d *= x;
	}
	return d;
}

int main() {
	cout << dexp(1) << endl;
	cout << dexploop(1);
	return 0;
}

