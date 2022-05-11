/*********************************************************************
程序名：输入数据中的最大值、最小值和平均值
版权：遵从GPL版权协议，可自由使用和传播（请勿上传到收费性网络文库）
作者：anbangli@foxmail.com
日期：2019-07-20
说明：
4-11.写一个程序，从标准输入设备（键盘）读入一系列整数（第一个数是数据
的项数，其余的是数据），输出其中最大的数和最小的数，并且输出所读入数据
的平均值。

4-12.把上例改写成用字符串流输入和文件流输入。
解析：参照教材【例4-12】和【例4-13】编写
*********************************************************************/
#include <iostream>
#include <sstream>	//字符串流
#include <fstream>	//文件流
using namespace std;

int main () {
    int n, k, t, sum, biggest, smallest;

	cout << "从字符串读取数据" << endl;
	string str = "8 5 7 4 10 24 -3 15 -9"; 	//含有数据的示例字符串
	//字符串的内容是根据下文的读入操作而准备的，第一个数字是数据项数，后续为数据
	istringstream instr(str); 	//定义输入字符串流并绑定到字符串

    instr >> n; //!!从输入字符串流读取数据项数
    cout << "从字符串读入数据项数：" << n << endl;
    biggest = INT_MIN;	//先给最大值赋最小整数
	smallest = INT_MAX;	//先给最小值赋最大整数

    for (k = 1, sum = 0; k <= n; k++ ) {
    	instr >> t;	//!!从输入字符串流读取数据
		cout << "读入第 " << k << " 个整数：" << t << endl;;
        sum += t;
        if (t > biggest) biggest = t;
        if (t < smallest) smallest = t;
    }

    cout << "最大值：" << biggest << "\t最小值：" << smallest
		<< "\t平均值：" << sum / n << endl << endl;

	cout << "从文件读取数据" << endl;
	//用户应当事先编辑数据文件 data.txt ，并保存于与此程序同一文件夹下。
	ifstream infile("data.txt");	//!!定义输入文件流
	if (!infile) {	//如果文件不存在，则输入文件流会创建失败
		//cout << "程序出错：数据文件并不存在。请事先编辑并保存文件。" << endl;
		//exit(1);	//结束程序并向操作系统返回 1 ，表示程序出错结束。

		//本程序为了方便读者学习，如果文件不存在，则自动创建文件，以供后续读取。
		ofstream outfile("data.txt");	//定义输出文件流并绑定到文件
		outfile << "9 2 5 3 7 12 -13 11 -14 2";	//向输出文件流输出示例数据
		outfile.close();	//关闭输出文件流
		cout << "已创建数据文件供读取。" << endl;
		ifstream infile("data.txt");	//再次定义输入文件流，这次应该肯定成功
	}
	//如果文件流创建成功，则继续执行。
    infile >> n; 	//!!从输入文件流读取数据项数
    cout << "从文件读入数据项数：" << n << endl;
    biggest = INT_MIN;	//先给最大值赋最小整数
	smallest = INT_MAX;	//先给最小值赋最大整数

    for (k = 1, sum = 0; k <= n; k++ ) {
    	infile >> t;	//!!从输入文件流读取数据
		cout << "读入第 " << k << " 个整数：" << t << endl;;
        sum += t;
        if (t > biggest) biggest = t;
        if (t < smallest) smallest = t;
    }

    cout << "最大值：" << biggest << "\t最小值：" << smallest
		<< "\t平均值：" << sum / n << endl << endl;

    return 0;
}

