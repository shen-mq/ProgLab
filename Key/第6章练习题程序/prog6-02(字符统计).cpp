/*********************************************************************
程序名：读取纯文本文件并统计各个字符的出现次数
版权：遵从GPL版权协议，可自由使用和传播（请勿上传到收费性网络文库）
作者：anbangli@foxmail.com
日期：2019-07-22
说明：6-2.写一个程序，统计由标准输入得到的一批字符中各个英文字母（不区分
大小写）出现的次数。
（提示：使用标准库中的字符函数判断所输入的字符是否英文字母，并把英文字母
统一转换为大写或小写，然后参考例6-3中的技术进行统计。）
*********************************************************************/
#include <iostream>
using namespace std;

int main () {
	int ch, i;
	//用一个含有 26 个元素的数组分别存储各个字符的出现次数
	int cs[26] = {0};  //第0号元素初始化为0，其它元素自动初始化为0

	cout << "input some chars (Ctrl-Z to end): ";
	while ((ch = cin.get()) != EOF) {	//从标准输入中读取字符
		if (isalpha(ch))   	//!! 判断是英文字符
			cs[tolower(ch) - 'a']++;  //!!字符转换为小写，相应的计数器加 1
	}

	for (i = 0; i < 26; ++i)
		cout << "Number of " << (char)(i + 'a') << ": " << cs[i] << endl;

	return 0;
}


