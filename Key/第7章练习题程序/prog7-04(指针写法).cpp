/*********************************************************************
��������������д����дΪָ��д��
��Ȩ�����GPL��ȨЭ�飬������ʹ�úʹ����������ϴ����շ��������Ŀ⣩
���ߣ�anbangli@foxmail.com
���ڣ�2019-07-24
˵����
7-4. ����һ���������鷽ʽ����ĺ�������6-9��������Ԫ�����򣩺͡���6-14��
���ַ������ƣ���дΪ��ָ������ķ�ʽ���塣
*********************************************************************/
#include <iostream>
using namespace std;

//����6-9������Ԫ������
void insertsort(int n, int a[]) { //���������鰴�յ�����ֱ�Ӳ�������
    int i, j;
    int t;

    for (i = 1; i < n; ++i ) {
        for (t = a[i], j = i - 1; j >= 0 && t < a[j]; --j)
            a[j + 1] = a[j];  //��Ԫ�����κ���
        if (j != i - 1)
            a[j + 1] = t;
    }
}

void insertsort_ptr(int n, int *a) { //ָ��д�����Ѳ��� a[] ��Ϊ *a
    int i, j;
    int t;
    //����ѭ������������д������Ϊָ��д��
    for (i = 1; i < n; ++i ) {
        for (t = *(a + i), j = i - 1; j >= 0 && t < * (a + j); --j)
            *(a + j + 1) = *(a + j);    //��Ԫ�����κ���
        if (j != i - 1)
            *(a + j + 1) = t;
    }
}


//����6-14���ַ�������
void str_copy (char s[], const char t[]) {  //����д�� �汾3
    int i = 0;
    while (s[i] = t[i])
        ++i;
}

void str_copy_ptr (char *s, const char *t) {//ָ��д��������s[]��Ϊ*s��t[]��Ϊ*t
    int i = 0;
    while (*(s + i) = *(t + i))		//�� s[i] �� t[i] ��Ϊָ��д��
        ++i;
}


void printall(int n, int *a) {	//ָ��д�������� int a[] �ȼ��� int *a
    for (int i = 0; i < n; ++i)
        cout << *(a + i) << '\t';
    cout << endl;
}


int main() {
    cout << "\n���ԡ���6-9������Ԫ������\n";
    int array[] = {3, 2, 5, 1, 7, 8, 10, 6, 5 };//�������鲢��ʾ�����ݳ�ʼ��
    int len = sizeof(array) / sizeof(array[0]);

    cout << "before sorting:" << endl;
    printall(len, array);

    insertsort_ptr(len, array);    //!!!

    cout << "after sorting:" << endl;
    printall(len, array);

    cout << "\n���� ����6-14���ַ�������\n";
    const int LEN = 200;
    char s[LEN] = "";
    char t[LEN] = "Welcome to programming kingdom!";

    cout << "t: " << t << endl;
    str_copy_ptr(s, t);    //!!!
    cout << "s: " << s << endl;

    return 0;
}




