/*********************************************************************
    程序名: prog4-18 水仙花数
    版权:
    作者: 2021212577 沈鸣谦
    日期: 2022-03-30 16:03
    说明:
*********************************************************************/

#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int n;

	for (n = 100; n <= 999; n++) {
		int o, t, h; //one, ten, hundred
		h = n / 100;
		t = (n / 10) % 10;
		o = n % 10;

		if (o * o * o + t * t * t + h * h * h == n) {
			cout << n << "\t";
		}

	}



	return 0;
}
