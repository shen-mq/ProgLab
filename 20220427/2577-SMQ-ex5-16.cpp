/*********************************************************************
    程序名: ex5-16
    版权:
    作者: 2021212577 沈鸣谦
    日期: 2022-04-27 16:17
    说明:
*********************************************************************/
#include <iostream>
using namespace std;

int factloop(int n) {
	int fac = 1;
	for (int i = 1; i <= n; i++) {
		fac *= i;
	}
	return fac;
}

int fact(int n) {
	return n == 0 ? 1 : n * fact(n - 1);
}

int main() {
	cout << factloop(10);

	return 0;
}

