/*********************************************************************
    程序名:ex7-8
    版权:
    作者: 2021212577 沈鸣谦
    日期: 2022-06-01 15:52
    说明:
*********************************************************************/
#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

int main() {
	const int MAXLEN = 80;
	char line[MAXLEN + 1];
	char *pch = NULL;
	double mass;

	char pdbname[20] = "2b4z.pdb";//pdb文件从www.rcsb.org获取
	ifstream infile (pdbname);
	if (!infile) {
		cout << "ERROR: data file " << pdbname << " not found." << endl;
		exit(1);
	}

	char mxyzname[20] = "";
	strcpy(mxyzname, pdbname);
	pch = strstr(mxyzname, ".pdb");
	mxyzname[pch - mxyzname] = '\0';
	strcat(mxyzname, "-mxyz.txt");
	ofstream outfile(mxyzname);
	if (!outfile) {
		cout << "Fail to open the file: " << mxyzname << endl;
		infile.close();
		exit(1);
	}
	outfile << "mass		x		y		z" << endl;

	cout << "Reading from file: " << pdbname << endl;


//	infile.getline(line, MAXLEN);
//	cout << line << endl;
//	cout << line << endl;
//	infile.getline(line, MAXLEN);
//	cout << line << endl;

	size_t read;
	while ((read = infile.getline(line, MAXLEN)) != 0) {//while循环无法进入
//		cout << "in while" << endl;
		if (strstr(line, "ATOM  ") != line) {
			continue;
		}
		if (line[77] == 'C' && line[78] == ' ') {
			mass = 12.0;
		} else if (line[77] == 'N') {
			mass = 14.0;
		} else if (line[77] == 'O') {
			mass = 16.0;
		} else
			continue;
		pch = &line[30];
		line[54] = '\0';
		cout << mass << "  " << pch << endl;
		outfile << mass << "  " << pch << endl;
	}
	cout << "mxyz data saved in file: " << mxyzname << endl;

	infile.close();
	outfile.close();

	return 0;
}

