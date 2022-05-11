/*********************************************************************
����������ʾ���ڵĽṹ��
��Ȩ�����GPL��ȨЭ�飬������ʹ�úʹ����������ϴ����շ��������Ŀ⣩
���ߣ�anbangli@foxmail.com
���ڣ�2019-07-24
˵����
8-2.����һ����ʾ�������ڣ����������գ��Ľṹ�����ͣ�ȡ��tDate)��Ȼ������
�ýṹ�����Ͷ������º�����
��1�����������ͼ��������ĳ�������Ǹ���ĵڼ���ĺ�����
����ԭ����Ϊ int DayNum(tDate date)��
����ʾ����Ҫע���������⣬���ǰ�ĵ�isleapyear�������Ƶ��������У�
��2���Ƚ��������ڵĴ�С�ĺ�����
����ԭ����Ϊ int DateCompare(tDate date1, tDate date2)��date1 ���� date2 
�򷵻�ֵΪ -1��������ȷ��� 0��date1 ���� date2 �򷵻� 1��
��3�������������ڵ�������ĺ�����
����ԭ����Ϊ int DateDiff(tDate date1, tDate date2)��date1 ���� date2 �򷵻�
ֵΪ��ֵ��������ȷ��� 0��date1 ���� date2 �򷵻���ֵ��
*��4��������һ�����ں�һ������Ϊ�����ĺ������������ĳ����������֮���
���ڡ�����ԭ����Ϊ tDate AfterDate(tDate date, int after)��
*��5���������ĳ����֮ǰ����������ڵĺ�����
����ԭ����Ϊ tDate BeforeDate(tDate date, int after)��
����Щ�������㣺���Լ��Ѿ������˶����죬�������һ�����ջ��ж����죬�ȵȡ�
*********************************************************************/

#include <iostream>
#include <cmath>
using namespace std;

typedef struct tDate {
	int year, month, day;
} tDate;

int isleapyear(int year) {	//����������Ƿ����� 
    return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}	

int DayNum(tDate date) {	//���������ĳ�������Ǹ���ĵڼ���
	int num = date.day; 	//��ʼ��Ϊ���µ�����
	int mdays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};//��������
	for (int i = 0; i < date.month-1; ++i)	//ǰ�����µ������ۼ�����
		num += mdays[i];

	//�������꣬�� 2 ��֮����·ݶ�����Ҫ�� 1 ��
	if (isleapyear(date.year) && date.month > 2)
		num += 1;
	return num;
}

int DateCompare(tDate date1, tDate date2) {	//�Ƚ��������ڵ�ǰ�����ȹ�ϵ 
	if (date1.year < date2.year)
		return -1;
	else if (date1.year == date2.year) {	//ͬһ���������Ƚ� 
		if (DayNum(date1) < DayNum(date2))
			return -1;
		else if (DayNum(date1) == DayNum(date2))
			return 0;
		else
			return 1;
	} else if (date1.year > date2.year)
		return 1;
}

int  DaysDiff(tDate date1, tDate date2) {//��������������������
	if (DateCompare(date1, date2) == 0)	//������ͬ���������Ϊ 0 
		return 0;
	
	int sign = 1;	//������ڵ������š��ȼ��� date1 ���� date2��sign Ϊ�� 
	if (DateCompare(date1, date2) == -1) { //date1 ���� date2���򻥻� 
		tDate tmp = date1;
		date1 = date2;
		date2 = tmp;
		sign = -1;
	}
	
	int diff = 0;
	// �������� date1 ���� date2 ������½��м��� 
	if (date1.year == date2.year) 
		diff = DayNum(date1) - DayNum(date2);
	else {	//��ݲ�ͬ��date1.year > date2.year
		//date2 ����ʣ�µ����� 
		diff = (isleapyear(date2.year) ? 366 : 365) - DayNum(date2);
		//�����������֮��ĸ�������� 
		for (int year = date2.year + 1; year <= date1.year - 1; year++)
			diff += (isleapyear(year) ? 366 : 365);
		//���� date1 ��������� 
		diff += DayNum(date1);
	}
	return sign * diff;
}

tDate AfterDate(tDate date, int days) {

}

tDate BeforeDate(tDate date, int days) {

}

int main() {
	
	//��ʾ�����ݽ��в��� 
//	tDate date1 = {2020, 3, 1};
//	tDate date2 = {2022, 10, 7};
//	
//	cout << "date1 �ǵ���ĵڼ��죺" << DayNum(date1) << endl;
//	cout << "date2 �ǵ���ĵڼ��죺" << DayNum(date2) << endl;
//	cout << "date1 �� date2 ����������" << DaysDiff(date1, date2) << endl;
//	cout << "date2 �� date1 ����������" << DaysDiff(date2, date1) << endl << endl;

	tDate birthday, today, nextbirthday;
	cout << "������������գ��� �� �գ���";
	cin >> birthday.year >> birthday.month >> birthday.day;
	cout << "�������������ڣ��� �� �գ���";
	cin >> today.year >> today.month >> today.day;
	cout << "���������������" << DaysDiff(today, birthday) << endl;
	
	//�����������Ϣ������һ�����յ���Ϣ 
	nextbirthday = birthday;
	nextbirthday.year = today.year;
	if (DateCompare(nextbirthday, today) > 0)
		cout << "����껹û�й����ա�\n";
	else if (DateCompare(nextbirthday, today) == 0)		
		cout << "����������գ�\n";
	else { //���������Ѿ���ȥ 
		cout << "���������ѹ�����һ�������������ꡣ\n";
		nextbirthday.year++;
	}
	cout << "������һ�����ջ���������" << DaysDiff(nextbirthday, today) << endl;	 

	return 0;
}


