/*********************************************************************
    程序名:ex6-4
    版权:
    作者: 2021212577 沈鸣谦
    日期: 2022-05-11 16:22
    说明:
*********************************************************************/
#include <iostream>
using namespace std;

int main() {
	int ch, cs[10] = {0};

	cout << "Input some chars (<C-z> to end): ";
	while ((ch = getchar()) != EOF) {
//		cout << ch << endl;
// getchar()是否是一个字符一个字符读入？那为什么在一串字符中夹杂入^Z就不能结束输入？ch在过程中究竟被赋了何值？
		/* 试验（针对上面的 cout<<ch<<endl;）：

		input				output
		12^Z34				49 50 26
		1234				49 50 51 52 10
		abc123				97 98 99 49 50 51 10

		Analysis: ^Z不是单独输入时的ascii值为 26 ，并且碰到 ^Z 循环确实停止了。而普通的回车输入的ascii值就为 10

		*/
		if ( isdigit(ch)) {
			cs[ch - '0']++;
		}
	}
	for (int i = 0; i < 10; i++) {
		cout << "Number of " << i << " : " << cs[i] << endl;
	}

	return 0;
}

