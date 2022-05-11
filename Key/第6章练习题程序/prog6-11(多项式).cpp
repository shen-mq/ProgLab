/*********************************************************************
������������ʽ��ֵ���ͼ
��Ȩ�����GPL��ȨЭ�飬������ʹ�úʹ����������ϴ����շ��������Ŀ⣩
���ߣ�anbangli@foxmail.com
���ڣ�2019-07-22
˵����6-11.��1�����ա���6-6����ʵ��һ�����������ʾ�Ķ���ʽ��ֵ�ĺ�����
����ԭ����Ϊdouble polynomial(int n, double po[], double x)��
��2��д���������ֱ����һ��double�����е����ֵ����Сֵ������ԭ�ͷֱ�Ϊ��
double arraymax(int n, double a[])��double arraymin(int n, double a[]);
��3�����ú��� polynomial �������ʽ�� [-5, 5] �����ڼ��Ϊ 0.2 ��һϵ��
����51�������ֵ������������У�Ȼ�����ú��� arraymax �� arraymin ���
���е����ֵ����Сֵ��
*��4������һ���д���������е�ֵ���й�񻯣�ת���� [0, 1] ���䣩��Ȼ��
�跨���Ǻ�����Ļ�ϴ�ӡ��ʾ��������ʽ��[-5, 5]�����ڵĽ���ͼ�Ρ�
*********************************************************************/
#include <iostream>
#include <iomanip>
using namespace std;

double polynomial(int n, double po[], double x) {
//�������ܣ�����������Ϊ n �Ķ���ʽ���Ա���Ϊ x ʱ��ֵ��
//����ʽ�ĸ���ϵ�����δ�������� po �С�
	int k;
	double sum;
	for (sum = 0.0, k = n - 1; k >= 0; --k)
		sum = sum * x + po[k];
	//cout << "Polynomial value: " << sum << endl;
	return sum;
}

double arraymax(int n, double a[]) {  //��һ��double�����е����ֵ
	double amax = a[0];	//�������ڼ�¼���ֵ�ı�������ʼ��Ϊ a[0]
	for (int i = 0; i < n; i++)
		if (a[i] > amax)
			amax = a[i];
	return amax;
}

double arraymin(int n, double a[]){	//��һ��double�����е���Сֵ
	double amin = a[0];
	for (int i = 0; i < n; i++)
		if (a[i] < amin)
			amin = a[i];
	return amin;
}

int main() {
	//ʾ������ʽ��40 - 10 * x - 1.2 * x^2 + 0.5 * x^3
	double po[] = {40, -10, -1.2, 0.5}; //�������鲢��ʼ��
	int len = sizeof(po)/sizeof(po[0]);
	int i, j;

	double dmin = -5, dmax = 5;	//x������ [-5, 5]
	const int num = 51;	//ȡ����
	double d = (dmax - dmin) / (num - 1);	//x ��ȡ����
	double x[num], y[num];	// x �� y ��һϵ��ֵ

	cout << "x \ty\n";	//��Ļ���ʱ�ı�����
	for (i = 0; i < num; i++) {
		x[i] = dmin + d * i;
		y[i] = polynomial(len, po, x[i]);
		cout  << setprecision(5) << x[i] << "\t" << y[i] << endl;
	}

	double ymax = arraymax(num, y);
	double ymin = arraymin(num, y);
	cout << "ymin = " << ymin << "\tymax = " << ymax << endl;

	//�� y �����е�ֵ���й�񻯣�ת�������� [0, 1] ��
	for (i = 0; i < num; i++) {
		y[i] = y[i] / (ymax - ymin);
		//cout << fixed << x[i] << "\t" << y[i] << endl;
	}

	cout << "\n�����ͼ��y ֵ������ƣ����ֵ��Ϊ maxlen��\n";
	int maxlen = 60;	//�ַ��ն˴���ͨ����25��80�У�ȡһ�����ʵ����������
	for (i = 0; i < num; i++) {
		cout << setw(8) << fixed << setprecision(2)  << x[i] << "|";
		for (j = 0; j < y[i] * maxlen-1; j++)
			putchar(' ');//���һϵ�пո�
		cout << "*\n";	//����Ǻźͻس�
	}
	cout << setw(8) << ymin << "-"
		<< setw(maxlen) << setfill('-')<< ymax << setfill(' ') << endl;//������

	cout << "\n�����ͼ��yֵ������ƣ�\n";
	//���ɣ��ַ�������ֻ�����л��ƣ��൱���Ǵ�����ͼ�ε��Ϸ����·����ƣ�
	//�����ڳ������Ƕ� y �Ӵ�С�ػ��ƣ���ÿ�� y ֵ�����һ���ĸ���Ӧ�� x ֵ��֮��Ӧ��
	maxlen = 20;	//�ַ��ն˴���ͨ����25��80�У�ȡһ�����ʵ����������
	for (int iy = maxlen; iy >= 0; iy--) {	//��ͼ y ֵ�Ӵ�С�ر仯
		cout << setw(8) << setprecision (2) << ymin + (ymax - ymin)*iy << "|";
		for (int jx = 0; jx < num; jx++) {	//������ x ֵ�Ķ���ʽֵ�Ƿ����ͼyֵ��Ӧ
			if ((int)(y[jx] * maxlen) != iy)
				putchar(' ');	//����ո�
			else
				putchar('*');	//����Ǻ�
		}
		cout << endl;
	}
	cout << setw(8) << dmin << "-"
		<< setw(num) << setfill('-')<< dmax << setfill(' ') << endl;//������
	return 0;
}
