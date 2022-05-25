/*********************************************************************
    ������:prog7-4 ��ӡ��������У��������п���
    ��Ȩ:
    ����:2021212577 ����ǫ
    ����: 2022-05-25 16:21
    ˵��:
*********************************************************************/
#include <iostream>
#include <ctime>
#include <cmath>
using namespace std;

void prtSeq(double *begin, double *end) {
	for (double *p = begin; p < end; p++) {
		cout << *p << ( (p - begin) % 10 == 9 ? '\n' : '\t' );
	}
}

void sqrtSeq(double *begin, double *end) {
	for (double *p = begin; p < end; p++) {
		*p = sqrt(*p);
	}
}

int main() {
	const int LEN = 40;
	double a[LEN] = {0.};
//	srand(time(0));
	for (int i = 0; i < LEN; i++) {
		a[i] = (double)rand() / (RAND_MAX / 10) ;
		cout << fixed << a[i] << (i % 5 == 4 ? '\n' : '\t');
	}

	cout << endl << endl;
	prtSeq(a + 10, a + 20);
	sqrtSeq(a + 10, a + 20);

	cout << endl << endl;
	for (int i = 0; i < LEN; i++) {
		cout << fixed << a[i] << (i % 5 == 4 ? '\n' : '\t');
	}



	return 0;
}

