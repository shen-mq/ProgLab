/*********************************************************************
    ������:prog5-4 "perfect number"
    ��Ȩ:
    ����: 2021212577 ����ǫ
    ����: 2022-04-20 16:11
    ˵��:
*********************************************************************/
#include <iostream>
using namespace std;

int isperfect(int n) {
	int sum = 0;
	for (int i = 1; i < n; i++) {
		if (n % i == 0) {
			sum += i;
		}
	}
	return sum == n ? 1 : 0;
}

int main() {
	for (int i = 1; i <= 10000; i++) {
		if (isperfect(i)) {
			cout << i << '\t';
		}
	}

	return 0;
}
