/*********************************************************************
    程序名:prog6-1
    版权:
    作者: 2021212577 沈鸣谦
    日期: 2022-05-11 16:22
    说明:
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

