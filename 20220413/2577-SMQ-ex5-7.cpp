/*********************************************************************
    程序名:ex5-7
    版权:
    作者: 2021212577 沈鸣谦
    日期: 2022-04-13 16:12
    说明:
*********************************************************************/
#include <iostream>
using namespace std;

int sumsq(int m) {
	int sum = 0;
	for (int n = 1; n <= m; n++) {
		int k = n * n;
		sum += k;
		cout << "n = " << n << " sum = " << sum << endl;
	}
	cout << "m = " << m << " sum = " << sum << endl;
	return sum;
}

int main() {
	int m;
	cout << "Input an integer: ";
	cin >> m;
	cout << "sum = " << sumsq(m) << endl;

	return 0;
}

