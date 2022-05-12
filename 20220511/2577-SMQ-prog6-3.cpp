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

int main()
{
	int len, num[100000], interval[33] = {0};//interval 长度设为33, 以避免下标越界. 如果 rand() 在 [RAND_MAX - RAND_MAX % 32, RAND_MAX] 范围内, rand() / len 会得到32. 
	len = RAND_MAX / 32;

	srand(time(0));

	for (int i = 0; i < 100000; i++)
	{
		num[i] = rand();
		interval[num[i] / len]++;
	}

	int sum = 0;
	for (int i = 0; i < 32; i++)
	{
		sum += interval[i];
		cout << interval[i] << (i % 5 != 4 ? '\t' : '\n');
	}
	cout << sum;

	return 0;
}