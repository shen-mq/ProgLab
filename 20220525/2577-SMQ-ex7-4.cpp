/*********************************************************************
    ������:ex7-4
    ��Ȩ:
    ����:2021212577 ����ǫ
    ����: 2022-05-25 16:21
    ˵��:
*********************************************************************/
#include <iostream>
#include <ctime>
using namespace std;

double avrgSeq(double *begin, double *end) {
	double sum = 0.;
	for (double *p = begin; p < end; ++p) {
		sum += *p;
	}
	return (begin >= end ? 0 : sum / (end - begin));
}

int main() {
	double b[40] = {0.};

//	srand(time(0));
	for (int i = 0; i < 40; i++) {
		b[i] = (double)rand() / (RAND_MAX / 10) ;
		cout << fixed << b[i] << (i % 5 == 4 ? '\n' : '\t');//ԭ��fixedҲֻ��Ҫ<iostream>�͹���
	}

	cout << avrgSeq(b, b + 20) << endl;
	cout << avrgSeq(b + 10, b + 10) << endl;
	cout << avrgSeq(b + 40, b + 40) << endl;
	cout << avrgSeq(b, b + 1) << endl;

	return 0;
}

