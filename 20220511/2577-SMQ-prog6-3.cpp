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

int main()
{
	int len, num[100000], interval[33] = {0};//interval ������Ϊ33, �Ա����±�Խ��. ��� rand() �� [RAND_MAX - RAND_MAX % 32, RAND_MAX] ��Χ��, rand() / len ��õ�32. 
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