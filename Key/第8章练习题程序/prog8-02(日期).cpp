/*********************************************************************
程序名：表示日期的结构体
版权：遵从GPL版权协议，可自由使用和传播（请勿上传到收费性网络文库）
作者：anbangli@foxmail.com
日期：2019-07-24
说明：
8-2.定义一个表示公历日期（包含年月日）的结构体类型（取名tDate)，然后利用
该结构体类型定义如下函数：
（1）由这种类型计算给定的某个日期是该年的第几天的函数。
函数原型设为 int DayNum(tDate date)。
（提示：需要注意闰年问题，请把前文的isleapyear函数复制到本程序中）
（2）比较两个日期的大小的函数。
函数原型设为 int DateCompare(tDate date1, tDate date2)，date1 早于 date2 
则返回值为 -1，两者相等返回 0，date1 迟于 date2 则返回 1。
（3）计算两个日期的天数差的函数。
函数原型设为 int DateDiff(tDate date1, tDate date2)，date1 早于 date2 则返回
值为负值，两者相等返回 0，date1 迟于 date2 则返回正值。
*（4）定义以一个日期和一个天数为参数的函数，它能算出某日期若干天之后的
日期。函数原型设为 tDate AfterDate(tDate date, int after)。
*（5）定义计算某日期之前若干天的日期的函数。
函数原型设为 tDate BeforeDate(tDate date, int after)。
用这些函数计算：你自己已经生活了多少天，离你的下一个生日还有多少天，等等。
*********************************************************************/

#include <iostream>
#include <cmath>
using namespace std;

typedef struct tDate {
	int year, month, day;
} tDate;

int isleapyear(int year) {	//给定的年份是否闰年 
    return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}	

int DayNum(tDate date) {	//计算给定的某个日期是该年的第几天
	int num = date.day; 	//初始化为本月的天数
	int mdays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};//各月天数
	for (int i = 0; i < date.month-1; ++i)	//前几个月的日子累加起来
		num += mdays[i];

	//考虑闰年，在 2 月之后的月份都可能要加 1 天
	if (isleapyear(date.year) && date.month > 2)
		num += 1;
	return num;
}

int DateCompare(tDate date1, tDate date2) {	//比较两个日期的前后或相等关系 
	if (date1.year < date2.year)
		return -1;
	else if (date1.year == date2.year) {	//同一年则按天数比较 
		if (DayNum(date1) < DayNum(date2))
			return -1;
		else if (DayNum(date1) == DayNum(date2))
			return 0;
		else
			return 1;
	} else if (date1.year > date2.year)
		return 1;
}

int  DaysDiff(tDate date1, tDate date2) {//计算两个日期相差的天数
	if (DateCompare(date1, date2) == 0)	//日期相同，相差天数为 0 
		return 0;
	
	int sign = 1;	//相差日期的正负号。先假设 date1 迟于 date2，sign 为正 
	if (DateCompare(date1, date2) == -1) { //date1 早于 date2，则互换 
		tDate tmp = date1;
		date1 = date2;
		date2 = tmp;
		sign = -1;
	}
	
	int diff = 0;
	// 下面是在 date1 迟于 date2 的情况下进行计算 
	if (date1.year == date2.year) 
		diff = DayNum(date1) - DayNum(date2);
	else {	//年份不同。date1.year > date2.year
		//date2 当年剩下的天数 
		diff = (isleapyear(date2.year) ? 366 : 365) - DayNum(date2);
		//加上两个年份之间的各年的天数 
		for (int year = date2.year + 1; year <= date1.year - 1; year++)
			diff += (isleapyear(year) ? 366 : 365);
		//加上 date1 当年的天数 
		diff += DayNum(date1);
	}
	return sign * diff;
}

tDate AfterDate(tDate date, int days) {

}

tDate BeforeDate(tDate date, int days) {

}

int main() {
	
	//用示例数据进行测试 
//	tDate date1 = {2020, 3, 1};
//	tDate date2 = {2022, 10, 7};
//	
//	cout << "date1 是当年的第几天：" << DayNum(date1) << endl;
//	cout << "date2 是当年的第几天：" << DayNum(date2) << endl;
//	cout << "date1 与 date2 相差的天数：" << DaysDiff(date1, date2) << endl;
//	cout << "date2 与 date1 相差的天数：" << DaysDiff(date2, date1) << endl << endl;

	tDate birthday, today, nextbirthday;
	cout << "请输入你的生日（年 月 日）：";
	cin >> birthday.year >> birthday.month >> birthday.day;
	cout << "请输入今天的日期（年 月 日）：";
	cin >> today.year >> today.month >> today.day;
	cout << "你已生活的天数：" << DaysDiff(today, birthday) << endl;
	
	//根据上面的信息构造下一个生日的信息 
	nextbirthday = birthday;
	nextbirthday.year = today.year;
	if (DateCompare(nextbirthday, today) > 0)
		cout << "你今年还没有过生日。\n";
	else if (DateCompare(nextbirthday, today) == 0)		
		cout << "今天你的生日！\n";
	else { //当年生日已经过去 
		cout << "今年生日已过。下一个生日是在明年。\n";
		nextbirthday.year++;
	}
	cout << "距离下一个生日还有天数：" << DaysDiff(nextbirthday, today) << endl;	 

	return 0;
}


