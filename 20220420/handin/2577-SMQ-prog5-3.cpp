/*********************************************************************
    程序名:prog5-3 printing factors of integers
    版权:
    作者: 2021212577 沈鸣谦
    日期: 2022-04-20 16:11
    说明:
*********************************************************************/
#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;

void prtFactors(int n) {
	for (int i = 1; i <= n; i++) {
		if (n % i == 0) {
			cout << i << '\t';
		}
	}
}

//void prtFactors2(int n) {
//	for (int i = 1; i <= sqrt(n); i++) {
//		if (n % i == 0) {
//			cout << i << " * " << n / i << ", " << '\t';
//		}
//	}
//}


int main() {

//	int t0, t1, t2;
//
//	t0 = clock();

	for (int i = 10; i <= 100; i++) {
		cout << "The factors of " << i << " : ";
		prtFactors(i);
		cout << endl;
	}

//	t1 = clock();

//	for (int i = 10; i <= 100; i++) {
//		cout << "The factors of " << i << " : ";
//		prtFactors2(i);
//		cout << endl;
//	}

//	t2 = clock();

//	cout << (double)(t1 - t0) / CLOCKS_PER_SEC << '\t' << (double)(t2 - t1) / CLOCKS_PER_SEC;

	return 0;
}
