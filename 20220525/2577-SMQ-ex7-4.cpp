/*********************************************************************
    程序名:ex7-4
    版权:
    作者:2021212577 沈鸣谦
    日期: 2022-05-25 16:21
    说明:
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
		cout << fixed << b[i] << (i % 5 == 4 ? '\n' : '\t');//原来fixed也只需要<iostream>就够了
	}

	cout << avrgSeq(b, b + 20) << endl;
	cout << avrgSeq(b + 10, b + 10) << endl;
	cout << avrgSeq(b + 40, b + 40) << endl;
	cout << avrgSeq(b, b + 1) << endl;

	return 0;
}

