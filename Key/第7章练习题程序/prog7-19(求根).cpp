/*********************************************************************
����������ֵ������������ַ���ţ�ٵ�����
��Ȩ�����GPL��ȨЭ�飬������ʹ�úʹ����������ϴ����շ��������Ŀ⣩
���ߣ�anbangli@foxmail.com
���ڣ�2019-08-09
˵����
7-19. ���õĶ���ѧ��������ֵ����������ж��ַ���ţ�ٵ����������ַ������
��ʼ������ҽط����ƣ�Ҳ�Ǵ����˵㺯��ֵ��ŵ�һ�����俪ʼ��ÿ���������
�е㣬���е㺯��ֵ�ķ��ž���ȡ��߰����仹���ұ߰�������Ϊ���̵����䡣
�����ظ����������ֱ���õ�����Ľ��������ţ�ٵ������󷽳� f(x) = 0�ĸ�
�ĵ�����ʽ�ǣ�...... ������ f'(x) �� f(x) �ĵ�������ĳ����ʼֵ x ������
����ʹ�����湫ʽ����������̸��Ľ���ֵ��д���ֱ��ö��ַ���ţ�ٵ�������
��ѧ��������ĺ�����ʹ�ú���ָ��������������������һЩ���̣�����ʽ����
�������Խ�����ķ��̣���ĳ�㸽����ĳ�Ե�֮��ĸ������п��ܣ��뿼�췽��
�����ѭ�������Ĺ�ϵ�������Ҫͳ�Ƴ���ѭ��ִ�еĴ�������

�����������1�����ս̲������и������ҽط������м��޸ļ���д�����ַ���
��2��ţ�ٵ�������Ҫ���ڷ��̱����䵼�������������Ҫ����ָ������ָ�룬
��ֻ��Ҫһ����ʼ�㡣���ս̲ĵ�4���н����ĵ�������д�˺�����
��3�����ڴ��������ѧ��������Ҫдһ����Ӧ�ĺ�������ʹ��ţ�ٵ�����ʱ��Ҫ
���䵼��дһ����Ӧ�ĺ�����
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
	return ((x-5.0)*x+16.0)*x-80.0;
}

double f3 (double x) {	//
	return x * x * x - 7.7 * x * x + 19.2 * x -15.3;
}

double f3d(double x) {	//f3 �ĵ���
	return 3 * x * x - 15.4 * x + 19.2;
}

double cross(double (*pf)(double), double x1, double x2) {
	double y1 = pf(x1), y2 = pf(x2);
	return (x1 * y2 - x2 * y1) / (y2 - y1);
}

double chordroot(double (*pf)(double), double x1, double x2) {
//�ҽط����
	double x, y, y1 = pf(x1);
	do {
		x = cross(pf, x1, x2);
		y = pf(x);
		if (y * y1 > 0.0) {
			y1 = y;
			x1 = x;
		} else
			x2 = x;
	} while (y >= 1E-6 || y <= -1E-6);

	return x;
}


double binaryroot(double (*pf)(double), double x1, double x2) {//���ַ����
	int iterate = 0;	//��������
	cout << "���ַ����\n" ;
	cout << "����\t" << "x1\t\t" << "x2\t\t" << "y1\t\t" << "y2\n";

	double x, y, y1, y2;
	if (pf(x1) * pf(x2) > 0)
		cout << "�������˵�ĺ���ֵͬ�ţ������޷����\n";
	do	{
		x = (x1 + x2) / 2;	//�����е�
		y = pf(x);
		y1 = pf(x1);
		y2 = pf(x2);
		if(y1 * y > 0) //y1 �� y ͬ��
			x1 = x;
		else if( y2 * y > 0)
			x2 = x;
		cout << fixed << ++iterate << "\t"
			<< x1 << "\t" << x2 << "\t" << y1 << "\t" << y2 << endl;
	} while (!(fabs(y1) <= 1E-6 || fabs(y2) <= 1E-6));//ֱ������һ�����ֵ�㹻С

	return (fabs(y1) < fabs(y2) ? x1 : x2);	//���غ���ֵ����ֵ��С���Ǹ� x ֵ
}

double newtonroot(double (*pf)(double), double (*pfd)(double), double x1) {//ţ�ٵ��������
	int iterate = 0;	//��������
	cout << "ţ�ٵ��������\n" ;
	cout << "����\t" << "x\t\t" << "y\n";

	double x2;
	while( fabs(pf(x1)) >0.000001) {
		x2 = x1 - pf(x1) / pfd(x1);
		x1 = x2;
		cout << ++iterate << "\t" << x2 << "\t" << pf(x2) << "\n";
	}
	return x2;
}


int main() {
	cout << "��ֵ���\n";
	double x;
//	x = chordroot(f1, 1.26, 7.03);
//	cout <<"A root of equation f1 is: "<< x <<endl;
//
//	x = chordroot(f2, 1.26, 7.03);
//	cout <<"A root of equation f2 is: "<< x <<endl;
//
//	x = chordroot(sin, 0.4, 4.5);
//	cout <<"A root of equation sin is: "<< x <<endl;
//
//	x = chordroot(cos, 0.4, 4.5);
//	cout<<"A root of equation cos is: "<< x <<endl;

	x = binaryroot(f3, 1, 2);
	cout<<"A root of equation f3 by binaryroot is: " << x << "\n\n";

	x = newtonroot(f3, f3d, 1);
	cout<<"A root of equation f3 by newtonroot is: "<< x << "\n\n";

	return 0;
}

