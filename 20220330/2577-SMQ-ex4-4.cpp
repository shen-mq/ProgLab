/*********************************************************************
    程序名: ex4-4 Fibonacci
    版权:
    作者: 2021212577 沈鸣谦
    日期: 2022-03-30 16:03
    说明:
*********************************************************************/

#include <iostream>
using namespace std;

int main() {
	int n;
	do {
		cout << "Please input n (between 3 and 46): ";
		cin >> n;
	} while ( n < 3 || n > 46 );

	int a = 1, b = 1;
	int tmp;
	cout << a << '\t' << b << '\t';
	int k = 2;
	while (k < n) {
		tmp = b;
		b = b + a;
		a = tmp;
		++k;
		cout << b << (k % 5 == 0 ? '\n' : '\t');
	}
	cout << "\nThe " << n << "th Fibonacci number is " << b << endl;
	return 0;
}
