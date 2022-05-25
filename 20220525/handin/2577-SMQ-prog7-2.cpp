/*********************************************************************
    程序名:
    版权:
    作者:2021212577 沈鸣谦
    日期: 2022-05-25 16:21
    说明:
*********************************************************************/
#include <iostream>
using namespace std;

//ex5-8
void swap(int a, int b) {
	int k = a;
	a = b;
	b = k;
	cout << "swap: a=" << a << ", b=" << b << endl;;
}

//ex5-9
void swapref(int &a, int &b) {
	int k = a;
	a = b;
	b = k;
	cout << "swaped inside: a= " << a << "  b= " << b << endl;
}

//ex7-1
void swapptr(int *p, int *q) {
	int t = *p;
	*p = *q;
	*q = t;
}

int main() {

	int m = 10, n = 25;
	cout << "before swap: m = " << m << "  n = " << n << endl;
	swap(m, n);
	cout << "after swap: m = " << m << "  n = " << n << endl << endl;

	m = 10, n = 25;
	cout << "before swapref: m = " << m << "  n = " << n << endl;
	swapref(m, n);
	cout << "after swapref: m = " << m << "  n = " << n << endl << endl;

	m = 10, n = 25;
	cout << "before swapptr: m = " << m << "  n = " << n << endl;
	swapptr(&m, &n);
	cout << "after swapptr: m = " << m << "  n = " << n << endl << endl;

	return 0;
}

