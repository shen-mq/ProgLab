/*********************************************************************
    ������: prog4-30 counters
    ��Ȩ:
    ����: 2021212577 ����ǫ
    ����: 2022-04-06 16:06
    ˵��:
*********************************************************************/
#include <iostream>
#include <fstream>
using namespace std;

int main() {
	int alph = 0, num = 0, punc = 0, spc = 0;//counters: alpha, number, punctuation, space
	int ch;

	//��ȡ����
	ifstream infile("./mytext.txt");//���ļ�
	if (!infile) { //�ļ���������������
		cout << "ERROR: can't open the input file" << endl;
		exit(1);
	}
//	cout << (char) infile.get() << endl;

	//��ʼ����
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
	infile.close();//�ر�input�ļ�

	//���ͳ�ƽ��
	ofstream outfile("output.txt");//������ļ�
	if (!outfile) {
		cout << "ERROR: can't open output file" << endl;
		exit(1);
	}
	outfile << "��ĸ������" << alph << endl;
	outfile << "���ָ�����" << num << endl;
	outfile << "��������" << punc << endl;
	outfile << "�ָ���������" << spc << endl;
	outfile.close();//�ر�output�ļ�

	cout << "��ĸ������" << alph << endl;
	cout << "���ָ�����" << num << endl;
	cout << "��������" << punc << endl;
	cout << "�ָ���������" << spc << endl;

	return 0;
}

