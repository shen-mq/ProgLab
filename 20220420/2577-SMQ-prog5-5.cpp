/*********************************************************************
    程序名:prog5-5 Prime Decomposition
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

void prtPrimeDecomp(int n) {
	if (isprime(n)) {
		cout << n;
	} else if (n > 0) {
		bool flag = false;
		int i = 2;
		while (i <= n) {
			if (n % i == 0) {
				if (flag == false) {
					cout << i;
					n /= i;
					flag = true;
					continue;
				}
				cout << " * " << i;
				n /= i;
				continue;
			} else {
				i++;
			}
		}
	}
}


int main() {

	for (int i = 1; i <= 100; i++) {
		cout << i << "的质因数分解：";
		prtPrimeDecomp(i);
		cout << endl;
	}

	return 0;
}
