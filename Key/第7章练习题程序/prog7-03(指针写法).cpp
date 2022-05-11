/*********************************************************************
��������������д����дΪָ��д��
��Ȩ�����GPL��ȨЭ�飬������ʹ�úʹ����������ϴ����շ��������Ŀ⣩
���ߣ�anbangli@foxmail.com
���ڣ�2019-07-24
˵����
7-3.����һ���������鷽ʽ����ĺ�������6-7������Ԫ��ƽ��ֵ���͡���6-8��
����ת�������Ԫ�أ���дΪ��ָ������ķ�ʽ���塣
*********************************************************************/
#include <iostream>
using namespace std;

//����6-7��������Ԫ��ƽ��ֵ�ĺ���
double avrg(int len, double a[]) {	//ԭ�е�����д��
    double sum = 0.0;

    for (int i = 0; i < len; ++i)
        sum += a[i];

    return sum / len;
}

double avrg_ptr(int len, double *a) {//ָ��д�������� a[] ��дΪ *a
    double sum = 0.0;

    for (int i = 0; i < len; ++i)
        sum += *(a + i);	// �� a[i] ��дΪ *(a+i)

    return sum / len;
}

//����6-8����ת�������Ԫ�ء�
void rev(int len, int a[]) {	//ԭ�е�����д��
    int t, i, j;

    for (i = 0, j = len - 1; i < j; ++i, --j) {
        t = a[i];
        a[i] = a[j];
        a[j] = t;
    }
}

void rev_ptr(int len, int *a) {	//ָ��д�������� a[] ��Ϊ *a
    int t, i, j;
    for (i = 0, j = len - 1; i < j; ++i, --j) {
        //�� a[i] ��дΪ *(a + i)���� a[j] ��дΪ  *(a + j)
        t = *(a + i);
        *(a + i) = *(a + j);
        *(a + j) = t;
    }
}

void printall(int n, int a[]) {
    for (int i = 0; i < n; ++i)
        cout << *(a + i) << '\t';
    cout << endl;
}

int main() {

    cout << "\n���ԡ���6-7����Ԫ��ƽ��ֵ\n";
    double a1[5] = {6.54, 9.23, 8.463, 4.25, 0.386};    //�������鲢��ʾ�����ݳ�ʼ��

    cout << "averages of a1: " << avrg_ptr(3, a1) << endl;

    cout << "\n���ԡ���6-8����ת�������Ԫ��\n";
    int i, a2[] = {1, 2, 3, 4, 5, 6, 7};
    int len = sizeof(a2) / sizeof(a2[0]);
    cout << "before reversion:" << endl;
    printall(len, a2);

    rev_ptr(len, a2);	//!!!

    cout << endl << "After reversion:" << endl;
    printall(len, a2);

    return 0;
}




