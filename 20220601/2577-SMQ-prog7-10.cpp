/*********************************************************************
    ������:
    ��Ȩ:
    ����: 2021212577 ����ǫ
    ����: 2022-06-01 15:52
    ˵��:
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

	//strchr��������
	strcpy(str, "Almost#all#programmers#love#programming");
	cout << "str: " << str << endl;
	char ch = '#';//��"#"�ᱨ��char������""��
	pch = strchr(str, ch);
	if (pch != NULL) {
		cout << "pch: " << pch << endl;
		cout << ch << " �״γ���λ��: " << pch - str << endl;
	} else {
		cout << ch << " δ������" << str << endl;
	}//����snippets֮�����ת�����ţ�
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
	cout << ch << " �ַ������ִ���: " << cnt << endl;
	cout << "�޸ĺ���ַ���" << str << endl << endl;

	//strstr��������
	char ss[] = "program";
	if (pch = strstr(str, ss)) {
		cout << "pch: " << pch << endl;
		cout << ss << " �״γ���λ��: " << pch - str << endl;
	} else {
		cout << ss << " δ������ " << str << endl;
	}

	const char *ps = "program";
	if (pch = strstr(str, ps)) {
		cout << "pch: " << pch << endl;
		cout << ps << " �״γ���λ��: " << pch - str << endl;
	} else {
		cout << ps << " ��δ������ " << str << endl;
	}

	//strcat��������
	cout << endl;
	strcpy(str, "This is the first sentence. ");
	strcat(str, "This is the second sentence. ");
	cout << str << endl;

	//strcam��������
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

