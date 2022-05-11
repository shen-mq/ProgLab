/*********************************************************************
���������ַ�������
��Ȩ�����GPL��ȨЭ�飬������ʹ�úʹ����������ϴ����շ��������Ŀ⣩
���ߣ�anbangli@foxmail.com
���ڣ�2019-08-09
˵����
7-15.�޸�7.5�ڵ�ɸ�����򣬽���������Ĺ����Ƶ�ʵ��ɸ���ĺ��� sieve �
ʹ���������õ����飬�������������ʵ����졣�ӳ���������Ժ͹��ܷ����
�����Եȷ���Ƚ�������ʵ�ַ�ʽ��
**********************************************************************/
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>
using namespace std;

//void sieve(int lim, int an[]) {
int * sieve2(int lim) {	//��д����ͷ��ֻ��һ������������ֵ��Ϊ int *
    int i, j, upb = sqrt(lim + 1);

	//�޸ģ��ں����ж�̬�����ڴ�ռ�
	int * an = new int[lim];	//!!!
    if (an == NULL) {
        cout << "ERROR: No enough memory!\n";
        return NULL;	//�����̬�����ڴ�ʧ�ܣ��������� NULL ֵ
    }

    //��ʼ������
    //an[0] = an[1] = 0;
    for (i = 2; i <= lim; ++i)
        an[i] = 1;

    for (i = 2; i <= upb; ++i)
        if (an[i] == 1) // i������
            for (j = i*2; j <= lim; j += i)
                an[j] = 0; // ��Щ������ i �ı�������˲�������

    return an;	//!!! �����ڱ������ж�̬������ڴ�ռ�ĵ�ַ
}

int main() {
    int i, j, n = -1, *pn;

    do {
        cout << "please input an positive integer (>=2): ";
        cin >> n;
    } while (n < 2);


//    pn = new int[n];
//    if ( pn == NULL) {
//        cout << "ERROR: No enough memory!\n";
//        exit(1);
//    }
//    sieve(n, pn);    //ɸ������

    pn = sieve2(n);    //!!���ø�д���ɸ��������ֻ�ṩ���� n������ָ��

    for(j = 0, i = 2; i <= n; ++i)
        if (pn[i] == 1)
            cout << i << ((++j) % 10 != 0 ? '\t' : '\n');
    cout << "\n�ܸ���: " << j <<endl;

	delete []pn;

    return 0;
}

