/*********************************************************************
�����������ȷֱ�Ϊ1 ~ 20�ĵ��ʵĳ���Ƶ��
��Ȩ�����GPL��ȨЭ�飬������ʹ�úʹ����������ϴ����շ��������Ŀ⣩
���ߣ�anbangli@foxmail.com
���ڣ�2019-07-24
˵����6-21.д�������Ӣ�Ĵ��ı��ļ�����ͳ�����г��ȷֱ�Ϊ1 ~ 20�ĵ���
�������ĵ��ʶ������ܣ��ĳ��ִ������跨��ӡ��������ֱ��ͼ���������
��ʾ���ֳ��ȵĵ������ļ��еĳ���Ƶ�ʡ�

����˵�����ο����� 6-16���ҳ��ļ�����Ĵʡ�ʵ�ֶ�ȡ���ʣ��ο���ϰ��
6-18ʵ�ֶԲ�ͬ���ȵĵ��ʷֱ������
������Դ�����У����� !!! ע�͵�����ǹؼ���䡣����һЩ�������û��ɾ����
*********************************************************************/
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;

void DrawVertical(int len, int a[]);	//����ԭ����������������ֱ��ͼ

int main () {

	//��һ������ 20 ��Ԫ�ص�����ֱ�洢����Ϊ 1 ~ 20 �ĵ��ʵĳ��ִ���
	int cs[20] = {0};  //��0��Ԫ�س�ʼ��Ϊ0������Ԫ���Զ���ʼ��Ϊ0

	char filename[20] = "GPL.txt";  //�����ַ������Դ洢�ļ���
	//����Ӧ��׼��һ���ϴ���ļ���������һЩ�е����ֳ��Ƚϴ�
	//�����������ҳ���Ʋ�����Ϊ GPL.txt ��http://www.gnu.org/licenses/gpl-3.0.html
	ifstream infile(filename);  //�����ļ����������������ļ�
	if (infile)
		cout << "Reading from file: " << filename << endl;
	else {
		cout << "ERROR: can't open input file " << filename << endl;
		exit(1);
	}

	const int MAXLEN = 256;//����Ӣ�ĵ�����󳤶�Ϊ 256)
	char word[MAXLEN], maxword[MAXLEN];	//��ǰ����ĵ��ʣ���ĵ��ʣ�
	int len, maxlen = 0;	//��ǰ���ʳ��ȣ���󵥴ʳ���

	//�˴�ѡȡ����4-18���ж�ȡ���ʵĵ�����д�������в�����Ҫ��״̬ת����
	int ch = ' ', counter = 0;
	while (ch != EOF) {
		while ((ch = infile.get()) != EOF && !isalnum(ch))
			//���ļ��ж�ȡ�ַ�����ch�Ƿָ��ַ�ʱ�ظ���ȡ
			;    //��ѭ����
		if (ch == EOF) break;
		++counter;	//���ʼ���

		//����ѭ������ʱ�Ѷ���һ���ǿո��ַ�
		len = 1;	//���ʳ���
		word[len - 1] = ch;
		while ((ch = infile.get()) != EOF && isalnum(ch)) {
			//���ļ��ж�ȡ�ַ����� ch ����ĸ�������ַ��ظ���ȡ
			//��ԭ�еĿ�ѭ�����дΪ�Ե��ʳ��ȼ���
			len++;
			word[len-1] = ch;
		}
		//����һ�����ʣ������Ӧ�Ĵ���
		word[len] = '\0';	//�ַ�����ĩβ��ӿ��ַ�
		if (len <= 20) 	//!!! ��ͬ���ȵĵ��ʼ���
			cs[len - 1] ++; 	//!!!

	}
	infile.close(); //�ر��ļ�

	for (int i = 1; i <= 20; ++i)	//!!!
		cout << "words with length of " << i << ": " << cs[i-1] << endl;

	DrawVertical(20, cs);	//!!!��������ֱ��ͼ

	return 0;
}

void DrawVertical(int len, int a[]) {
	cout << "\n��ͬ���ȵĵ��ʳ���Ƶ�������ͼ��yֵ������ƣ�\n";

	//���������Ԫ���е����ֵ����Сֵ
	int amax = a[0], amin = a[0];	//�������ڼ�¼���ֵ����Сֵ�ı�������ʼ��Ϊ a[0]
	for (int i = 0; i < len; i++) {
		amax = (a[i] > amax ? a[i] : amax);
		amin = (a[i] < amin ? a[i] : amin);
	}
	//cout << "amin = " << amin << ", amax =" << amax << endl;

	//���ɣ��ַ�������ֻ�����л��ƣ��൱���Ǵ�����ͼ�ε��Ϸ����·����ƣ�
	//�����ڳ������Ƕ� y �Ӵ�С�ػ��ƣ���ÿ�� y ֵ�����һ���ĸ���Ӧ�� x ֵ��֮��Ӧ��
	int maxheight = 18;	//�ַ��ն˴���ͨ����25��80�У�����ȡһ�����ʵ����������
	for (int iy = maxheight; iy >= 0; iy--) {	//��ͼ iy ֵ�Ӵ�С�ر仯
		cout << setw(6) << setprecision (2) << amin + (amax - amin) * iy / maxheight << "|";
		for (int jx = 0; jx < len; jx++) {	//��������и�Ԫ�ص�ֵ�Ƿ����ͼ iy ֵ��Ӧ
			//��ÿ��ֵӳ�䵽 [0, maxheight]������ iy ��Ƚ�
			if ((int)(1.0 * a[jx]/(amax - amin) * maxheight) >= iy)//����״ͼ���˴�дΪ >=
				cout << "��";	//������ε�ȫ���ַ�
			else
				cout << "  ";	//��������ո�
		}
		cout << endl;
	}
	cout << "      + 1 2 3 4 5 6 7 8 91011121314151617181920";//������
	return;
}
