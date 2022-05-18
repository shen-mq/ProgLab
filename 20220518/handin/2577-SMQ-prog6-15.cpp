/*********************************************************************
    程序名:prog6-15 回文
    版权:
    作者: 2021212577 沈鸣谦
    日期: 2022-05-18 16:19
    说明:
*********************************************************************/
#include <iostream>
#include <cstring>
using namespace std;

int palindrome(char str[]) {
	int len = strlen(str);
	for (int i = 0; i < len / 2; i++)
		if (str[i] != str[len - 1 - i])
			return 0;
	return 1;
}

int palindrome2(char str[]) {
	int len = strlen(str);
	for (int i = 0, j = len - 1; i < j; i++, j--) {
		while (!isalpha(str[i]) && i < j)
			i++;
		while (!isalpha(str[j]) && i < j)
			j--;
//		cout << i << " " << str[i] << "\t" << j << " " << str[j] << endl;
		if (tolower(str[i]) != tolower(str[j]))
			return 0;
	}
	return 1;
}


int main() {

	char s1[] = "Madam, I'm Adam. ", s2[] = "asdcdsa", s3[] = "madamimadam", s4[] = "qw@er%_ty...ui^op,,oiu..yt{rewq}";
	cout << palindrome(s1) << '\t' << palindrome(s2) << '\t' << palindrome(s3) << '\t' << palindrome(s4) << endl;
	cout << palindrome2(s1) << '\t' << palindrome2(s2) << '\t' << palindrome2(s3) << '\t' << palindrome2(s4) << endl;

	return 0;
}

