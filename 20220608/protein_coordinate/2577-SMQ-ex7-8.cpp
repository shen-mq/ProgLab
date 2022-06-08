/*********************************************************************
    ������:ex7-8 ver.2
    ��Ȩ:
    ����: 2021212577 ����ǫ
    ����: 2022-06-08 16:06
    ˵��:
*********************************************************************/
#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

int main() {
	const int MAXLEN = 100;
	char line[MAXLEN];
	char *pch = NULL;
	double mass;

	char pdbname[20] = "2b4z.pdb";//pdb�ļ���www.rcsb.org��ȡ
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
	outfile << "mass    x        y        z" << endl;
	cout << "Reading from file: " << pdbname << endl;

	while (infile.getline(line, MAXLEN)) {
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

