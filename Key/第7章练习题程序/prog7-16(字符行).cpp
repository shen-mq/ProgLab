/*********************************************************************
���������ַ�ָ������
��Ȩ�����GPL��ȨЭ�飬������ʹ�úʹ����������ϴ����շ��������Ŀ⣩
���ߣ�anbangli@foxmail.com
���ڣ�2019-08-09
˵����
7-16.׼��һ��ֻ��Ӣ���ַ��Ĵ��ı��ļ������а�������100�����Ȳ�����80��
�ַ����С�дһ�����������ж�ȡ�ļ����ݣ��������������α��浽��̬����
�Ĵ洢���У�����һ���ַ�ָ����������ָ����Щ�洢�顣��ȡ���֮����
������г��Ȳ�����40���ַ����У�������������С�������Ҳ��������ά�ַ�
������
*********************************************************************/
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main () {
	ifstream infile;	//���������ļ�������δ�󶨵��ı��ļ���
	int ch, i, j, num;

	//�û�Ӧ�����ȱ༭���ı��ļ�������������˳���ͬһ�ļ����¡�
	char fname[] = "prog7-16.txt";
	infile.open(fname);	//�������ļ������ļ�����֮�󶨡�
	if (!infile) {	//����ļ������ڣ��������ļ����ᴴ��ʧ��
		//cout << "��������ļ��������ڡ������ȱ༭�������ļ���" << endl;
		//exit(1);	//�������������ϵͳ���� 1 ����ʾ������������

		//������Ϊ�˷������ѧϰ������ļ������ڣ����Զ������ļ����Թ�������ȡ��
		ofstream outfile(fname);	//��������ļ������󶨵��ļ�
		//������ļ������ʾ������
		outfile << "One Small Step, One Giant Leap\n"
		        "On July 16, 1969, \n "
		        "astronauts Neil Armstrong, Buzz Aldrin and Michael Collins \n"
		        "lifted off from Launch Pad 39A \n"
		        "at NASA's Kennedy Space Center in Florida \n"
		        "on a journey to the Moon and into history.\n"
		        "Four days later, while Collins orbited the Moon in the command module, \n"
		        "Armstrong and Aldrin landed Apollo 11's lunar module, Eagle, \n"
		        "on the Moon's Sea of Tranquility, \n"
		        "becoming the first humans to set foot on the lunar surface.";
		outfile.close();	//�ر�����ļ���
		cout << "�Ѵ��������ļ� " << fname << " ����ȡ��" << endl;
		infile.open(fname);	//�ٴζ��������ļ��������Ӧ�ÿ϶��ɹ�
	}
	//����ļ��������ɹ��������ִ�С�

	cout << "��1����һ���ַ�ָ�����飬���ַ��б�����ͨ����̬����Ĵ洢����\n";
	char *ps[100] = {NULL};	//����100���ַ�ָ�룬��ȫ����ʼ��Ϊ NULL��
	char str[80];	//��ʱ�Ե��ַ�����
	i = j = num = 0;
	while (i < 100) {	//��ദ�� 100 �У��ڲ����� EOF ʱʹ�� break ����ѭ����
		ch = infile.get();
		//putchar(ch);	//debug
		if (ch != '\n' && ch != EOF && j < 80)	//ͬһ��
			str[j++] = ch;
		else {	//��β���ļ�ĩβ
			str[j] = '\0';	//�ַ���ĩβ��ӿ��ַ�
			ps[i] =  new char[j + 1]; 	//!!! ��̬��������ڴ�
			strcpy(ps[i], str);
			//cout << ps[i] << endl; 	//!!! ע����� ps[i] ��д��
			i++;
			j = 0;
		}
		if (ch == EOF)
			break;
	}
	infile.close();

	num = i;
	cout << "��������" << num << endl;
	cout << "�ַ��������� 40 ���У�\n";
	for (i = 0; i < num; i++) {
		if (strlen(ps[i]) <= 40)
			cout << ps[i] << endl;
	}
	cout << "�����У�\n";
	for (i = 0; i < num; i++) {
		if (strlen(ps[i]) > 40)
			cout << ps[i] << endl;
	}

	for (i = 0; i < num; i++)
		delete []ps[i];	//!!!�ͷŶ�̬������ڴ�

	cout << "\n��2������ά�ַ����鱣���ַ���\n";
	char line[100][80];	//��Ŀ����˵�����ļ������� 100 �У�ÿ�еĳ��Ȳ����� 80 ���ַ�
	i = 0, j = 0, num = 0;
	infile.open(fname);	//���ļ�
	while (i < 100) {	//��ദ�� 100 �У��ڲ����� EOF ʱʹ�� break ����ѭ����
		ch = infile.get();
		//putchar(ch);	//debug
		if (ch != '\n' && ch != EOF && j < 80)	//ͬһ��
			line[i][j++] = ch;
		else {	//��β�� EOF
			line[i][j] = '\0';	//�ַ���ĩβ��ӿ��ַ�
			i++;
			j = 0;
		}
		if (ch == EOF)
			break;
	}
	infile.close();	//��ȡ��ϣ��ر��ļ�

	num = i;	//������
	cout << "��������" << num << endl;
	cout << "�ַ��������� 40 ���У�\n";
	for (i = 0; i < num; i++) {
		if (strlen(line[i]) <= 40)
			cout << line[i] << endl;
	}
	cout << "�����У�\n";
	for (i = 0; i < num; i++) {
		if (strlen(line[i]) > 40)
			cout << line[i] << endl;
	}

	return 0;
}
