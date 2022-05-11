/*********************************************************************
�������������ַ���ת��������
��Ȩ�����GPL��ȨЭ�飬������ʹ�úʹ����������ϴ����շ��������Ŀ⣩
���ߣ�anbangli@foxmail.com
���ڣ�2019-07-22
˵����6-14.��1��дһ���������ַ���ת���������ĺ�������ֻ��һ���ַ�����
��������2�����Ƶأ�дһ���ѺϺ�C/C++ ����ʵ����������ʽ���ַ���ת����
һ��˫�������ĺ�����
*********************************************************************/
#include <iostream>
using namespace std;

int str2int(const char str[]) {
	int num = 0;	//��������
	int sign = 1;	//������
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] >= '0' && str[i] <= '9')
			num = num*10 + str[i] - '0';
		if (str[i] == '-')
			sign = -1 * sign;
		//����������ֱ������ num ��������ԭ���� num ��ʼֵΪ 0 �����ܶ� 0 ����������
	}
	num = num * sign;
	return num;
}

double str2double(const char str[]){	//ע�⣬����ֵΪ double ����
	double num = 0;	//˫����������
	int sign = 1;	//������
	int isfract = 0;	//�Ƿ�ΪС������
	double fract = 0.1;	//С�����ֵ�Ȩ
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] == '.')
			isfract = 1;	//����ΪС������
		if (str[i] >= '0' && str[i] <= '9'){
			if (!isfract)	//��������
				num = num*10 + str[i] - '0';
			else{ 	//С������
				num = num + (str[i] - '0') * fract;
				fract = fract * 0.1;
			}
		}
		if (str[i] == '-')
			sign = -1 * sign;
		//����������ֱ������ num ��������ԭ���� num ��ʼֵΪ 0 �����ܶ� 0 ����������
	}
	num = num * sign;
	return num;
}

int main () {
	char str[100];
	cout << str2int("1a2b3c4d") << endl;
	cout << str2int("-1a2b3c4d") << endl;

	cout << str2double("3.1415926d") << endl;
	cout << str2double("-3.1415926d") << endl;

	return 0;
}


