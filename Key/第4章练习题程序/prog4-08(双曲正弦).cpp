/*********************************************************************
����������˫�����ҷ�������ͨ����㣩
��Ȩ�����GPL��ȨЭ�飬������ʹ�úʹ����������ϴ����շ��������Ŀ⣩
���ߣ�anbangli@foxmail.com
���ڣ�2019-07-20
˵����
4-8.(ͨ����㣩��֪˫�����ҷ����� asinh(x)= ......                 ��
д������� asinh(x)�Ľ���ֵ��β���ֵС��10?7ʱ�ض�)�������׼�⺯��
asinh ��Ƚ���ȷ�Ͻ���Ƿ���ȷ��
*********************************************************************/

#include <iostream>
#include <cmath>	//��ѧ����
#include <iomanip>
using namespace std;

int main() {
	int i;
	double x, term = 0, sum = 0;

	cout << "����˫�����ҷ����� asinh(x)" << endl;
	//cout << "������ x (|x|<1): " ;
	//cin >> x;
	x = 0.8;
	if (fabs(x) >= 1) {
		cout << "ERROR��x >= 1" << endl;
		return 1;
	}

	sum = term = x;	// ���� �����߳�Ϊ �� 0 �
	for (i = 1; fabs(term) > 1e-7; i++) {
		//��һ����ǰһ��Ĺ�ϵ������ -x*x �����ӳ��� (2*i-1)*(2*i-1)����ĸ���� (2*i)*(2*i+1)
		term = term * (-1) * x * x * (2*i-1) * (2*i-1) /(2*i) / (2*i+1);
		sum = sum + term;
		cout << "i= " << i << setprecision(10) << "\tterm= " << term << "\tasinh(x)= " << sum << endl;
	}
	cout << "x= " << x << "\t   asinh(x)= " << sum << endl;
	cout << "��׼�⺯�� asinh(x)= " << asinh(x) << endl;

	return 0;
}

