/*********************************************************************
��������շת��������Լ��
��Ȩ�����GPL��ȨЭ�飬������ʹ�úʹ����������ϴ����շ��������Ŀ⣩
���ߣ�anbangli@foxmail.com
���ڣ�2019-07-21
˵����
5-6.6.�����Լ������һ�ַ�����շת���������ݹ鶨��Ϊ������m > 0, n > 0����
              m              (m=n)
gcd(m, n) =   gcd(n, m) 	 (n>m)
              gcd(m-n, n)    (m>n)
����������壬�õݹ��ѭ����ʽ��д��һ�������Լ���ĺ�����
���õݹ鷽��д���ĺ���ȡ��Ϊ gcdminus �� gcdrecur2��ѭ����ʽд���ĺ���ȡ��
Ϊ gcdcycle2��
*********************************************************************/
#include <iostream>
using namespace std;

//�õݹ鷽����дʱ�������ڽ̲��е�ʾ���������������������Ĺ��ܡ�
long gcdminus(long m, long n) {	
// m �� n �Բ�Ϊ 0 ʱ��շת������ĵݹ鷽ʽ�������Լ�� 
	if (m == n)
		return m;
	else if (n > m)
		return gcdminus(n, m);
	else
		return gcdminus(m - n, n);
	//�������� if ���д�ɵģ�Ҳ������Ƕ�׵��������ʽд�����¼����ʽ��
	//return m == n ? n : (n > m? gcdminus(n, m) : gcdminus(m -n, n);
}

long gcdrecur2(long m, long n) {
	if (m < 0) m = -m;
	if (n < 0) n = -n;
	
	//����Ҫ������������ m �� n Ϊ 0 ������ 
	if (m == 0)
		return n;
	else if (n == 0)
		return m;
	else 
		return gcdminus(m, n);	//m �� n �Բ�Ϊ 0 ������ 
}

long gcdcycle2 (long m, long n) {	
//ѭ����ʽʵ����շת������������������Լ�� 
	m = (m >= 0 ? m : -m);
	n = (n >= 0 ? n : -n);
	
	if (m == 0)
		return n;
	if (n == 0 || n == m )
		return m;
		
	while(m != n)
		if(m > n )
			m = m - n;
		else 
			n = n -m;
	return m; 
}

int main() {

	cout << "��շת������������������Լ��" << endl;
	// Ҫʹ�ø��ֲ��������������ֱ���в��� 

	cout << "�ݹ鷽����" << endl;
	
	//������ͨ���������Լ����Ϊ 1 
	cout << "18  24 : " << gcdrecur2(18, 24) << endl;	
	cout << "24  18 : " << gcdrecur2(24, 18) << endl;
	//�����������ʣ����Լ��Ϊ 1 
	cout << "18   5 : " << gcdrecur2(18, 5) << endl;
	cout << " 5  18 : " << gcdrecur2(5, 18) << endl;
	//����һ������Ϊ 0 
	cout << "18   0 : " << gcdrecur2(18, 0) << endl;
	cout << " 0  18 : " << gcdrecur2(0, 18) << endl;
	//����һ������Ϊ����
	cout << "-18  24 : " << gcdrecur2(-18, 24) << endl;	 
	cout << "24  -18 : " << gcdrecur2(24, -18) << endl;
	

	cout << "ѭ��������" << endl;
	//������ͨ���������Լ����Ϊ 1 
	cout << "18  24 : " << gcdcycle2(18, 24) << endl;
	cout << "24  18 : " << gcdcycle2(24, 18) << endl;
	//�����������ʣ����Լ��Ϊ 1
	cout << "18   5 : " << gcdcycle2(18, 5) << endl;
	cout << " 5  18 : " << gcdcycle2(5, 18) << endl;
	//����һ������Ϊ 0
	cout << "18   0 : " << gcdcycle2(18, 0) << endl;	 
	cout << " 0  18 : " << gcdcycle2(0, 18) << endl;
	//����һ������Ϊ����
	cout << "-18  24 : " << gcdcycle2(-18, 24) << endl;	 
	cout << "24  -18 : " << gcdcycle2(24, -18) << endl;

	return 0;
}

