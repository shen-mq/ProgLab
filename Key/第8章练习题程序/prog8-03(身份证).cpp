/*********************************************************************
����������ʾ���֤�Ľṹ��
��Ȩ�����GPL��ȨЭ�飬������ʹ�úʹ����������ϴ����շ��������Ŀ⣩
���ߣ�anbangli@foxmail.com
���ڣ�2019-07-24
˵����
8-3.�����ʾ���֤���������֤�š��������Ա𡢳��������պ�סַ����Ϣ��
�Ľṹ�壨ȡ��IDcard���������弸�����������֤���бȽϵĺ�����
��1�����֤���Ƿ���ȣ�����ȡ��cmpNum)����2�������Ƿ���ȣ�cmpName����
��3�������������Ƿ����(cmpBirth)��(4�����֤������Ϣ�Ƿ���ȣ�cmpID����
����Ӧ��ʹ�ýṹ�����������ʹ�ýṹ��ָ�������
���дһ����������������Щ������
*********************************************************************/

#include <iostream>
#include <cstring>
using namespace std;

typedef struct IDcard {
	char num[19];	//���֤���Ϊ18λ��ֻ�����ַ�����洢��
	char name[20];
	char sex;
	int year, month, day;
	char address[100];
} IDcard;

//���֤��Ϣ�Ƚ϶࣬ʹ�ýṹ��ָ�����Ϊ�� 

int cmpNum(IDcard *a, IDcard *b) {
	int i, len = 18;
	for (int i = 0; i < len; i++)	//���ַ��Ƚ�
		if (a->num[i] != b->num[i])	//ֻҪ��һ���ַ�����ȼ����жϲ����
			return false;
	return true;	//�����ַ������
}

int cmpName(IDcard *a, IDcard *b) {
	//��������ַ������Ȳ���ȣ�����ȡ�
	if (strlen(a->name) != strlen(b->name))
		return false;
	else {	//���������ȣ������ַ��Ƚ�
		for (int i = 0; i < strlen(a->name); i++)
			if (a->name[i] != b->name[i])
				return false;
	}
	return true;	//������ȣ�����ÿ���ַ������
}

int cmpSex(IDcard *a, IDcard *b) {	//�Ƚ��Ա�(��ĿδҪ�����б�д��
	return (a->sex == b->sex);
}

int cmpBirth(IDcard *a, IDcard *b) {
	return (a->year == a->year && a->month == b->month && a->day == b->day);
}

int cmpAddress(IDcard *a, IDcard *b) { //�Ƚ��Ա�(��ĿδҪ�����б�д��
	//�����ַ�ַ������Ȳ���ȣ�����ȡ�
	if (strlen(a->address) != strlen(b->address))
		return false;
	else {	//���������ȣ������ַ��Ƚ�
		for (int i = 0; i < strlen(a->address); i++)
			if (a->address[i] != b->address[i])
				return false;
	}
	return true;	//������ȣ�����ÿ���ַ������
}

int cmpID(IDcard *a, IDcard *b) {
	return (cmpNum(a, b) && cmpName(a, b) && cmpSex(a, b)
	        && cmpBirth(a, b) && cmpAddress);
}

void printID(IDcard *a) {
	cout << "��ţ�" << a->num << endl;
	cout << "������" << a->name << "\t"
		 << "�Ա�" << (a->sex == 'M' ? "��" : "Ů") << endl;
	cout << "�������ڣ�" << a->year << " �� " << a->month << " �� " 
		 << a->day << " �� " << endl;
	cout << "��ַ��" << a->address << endl;
}

int main() {
	//��ʾ�����ݽ��в���
	IDcard id1 = {"430224198905120057", "����", 'M', 1989, 5, 12,
	              "����ʡ�人�к�ɽ�����·152��"
	             };
	IDcard id2 = {"432522200110030269", "����", 'F', 2001,10, 3,
	              "����ʡ��ɳ�г�ɳ��������ɼľ����·9��"
	             };//�� id1 ��ͬ
	IDcard id3 = {"430224198905120057", "����", 'M', 1989, 5, 12,
	              "����ʡ�人�к�ɽ�����·152��"
	             }; //�� id1 ��ͬ

	cout << "\nid1 ��Ϣ��\n";
	printID(&id1);

	cout << "\nid2 ��Ϣ��\n";
	printID(&id2);

	cout << "\nid3 ��Ϣ��\n";
	printID(&id3);

	cout << "\n���֤�Ƚ�\n";
	cout << "id1 �� id2 �Ƚϣ���š��������������ڡ��������֤����\n"
	     << cmpNum(&id1, &id2) << "\t" << cmpName(&id1, &id2) << "\t"
	     << cmpBirth(&id1, &id2) << "\t" << cmpID(&id1, &id2) << endl;

	cout << "id1 �� id3 �Ƚϣ�\n"
	     << cmpNum(&id1, &id3) << "\t" << cmpName(&id1, &id3) << "\t"
	     << cmpBirth(&id1, &id3) << "\t" << cmpID(&id1, &id3) << endl;

	return 0;
}


