/*********************************************************************
程序名：求圆的面积，指定格式输出
版权：遵从GPL版权协议，可自由使用和传播（请勿上传到收费性网络文库）
作者：anbangli@foxmail.com
日期：2019-08-09
说明：
prog2-10.计算半径分别为2.50厘米和34.2厘米的两个圆的面积，要求输出结果
固定宽度为10个字符，小数点后保留4位数字。
*********************************************************************/
#include <iostream>
#include <cmath>	//数学函数
#include <iomanip>	//输出操作符
using namespace std;

int main() {
	//说明：1、联合使用 fixed 和 setprecision 才能指定浮点数的小数位数。
	//（单独使用 setprecision 只能指定浮点数最大有效数字的位数。）
	//2、setw(n)效果是临时的，只作用于紧随其后的一个输出对象。

	cout << "半径分别为 2.50 厘米和 34.2 厘米的两个圆的面积分别为：\n"
	     << fixed << setprecision(4)
	     << setw(10) << 3.14159265 * 2.50 * 2.50 << " cm^2\n"
	     << setw(10) << 3.14159265 * 34.2 * 34.2 << " cm^2\n";

	return 0;
}






