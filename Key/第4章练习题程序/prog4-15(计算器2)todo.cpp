/*********************************************************************
程序名：交互式计算器改进
版权：遵从GPL版权协议，可自由使用和传播（请勿上传到收费性网络文库）
作者：anbangli@foxmail.com
日期：2019-04-16
说明：
【例4-16】考虑一个简单的交互式计算器。假定它从键盘读入如下形式的
输入行（左右两个运算数，中间是加减乘除运算符，可能夹杂有空格）：
12.8+36.5      254 - 14.38                10313 /524
程序每读入一个形式正确的表达式后就计算并输出其结果，直至用户要求结束。

4-15. 改造上述计算器程序，使得在用户输入表达式的过程中出现任何错误时，
程序都能给出适当的错误信息，并重新回到等待用户输入的状态。直至用户要求
结束时程序才终止。（提示：需要设计一个用户要求结束的约定，并实现这个约定。）

*********************************************************************/

下面是练习题4-14的程序文件。待改进。
#include <iostream>
using namespace std;

int main () {
	int op;    //operator
	double left, right;    //左边运算数和右边运算数

	cout << "小小计算器（允许连续运算），）\n";
	cout << "连续运算以 c 结束。新运算式开始为非数字时结束程序。\n";
	cout << "input: ";

	while ( (cin >> left)) {    //读得左边运算数

		while (true) {	//添加添加循环：重复读取运算符和右运算数
			do //跳过空格或其它字符，直到获得运算符+-*/，或结束符c
				op = cin.get();
			while (op != '+' && op != '-' && op != '*' && op != '/' && op != 'c');

			if (op == 'c') //如果读得运算符为 c 则结束此次连续运算
				break;

			if (!(cin >> right) ) {//读取右边运算数
				cout << "ERROR: Format incorrect. Example: 6.4 + 3.6\n ";
				cin.clear();
				cin.sync();
				continue;
			}
			cout << "calc: " << left << " " << (char)op << " " << right << " = ";
			switch (op) {	//把计算结果保存到 left 中
				case '+':
					left = left + right;
					break;
				case '-':
					left = left - right;
					break;
				case '*':
					left = left * right;
					break;
				case '/':
					left = left / right;
					break;
				default :
					break;
			}
			cout << left << endl;	//输出单个计算结果
			//继续内层循环，读取后续操作符和运算数。

		}	//一次连续运算结束
		cout << "input: ";	//开始输入新运算式
	}
	return 0;
}


