/*********************************************************************
程序名：输入数据中的最大值、最小值和平均值
版权：遵从GPL版权协议，可自由使用和传播（请勿上传到收费性网络文库）
作者：anbangli@foxmail.com
日期：2019-07-20
说明：
4-11.写一个程序，从标准输入设备（键盘）读入一系列整数（第一个数是数据
的项数，其余的是数据），输出其中最大的数和最小的数，并且输出所读入数据
的平均值。
*********************************************************************/
#include <iostream>
using namespace std;

int main () {
    int n, k, t, sum, biggest, smallest;

    cout << "请输入数据项数：";
    cin >> n;
    biggest = INT_MIN;	//先给最大值赋最小整数
	smallest = INT_MAX;	//先给最小值赋最大整数

    for (k = 1, sum = 0; k <= n; k++ ) {
    	cout << "请输入第 " << k << " 个整数：";
    	while (!(cin >> t))	{//允许重复输入，直到接收到一个整数为止
    		cin.clear();
			cin.sync();
			cout << "重新输入：";
    	}
        sum += t;
        if (t > biggest) biggest = t;
        if (t < smallest) smallest = t;
    }

    cout << "最大值：" << biggest << "\t最小值：" << smallest
		<< "\t平均值：" << sum / n << endl;

    return 0;
}

