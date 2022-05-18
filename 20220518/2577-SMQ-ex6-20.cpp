/*********************************************************************
    程序名:ex6-20
    版权:
    作者: 2021212577 沈鸣谦
    日期: 2022-05-18 16:19
    说明:
*********************************************************************/
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int setPara(int &t, int &n, int MAX);
int alloMoney(int t, int n, int money[]);
void prtAll(int t, int n, int money[]);

int main() {
	const int MAX = 100;
	int t, n, money[MAX];

	cout << "=== 拼手气抢红包 ===" << endl;
	if (!setPara(t, n, MAX)) {
		cout << "参数设置失败，程序结束。";
		exit(1);
	}

	alloMoney(t, n, money);
	prtAll (t, n, money);

	return 0;
}

int setPara(int &t, int &n, int MAX) {
	double total;
	int errs = 0, ERRNUM = 3;
	do {
		cout << "请输入红包总金额（元）：";
		cin >> total;
		cout << "输入红包个数：";
		cin >> n;
		if (n > MAX) {
			cout << "错误：总人数超过了" << MAX << endl;
			errs++;
		}

		t = total * 100;
		if (t < n) {
			cout << "错误：红包总金额分数小于人数！请重新输入。" << endl;
			errs++;
		}
	} while ((n > MAX || t < n) && errs <= ERRNUM);
	return (errs <= ERRNUM ? 1 : 0);
}

int alloMoney(int t, int n, int money[]) {
	int i, total = 0;
	int min = .5 * t / n, max = 1.5 * t / n;

	srand(time(0));
	for (i = 0; i < n; i++) {
		money[i] = rand() % (max - min + 1) + min;
		total += money[i];
	}

	//红包金额归一化
	int sum = 0;
	for (i = 0; i < n - 1; i++) {
		money[i] = double(money[i]) / total * t;
		sum += money[i];
	}
	money[n - 1] = t - sum;

	//TODO: 调整以避免0元红包
	return 0;
}

void prtAll(int t, int n, int money[]) {
	for (int i = 0; i < n; i++) {
		cout << 0.01 * money[i] << (i % 5 == 4 ? '\n' : '\t');
	}
}

