/*********************************************************************
��������ͳ��Դ�����е� ANSI C ���Թؼ���
��Ȩ�����GPL��ȨЭ�飬������ʹ�úʹ����������ϴ����շ��������Ŀ⣩
���ߣ�anbangli@foxmail.com
���ڣ�2019-07-24
˵����
6-22.���ձ�����������ʵ��һ�� ANSI C ���Թؼ��ֵ�ͳ�Ƴ��򡣻ش�������
����������⡣�޸���ĳ���ʹ���ܹ���ȷ�����κ� ANSI C ����

1.Ӧ���ö���������ʶ�������ԶԱ�ʶ������û�����ƣ���ǰ�濼�� getident
����ʱ���˳������Ʋ������뿼�Ǹò��������ã��������������ʶ������ĳ���
�����������ϵĳ�������ȷͳ����ʲôʱ�������⣿��ʲô���⣿
2.������ʶ������ʱӦ�ò�ȡʲô����ԭ��������֤ͳ�ƽ����ȷ����ĳ���
����������ĳ�����ȷ��������һ������
3.����ANSI C���Թؼ��֣���ע�⵽���ǵĳ��ȶ������� 8 ���ַ���һ��Ҫ��������
��ĳ�������������������������ܷ�ʹͳ�ƵĹ������򵥣��ܷ��緢��ĳ��ʶ��
�������ǹؼ��֣�����ʾ����getidentʵ��Ϊ��ȡ����һ���Ȳ�����8�ı�ʶ��������
4.���Ҫʹ��ĳ������ƣ������뿼��C/C++ �����еĸ��ֳɷ֡���ע�͡��ַ�������
�ַ��������ȡ�
��ϸ������Щ���⣬�޸���ĳ���ʹ�����κ�����¶��ܹ����ڲ���֮�ء��������
�����׵��£�������Ŭ��������һ��Ĺ����У����ѧ����ණ����

����˼·��
Ҫ��������Ŀ��������Ҫ�Լ�׼��һ�����ʵĲ����ļ����ò����ļ���Ӧ����
һЩ�����ĺ��йؼ��ʵ���䣬�Թ�������ʶ��ͳ�ƣ�ͬʱ���ļ��Ŀ�ע�͡�
��ע�ͺ��ַ�����ҲҪ�������һЩ�ؼ��ʣ�Ҫ�ñ�����������ų�����ͳ�ơ�
������������䣺
const int LEN = 100;	//const
char str[LEN] = "keywords such as \"goto\" and \"register\" are seldom used\n";
//"union" and "volatile" are also seldom used.
��Ҫ����һЩ����������������е���䣬���磺
double doublexyz = 200 / LEN;
double registerregister = doublexyz/LEN;
*********************************************************************/
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

ifstream inFile;    //ȫ�ֵ������ļ���

int getident(int limit, char id[]) {	//�̲��ϵİ汾������ʶ��ע�ͺ��ַ���
	int ch = ' ', i = 0;
	while (ch != EOF) {
		i = 0;
		while ((ch = inFile.get()) != EOF && !isalnum(ch) && ch != '_')
			;    //ch������ĸ�������ַ����»��ߣ�����
		if (ch == EOF) break;

		id[i] = ch;    //���ַ�
		while ((ch = inFile.get()) != EOF && (isalnum(ch) || ch == '_') )
			id[++i] = ch;    //ch����ĸ�������ַ����»��ߣ���ӽ��ַ���
		id[++i] = '\0';    //��ӿ��ַ���Ϊ������־
		break;
	}
	return i;
}

int getident2(int limit, char id[]) {	//�Ľ��汾����ʶ��ע�ͺ��ַ���
	int ch = ' ', ch2 = ' ', i = 0;
	while (ch != EOF) {
		i = 0;
		while ((ch=inFile.get()) != EOF && !isalnum(ch) && ch!='_' && ch!='/' && ch!='\"')
			;    //ch���������ַ�����������ĸ�����֡��»��ߡ���б�ܡ�˫����
		if (ch == EOF)
			break;
		cout << (char)ch << "\n";	//!!!debug

		if (ch == '\"'){ //���������һ��˫���ţ��ַ�����ʼ������Ҫ����
			ch2 = ch;	//��ch2 ���� ch
			//������һ��������˫���ţ���ǰһ������б�ܣ���Ϊ�ַ���������
			while (((ch = inFile.get()) != EOF) && !(ch2 != '\\' && ch =='\"') )
				ch2 = ch;
			continue;	//�����˴�ѭ������ʼ��һ��ѭ��
		}

		if (ch == '/')	{//������õ���һ����б�ܣ�����һ���ַ��������ж�����ע�ͻ��ע��
			ch2 = ch;
			if ((ch = inFile.get()) == EOF )	//����һ���ַ���˳��Ҫ�ж����Ƿ�EOF��
				break;
			if (ch2 == '/' && ch == '/') {	//��ע�ͣ���һֱ������β
				while ((ch = inFile.get()) != EOF && ch != '\n' )	//
					;    //�����ַ���ֱ����β
				continue;//�����˴�ѭ������ʼ��һ��ѭ��
			}else if  (ch2 == '/' && ch == '*') {	//��ע�ͣ���һֱ�������Ǻź�б��
				while ((ch = inFile.get()) != EOF && !(ch2 == '*' && ch == '/')) {
					ch2 = ch;
				}
				continue;	//�����˴�ѭ������ʼ��һ��ѭ��
			}
			if (!isalnum(ch) && ch != '_')   //���������ĸ�����ֻ��»��ߣ�������˴�ѭ��
				continue;
			//����ֻ�ǽ�����ǰ if ��䣬�������˴�ѭ��
		}

		id[i] = ch;    //���ַ�
		//����ĸ�Ϸ��������һ���8���ַ��ı�ʶ��
		while (i < 7 && (ch = inFile.get()) != EOF && (isalnum(ch) || ch == '_') )
			id[++i] = ch;    //ch����ĸ�������ַ����»��ߣ���ӽ��ַ���
		id[++i] = '\0';    //��ӿ��ַ���Ϊ������־
		if (i >= 8) {	//�������ı�ʶ�����ȸպ�Ϊ 8 �ַ�����Ӧ�ö��⴦��
			//���һ���ַ����������ĸ�����ֻ��»��ߣ���Ϊ������ʶ����
			if ((ch = inFile.get()) != EOF && (isalnum(ch) || ch == '_') ) {
				i = 0;
				id[0] = '\0';	//�ⲻ�����ǹؼ��ʣ����԰�����Ϊ�մ�
				while ((ch=inFile.get()) != EOF && (isalnum(ch) || ch =='_') )
					;    //���벢�����ܹ��ɱ�ʶ���ĺ����ַ�
				continue;	//�����˴�ѭ������ʼ��һ��ѭ��
			}
		}
		break;	//����һ���Ϸ���ʶ��������ѭ��
	}
    return i;
}

int main() {
	//���ļ�
	char filename[56] = "prog6-22test.cpp";    //����׼��һ��ʾ��Դ����
	//cout << "�������ļ���: ";    //��������ʱ����һ��Դ�����ļ���
	//cin >> filename;
	inFile.open (filename); //���ļ�������
	if (!inFile) { //������ļ�ʧ�ܣ��� infile �õ�һ����ֵ
		cout << "�����޷����ļ� " << filename << "��������ֹ��\n";
		exit(1);    // ��ʾ������Ϣ���˳�����
	} else
		cout << "�Ѵ��ļ�����ȡ��" << filename << endl;

	char keywords[32][9] = {
		"auto",  "break",  "case",  "char",  "const",  "continue",  "default",
		"do",  "double",  "else",  "enum",  "extern",  "float",  "for",
		"goto",  "if",  "int",  "long",  "register",  "return",  "short",
		"signed",  "sizeof",  "static",  "struct",  "switch",  "typedef",
		"union", "unsigned",  "void",  "volatile",  "while"
	};

	int counters[32] = {0};
	int MAXLEN = 20;
	char str[MAXLEN];
	int n;
	//while (getident(MAXLEN, str) > 0) {	//���ñ�ʶ�����̲��ϵİ汾��
	while (getident2(MAXLEN, str) > 0) {	//���ñ�ʶ�����Ľ�������ư汾��
		for (n = 0; n < 32; ++n)
			if (strcmp(str, keywords[n]) == 0) {
				counters[n]++;
				break;
			}
	}


	for (n = 0; n < 32; ++n)
		cout << keywords[n] << "\t" << counters[n] << endl;

	inFile.close();

	return 0;
}


