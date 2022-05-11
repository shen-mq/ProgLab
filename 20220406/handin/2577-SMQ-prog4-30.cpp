/*********************************************************************
    程序名: prog4-30 counters
    版权:
    作者: 2021212577 沈鸣谦
    日期: 2022-04-06 16:06
    说明:
*********************************************************************/
#include <iostream>
#include <fstream>
using namespace std;

int main() {
	int alph = 0, num = 0, punc = 0, spc = 0;//counters: alpha, number, punctuation, space
	int ch;

	//读取数据
	ifstream infile("./mytext.txt");//打开文件
	if (!infile) { //文件输入流创建出错
		cout << "ERROR: can't open the input file" << endl;
		exit(1);
	}
//	cout << (char) infile.get() << endl;

	//开始计数
	do {
		ch = infile.get();//
		if (isalpha(ch)) {
			alph++;
		} else if (isdigit(ch)) {
			num++;
		} else if (ispunct(ch)) {
			punc++;
		} else if (isspace(ch)) {
			spc++;
		} else {
			cout << "Encountered an Unexpected Character: " << ch << endl;
		}
	} while (ch != EOF);
	infile.close();//关闭input文件

	//输出统计结果
	ofstream outfile("output.txt");//打开输出文件
	if (!outfile) {
		cout << "ERROR: can't open output file" << endl;
		exit(1);
	}
	outfile << "字母个数：" << alph << endl;
	outfile << "数字个数：" << num << endl;
	outfile << "标点个数：" << punc << endl;
	outfile << "分隔符个数：" << spc << endl;
	outfile.close();//关闭output文件

	cout << "字母个数：" << alph << endl;
	cout << "数字个数：" << num << endl;
	cout << "标点个数：" << punc << endl;
	cout << "分隔符个数：" << spc << endl;

	return 0;
}

