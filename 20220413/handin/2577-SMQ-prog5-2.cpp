/*********************************************************************
    ������: prog5-2 ��ӡ���ľ���
    ��Ȩ:
    ����: 2021212577 ����ǫ
    ����: 2022-04-13 16:12
    ˵��:
*********************************************************************/
#include <iostream>
using namespace std;

void prtRect(char ch, int m, int n) {
	if (m > 0) {
		for (int i = 1; i <= n; i++) {
			cout << ch;
		}
		cout << endl;
	}
	for (int i = 1; i <= m - 2; i++) {
		if (n > 0)
			cout << ch;
		for (int j = 1; j <= n - 2; j++) {
			cout << " ";
		}
		if (n > 1)
			cout << ch;
		cout << endl;
	}
	if (m > 1)
		for (int i = 1; i <= n; i++) {
			cout << ch;
		}
	// �˴�����ݸ�������������޲��������䲻���ţ�����ʺɽ���������ѳɵ���
	// ������ʦ��ʾ�����룬������̾ȷʵ���������
}

int main() {
	char ch;
	int m, n;
	cout << "Please input ch, m, n: ";
	while (cin >> ch >> m >> n ) {
//		cin >> ch >> m >> n;
		prtRect(ch, m, n);
		cout << endl << "Please input ch, m, n: ";
	}


//	putchar('$');

	return 0;
}

