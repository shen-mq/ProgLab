/*********************************************************************
    程序名: ex6-16
    版权:
    作者: 2021212577 沈鸣谦
    日期: 2022-05-18 16:19
    说明:
*********************************************************************/
#include <iostream>
using namespace std;

void stringcopy(char s[], const char t[]) {
	int i = 0;
	while (s[i] = t[i])
		++i;
}

int main() {
	const int LEN = 200;
	char s1[LEN] = "";
	char s2[LEN] = "Welcome to programming kingdom!";

//	char s3[3] = {'a', 'b', 0};
//	cout << s3 << endl << endl;
//	cout << ('\0' == 0 ? 1 : 0) << endl;

	cout << "s2: " << s2 << endl;
	stringcopy(s1, s2);
	cout << "s1: " << s1 << endl;
	stringcopy(s1, "Use string interal, OK!");
	cout << "s1: " << s1 << endl;

	return 0;
}

