/*********************************************************************
����������ȡ�ı��ļ������ַ�������ͳ��
��Ȩ�����GPL��ȨЭ�飬������ʹ�úʹ����������ϴ����շ��������Ŀ⣩
���ߣ�anbangli@foxmail.com
���ڣ�2019-07-21
˵����
4-13.����׼��һ�����ݽ϶��Ӣ�Ĵ��ı��ļ������磬��һ��Ӣ����ҳ�ϸ���
�������֣�ճ�������±��У�Ȼ�󱣴�Ϊ��mytext.txt��)��д�����ȡ���ļ�
�е�ȫ���ַ����ֱ�ͳ�����е�Ӣ���ַ��������ַ��������źͷָ������ո�
�Ʊ���ͻس������ĸ�������ͳ�ƽ�������ʾ����Ļ�ϣ���ͬʱ������浽
���ı��ļ���output.txt����
���������ս̲��϶�ȡ���ı��ļ���ʾ�����򣬲�ʹ���ַ����ຯ����
*********************************************************************/
#include <iostream>
#include <sstream>	//�ַ�����
#include <fstream>	//�ļ���
using namespace std;

int main () {

    //�û�Ӧ�����ȱ༭���ı��ļ� mytext.txt ������������˳���ͬһ�ļ����¡�
    ifstream infile("mytext.txt");	//!!���������ļ���
    if (!infile) {	//����ļ������ڣ��������ļ����ᴴ��ʧ��
        //cout << "��������ļ��������ڡ������ȱ༭�������ļ���" << endl;
        //exit(1);	//�������������ϵͳ���� 1 ����ʾ������������

        //������Ϊ�˷������ѧϰ������ļ������ڣ����Զ������ļ����Թ�������ȡ��
        ofstream outfile("mytext.txt");	//��������ļ������󶨵��ļ�
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
        ifstream infile("mytext.txt");	//�ٴζ��������ļ��������Ӧ�ÿ϶��ɹ�
    }
    //����ļ��������ɹ��������ִ�С�

    ofstream outfile("output.txt");
    if (!outfile) {
        cout << "��������ļ� output.txt ʧ�ܣ���������˳���";
        exit(1);
    }

    cout << "���ļ���ȡ�ַ�����Ӣ���ַ��������ַ��������źͷָ����������\n";
    int ch, alphas = 0, digits = 0, puncts = 0, spaces = 0;
    while ((ch = infile.get()) != EOF) {
        if (isalpha(ch))
            ++alphas;	//Ӣ���ַ�
        if (isdigit(ch))
            ++digits;	//�����ַ�
        if (ispunct(ch))
            ++puncts;	//������
        if (isspace(ch))
            ++spaces;	//�ָ��ַ�(�ո��Ʊ���ͻس�����
    }
    cout << "Ӣ���ַ�����: " << alphas << endl;
    cout << "�����ַ�����: " << digits << endl;
    cout << "�����Ÿ���: " << puncts << endl;
    cout << "�� �� ������: " << spaces << endl;

    outfile << "Ӣ���ַ�����: " << alphas << endl;
    outfile << "�����ַ�����: " << digits << endl;
    outfile << "�����Ÿ���: " << puncts << endl;
    outfile << "�� �� ������: " << spaces << endl;

    infile.close();
    outfile.close();
    return 0;

}

