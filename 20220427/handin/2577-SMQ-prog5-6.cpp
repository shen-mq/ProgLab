/*********************************************************************
    ������: prog 5-6
    ��Ȩ:
    ����: 2021212577 ����ǫ
    ����: 2022-04-27 16:17
    ˵��:
*********************************************************************/
#include <iostream>
#include <cstdlib>
using namespace std;

/////////////////////////////////////////////////
//gcddiv ��������
int gcddiv(int m, int n) {
	return m % n == 0 ? n : gcddiv(n, m % n);
}
/////////////////////////////////////////////////

int gcdminus(int m, int n) {
	if (n > m) {
		int t = m;
		m = n;
		n = t;
	}
//	cout << m << n << endl;
	return m == n ? m : gcdminus(m - n, n);
}

int gcdrecur2(int m, int n) {
	if (m < 0)
		m = -m;
	if (n < 0)
		n = -n;
	return m == n ? m : gcdminus(m, n);//��Ϊû�бȽ�m, n�Ĵ�С, ����óȻ�� gcdminus(m-n, n)
}

int gcdloop2(int m, int n) {
	if (m < 0)
		m = -m;
	if (n < 0)
		n = -n;

	while (m != n) {
		if (n > m) {
			int t = m;
			m = n;
			n = t;
		}
		m = m - n;
	}
	return m;
}

int main() {
	srand(5);
	int m, n;
	for (int i = 1; i <= 200; ++i) {
		m = rand() % (500 + 1 - 200) + 200;
		n = rand() % (500 + 1 - 200) + 200;
		cout << m << '\t' << n << '\t' << gcddiv(m, n) << '\t' << gcdloop2(m, n) << '\t' << gcdrecur2(m, n) << endl;
	}
//	cout << gcdminus(14, 6);

	return 0;
}

