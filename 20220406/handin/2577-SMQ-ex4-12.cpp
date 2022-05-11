/*********************************************************************
    程序名: ex4-12
    版权:
    作者: 2021212577 沈鸣谦
    日期: 2022-04-06 16:06
    说明:
*********************************************************************/
#include <iostream>
#include <sstream>
using namespace std;

int main() {
	int i, n;
	double x, sum;

	istringstream inss("8 1.2 2.4 4.6 6.8 5.3 21.1 1.5 3.3");

	inss >> n;
	cout << "number of data items: " << n << endl;
	for (i = 1, sum = 0; i <= n; ++i) {
		inss >> x;
		cout << i << " : " << x << endl;
		sum += x;
	}
	cout << "Sum = " << sum << endl;

	return 0;
}

