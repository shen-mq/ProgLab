/*********************************************************************
    ������: ex4-5
    ��Ȩ:
    ����: 2021212577 ����ǫ
    ����: 2022-03-30 16:03
    ˵��:
*********************************************************************/

#include <iostream>
#include <cmath>
using namespace std;

int main() {
	double x, sum, t;

	cout << "Please input x: ";
	cin >> x;
	x = fmod(x, 2 * 3.14159265359);

	sum = 0.;
	t = x;
	int n = 0;
	while ( t >= 1e-6 || t <= -1e-6 ) {
		sum += t;
		n += 1;
		t = -t * x * x / (2 * n) / (2 * n + 1);
		cout << "n = " << n << " t = " << t << " sum = " << sum << endl;
	}

	cout << "my sin " << x << " = " << sum << endl;
	cout << "standard sin" << x << " = " << sin(x) << endl;

	return 0;
}
