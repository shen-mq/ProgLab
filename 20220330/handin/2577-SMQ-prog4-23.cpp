/*********************************************************************
    程序名: prog4-23 sum of factorial
    版权:
    作者: 2021212577 沈鸣谦
    日期: 2022-03-30 16:03
    说明:
*********************************************************************/

#include <iostream>
using namespace std;

int main() {
	int k;
	cout << "Please input k: ";
	cin >> k;
//	k = 1;
//	do {

	//两重循环的解法
	//外层循环控制求和，内层循环计算阶乘
	int sum = 0, n = 1; //sum 存储求和的值，n存储阶乘的值; 可分别用 int 和long long 声明
	for (int i = 1; i <= k; i++) {
		for (int j = 1; j <= i; j++) {
			n *= j;
		}
		sum += n;
		n = 1;
	}
	cout << "sum of the factorial is: " << sum << endl;

	//一重循环解法
	//每次循环做的事为：将上一次求出的阶乘乘上 j （得到下一次阶乘的值），然后把阶乘的值累加到 sum 中去
	sum = 0;
	n = 1;
	for (int i = 1; i <= k; i++) {
		n *= i;
		sum += n;
	}
	cout << "sum of the factorial is: " << sum << endl;

//		cout << "k = " << k << endl;
//		k += 1;
//	} while (k <= 40);//用 do-while 来循环输出

	return 0;
}
// sum, n 为 int 型时, 从 k = 13 起结果错误; 用long long型从 k = 21 开始结果错误
