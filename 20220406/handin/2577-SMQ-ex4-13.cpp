/*********************************************************************
    程序名: ex4-13
    版权:
    作者: 2021212577 沈鸣谦
    日期: 2022-04-06 16:06
    说明:
*********************************************************************/
#include <iostream>
#include <fstream>
using namespace std;

int main() {
	int n = 0;
	double x, sum = 0;

	ifstream infile("./data.txt");//打开文件
	if (!infile) { //文件输入流创建出错
		cout << "ERROR: can't open the input file" << endl;
		exit(1);
	}
	ofstream outfile("output.txt");//打开输出文件
	if (!outfile) {
		cout << "ERROR: can't open output file" << endl;
		exit(1);
	}

	cout << "read data from input file" << endl;
	while ((infile >> x)) {
		n++;
		sum += x;
		cout << x << endl;
	}
	infile.close();//关闭input文件

	//输出到屏幕&文件
	cout << "n = " << n << endl;
	outfile << "n = " << n << endl;
	cout << "Sum = " << sum << endl;
	outfile << "Sum = " << sum << endl;

	outfile.close();
	cout << "results save in the file output.txt";

	return 0;
}

