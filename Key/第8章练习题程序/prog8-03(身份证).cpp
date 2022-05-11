/*********************************************************************
程序名：表示身份证的结构体
版权：遵从GPL版权协议，可自由使用和传播（请勿上传到收费性网络文库）
作者：anbangli@foxmail.com
日期：2019-07-24
说明：
8-3.定义表示身份证（包含身份证号、姓名、性别、出生年月日和住址等信息）
的结构体（取名IDcard），并定义几个对两个身份证进行比较的函数：
（1）身份证号是否相等（函数取名cmpNum)；（2）姓名是否相等（cmpName），
（3）出生年月日是否相等(cmpBirth)；(4）身份证所有信息是否相等（cmpID）。
考虑应该使用结构体参数，还是使用结构体指针参数。
最后写一个主函数，测试这些函数。
*********************************************************************/

#include <iostream>
#include <cstring>
using namespace std;

typedef struct IDcard {
	char num[19];	//身份证编号为18位，只能用字符数组存储。
	char name[20];
	char sex;
	int year, month, day;
	char address[100];
} IDcard;

//身份证信息比较多，使用结构体指针参数为好 

int cmpNum(IDcard *a, IDcard *b) {
	int i, len = 18;
	for (int i = 0; i < len; i++)	//逐字符比较
		if (a->num[i] != b->num[i])	//只要有一个字符不相等即可判断不相等
			return false;
	return true;	//所有字符都相等
}

int cmpName(IDcard *a, IDcard *b) {
	//如果姓名字符串长度不相等，则不相等。
	if (strlen(a->name) != strlen(b->name))
		return false;
	else {	//如果长度相等，则逐字符比较
		for (int i = 0; i < strlen(a->name); i++)
			if (a->name[i] != b->name[i])
				return false;
	}
	return true;	//长度相等，而且每个字符都相等
}

int cmpSex(IDcard *a, IDcard *b) {	//比较性别(题目未要求，自行编写）
	return (a->sex == b->sex);
}

int cmpBirth(IDcard *a, IDcard *b) {
	return (a->year == a->year && a->month == b->month && a->day == b->day);
}

int cmpAddress(IDcard *a, IDcard *b) { //比较性别(题目未要求，自行编写）
	//如果地址字符串长度不相等，则不相等。
	if (strlen(a->address) != strlen(b->address))
		return false;
	else {	//如果长度相等，则逐字符比较
		for (int i = 0; i < strlen(a->address); i++)
			if (a->address[i] != b->address[i])
				return false;
	}
	return true;	//长度相等，而且每个字符都相等
}

int cmpID(IDcard *a, IDcard *b) {
	return (cmpNum(a, b) && cmpName(a, b) && cmpSex(a, b)
	        && cmpBirth(a, b) && cmpAddress);
}

void printID(IDcard *a) {
	cout << "编号：" << a->num << endl;
	cout << "姓名：" << a->name << "\t"
		 << "性别：" << (a->sex == 'M' ? "男" : "女") << endl;
	cout << "出生日期：" << a->year << " 年 " << a->month << " 月 " 
		 << a->day << " 日 " << endl;
	cout << "地址：" << a->address << endl;
}

int main() {
	//用示例数据进行测试
	IDcard id1 = {"430224198905120057", "张三", 'M', 1989, 5, 12,
	              "湖北省武汉市洪山区珞瑜路152号"
	             };
	IDcard id2 = {"432522200110030269", "李四", 'F', 2001,10, 3,
	              "湖南省长沙市长沙市天心区杉木冲西路9号"
	             };//与 id1 不同
	IDcard id3 = {"430224198905120057", "张三", 'M', 1989, 5, 12,
	              "湖北省武汉市洪山区珞瑜路152号"
	             }; //与 id1 相同

	cout << "\nid1 信息：\n";
	printID(&id1);

	cout << "\nid2 信息：\n";
	printID(&id2);

	cout << "\nid3 信息：\n";
	printID(&id3);

	cout << "\n身份证比较\n";
	cout << "id1 与 id2 比较（编号、姓名、出生日期、整个身份证）：\n"
	     << cmpNum(&id1, &id2) << "\t" << cmpName(&id1, &id2) << "\t"
	     << cmpBirth(&id1, &id2) << "\t" << cmpID(&id1, &id2) << endl;

	cout << "id1 与 id3 比较：\n"
	     << cmpNum(&id1, &id3) << "\t" << cmpName(&id1, &id3) << "\t"
	     << cmpBirth(&id1, &id3) << "\t" << cmpID(&id1, &id3) << endl;

	return 0;
}


