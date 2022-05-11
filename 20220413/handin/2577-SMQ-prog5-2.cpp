/*********************************************************************
    程序名: prog5-2 打印空心矩形
    版权:
    作者: 2021212577 沈鸣谦
    日期: 2022-04-13 16:12
    说明:
*********************************************************************/
#include <iostream>
using namespace std;

void prtRect(char ch, int m, int n) {
	if (m > 0) {
		for (int i = 1; i <= n; i++) {
			cout << ch;
		}
		cout << endl;
	}
	for (int i = 1; i <= m - 2; i++) {
		if (n > 0)
			cout << ch;
		for (int j = 1; j <= n - 2; j++) {
			cout << " ";
		}
		if (n > 1)
			cout << ch;
		cout << endl;
	}
	if (m > 1)
		for (int i = 1; i <= n; i++) {
			cout << ch;
		}
	// 此代码根据各种特殊情况修修补补，及其不优雅（代码屎山就是这样堆成的吗
	// 看了老师的示例代码，不禁感叹确实难以望其项背
}

int main() {
	char ch;
	int m, n;
	cout << "Please input ch, m, n: ";
	while (cin >> ch >> m >> n ) {
//		cin >> ch >> m >> n;
		prtRect(ch, m, n);
		cout << endl << "Please input ch, m, n: ";
	}


//	putchar('$');

	return 0;
}

