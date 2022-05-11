/*********************************************************************
    ������:ex5-11
    ��Ȩ:
    ����: 2021212577 ����ǫ
    ����: 2022-04-20 16:11
    ˵��:
*********************************************************************/
#include <iostream>
#include <cmath>
using namespace std;

double dsin(double x) {
	x = fmod(x, 2 * 3.14159265);
	double sum = 0., t = x;
	int n = 0;
	while (t >= 1e-7 || t <= -1e-7) {
		sum += t;
		n += 1;
		t = -t * x * x / (2 * n) / (2 * n + 1);
//		cout << "n = " << n << " t = " << t << " sum = " << sum << endl;
	}
	return sum;
}

int main() {
	double x;
	cout << "test dsin:\n" << "x\tdsin(x)\t\tsin(x)\t\tdiff\n";
	for (int k = -314; k <= 314; k += 2) {
//		x = k * .1;
		x = k;
		cout << x << '\t' << dsin(x) << '\t' << sin(x) << '\t';
		cout << dsin(x) - sin(x) << endl;
	}

	return 0;
}
