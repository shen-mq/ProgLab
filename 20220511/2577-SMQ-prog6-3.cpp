/*********************************************************************
    程序名:prog6-3
    版权:
    作者: 2021212577 沈鸣谦
    日期: 2022-05-11 16:22
    说明:
*********************************************************************/
#include <iostream>
#include <ctime>
using namespace std;

int main() {
	int len, num[100000], interval[32] = {0};
	len = RAND_MAX / 32;

	srand(0);

	for (int i = 0; i < 100000; i++) {
		num[i] = rand();
		interval[num[i] / len]++;
	}

	for (int i = 0; i < 32; i++) {
		cout << interval[i] << (i % 5 != 4 ? '\t' : '\n');
	}

	return 0;
}

