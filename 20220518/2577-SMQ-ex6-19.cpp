/*********************************************************************
    ������:ex6-19
    ��Ȩ:
    ����: 2021212577 ����ǫ
    ����: 2022-05-18 16:19
    ˵��:
*********************************************************************/
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main() {
	const int MAXLEN = 1024;
	char line[MAXLEN + 1], maxline[MAXLEN + 1];
	int max = 0;//OR long long unsigned int
//	[����] comparison of integer���ʽs of different signedness: 'size_t' {aka 'long long unsigned int'} �� 'int' [-Wsign-compare]

	char filename[56] = "plain.txt";
	ifstream input(filename);
	if (!input) {
		cout << "ERROR: file not found" << endl;
		exit(1);
	}
	cout << "Reading from file: " << filename << endl << endl;
	while (input.getline(line, MAXLEN)) {
		if (strlen(line) > max) {
			strcpy(maxline, line);
			max = strlen(line);
		}
	}
	input.close();

	cout << "Longest line: \n" << maxline << endl;
	cout << "\nLength: " << max << endl;

	return 0;
}

