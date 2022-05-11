/*********************************************************************
    程序名: ex 3-5
    版权:
    作者: 2021212577 沈鸣谦
    日期: 2022-03-09 15:57
    说明:
*********************************************************************/
#include <iostream>
#include <iomanip>
#include <limits.h>
using namespace std;

int main() {
	cout << "int 类型的最小值和最大值：\t" << INT_MIN << '\t' << INT_MAX << endl;
	cout << "减1加1发生溢出得到的错误结果：\t" << INT_MIN - 1 << '\t' << INT_MAX + 1 << endl;
	cout << "转换到双精度避免了溢出：\t" << setprecision(12) << INT_MIN - 1. << '\t' << INT_MAX + 1. << endl;

	return 0;
}

