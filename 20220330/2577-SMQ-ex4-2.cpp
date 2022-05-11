/*********************************************************************
    程序名: ex4-2
    版权:
    作者: 2021212577 沈鸣谦
    日期: 2022-03-30 16:03
    说明:
*********************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	int m, n;
	double x, dist;
//	float x, dist;

//	计算乌龟 m 秒爬行的时间
	cout << "请输入乌龟爬行时间（秒）：";
	cin >> m;
	for (n = 1, dist = 0. ; n <= m ; ++n) {
		dist += 1. / n;
		if (n % 100000 == 0)
			cout << "n = " << n << " dist = " << dist << endl;
	}
	n--;
	cout << "乌龟在" << n << "秒时爬了" << dist << "米远" << endl;

//	计算乌龟爬行 dist 米所需要的时间
	cout << "\n 请输入待爬行的距离（米）： ";
	cin >> dist;
	x = 0.;
	for (n = 1; x < dist; ++n) {
		x += 1. / n;
		if (n % 100000 == 0)
			cout << "n = " << n << " x = " << setprecision(10) << x << endl;
	}
	cout << "乌龟爬行" << dist << " 米需要" << --n << "秒" << endl;
	cout << "约为" << n / 3600 << " 小时, " << n / 3600 / 24 << " 天" << endl;

	return 0;
}
