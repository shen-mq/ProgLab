/*********************************************************************
    程序名:ex 8-4
    版权:
    作者: 2021212577 沈鸣谦
    日期: 2022-06-08 16:06
    说明:
*********************************************************************/
#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

typedef struct Atom {
	double m, x, y, z;
} Atom;

int main() {
	const int MAXLEN = 80;
	char line[MAXLEN];
	int n = 0;

	char fname[] = "2b4z-mxyz.txt";
	ifstream infile;
	infile.open(fname);
	if (!infile) {
		cout << "打开文件错误" << fname << endl;
		exit(1);
	}
	cout << "读取数据文件：" << fname << endl;
	infile.getline(line, MAXLEN); //读入文件首行注释（因为首行不用）
	while (infile.getline(line, MAXLEN)) {
		if (strlen(line) != 0) {
			n++;
		}
	}
	infile.close();
	cout << "原子总数：" << n << endl;

	infile.open(fname);
	infile.getline(line, MAXLEN);
	Atom *atm = new Atom[n];
	//Atom atm[n];
	Atom cent = {0, 0, 0, 0};
	for (int i = 0; i < n; i++) {
		infile >> atm[i].m >> atm[i].x >> atm[i].y >> atm[i].z;
		cout << i << ": " << atm[i].m << "  " << atm[i].x << "  " << atm[i].y << "  " << atm[i].z << endl;
	}
	infile.close();

	for (int i = 0; i < n; i++) {
		cent.m += atm[i].m;
		cent.x += atm[i].x * atm[i].x;
		cent.y += atm[i].y * atm[i].y;
		cent.z += atm[i].z * atm[i].z;
	}
	cent.x /= cent.m;
	cent.y /= cent.m;
	cent.z /= cent.m;

	cout << "质心坐标：(" << cent.x << ", " << cent.y << ", " << cent.z << ")" << endl;
	delete []atm;

	return 0;
}

