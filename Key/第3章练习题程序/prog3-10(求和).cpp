/*********************************************************************
程序名：用 while 结构编程求和 
版权：遵从GPL版权协议，可自由使用和传播（请勿上传到收费性网络文库）
作者：anbangli@foxmail.com
日期：2019-08-09
说明：
3-10.使用 while 结构，求出：（1）在从 -10 开始到 20 之间间隔为 3 的整数
的立方和；（2）公式“π + 2π + ... + 20π”的值（π取近似值3.14159266）。

解题分析：仿照教材正文里面使用了 while 结构的示例程序进行编写。 
*********************************************************************/
#include <iostream>
using namespace std;

int main() {
	cout << "（1）求出从 -10 开始到 20 之间间隔为 3 的整数的立方和\n";
	int n = -10, sum = 0;	//定义变量并初始化 
	while (n <= 20) {
		sum += n * n * n;	//立方通常写成连乘形式，而不用 pow 函数。 
		cout << n << "\t" << sum << endl;	//注意，应该在 n 变化之前输出 
		n = n + 3;
	}
	cout << n - 3 << "\t" << sum << endl;	//要注意 n 在循环结束时的值 
	
	cout << "\n（2）求公式“π + 2π + ... + 20π”的值\n";
	const double PI = 3.14159266;	//表示圆周率的常变量
	double sumpai = 0;	//注意这个公式的求和为 double 类型 
	n = 1; //分析公式，需要使用一个循环变量从 1 增长到 20;
	while (n <= 20) {
		sumpai += n * PI;
		cout << n << "\t" << sumpai << endl;//应该在 n 变化之前输出 
		n++; 
	}
	cout << n - 1 << "\t" << sumpai << endl;	//要注意 n 在循环结束时的值
	
	//也可将公式变为“(1 + 2 + ... + 20)*π”，先对整数累加求和，然后再乘 π。 
//	n = 1;
//	sum = 0; 
//	while (n <= 20) {
//		sum += n;
//		//cout << n << "\t" << sum << endl;
//		n++; 
//	}
//	cout << n - 1 << "\t" << sum * PI << endl;	//此处输出 sum *π 

	return 0;
}




