/*********************************************************************
    程序名:prog7-1
    版权:
    作者:2021212577 沈鸣谦
    日期: 2022-05-25 16:21
    说明:
*********************************************************************/
#include <iostream>
using namespace std;

int main() {
	int *p, *q;
	double *px, *py;
	char *pch, *pchar1;

	int m = 0, n = 0;
	double a[10] = {0.};

	p = &m;
	q = &n;

	cout << p << '\t' << q << endl;
	cout << ++(*p) << endl;
	cout << --(*q) << endl;
	cout << p << '\t' << q << endl;

	px = &a[10];
	py = a;

	for (double *p0 = a; p0 < px; p0++) {
		(*p0)++;
		cout << *p0 << endl;
	}

	return 0;
}

