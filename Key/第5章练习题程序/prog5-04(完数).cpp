/*********************************************************************
程序名：判断完数 
版权：遵从GPL版权协议，可自由使用和传播（请勿上传到收费性网络文库）
作者：anbangli@foxmail.com
日期：2019-07-08 16:43
说明：
5-4.如果一个整数的所有真因数（除了该数本身以外的约数，包括 1 在内）之和
正好等于这个数，那么就称它为“完数”。因数之和小于自身的数称为“亏数”；
因子之和大于自身的数称为“盈数”。写一个函数（取名为“isperfect”），
当其参数是完数时返回 1，否则返回 0。然后编写主函数，调用这个函数求出
10000 以内的所有完全数（共 4 个：6、28、496 和 8128）。
*********************************************************************/
#include <iostream>
using namespace std;

int isperfect(int n) { 
    int k, sum = 0;
    for (k = 1;  k < n; k++)    
        if (n % k == 0)    //发现一个因数 
            sum += k;
    
	//根据循环结束的情形来判断 
	//cout << n << "\t" << sum << endl;
    return (sum == n)? 1 : 0;	//完数 : 非完数 
}

int main() {    
	cout << "10000 以内的完数："; 
    for (int n = 2; n < 10000; n++)
        if (isperfect(n))
            cout << n << "\t";
    return 0;
}
//扩展思考：完数是很罕见的，请编程求出后续第五个完数。

//勤奋好学的同学，请自行编程解答这个问题，并在QQ上单独发送给我。
 

