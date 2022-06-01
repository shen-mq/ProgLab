/*********************************************************************
    程序名:
    版权:
    作者: 2021212577 沈鸣谦
    日期: 2022-06-01 15:52
    说明:
*********************************************************************/
#include <iostream>
#include <cstring>
using namespace std;

int main() {
	const int NUM = 100;
	char str[NUM] = "", dest[NUM] = "";
	strcpy(str, "welcome to China!");
	cout << "str: " << str << endl;

	strcpy(dest, str);
	cout << "dest: " << dest << endl;

	char *pch = str;
	cout << "pch: " << pch << endl;
	cout << strlen(pch) << endl;
	pch = str + 11;
	cout << "pch: " << pch << endl;
	cout << "pch: " << str + 11 << endl;
	strcpy(dest, pch);
	cout << "dest: " << dest << endl << endl;

	//strchr函数测试
	strcpy(str, "Almost#all#programmers#love#programming");
	cout << "str: " << str << endl;
	char ch = '#';//用"#"会报错，char不能用""。
	pch = strchr(str, ch);
	if (pch != NULL) {
		cout << "pch: " << pch << endl;
		cout << ch << " 首次出现位置: " << pch - str << endl;
	} else {
		cout << ch << " 未出现在" << str << endl;
	}//有无snippets之类可跳转出括号？
	pch = str;
	int cnt = 0;
	while ( pch != NULL && *pch != '\0' ) {
		if (pch = strchr(pch, ch)) {
			cout << "pch: " << pch << endl;
			cnt++;
			*pch = ' ';
			pch++;
		}
	}
	cout << ch << " 字符共出现次数: " << cnt << endl;
	cout << "修改后的字符串" << str << endl << endl;

	//strstr函数测试
	char ss[] = "program";
	if (pch = strstr(str, ss)) {
		cout << "pch: " << pch << endl;
		cout << ss << " 首次出现位置: " << pch - str << endl;
	} else {
		cout << ss << " 未出现在 " << str << endl;
	}

	const char *ps = "program";
	if (pch = strstr(str, ps)) {
		cout << "pch: " << pch << endl;
		cout << ps << " 首次出现位置: " << pch - str << endl;
	} else {
		cout << ps << " 从未出现在 " << str << endl;
	}

	//strcat函数测试
	cout << endl;
	strcpy(str, "This is the first sentence. ");
	strcat(str, "This is the second sentence. ");
	cout << str << endl;

	//strcam函数测试
	cout << endl;
	char str1[15];
	char str2[15];
	int ret;

	strcpy(str1, "abcdef");
	strcpy(str2, "ABCDEF");

	ret = strcmp(str1, str2);

	if (ret < 0) {
		cout << str1 << " < " << str2 << endl;
	} else if (ret > 0) {
		cout << str1 << " > " << str2 << endl;
	} else {
		cout << str1 << " = " << str2 << endl;
	}


	return 0;
}

