/*********************************************************************
    ������: ex 3-5
    ��Ȩ:
    ����: 2021212577 ����ǫ
    ����: 2022-03-09 15:57
    ˵��:
*********************************************************************/
#include <iostream>
#include <iomanip>
#include <limits.h>
using namespace std;

int main() {
	cout << "int ���͵���Сֵ�����ֵ��\t" << INT_MIN << '\t' << INT_MAX << endl;
	cout << "��1��1��������õ��Ĵ�������\t" << INT_MIN - 1 << '\t' << INT_MAX + 1 << endl;
	cout << "ת����˫���ȱ����������\t" << setprecision(12) << INT_MIN - 1. << '\t' << INT_MAX + 1. << endl;

	return 0;
}

