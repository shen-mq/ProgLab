/*********************************************************************
    ������: prog 2-10 and 2-11
    ��Ȩ:
    ����: 2021212577 ����ǫ
    ����: 2022-03-09 15:57
    ˵��:
*********************************************************************/
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	const double PI = 3.1415927;

	//2-10
	double r1 = 2.50, r2 = 34.2; //��λ cm
	cout << fixed << setprecision(4);//�趨�����ʽ
	cout << "�뾶Ϊ2.50���׵�Բ�����Ϊ��"  << setw(10) << PI *r1 *r1 << " cm^2" << endl;
	cout << "�뾶Ϊ34.2���׵�Բ�����Ϊ��"  << setw(10) << PI *r2 *r2 << " cm^2" << endl;


	//2-11
	cout << "\n\n";
	double r_1 = 1, r_2 = 2, r_3 = 4, r_4 = 8, r_5 = 16;//cm
	cout << setprecision(3);//�趨3λС����fixed��2-10���Ѿ��趨
//	cout.unsetf(ios::adjustfield | ios::basefield | ios::floatfield);
	cout << "Radius\t" << "Volume" << endl;
	cout << r_1 << '\t' << 4. / 3 * PI *r_1 *r_1 *r_1 << endl;
	cout << r_2 << '\t' << 4. / 3 * PI *r_2 *r_2 *r_2 << endl;
	cout << r_3 << '\t' << 4. / 3 * PI *r_3 *r_3 *r_3 << endl;
	cout << r_4 << '\t' << 4. / 3 * PI *r_4 *r_4 *r_4 << endl;
	cout << r_5 << '\t' << 4. / 3 * PI *r_5 *r_5 *r_5 << endl;

	return 0;
}

