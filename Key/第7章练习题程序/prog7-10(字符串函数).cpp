/*********************************************************************
������: �ַ�����غ���
��Ȩ�����GPL��ȨЭ�飬������ʹ�úʹ����������ϴ����շ��������Ŀ⣩
���ߣ�anbangli@foxmail.com
����: 2021-06-03 08:46
˵��:
7-10. ��ϰʹ�ñ�׼���е��ַ�����غ�������1���ѱ����в���ʹ���Աຯ�� stringlen ��
stringcopy �Ĵ���Ƭ�κϲ�д��һ�������У����ѵ����������Աຯ������䶼��Ϊ���ñ�
׼�⺯�� strlen �� strcpy����2���Ѳ��Ա�׼�⺯�� strchr �� strstr �Ĵ���Ƭ��Ҳ��
������������У���3�����б�дһЩ��䣬��ϰʹ�� strcat �� strcmp��
*********************************************************************/

#include <iostream>
using namespace std;

int main() {
//��1���ѱ����в���ʹ���Աຯ�� stringlen �� stringcopy �Ĵ���Ƭ�κϲ�д��һ�������У�
//���ѵ����������Աຯ������䶼��Ϊ���ñ�׼�⺯�� strlen �� strcpy��
    cout << strlen("Hello, world!") << endl;  //�Գ����ַ�����Ϊ����
    char line[] = "Hello, my friends!" ;  //�����ַ����鲢��ʼ��Ϊ�ַ���
    cout << strlen(line) << endl;  //�Դ洢���ַ������ַ�������Ϊ����

    const int NUM = 100;
    char str[NUM] = "", dest[NUM] = "";  //�����ַ����鲢��ʼ��Ϊ�մ�
    strcpy(str, "Welcome to China!");  //�ѳ����ַ������Ƶ��ַ�����src
    cout << "str: " << str << endl;
    strcpy(dest, str);  //���ַ�����str�и����ַ������ַ�����dest
    cout << "dest: " << dest << endl;

//��2���Ѳ��Ա�׼�⺯�� strchr �� strstr �Ĵ���Ƭ��Ҳ�ϲ�����������У�
    char *pch = str;  //�����ַ�ָ�벢��ʼ��Ϊָ���ַ���ͷ��
    cout << "pch: " << pch << endl;  //��ӡ��������ַ���
    cout << strlen(pch) << endl; //���ַ�ָ��Ϊ���������������ַ���������
    pch = str + 11;   //�ַ�ָ��ָ���ַ������в���Ԫ��
    cout << "pch: " << pch << endl;  //��ӡ������ַ���
    cout << "pch: " << str + 11 << endl;  //ֱ�������ַ������д��
    cout << strlen(pch) << endl; //���ַ�ָ��Ϊ�������������ַ���������
    cout << strlen(str + 11) << endl; //ֱ������ָ�������д��
    strcpy(dest, pch);  //���ַ�ָ��Ϊ�������������ַ���������
    cout << "dest: " << dest << endl << endl;

    strcpy(str, "Almost#all#programmers#love#programming");
    cout << "str: " << str << endl;
    char ch = '#';
    pch = strchr(str, ch);  //�����״γ����ַ�ch��λ��
    if (pch != NULL) {
        cout << "pch: " << pch << endl;
        cout << ch << " �״γ���λ��: " << pch - str << endl;
    } else
        cout << ch << " δ������ " << str << endl;
    //������һ��ѭ��ͳ���ַ����� # ���ֵĴ��������䶼�޸�Ϊ' '
    pch = str;  //pch ָ��strͷ��
    int cnt = 0;
    while (pch != NULL && *pch != '\0') { //ע�������������Ĵ����ܵߵ�
        if (pch = strchr(pch, ch)) {  //���Ҳ��ѷ���ֵ�����߼�ֵʹ��
            cout << "pch: " << pch << endl;
            cnt++;  //���ִ�����1
            *pch = ' ';
            pch++;  //�ַ�ָ�����1λ
        }
    }
    cout << ch << " �ַ������ִ���: " << cnt << endl;
    cout << "�޸ĺ���ַ�����" << str << endl << endl;

    char ss[] = "program";  //�����ַ����鲢��ʼ��Ϊ�ַ���
    if (pch = strstr(str, ss)) {  //����ַ���ss�Ƿ������str��
        cout << "pch: " << pch << endl;
        cout << ss << " �״γ���λ��: " << pch - str << endl;
    } else
        cout << ss << " δ������ " << str << endl;

    const char *ps = "program";  //���峣���ַ�ָ�룬��ʼ��ָ��һ���ַ�������
    if (pch = strstr(str, ps)) {  //����ַ���ps�Ƿ������str��
        cout << "pch: " << pch << endl;
        cout << ps << " �״γ���λ��: " << pch - str << endl;
    } else
        cout << ps << " δ������ " << str << endl;

//��3�����б�дһЩ��䣬��ϰʹ�� strcat �� strcmp��
    strcat(str, ". At least it is true for me.");
    cout << str << endl;

    cout << "compare read and real: " << strcmp("read", "real") << endl;
    cout << "compare really and real: " << strcmp("really", "real") << endl;


    return 0;
}
