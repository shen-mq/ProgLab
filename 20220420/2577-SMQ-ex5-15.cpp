/*********************************************************************
    程序名:ex5-15 Goldbach
    版权:
    作者: 2021212577 沈鸣谦
    日期: 2022-04-20 16:11
    说明:
*********************************************************************/
#include <iostream>
using namespace std;

int isprime(int n) {
	if (n <= 1)
		return 0;

	int k;
	for (k = 2; k * k <= n; k++) {
		if (n % k == 0)
			break;
	}
	return (k * k < n) ? 0 : 1;
}

int goldbach(int n, int &k1, int &k2) {
	if (n % 2 == 1 || n < 6) {
		return 0;
	}

	k1 = (n / 2) % 2 ? n / 2 : n / 2 + 1;
	for (k2 = n - k1; k1 <= n; k1 += 2, k2 = n - k1) {
		if (isprime(k1) && isprime(k2)) {
			return (k1 - k2 < n / 4 ? 1 : 0);
		}
	}
}

int main() {
	int m, m1, m2, found;

	for (m = 6; m <= 200; m += 2) {
		found = goldbach(m, m1, m2);
		cout << m << " = " << m1 << " + " << m2 << "\t" ;
		cout << (found ? "Yes" : "No") << '\t' << m1 - m2 << endl;
	}

	return 0;
}
