/*********************************************************************
    ������: ex4-13
    ��Ȩ:
    ����: 2021212577 ����ǫ
    ����: 2022-04-06 16:06
    ˵��:
*********************************************************************/
#include <iostream>
#include <fstream>
using namespace std;

int main() {
	int n = 0;
	double x, sum = 0;

	ifstream infile("./data.txt");//���ļ�
	if (!infile) { //�ļ���������������
		cout << "ERROR: can't open the input file" << endl;
		exit(1);
	}
	ofstream outfile("output.txt");//������ļ�
	if (!outfile) {
		cout << "ERROR: can't open output file" << endl;
		exit(1);
	}

	cout << "read data from input file" << endl;
	while ((infile >> x)) {
		n++;
		sum += x;
		cout << x << endl;
	}
	infile.close();//�ر�input�ļ�

	//�������Ļ&�ļ�
	cout << "n = " << n << endl;
	outfile << "n = " << n << endl;
	cout << "Sum = " << sum << endl;
	outfile << "Sum = " << sum << endl;

	outfile.close();
	cout << "results save in the file output.txt";

	return 0;
}

