/*********************************************************************
    ������: ex6-3
    ��Ȩ:
    ����: 2021212577 ����ǫ
    ����: 2022-05-11 16:22
    ˵��:
*********************************************************************/
#include <iostream>
using namespace std;

int main() {
	int year = 2020, month = 2, day = 28;
	cout << "Please input 3 integers for YEAR, MONTH and DAY: ";
	cin >> year >> month >> day;

	if (year < 0 || month < 1 || month > 12) {
		cout << "ERROR: The input YEAR or MONTH is wrong" << endl;
		exit(1);
	}
	int mdays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if ( (year % 100 != 0 && year % 4 == 0) || year % 400 == 0 ) {
		mdays[1] = 29;
	}

	if (day > mdays[month - 1]) {
		cout << "ERROR: Thei input DAY is wrong" << endl;
		exit(1);
	}

	int daynum = day;
	for (int i = 0; i < month - 1; i++) {
		daynum += mdays[i];
	}

	cout << year << " �� " << month << " �� " << day << " �� �ǵ���ĵ�" << daynum << " ��. \n";

	return 0;
}

