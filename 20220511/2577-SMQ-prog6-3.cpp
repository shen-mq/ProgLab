/*********************************************************************
    ������:prog6-3
    ��Ȩ:
    ����: 2021212577 ����ǫ
    ����: 2022-05-11 16:22
    ˵��:
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

