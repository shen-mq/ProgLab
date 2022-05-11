/*********************************************************************
程序名：魔方阵
版权：遵从GPL版权协议，可自由使用和传播（请勿上传到收费性网络文库）
作者：anbangli@foxmail.com
日期：2019-07-22
说明：7-18.（*）魔方阵是由1到n2的自然数排成的n × n方阵，其中每一行、
每一列和两个对角线上的数之和相同。下面是一个构造奇数阶魔方阵的通用算法：
首先把 1 放在第一行中间。放好 k 后考虑 k + 1 的安放，总是先考虑把它放在
向上一行、向右一列的位置。下面是各种特殊情况的处理：（1）如果要从最上
一行向上，那就转到最下一行；（2）要从最右一列向右，那么就转到最左一列；
（3）如果企图放数的位置已经被占，那么就把这个数放在它前面一个数的下面。
编写函数实现这个构造奇数阶魔方阵的算法，函数原型设为int SetMagicMat(int n)，
它根据参数 n（只能是奇数）而在函数内动态申请分配 n 行 n 列的数组，并构造
魔方阵。另外请采用7.3.4节提出的处理两维数组的通用函数的技术，写一个函数
检查一个 n 阶方阵是否为一个魔方阵，函数原型设为int isMagicMat(int n, int *mat)。
*********************************************************************/
#include <iostream>
using namespace std;

int isMagicMat(int n, int *mat) {	//判断是否魔方阵。
//由于方阵是二阶的，所以需要传递一个二维数组。但是根据现有知识，如果写成二维数组
//则需要给出数组除了最高维的其它维数，显然不方便传递 n*n 二维数组。
//此处第二个参数使用了教材第 7 章才会讲到的指针，用指针把数组传递过来。
//mat[] 是一个 n*n 方阵，但视为长度为 n*n 的一维数组，
//参数表中用于表征数组长度的参数写成 n。
//那么在二维数组中 i 行 j 列的元素可以视为一维数组中编号为 i * n + j 的元素。

	int i, j, sum0, sum;
	//检查各行之和是否相等
	for (sum0 = 0, i = 0, j = 0; j < n; j++)	//求出第 0 行的和
		sum0 = sum0 + mat[i * n +j];
	for (i = 1; i < n; i++) {	//求出 1~ n-1 行的和，并与第 0 行的和进行比较
		for (sum = 0, j = 0; j < n; j++)
			sum += mat[i * n + j];
		if (sum0 != sum)	// 如果不相等则可判断为非魔方阵
			return 0;
	}

	//检查各列之和是否相等
	for (sum0 = 0, i = 0, j = 0; i < n; i++)	//求出第 0 列的和
		sum0 = sum0 + mat[i * n +j];
	for (j = 1; j < n; j++) {	//求出 1~ n-1 列的和，并与第 0 列的和进行比较
		for (sum = 0, i = 0; i < n; i++)
			sum += mat[i * n + j];
		if (sum0 != sum)	// 如果不相等则可判断为非魔方阵
			return 0;
	}

	//检查两条对角线之和是否相等
	for (sum0 = 0, i = 0, j = 0; i < n; i++, j++)	//求出从左上角指向右下角的对角线之和
		sum0 = sum0 + mat[i * n +j];
	for (sum = 0, i = n - 1, j = 0; i >= 0; i--, j++)	//求出从左下角指向右上角的对角线之和
		sum = sum + mat[i * n +j];
	if (sum0 != sum)	// 如果不相等则可判断为非魔方阵
		return 0;

	return 1;	//通过了上述三次检查，可以判断是魔方阵
}

void SetMagicMat(int n) {
	if (n <1 || n %2 == 0) {	//此函数只能构造奇数阶魔方阵
		cout << "错误：参数小于 0 或 参数为偶数。 n = " << n << endl;
		return;
	}//参数符合要求才继续

	int i, j, k, inew, jnew;
	int mat[n][n];//按照C99和 C++标准，可以利用形参作为长度来定义数组（但不可初始化）
	//有些参考资料上使用动态分配内存方式创建一维数组，导致下文处理坐标时颇为麻烦

	//数组所有元素初始化为 0
	for(i = 0; i < n; i++) {
		for(j = 0; j < n; j++) {
			mat[i][j] = 0;
		}
	}

	for(k = 1; k <= n * n; k++) {	//用 k 控制循环，i 和 j 是行号和列号
		if (k == 1) { // 先把 1 放在第一行中间，即坐标为 (0, n/2)
			i = 0;
			j = n / 2;
		} else {	//以下是 k 不为 1 的情形
			// 当数 k 放好后，考虑数 k+1 的安放，总把它放在向上一行、向右一个位置
			// 注意这里要使用另外两个变量，而不能直接修改 i 和 j
			inew = i - 1;
			jnew = j + 1;
			if (inew < 0)		//（1）要从最上一行向上，那么就转移到最下一行；
				inew = n-1;
			if (jnew == n)	//（2）要从最右一列向右，那么就转移到最左一列；
				jnew = 0;
			if (mat[inew][jnew] > 0) {	//（3）如果企图放数的位置已经被占，那么就把这个数放在它前面一个数的下面。
				//在这里需要使用 i 和 j，所以上面不能直接修改 i 和 j。
				inew = i + 1;
				jnew = j;
				if (inew == n)	//如果已在最下行，则转到最上行
					inew = 0;
			}
			//以上十余行逻辑清晰易懂，但写得颇为罗索。可以改成下面三行：
			//inew = (i - 1 + n) % n //行号减1，如果变成 -1 则通过取余而转换为 n-1
			//jnew = (j + 1 )%n 	//列号加1，如果变成 n 则通过取余而转换为 0
			//if (mat[inew][jnew] > 0 { inew = (i + 1) %n; jnew = j; }
			i = inew;
			j = jnew;
		}
		mat[i][j] = k;
	}

	// 输出魔阵
	for(i = 0; i < n; i++) {
		for(j = 0; j < n; j++) {
			cout << fixed << mat[i][j] << "\t";
		}
		cout << endl;
	}

	if (isMagicMat(n, &mat[0][0]) )
		cout << "是魔方阵\n";
	else
		cout << "不 是 魔方阵\n";

}


int main () {
	SetMagicMat(-1);
	SetMagicMat(0);
	SetMagicMat(2);

	SetMagicMat(1);

	SetMagicMat(3);

	SetMagicMat(5);

	SetMagicMat(7);
}
/*********************************************************************
扩展思考
魔方阵可以分为三种：奇数阶、单偶数阶（能被2整除，不能被4整除）和双偶数阶
（能同时被2和4整除）。
以上介绍的是通用的奇数阶魔方阵构造方法。另外两种的解法可以参见如下网页：
https://blog.csdn.net/juicy_w/article/details/80099047


还可以在网络上搜索“魔方阵原理及十种解法”，有更详细的介绍（作者未知）。
例如这个网页：http://blog.chinaunix.net/uid-29270628-id-3959663.html
*********************************************************************/




