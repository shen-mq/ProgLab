/*********************************************************************
������������ļ��е����ֳ��������һ��
��Ȩ�����GPL��ȨЭ�飬������ʹ�úʹ����������ϴ����շ��������Ŀ⣩
���ߣ�anbangli@foxmail.com
���ڣ�2019-07-24
˵����6-17. ��������6-17�ĳ������ļ�����У��о����ԣ���Ҫ���ļ���
���г��ȶ������� MAXLEN ���ַ�����Ľ��ó���ʹ֮�ܴ���ÿ�����ֳ��Ȳ���
���Ƶ��ļ�������ȷ�����еĳ��ȣ���������ֳ��������һ�У��������
����������������������е�ǰ��һ���֣���
*********************************************************************/
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main () {
    const int MAXLEN = 1024;
    char line[MAXLEN + 1], maxline[MAXLEN + 1];
    int ch, n, max = 0; // ��¼��ǰ�к���еĳ���

    char filename[20] = "GPL.txt";  //�����ַ������Դ洢�ļ���
    //����Ӧ��׼��һ���ϴ���ļ���������һЩ�е����ֳ��Ƚϴ�
	//�����������ҳ���Ʋ�����Ϊ GPL.txt ��http://www.gnu.org/licenses/gpl-3.0.html
	//���ļ�����е��ַ�����Ϊ 937��

    ifstream inFile (filename);	//���������ļ������󶨵��ļ�
    if (!inFile) { //������ļ�ʧ�ܣ��� infile �õ�һ����ֵ����ָ�룩
        cout << "����δ�ҵ������ļ� " << filename << " ��\n";
        cout << "���������ļ�����������ڱ�����ͬһ�ļ����¡�\n\n" ;
        exit(1);    // ���ļ�ʧ�ܣ�����ʾ������Ϣ���˳�����
    }
    cout << "Reading from file: " << filename << endl << endl;
    //while (inFile.getline(line, MAXLEN))
	//getline����������ֻ�ܽ���ָ����󳤶ȵ��ַ������������ô˺��������� get() ������


	int i = 0;	//ÿ�е��ַ���������ŵ��ַ�������ʱ���±�Ϊ i-1
	while ((ch = inFile.get()) != EOF){	//�����ѭ���Ǵ��ļ��ж�ȡ�ַ������� EOF Ϊ������
		i++;
		if (ch != '\n') {	// �� '\n' ��Ϊ���������־
			if (i <= MAXLEN ) 	//�ַ�����С�� MAXLEN ʱ����ŵ� line ����֮��
				line[i - 1] = ch;
		} else {// ������ '\n'��������һ��
			if (i <= MAXLEN)	//����ĩβ��ӿ��ַ�
				line[i] = '\0';
			else
				line[MAXLEN] = '\0';
		    if (i > max) {	//��¼����С�ע�⣬�˴��� i �����ŵ�ǰ�е����ֳ��ȡ�
            	strcpy(maxline, line);	//�� line ����¼���ַ�����ŵ� maxline
            	max = i - 1;	//�����ַ�����Ϊ i - 1����ŵ� max
            	//cout << line << endl << max << endl << endl;	//debug
        	}
			i = 0; //׼����ȡ�µ�һ��
    	}
	}
    inFile.close(); //�ر��ļ�

    cout << "Longest line: \n" << maxline << endl;
    cout << "\nLength: " << max << endl;

    return 0;
}


