/*********************************************************************
    程序名:prog7-3
    版权:
    作者:2021212577 沈鸣谦
    日期: 2022-05-25 16:21
    说明:
*********************************************************************/
#include <iostream>
#include <ctime>
using namespace std;

void reverse(int len, int a[]) {//ex6-9
	int t, i, j;
	for (i = 0, j = len - 1;  i < j;  ++i, --j) {
		t = a[i];
		a[i] = a[j];
		a[j] = t;
	}
}

void reversePtr(int len, int *a) {//ex6-9 指针改写
	int *begin = a, *end = a + len;
	int t;
	for (int *p = begin, *q = end - 1; p < q; p++, q--) {
		t = *p, *p = *q, *q = t;//用","似乎也可以?
	}
}

void insertsort(int n, int a[]) { //ex6-10 升序插入排序
	int i, j;
	int t;
	for (i = 1; i < n; ++i) {
		for (t = a[i], j = i - 1; j >= 0 && t < a[j]; --j)
			a[j + 1] = a[j];
		if (j != i - 1)
			a[j + 1] = t;
	}
}

void insertsortPtr(int len, int *a) {
	int *begin = a, *end = a + len;
	int *p_i, *p_j;
	int t;

	for (p_i = a + 1; p_i < end; p_i++) {
		for (p_j = p_i - 1, t = *p_i; p_j >= begin && t < *p_j; --p_j) {
			*(p_j + 1) = *p_j;
		}
		*(p_j + 1) = t;
	}
}

int main() {
	const int LEN = 30;
	int a[LEN] = {0}, b[LEN] = {0};

	srand(time(0));
	for (int i = 0; i < LEN; i++) {//initialize
		a[i] = b[i] = rand() % 100 ;
		cout << a[i] << (i % 10 == 9 ? '\n' : '\t');
	}

//分别用两个reverse函数作用与a, b数组
	reverse(sizeof(a) / sizeof(a[0]), a);
	reversePtr(sizeof(b) / sizeof(b[0]), b);

	cout << endl << endl;

	for (int i = 0; i < LEN; i++) {
		cout << a[i] << (i % 10 == 9 ? '\n' : '\t');
	}
	cout <<  endl;
	for (int i = 0; i < LEN; i++) {
		cout << b[i] << (i % 10 == 9 ? '\n' : '\t');
	}

	cout << endl << endl;
//分别用两个sort对a, b排序
	insertsort(sizeof(a) / sizeof(a[0]), a);
	insertsortPtr(sizeof(b) / sizeof(b[0]), b);

	for (int i = 0; i < LEN; i++) {
		cout << a[i] << (i % 10 == 9 ? '\n' : '\t');
	}
	cout <<  endl;
	for (int i = 0; i < LEN; i++) {
		cout << b[i] << (i % 10 == 9 ? '\n' : '\t');
	}


	return 0;
}

