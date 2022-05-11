/*********************************************************************
���������� Pai �Ľ���ֵ
��Ȩ�����GPL��ȨЭ�飬������ʹ�úʹ����������ϴ����շ��������Ŀ⣩
���ߣ�anbangli@foxmail.com
���ڣ�2019-07-20
˵����
4-3.��ע�������븡������֪ sigma(1/n^2) = pai^2/6 ��
���øù�ʽ������� �� �Ľ���ֵ�����������ʽ��ǰ����������Ľ���ֵ��
3.14159266 �����С�� 10^5�����������������ݣ�����õ��ĺͣ��������
����� �� �Ľ���ֵ����øú����õ���������10^5 ��Ϊ 10^6��10^7���������顣

����ע�⣬�����в���д�� 1/(n*n)�������ᵼ�����������0��Ҳ����д��
 1.0/(n*n)��������n����ʱ��Ѹ�ٵ��� n*n�������ȷ�ķ�ʽ��д�� 1.0/n/n��)

4-9.�������3�⣨�����еĽ���ֵ���ĳ�������Ӽ�ʱ���ܣ��ֱ������ȡ
���Ϊ10^5��10^6��10^7 ʱ�����ִ��ʱ�䲢�ֹ���¼�������˹��ܽ�����
��С��ִ��ʱ��֮��Ĺ�ϵ��
*********************************************************************/

#include <iostream>
#include <cmath>	//��ѧ����
#include <ctime>	//��ʱ����
#include <cstdlib>
#include <iomanip>	//�����ʽ����
using namespace std;

int main() {
	int n;
	double sum, pai, devition;
	int tm1, tm2;

	for (int de = -5; de >= -7; de--) {	//����������ѭ��
		devition = pow(10, de);	//���
		tm1 = clock();	//��ʱ���
		for(n = 1, sum = 0; fabs(sqrt(6 * sum) - 3.14159265) > devition; n++) {
			sum += 1. / n / n;	// �ؼ���䣡
			// ����д�� sum += 1/n*n;  ��Ϊ 1/n*n ��ֵΪ 0��
			// ����д�� sum += 1/(n*n); ��Ϊ 1/(n*n) ��ֵΪ 0��
			// ����д�� sum += 1.0/(n*n)���� n ����ʱ���������
			pai = sqrt(6 * sum);
			//if (n % 10000 == 0)
			//	cout << "n= " << n << "  pai=" << setprecision(10) << pai << endl;
		}
		tm2 = clock();	//��ʱ������
		cout << "sum= " << sum  << setprecision(10) << "\tpai= " << pai << "\tn= " << n-- ;
		cout << "\ttime cost = " << (tm2-tm1)/CLOCKS_PER_SEC <<  "s\n";
	}
	return 0;
}

//4-8�����ʱ
//
//	pai=0;
//	for(n = 1; fabs(sqrt(6 * pai) - 3.14159265) > 1e-7; n++){
//		pai += 1./n/n;
//	//	printf("n=%d, pi= %f\n", n, sqrt(6*pai));
//	}
//	tm2=clock();
//	printf("pai=%f, pi= %f, n=%d\n", pai, sqrt(6*pai),n);
//	printf("time cost = %f s\n", (tm2-tm1)/CLOCKS_PER_SEC);
//
//	tm1=clock();
//	pai=0;
//	for(n=1; fabs(sqrt(6*pai)-3.14159265)>1e-7; n++){
//		pai += 1./n/n;
//	//	printf("n=%d, pi= %f\n", n, sqrt(6*pai));
//	}
//	tm2=clock();
//	printf("pai=%f, pi= %f, n=%d\n", pai, sqrt(6*pai),n);
//	printf("time cost = %f s\n", (tm2-tm1)/CLOCKS_PER_SEC);
//	return 0;
//}


