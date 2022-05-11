/*********************************************************************
    程序名: prog5-7
    版权:
    作者: 2021212577 沈鸣谦
    日期: 2022-04-27 16:17
    说明:
*********************************************************************/
#include <iostream>
//#include <cstdlib>
using namespace std;

int gcd(int m, int n) {
	if (m < 0)
		m = -m;
	if (n < 0)
		n = -n;

	while (m != n) {
		if (n > m) {
			int t = m;
			m = n;
			n = t;
		}
		m = m - n;
	}
	return m;
}

int lcm(int m, int n) {
	return m * n / gcd(m, n);
}

int main() {
//	srand(0);
//	int m, n;
//	for (int i = 1; i <= 100; i++) {
//		m = rand() % (10) + 1;
//		n = rand() % (10) + 1;
//		cout << m << '\t' << n << '\t' << lcm(m, n) << endl;
//	}

	int m, n;
	cout << "Please input two (non-zero)integers : ";
	cin >> m >> n;
	cout << "The least commen mutiple of " << m << " and " << n << " is " << lcm(m, n);

	return 0;
}

