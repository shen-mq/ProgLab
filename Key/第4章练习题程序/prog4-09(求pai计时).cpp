/*********************************************************************
程序名：求 Pai 的近似值
版权：遵从GPL版权协议，可自由使用和传播（请勿上传到收费性网络文库）
作者：anbangli@foxmail.com
日期：2019-07-20
说明：
4-3.（注意整除与浮点误差）已知 sigma(1/n^2) = pai^2/6 ，
利用该公式编程序求 π 的近似值，看用这个和式的前多少项求出的近似值与
3.14159266 的误差小于 10^5，令程序输出三项数据：计算得到的和，由这个和
求出的 π 的近似值，求得该和所用得项数。把10^5 改为 10^6、10^7并重新试验。

（请注意，程序中不能写成 1/(n*n)，那样会导致整数相除得0，也不能写成
 1.0/(n*n)，那样当n增大时会迅速导致 n*n溢出，正确的方式是写成 1.0/n/n。)

4-9.在上面第3题（编程求π的近似值）的程序中添加计时功能，分别计算所取
误差为10^5、10^6和10^7 时程序的执行时间并手工记录下来，人工总结出误差
减小与执行时间之间的关系。
*********************************************************************/

#include <iostream>
#include <cmath>	//数学函数
#include <ctime>	//计时函数
#include <cstdlib>
#include <iomanip>	//输出格式控制
using namespace std;

int main() {
	int n;
	double sum, pai, devition;
	int tm1, tm2;

	for (int de = -5; de >= -7; de--) {	//用整数控制循环
		devition = pow(10, de);	//误差
		tm1 = clock();	//计时起点
		for(n = 1, sum = 0; fabs(sqrt(6 * sum) - 3.14159265) > devition; n++) {
			sum += 1. / n / n;	// 关键语句！
			// 不能写成 sum += 1/n*n;  因为 1/n*n 求值为 0。
			// 不能写成 sum += 1/(n*n); 因为 1/(n*n) 求值为 0。
			// 不能写成 sum += 1.0/(n*n)。当 n 增大时容易溢出。
			pai = sqrt(6 * sum);
			//if (n % 10000 == 0)
			//	cout << "n= " << n << "  pai=" << setprecision(10) << pai << endl;
		}
		tm2 = clock();	//计时结束点
		cout << "sum= " << sum  << setprecision(10) << "\tpai= " << pai << "\tn= " << n-- ;
		cout << "\ttime cost = " << (tm2-tm1)/CLOCKS_PER_SEC <<  "s\n";
	}
	return 0;
}

//4-8计算耗时
//
//	pai=0;
//	for(n = 1; fabs(sqrt(6 * pai) - 3.14159265) > 1e-7; n++){
//		pai += 1./n/n;
//	//	printf("n=%d, pi= %f\n", n, sqrt(6*pai));
//	}
//	tm2=clock();
//	printf("pai=%f, pi= %f, n=%d\n", pai, sqrt(6*pai),n);
//	printf("time cost = %f s\n", (tm2-tm1)/CLOCKS_PER_SEC);
//
//	tm1=clock();
//	pai=0;
//	for(n=1; fabs(sqrt(6*pai)-3.14159265)>1e-7; n++){
//		pai += 1./n/n;
//	//	printf("n=%d, pi= %f\n", n, sqrt(6*pai));
//	}
//	tm2=clock();
//	printf("pai=%f, pi= %f, n=%d\n", pai, sqrt(6*pai),n);
//	printf("time cost = %f s\n", (tm2-tm1)/CLOCKS_PER_SEC);
//	return 0;
//}


