/*********************************************************************
    ������: prog4-23 sum of factorial
    ��Ȩ:
    ����: 2021212577 ����ǫ
    ����: 2022-03-30 16:03
    ˵��:
*********************************************************************/

#include <iostream>
using namespace std;

int main() {
	int k;
	cout << "Please input k: ";
	cin >> k;
//	k = 1;
//	do {

	//����ѭ���Ľⷨ
	//���ѭ��������ͣ��ڲ�ѭ������׳�
	int sum = 0, n = 1; //sum �洢��͵�ֵ��n�洢�׳˵�ֵ; �ɷֱ��� int ��long long ����
	for (int i = 1; i <= k; i++) {
		for (int j = 1; j <= i; j++) {
			n *= j;
		}
		sum += n;
		n = 1;
	}
	cout << "sum of the factorial is: " << sum << endl;

	//һ��ѭ���ⷨ
	//ÿ��ѭ��������Ϊ������һ������Ľ׳˳��� j ���õ���һ�ν׳˵�ֵ����Ȼ��ѽ׳˵�ֵ�ۼӵ� sum ��ȥ
	sum = 0;
	n = 1;
	for (int i = 1; i <= k; i++) {
		n *= i;
		sum += n;
	}
	cout << "sum of the factorial is: " << sum << endl;

//		cout << "k = " << k << endl;
//		k += 1;
//	} while (k <= 40);//�� do-while ��ѭ�����

	return 0;
}
// sum, n Ϊ int ��ʱ, �� k = 13 ��������; ��long long�ʹ� k = 21 ��ʼ�������
