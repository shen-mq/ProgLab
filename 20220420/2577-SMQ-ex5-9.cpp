/*********************************************************************
    ������:ex5-9
    ��Ȩ:
    ����: 2021212577 ����ǫ
    ����: 2022-04-20 16:11
    ˵��:
*********************************************************************/
#include <iostream>
using namespace std;

void swapref(int &a, int &b) {
	int t = a;
	a = b;
	b = t;
	cout << "swapped inside: a = " << a << " b = " << b << endl;
}

int main() {
	int m = 10, n = 25;
	cout << "before swap: m = " << m << " n = " << n << endl;
	swapref(m, n);
	cout << "after swap: m = " << m << " n = " << n << endl;

	return 0;
}
