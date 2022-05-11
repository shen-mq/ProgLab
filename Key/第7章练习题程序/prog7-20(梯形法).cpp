/*********************************************************************
�����������η����㶨����
��Ȩ�����GPL��ȨЭ�飬������ʹ�úʹ����������ϴ����շ��������Ŀ⣩
���ߣ�anbangli@foxmail.com
���ڣ�2019-08-09
˵����
7-20.Ϊ�˼��������׼ȷ�Ķ����֣��������δ�����μ��㶨���ֽ���ֵ����˼����
�����ɸ����ε����֮�ͣ���Щ���εĳ��̱߸��ɺ���ֵ����������Щ�������ϽǺ�
���Ͻ��ڱ��������ϡ���������Щ���ε����֮�;�Լ���ڶ����ֵĽ���ֵ��
���ú���ָ�빦�ܣ�д���������η�����ֵ���ֵĺ�����

�������������̲��ϵ���ֵ�����ֺ�����ֻҪ�����еľ��μ��㹫ʽ�޸�Ϊ����
���㹫ʽ���ɡ�
**********************************************************************/
#include <iostream>
#include <cmath>
using namespace std;

//�����ṩ������ʾ�������ɹ����ԡ�f1 �� f2 ���Խ̲����ģ�f3 ���Ա��⡣
//���߿�����������վ���ٻ�������ͼ���˽⺯�����ʣ�http://www.fooplot.com
double f1 (double x) {
	return x * sin(x) - 2 * x * x + 2 * x;
}

double f2 (double x) {
	return ((x - 5.0) * x + 16.0) * x - 80.0;
}

double f3 (double x) {	//
	return x * x * x - 7.7 * x * x + 19.2 * x -15.3;
}

double numInt2(double (*pf)(double), double a, double b) {	//���η�����
    long i, divn = 10;

    double step, dif, res, result = (pf(b) + pf(a)) * (b - a) / 2;
    for (dif = 1.0; dif > 1E-6 || dif < -1E-6; divn *= 2) {
        res = result;
        step = (b - a) / divn;
        for (result = 0.0, i = 0; i < divn; ++i)
        //    result += pf(a + i * step) * step;	//���λ���
            result += (pf(a + i * step) + pf(a + i * step + step)) * step / 2;	//!!!���λ���
        dif = result - res;
    }
    return res;
}

int main() {

	cout << "Function f1 integrated in [0, 1.5]: " << numInt2(f1, 0, 1.5) << endl;

	cout << "Function f2 integrated in [2, 8]: " << numInt2(f2, 2, 8) << endl;
    return 0;
}

