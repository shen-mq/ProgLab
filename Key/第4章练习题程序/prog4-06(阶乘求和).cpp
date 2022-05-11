/*********************************************************************
程序名：计算阶乘求和 1! + 2! + ... + k!(通项计算）
版权：遵从GPL版权协议，可自由使用和传播（请勿上传到收费性网络文库）
作者：anbangli@foxmail.com
日期：2019-07-20
说明：
4-6.(通项计算）输入一个整数 k，计算 1! + 2! + ... + k!（请分别用二重循环
求解和用一重循环求解）。请测试 k 取从 1 到 12 的结果。这个程序能对k = 20
得到正确结果吗？
*********************************************************************/

#include <iostream>
#include <cmath>	//数学函数
using namespace std;

int main() {
	int i, j, k;
	double term = 0, sum = 0;

	cout << "Calculate: 1! + 2! + ... + k!" << endl;

	cout << "方法一：循环方式求各项" << endl;
	for (k = 1; k <= 12; k++) {		// k 循环取值进行计算
		//对每一个 k 值求和，都使用二重循环
		for (i = 1, sum = 0; i <= k; i++) {
			for (j = 1, term = 1; j <= i; j++) {
				term = term * j;
			}
			sum = sum + term;
			//cout << "i= " << i << "\tterm= " << term << "\tsum= " << sum << endl;
		}
		cout << "k= " << k << "\tk!= " << term << "\tsum= " << sum << endl;
	}

	cout << "\n方法二：根据前后项关系简化求项" << endl;
	for (k = 1; k <= 12; k++) {		// k 循环取值进行计算
		// 考虑到前后项的关系，对每一个 k 值求和，只使用一层循环
		for (i = 1, sum = 0, term = 1; i <= k; i++) {//注意这里要初始化 i, sum 和 term
			term = term * i;	//前后项的关系式
			sum = sum + term;
			//cout << "i= " << i << "\tterm= " << term << "\tsum= " << sum << endl;
		}
		cout << "k= " << k << "\tk!= " << term << "\tsum= " << sum << endl;
	}

	return 0;
}
//附注：当 k > 12 时，长整型变量 sum 就会发生溢出；k > 16 时，长整型变量 term 就会发生溢出。
//如果把这两个变量改为 double 类型，则可以计算到更大的 k 值，但有效数字只有十进制15～16位。

