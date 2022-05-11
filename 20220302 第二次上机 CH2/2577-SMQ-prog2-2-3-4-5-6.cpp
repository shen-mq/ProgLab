/*********************************************************************
    程序名: programs in CH2, 2-2 to 2-6
    版权:
    作者: 2021212577 沈鸣谦
    日期: 2022-03-02 16:27
    说明:
*********************************************************************/
#include <iostream>
using namespace std;

int main() {
	cout << "2-2" << endl;
	cout << 24 * 3 / 5 + 6 << endl;
	cout << 36 + -(5 - 23) / 4 << endl;
	cout << 35 * 12 + 27 / 4 / 7 *  (12 - 4) << endl;

	cout << "2-3" << endl;
	cout << 3 * (2L + 4.5) - 44 << endl;
	cout << 10 / 25 + 10.0 / 25 + 10 / 25. + .1 / 2 << endl;
	cout << 5 / 3 * 4.2 + 'A' + 4.0 / 5 << endl;
	cout << 'A' / 10. + 10 / 'a' << endl;

	cout << "2-4" << endl;
	cout << 2.34 / (1 + 257) << endl;
	cout << 1065. / (24 * 13) << endl;
	cout << 23.582 / (7.96 / 3.67) << endl;
	cout << 1 + 2 / (3 + 4. / 5) << endl;

	cout << "2-5" << endl;
	double rho_iron = 7.86, rho_gold = 19.3; //单位为 g/cm^3
	double d_iron = 10, d_gold = 15; //单位为 cm
	const double PI = 3.1415927;
	double R_iron, R_gold, V_iron, V_gold;

	R_iron = d_iron / 2;
	R_gold = d_gold / 2;
	V_iron = 4. / 3 * PI * R_iron * R_iron * R_iron;
	V_gold = 4. / 3 * PI * R_gold * R_gold * R_gold;

	cout << "直径为10cm的铁球质量为：" << V_iron *rho_iron << " g\n";
	cout << "直径为15cm的金球质量为：" << V_gold *rho_gold << " g\n";

	cout << "2-6" << endl;
	cout << "串联电阻值：" << 10.5 + 15.6 << " Ohm\n";
	cout << "并联电阻值：" << 1 / (1 / 10.5 + 1 / 15.6) << " Ohm\n";


	return 0;
}
