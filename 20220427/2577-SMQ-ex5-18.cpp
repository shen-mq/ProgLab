/*********************************************************************
    程序名:ex5-18
    版权:
    作者: 2021212577 沈鸣谦
    日期: 2022-04-27 16:17
    说明:
*********************************************************************/
#include <iostream>
using namespace std;

int fib1(int a, int b, int n) {
	return n <= 1 ? a : fib1(b, a + b, n - 1);
}

int fib(int n) {
	return fib1(1, 1, n);
}

int fibV2(int n) {
	return n <= 2 ? 1 : fibV2(n - 1) + fibV2(n - 2);
}

int main() {
	cout << fib(60) << endl << fibV2(60);

	return 0;
}

