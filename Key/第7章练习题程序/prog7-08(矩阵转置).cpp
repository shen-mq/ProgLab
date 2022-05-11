/*********************************************************************
������������ת��
��Ȩ�����GPL��ȨЭ�飬������ʹ�úʹ����������ϴ����շ��������Ŀ⣩
���ߣ�anbangli@foxmail.com
���ڣ�2019-08-09
˵����
7-8.��*����������ֵ��������õĽṹ֮һ���ڳ�������Ժ���Ȼ�ز�����ά
�����ʾ���밴�ձ�������Ĵ�����ά�����ͨ�ú����ļ�����д��ʵ�־���ת��
�ĺ���������ԭ��Ϊ��TransMatrix (int m, int n, double *mat, double *trans)��
ʵ�ְ� m �� n �еĶ�ά���� mat ת��Ϊ n �� m �еĶ�ά���� trans��
*********************************************************************/
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

//�̲����ṩ�ľ����ӡ�����������ʽ������� fixed �� setprecision���Ա������ӡ��
void prtMatrix (int m, int n, double *mat) {
    int i, j;
    for (i = 0; i < m; ++i) {
        for (j = 0; j < n; ++j)
            cout << fixed << setprecision(2) << *(mat + i * n + j) << "\t";
        putchar('\n');
    }
}

void TransMatrix (int m, int n, double *mat, double *trans) {
//�� m �� n �еľ��� mat ת��Ϊ n �� m �еľ��� trans
    int i, j;
    for (i = 0; i < m; ++i) 	// �� mat ת�õĽ������� t ��
        for (j = 0; j < n; ++j)
            *(trans + j * m + i) = *(mat + i * n + j);
    //ת�ò���ʵ����ϣ���������¸�ֵ��trans[j][i] = mat[i][j]�����˺����в���������д����
    //���� m �� n �е����� mat���� i �� j �е�Ԫ�صĵ�ַ�� &mat[0][0] + i * n + j��
    //���� n �� m �е����� trans���� j �� i �е�Ԫ�صĵ�ַ�� &trans[0][0] + j * m + i��
}

int main() {
    const int ROW = 2, COL = 3;
    double a1[ROW][COL] = {{1.1, 2.2, 3.3}, {4.4, 5.5, 6.6}}; //�����ά���鲢��ʼ��Ϊʾ������
    double a2[COL][ROW] = {0};

    cout << "ԭ���� a1 = " << endl;
    prtMatrix (ROW, COL, &a1[0][0]);	//��ӡԭ������ע�����������д��

    TransMatrix (ROW, COL, &a1[0][0], &a2[0][0]);	//!!! �� a1 ת��Ϊ a2

    cout << "\nת�ú������ a2 = " << endl;
    prtMatrix (COL, ROW, &a2[0][0]);	//��ӡת�ú�ľ�����ע�������еĲ�����

    return 0;
}

