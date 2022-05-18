/*********************************************************************
    ������:ex6-20
    ��Ȩ:
    ����: 2021212577 ����ǫ
    ����: 2022-05-18 16:19
    ˵��:
*********************************************************************/
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int setPara(int &t, int &n, int MAX);
int alloMoney(int t, int n, int money[]);
void prtAll(int t, int n, int money[]);

int main() {
	const int MAX = 100;
	int t, n, money[MAX];

	cout << "=== ƴ��������� ===" << endl;
	if (!setPara(t, n, MAX)) {
		cout << "��������ʧ�ܣ����������";
		exit(1);
	}

	alloMoney(t, n, money);
	prtAll (t, n, money);

	return 0;
}

int setPara(int &t, int &n, int MAX) {
	double total;
	int errs = 0, ERRNUM = 3;
	do {
		cout << "���������ܽ�Ԫ����";
		cin >> total;
		cout << "������������";
		cin >> n;
		if (n > MAX) {
			cout << "����������������" << MAX << endl;
			errs++;
		}

		t = total * 100;
		if (t < n) {
			cout << "���󣺺���ܽ�����С�����������������롣" << endl;
			errs++;
		}
	} while ((n > MAX || t < n) && errs <= ERRNUM);
	return (errs <= ERRNUM ? 1 : 0);
}

int alloMoney(int t, int n, int money[]) {
	int i, total = 0;
	int min = .5 * t / n, max = 1.5 * t / n;

	srand(time(0));
	for (i = 0; i < n; i++) {
		money[i] = rand() % (max - min + 1) + min;
		total += money[i];
	}

	//�������һ��
	int sum = 0;
	for (i = 0; i < n - 1; i++) {
		money[i] = double(money[i]) / total * t;
		sum += money[i];
	}
	money[n - 1] = t - sum;

	//TODO: �����Ա���0Ԫ���
	return 0;
}

void prtAll(int t, int n, int money[]) {
	for (int i = 0; i < n; i++) {
		cout << 0.01 * money[i] << (i % 5 == 4 ? '\n' : '\t');
	}
}

