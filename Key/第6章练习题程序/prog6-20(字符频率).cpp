/*********************************************************************
������������Ӣ���ַ��ĳ���Ƶ��
��Ȩ�����GPL��ȨЭ�飬������ʹ�úʹ����������ϴ����շ��������Ŀ⣩
���ߣ�anbangli@foxmail.com
���ڣ�2019-07-24
˵����6-20.д�������Ӣ�Ĵ��ı��ļ���ͳ�Ƹ���Ӣ���ַ��������ִ�Сд��
���ֵĴ���������ӡ��������ֱ��ͼ���������ʾ�����ַ����ļ��г��ֵ�Ƶ�ʡ�

����˵����ǰ�沿�־�����ϰ�� 6-4�����沿���Ǵ�ӡֱ��ͼ
����������6-09(����ʽ)��
*********************************************************************/
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;


void DrawHorizon(int len, int a[]);	//����ԭ�����������ƺ���ֱ��ͼ
void DrawVertical(int len, int a[]);	//����ԭ����������������ֱ��ͼ

int main () {
	int ch, i;
	//��һ������ 26 ��Ԫ�ص�����ֱ�洢�����ַ��ĳ��ִ���
	int cs[26] = {0};  //��0��Ԫ�س�ʼ��Ϊ0������Ԫ���Զ���ʼ��Ϊ0

	char fname[100] = "prog6-20.txt";	//mytext.txt
	//�û�Ӧ�����ȱ༭һ�����ı��ļ�������������˳���ͬһ�ļ����¡�
	ifstream infile(fname);	//!!���������ļ���
	if (!infile) {	//����ļ������ڣ��������ļ����ᴴ��ʧ��
		//cout << "��������ļ��������ڡ������ȱ༭�������ļ���" << endl;
		//exit(1);	//�������������ϵͳ���� 1 ����ʾ������������

		//������Ϊ�˷������ѧϰ������ļ������ڣ����Զ������ļ����Թ�������ȡ��
		ofstream outfile(fname);	//��������ļ������󶨵��ļ�
		//������ļ������ʾ������
		outfile << "One Small Step, One Giant Leap\n"
		        "On July 16, 1969, astronauts Neil Armstrong, Buzz Aldrin "
		        "and Michael Collins lifted off from Launch Pad 39A at NASA's "
		        "Kennedy Space Center in Florida on a journey to the Moon and "
		        "into history. Four days later, while Collins orbited the Moon "
		        "in the command module, Armstrong and Aldrin landed Apollo 11's "
		        "lunar module, Eagle, on the Moon's Sea of Tranquility, becoming "
		        "the first humans to set foot on the lunar surface.\n";
		outfile.close();	//�ر�����ļ���
		cout << "�Ѵ��������ļ�����ȡ��" << endl;
		infile.open(fname);	//�������ļ������½����ļ������Ӧ�ÿ϶��ɹ�
	}
	//����ļ��������ɹ��������ִ�С�

	while ((ch = infile.get()) != EOF) {	//!!�������ļ����ж�ȡ�ַ�
		putchar(ch);		//�������Ļ�Թ��鿴
		if (isalpha(ch))   	//!!�ж���Ӣ���ַ�
			cs[tolower(ch) - 'a']++;  //!!�ַ�ת��ΪСд����Ӧ�ļ�������1
	}

	for (i = 0; i < 26; ++i)
		cout << "Number of " << (char)(i + 'a') << ": " << cs[i] << endl;

	DrawHorizon(26, cs);	//���ƺ���ֱ��ͼ
	DrawVertical(26, cs);	//��������ֱ��ͼ
	return 0;
}

void DrawHorizon(int len, int a[]) {
	cout << "\n�ַ�����Ƶ�������ͼ��yֵ������ƣ�\n";
	//���������Ԫ���е����ֵ����Сֵ
	int amax = a[0], amin = a[0];	//�������ڼ�¼���ֵ����Сֵ�ı�������ʼ��Ϊ a[0]
	for (int i = 0; i < len; i++) {
		amax = (a[i] > amax ? a[i] : amax);
		amin = (a[i] < amin ? a[i] : amin);
	}
	//cout << "amin = " << amin << ", amax =" << amax << endl;

	int maxlen = 60;	//�ַ��ն˴���ͨ����25��80�У�ȡһ�����ʵ����������
	int ix, jy, leny;
	for (ix = 0; ix < len; ix++) {
		cout << " " << char('a' + ix) << "|";
		leny = (int)(1.0 * a[ix] / (amax - amin) * maxlen);
		for (jy = 0; jy < leny; jy++)
			putchar('#');//���һϵ�пո�
		cout << "#\n";	//����Ǻźͻس�
	}
	cout << setw(3) << amin << "-"
	     << setw(maxlen) << setfill('-') << amax << setfill(' ') << endl; //������
}

void DrawVertical(int len, int a[]) {
	cout << "\n�ַ�����Ƶ�������ͼ��yֵ������ƣ�\n";

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
			if ((int)(1.0 * a[jx] / (amax - amin) * maxheight) >= iy) //����״ͼ���˴�дΪ >=
				cout << "��";	//������ε�ȫ���ַ�
			else
				cout << "  ";	//��������ո�
		}
		cout << endl;
	}
	cout << "      +a b c d e f g h i j k l m n o p q r s t u v w x y z";//������
	return;
}
