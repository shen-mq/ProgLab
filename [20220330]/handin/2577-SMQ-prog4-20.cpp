/*********************************************************************
    程序名: prog4-20 find pi
    版权:
    作者: 2021212577 沈鸣谦
    日期: 2022-03-30 16:03
    说明:
*********************************************************************/

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
	int n, k;
	for (k = 5; k <= 7; k++) {
		double precision = pow(10, -k);

		double sum = 0., term;
		for (n = 1; fabs(sum - 3.14159265 * 3.14159265 / 6) >= precision; n++) {
			term = 1. / n / n;//!
			sum += term;
		}
		cout << "n = " << n << '\t' << "sum = " << setprecision(13) << sum << '\t' << "Estimated Pi is "
		     << setprecision(13) << sqrt(6 * sum) << endl;
	}

	return 0;
}
