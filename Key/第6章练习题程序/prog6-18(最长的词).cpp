/*********************************************************************
������������һ��Ӣ�Ĵ��ı��ļ������������Ĵ�
��Ȩ�����GPL��ȨЭ�飬������ʹ�úʹ����������ϴ����շ��������Ŀ⣩
���ߣ�anbangli@foxmail.com
���ڣ�2019-07-24
˵����6-18.дһ������������һ��Ӣ�Ĵ��ı��ļ������������Ĵʣ��ο�
ǰ���½ڶԡ��ʡ��Ķ��壬��Ҳ�����Լ��涨������涨��������ĸ��ͷ����ĸ
�������У���

����˵����1���ο��̲ĵ� 4 ���С���4-18�������ʼ����������Զ�����ʹ�á�
ʾ������ʵ�ִ��ļ��ж�ȡ���ʣ����������ṩ�����ֶ�ȡ���ʵ�д����Ӧ��
ѡ������һ�ַ����ڸ�д�ԶԵ��ʼ��㳤�ȵ�д����2��Ȼ��ο���6�¡���6-17��
����ȡ���ı��ļ�������������һ�С���ʵ���������ʡ�
*********************************************************************/
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main () {
	char filename[20] = "GPL.txt";  //�����ַ������Դ洢�ļ���
	//����Ӧ��׼��һ���ϴ���ļ���������һЩ�е����ֳ��Ƚϴ�
	//�����������ҳ���Ʋ�����Ϊ GPL.txt ��http://www.gnu.org/licenses/gpl-3.0.html
	ifstream infile(filename);  //�����ļ����������������ļ�
	if (infile)
		cout << "Reading from file: " << filename << endl;
	else {
		cout << "ERROR: can't open input file " << filename << endl;
		exit(1);
	}

	const int MAXLEN = 256;		//�������ɴ� 256
	char word[MAXLEN], maxword[MAXLEN];	//��ǰ����ĵ��ʣ���ĵ��ʣ�
	int len, maxlen = 0;	//��ǰ���ʳ��ȣ���󵥴ʳ���

	//�˴�ѡȡ����4-18���ж�ȡ���ʵĵ�����д�������в�����Ҫ��״̬ת����
	int ch = ' ', counter = 0;
	while (ch != EOF) {
		while ((ch = infile.get()) != EOF && !isalnum(ch))
			//���ļ��ж�ȡ�ַ�����ch�Ƿָ��ַ�ʱ�ظ���ȡ
			;    //��ѭ����
		if (ch == EOF) break;
		++counter;	//���ʼ���

		//����ѭ������ʱ�Ѷ���һ���ǿո��ַ�
		len = 1;	//���ʳ���
		word[len - 1] = ch;
		while ((ch = infile.get()) != EOF && isalnum(ch)) {
			//���ļ��ж�ȡ�ַ����� ch ����ĸ�������ַ��ظ���ȡ
			//��ԭ�еĿ�ѭ�����дΪ�Ե��ʳ��ȼ���
			len++;
			word[len-1] = ch;
		}
		//����һ�����ʣ������Ӧ�Ĵ���
		word[len] = '\0';	//�ַ�����ĩβ��ӿ��ַ�
		//cout << word << "\t" ;	//debug
		if (len > maxlen) {
			strcpy(maxword, word);
			maxlen = len;
			cout << word << endl;	//debug
		}
	}
	infile.close(); //�ر��ļ�

	cout << "\nLongest word: " << maxword << endl;
	cout << "\nLength: " << maxlen << endl;
	//cout << "\ntotal words: " << counter << endl;
	return 0;
}

