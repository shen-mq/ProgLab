/*********************************************************************
    ������:prog6-1
    ��Ȩ:
    ����: 2021212577 ����ǫ
    ����: 2022-05-11 16:22
    ˵��:
*********************************************************************/
#include <iostream>
#include <ctime>
//#include <cstdlib>
using namespace std;

int main() {
	int random[100];
	srand(time(0));

	for (int i = 0; i < 100; i++) {
		random[i] = rand() % 201;

		cout << random[i] << (i % 5 != 4 ? '\t' : '\n');
	}


	return 0;
}

