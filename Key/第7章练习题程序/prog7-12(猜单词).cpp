/*********************************************************************
���������µ���
��Ȩ�����GPL��ȨЭ�飬������ʹ�úʹ����������ϴ����շ��������Ŀ⣩
���ߣ�anbangli@foxmail.com
���ڣ�2019-08-09
˵����
7-12.дһ�����µ��ʡ���С��Ϸ�������ڲ��洢��һЩӢ�ﵥ�ʣ���д����ʱ����
���ʼ��ϣ�������������ÿ������Щ�����������ѡ��һ�������Ըõ���������ĸ
������ʾһϵ�еġ�*���ַ���Ҫ����Ϸ�߲¡���Ϸ�߷����²�ĳЩ��ĸ�Ƿ������
���µ����У��������Ӧ��������ڴ��µ��ʡ�green��������Ϸ�߲²���ĸ��e��
ʱ�����������**ee*������ֱ����Ϸ�߲³�������ʣ����߷�������
**********************************************************************/
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <ctime>
#include <cmath>
#include <iomanip>

using namespace std;

int readword(int maxwords, char words[][20]) { //�������ļ��ж��뵥��
	char ch;
	int i = 0, j = 0;
	ifstream infile("words.txt");//�ļ���
	if(!infile) {
		printf("�������words.txt ���ܴ򿪣�\n");
		return 0;
	}
	while((ch = infile.get()) != EOF && i < maxwords) {
		if(ch != ' ' && ch != '\n') {	//ͬһ�������е���ĸ
			words[i][j] = ch;
			j++;
		} else if (j > 0){	//��ǰ���ʵ���ĸ������ 1
			i++;
			j = 0;
		}
	}
	infile.close();
	return i;//���ض��뵥����
}

int main() {
	cout << "�µ�����Ϸ\n";

	int i, j, k, n, maxlen = 0;
	char words[100][20];	//���µ��ʼ������ 100 �����ʣ�ÿ�����Ϊ20

	//�ṩ�������òµ��ʵķ�������Ȼʵ�ʲ�����ֻ��ѡ������һ�֡�
	//���ô��µ��ʼ��Ϸ���һ��׼��һЩʾ�����ʣ����Ƶ����µ��ʼ�
	const char *examples[] = {"red", "green", "blue", "yellow", "purple", "white", "gray", "black"};
	n = sizeof(examples) / sizeof(examples[0]);	//�洢��������������play���ѡ�񵥴ʱ��
	for (i = 0; i < n; i++)
		strcpy (words[i], examples[i]);

	//���ô��µ��ʼ��Ϸ�����������׼��һ���洢���ʵ��ļ����Ӹ��ļ��ж�ȡ
	//n =  readword(100, words);	//ʹ�� readword �������ļ��ж�ȡ����

	cout << "���µ��ʼ����еĵ�����Ŀ��" << n << endl;
	for (i = 0; i < n; i++)		//���������󳤶�
		if (strlen(words[i]) > maxlen)
			maxlen = strlen(words[i]);
	cout << "������󳤶ȣ�" << maxlen << endl;

	cout << "\t��ӭ����µ�����Ϸ��\n";

	int chok;	//chok����Ƿ�¶���ĸ
	int temp;	//�洢������ʱ��
	int len;	//���µ��ʳ���

	char guess;	//�û��²����ĸ
	char str[30];//���µ���
	char guessword[30];//��ԭ�����ʶԱ�

	char tt = 'Y';	//�Ƿ������
	int maxtime = 15;	//����Ĳ²����
	int correct, wrong;//ͳ�ƶ����Ĵ���
	double grade;	//��¼�ɼ�

	srand((unsigned)time(NULL));	//��ʼ�����������
	while(tt == 'Y' || tt == 'y') { //�ظ���Ϸ
		cout << "*************��Ϸ��ʼ*************\n";
		correct = 0;
		wrong = 0;//ÿ�β�֮ǰ��ʼ�������Ĵ���

		temp = rand() % n;	//ȡ�����
		strcpy(str, words[temp]);
		//cout << str << endl;	//debug

		len = strlen(str);
		for (i = 0; i < len; i++) //��ʼ���ַ���ȫ��Ϊ '*' �ַ�
			guessword[i] = '*';
		guessword[len] = '\0';
		temp = rand() % len;
		guessword[temp] = str[temp];	//�����ʾ����ĳ���ַ�

		for(i = 1; i <= maxtime; i++) { //δ��������ƣ�ѭ���²�
			cout << "���µ���: " << guessword << endl;
			chok = 0;
			cout << "����ĸ: ";
			cin >> guess;
			guess = tolower(guess);
			for(j = 0; j < len; j++) {	//�滻�ַ�
				if(guess == str[j]) {
					guessword[j] = guess;
					chok = 1;
				}
			}
			if(chok) { //chokΪ1���²���ĸ��ȷ
				cout << "��ȷ��" << endl;
				if (strchr(guessword, '*') == NULL ) {//������ĸ�Ƿ�ȫ���³�(�Ƿ����Ǻ�)
					cout << "��ϲ��¶���: " << guessword << endl;
					break;
				}
			} else {
				cout <<"�²���󣬻����Բ� " << maxtime - i << "��\n";
				wrong++;
			}
		}
		if (strchr(guessword, '*') == NULL)
			correct = (i - wrong);//��ȷ����������ֱ��ͳ�ƣ������������������
		else
			correct = (maxtime - wrong);
		cout << "\t���ֽ��������µ���Ϊ " << str << endl;
		cout << "�²���ĸ��ȷ������" << correct << "  ���������" << wrong << endl;
		cout << "�Ƿ������(Y/N) ";
		cin >> tt;
	}

	return 0;
}




