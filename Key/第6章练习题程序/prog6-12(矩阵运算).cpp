/*********************************************************************
����������ά����ĺ���
��Ȩ�����GPL��ȨЭ�飬������ʹ�úʹ����������ϴ����շ��������Ŀ⣩
���ߣ�anbangli@foxmail.com
���ڣ�2019-07-22
˵����6-12.���������йض��崦���ά����ĺ����Ĺ涨��д���� 4 �� 4 ��
������ӡ��������˵ĺ�����
*********************************************************************/
#include <iostream>
using namespace std;

const int N = 4;	//ȫ�ֳ�����

void MatPlus(int n, double a[][N], double b[][N], double c[][N]) {//����ӷ�
	int i, j;
	for (i = 0; i < n; i++)
		for (j = 0; j < N; j++)
			c[i][j] = a[i][j] + b[i][j];
	return;
}

void MatMinus(int n, double a[][N], double b[][N], double c[][N]) {//�������
	int i, j;
	for (i = 0; i < n; i++)
		for (j = 0; j < N; j++)
			c[i][j] = a[i][j] - b[i][j];
	return;
}


void MatMulti(int n, double a[][N], double b[][N], double c[][N]) {//����˷�
	int i, j, k;
	double x;

	for (i = 0; i < n; ++i)
		for (j = 0; j < N; ++j) {
			for (x = 0.0, k = 0; k < N; ++k)
				x += a[i][k] * b[k][j];
			c[i][j] = x;
		}
	return;
}

void MatInit0(int n, double mat[][N]) {	//����ȫ��Ԫ�س�ʼ��Ϊ 0
	int i, j;
	for (i = 0; i < n; i++)
		for (j = 0; j < N; j++)
			cout << mat[i][j] << (j != N-1 ? "\t" : "\n");
}

void PrintMat(int n, double mat[][N]) {	//��ӡ n * N �ľ���
	int i, j;
	for (i = 0; i < n; i++)
		for (j = 0; j < N; j++)
			cout << mat[i][j] << (j != N-1 ? "\t" : "\n");
}

int main() {
	// �������� matA �� matB������ʾ�����ݳ�ʼ��
	double matA[N][N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
	double matB[N][N] = {0.1, 0.2, 0.3, 0.4, 1.1, 1.2, 1.3, 1.4,
	                     2.1, 2.2, 2.3, 2.4, 3.1, 3.2, 3.3, 3.4
	                    };
	double matC[N][N] = {0}; //��������C����ʼ��������Ԫ�س�ʼ��Ϊ0��

	cout << "\n������ӣ�\n";
	MatPlus(N, matA, matB, matC);
	PrintMat(N, matC);

	cout << "\n���������\n";
	MatMinus(N, matA, matB, matC);
	PrintMat(N, matC);

	cout << "\n������ˣ�\n";
	MatMulti(N, matA, matB, matC);
	PrintMat(N, matC);

	return 0;
}

