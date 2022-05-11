/*********************************************************************
    ������: ex6-1
    ��Ȩ:
    ����: 2021212577 ����ǫ
    ����: 2022-05-11 16:22
    ˵��:
*********************************************************************/
#include <iostream>
using namespace std;

int main() {
	const int NUM = 30;
	int fib[NUM] = {1, 1};
	int n;

	for (n = 2; n <= NUM - 1; n++) {
		fib[n] = fib[n - 1] + fib[n - 2];
	}
	cout << "Fibonacci sequence: " << endl;
	for (n = 0; n < NUM; n++) {
		cout << fib[n] << (n % 5 != 4 ? '\t' : '\n');
	}

	return 0;
}

