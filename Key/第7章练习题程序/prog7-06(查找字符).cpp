/*********************************************************************
������: ���ַ����в����ַ�
��Ȩ�����GPL��ȨЭ�飬������ʹ�úʹ����������ϴ����շ��������Ŀ⣩
���ߣ�anbangli@foxmail.com
����: 2021-06-02 11:19
˵��:
prog7-6. ʹ�����ֲ�ͬʵ�ַ�ʽ��д���������ڲ����ַ��� s ���״γ����ַ� ch ��λ�ã�
��1������ԭ��Ϊ int strchar1(char s[], int ch); ���ɹ�ʱ�����ַ� ch ���ַ��� s ��
�״γ��ֵ�λ����ţ����±�ֵ�� 1�����Ҳ���ʱ����ֵ 0��
��2������ԭ��Ϊ char *strchar2(char *s int ch);�����ҳɹ�ʱ����ָ���λ�õ�ָ�룬
��� s �в����� ch �򷵻� NULL��
*********************************************************************/

#include <iostream>
using namespace std;

int strchar1(char s[], int ch) {
    int i;
    for (i = 0; s[i] != '\0'; i++)
        if (s[i] == ch)
            break;
//��һ�ֽ��յ�д����
//	for (i = 0; s[i] != '\0' && s[i] != ch; i++)	//ѭ�������бȽϿ��ַ����ַ�ch
//		;	//��ѭ����
    return (s[i] == '\0' ? 0 : i + 1);
}

char *strchar2(char *s, int ch) {
    char *p;
    for (p = s; *p != '\0'; p++)
        if (*p == ch)
            break;
    return (*p == '\0' ? NULL : p);
}

int main() {
    char str[100] = "hello, world!";
    char ch = 'o';
    int k = strchar1(str, ch);
    cout << "k= " << k << "  " << str[k - 1] << endl;

    char *p1 = strchar2(str, ch);
    cout << "p1= " << p1 << endl;
    cout << "*p1= " << *p1 << endl;
    return 0;
}
