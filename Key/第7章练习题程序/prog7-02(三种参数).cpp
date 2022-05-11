/*********************************************************************
��������C/C++�����е�ֵ���������ò�����ָ�����
��Ȩ�����GPL��ȨЭ�飬������ʹ�úʹ����������ϴ����շ��������Ŀ⣩
���ߣ�anbangli@foxmail.com
���ڣ�2019-12-29 15:43
˵����
7-2. ����5-8����5-9����7-1�е���������д��һ�������У���дһ��������
�ֱ�������ǣ��ԶԱ����ֲ������Ƶ���ͬ��
*********************************************************************/
#include <iostream>
using namespace std;

//����5-8��ֵ����
void swap(int a, int b) {
    int t = a;
    a = b;
    b = t;
    cout << "swaped inside: a= " << a << "  b= " << b << endl;
}

//����5-9�����ò���
void swapref(int &a, int &b)  { //�β�a, b��������
    int t = a;
    a = b;
    b = t;
    cout << "swaped inside: a= " << a << "  b= " << b << endl;
}

//����7-1��ָ�����
void swapptr(int *p, int *q) {
    int t = *p;
    *p = *q;
    *q = t;
    cout << "swaped inside: *p= " << *p << "  *q= " << *q << endl;
}

int main() {
    int m = 10, n = 25;
    cout << "before swap: m= " << m << "  n= " << n << endl;
    swap(m, n);		//����5-8��ֵ����
    cout << "after swap:  m= " << m << "  n= " << n << endl;

    m = 10, n = 25;
    cout << endl << "before swapref: m= " << m << "  n= " << n << endl;
    swapref(m, n);	//����5-9�����ò���
    cout << "after swapref:  m= " << m << "  n= " << n << endl;

    m = 10, n = 25;
    cout << endl << "before swapptr: m= " << m << "  n= " << n << endl;
    swapptr(&m, &n);	//����7-1��ָ�����
    cout << "after swapptr:  m= " << m << "  n= " << n << endl;
    return 0;
}

