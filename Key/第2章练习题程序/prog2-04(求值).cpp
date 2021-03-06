/*********************************************************************
程序名：数学式转写为表达式并求值
版权：遵从GPL版权协议，可自由使用和传播（请勿上传到收费性网络文库）
作者：anbangli@foxmail.com
日期：2019-08-09
说明：
prog2-4.写程序计算下面各个数学式的值（要注意类型转换和函数写法）：
（1）              （2）            （3）            （4）
*********************************************************************/
#include <iostream>
#include <cmath>
using namespace std;

int main() {
	//第1题特别简单，只需要注意在分母中要写括号。
	cout << "（1） " << 2.34 / (1 + 257) << endl;

	//第2题改写成表达式时，注意：1、分母要么写成连续除法，要么是把乘法写在括号里；
	//2、要有一个类型转换，避免出现整数结果相除。
	//具体写法有多种，例如 1065./ 24 / 13  或 1.0 * 1065 / (24 * 13) 。
	cout << "（2） " << 1065 / (24 * 13.0) << endl;

	//第3题相当简单，只需要注意在分母中要写括号。
	cout << "（3） " << 23.582 / (7.96 / 3.67) << endl;

	//第4题在教材正文讲过多种写法，特别要注意让 4/5 有一个类型转换，避免整数相除
	cout << 1 + 2 / (3 + 4.0 / 5) << endl;

	//第4题：把 π 写成近似数，平方写成连乘，根号使用 sqrt函数。
	cout << "（4） " << sqrt(3.14159266 * 3.14159266 + 1) << endl;



	return 0;
}






