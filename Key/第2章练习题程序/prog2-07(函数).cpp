/*********************************************************************
程序名：分析使用函数中的类型转换
版权：遵从GPL版权协议，可自由使用和传播（请勿上传到收费性网络文库）
作者：anbangli@foxmail.com
日期：2019-08-09
说明：
prog2-7
7.分析在下面含有多种类型数据而且使用了数学函数的表达式的计算过程中，在什么地方
将发生什么类型转换？编写程序计算各个表达式的值。
（1） 3 * (int)sqrt(34) - sin(6) * 5
（2） cos(2.5f + 4) - 6 * 27L + 100
（3） fabs(-2) + ceil (8.6) + 10
（4） floor(8.6) + round(16.6) + 5

解答：
（1）3 * (int)sqrt(34) - sin(6) * 5
1、int 类型的 34 转换为 double 类型，作为 sqrt 函数的参数；
2、sqrt 函数运算的返回值是 double 类型，被强制转换为 int 类型，与 3 相乘；
3、int 类型的 6 转换为 double 类型，作为 sin 函数的参数；
4、int 类型的 5 转换为 double 类型，与 sin 函数运算的返回值相乘；
5、3 * (int)sqrt(34) 的运算结果是 int 类型，转换为 double 类型，与 sin(6)*5
   的运算结果相减。最终运算结果是 double 类型。

（2） cos(2.5f + 4) - 6 *27L + 1526
1、int 类型的 4 转换为 float 类型，与 2.5f 相加；
2、2.5f + 4 的结果为 float 类型，转换为 double 类型，作为 cos 函数的参数；
3、int 类型的 6 转换为 long 类型，与 27L 相乘；
4、6 * 27L 的运算结果是 long 类型，转换为 double 类型，与 cos(2.5f + 4)
   的运算结果相减；
5、int 类型的 100 转换为 double 类型，与前面的运算结果相加。

（3） fabs(-2) + ceil (8.6) + 10
1、int 类型的 -2 转换为 double 类型，作为 fabs 函数（取浮点数绝对值）的参数
2、fabs 函数 和 ceil 函数（向上取整数）的返回值都是 double 类型，所以 int
类型的 10 转换为 double 类型，参与运算。
（附加说明：计算结果是 double 类型，以默认参数输出时显示为整数形式）

（4） floor(8.6) + round(16.6) + 5
1、floor 函数（向下取整） 和 round 函数（四舍五入取整）的返回值都是
 double 类型，所以 int 类型的 5 转换为 double 类型，参与运算。
（附加说明：计算结果是 double 类型，以默认参数输出时显示为整数形式）
*********************************************************************/
#include <iostream>
#include <cmath>
using namespace std;

int main() {
	cout << "（1）：" << 3 * (int)sqrt(34) - sin(6) * 5 << endl;
	cout << "（2）：" << cos(2.5f + 4) - 6 * 27L + 100 << endl;
	cout << "（3）：" << fabs(-2) + ceil (8.6) + 10 << endl;
	cout << "（4）：" << floor(8.6) + round(16.6) + 5 << endl;

	return 0;
}






