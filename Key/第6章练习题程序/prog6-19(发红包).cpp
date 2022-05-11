/*********************************************************************
��������ƴ��������������������Ϊ 0
��Ȩ�����GPL��ȨЭ�飬������ʹ�úʹ����������ϴ����շ��������Ŀ⣩
���ߣ�anbangli@foxmail.com
���ڣ�2019-07-24
˵����6-19.����6-18��ƴ�������������������������һ�������� allocate
�����л�Ӧ�ý��ж�������Ա������Ľ��Ϊ0ֵ��������һ�ַ�������̽��
������⣨����ԣ����� 0.1 Ԫ�� 10 �ˣ�ÿ�˶��ܵõ� 0.01 Ԫ����

����˵���������������������6-18�е����ݣ��� allocata ������ĩβд��
������������� 0 ֵ���ĳ���Ƭ�ξ��Ǳ�������Ĺ��ܡ�
*********************************************************************/
#include <iostream>
#include <cstdlib>        //ʹ���������������Ŀ��ļ�
#include <ctime>        //ʹ�� time() ��������Ŀ��ļ�
using namespace std;

int setpara(int &t, int &n, int MAX); //���ú���ܽ��t������ n��<=MAX��
int allocate(int t, int n, int money[]);//�ܽ��t���䵽��Ϊn������money��
void printout(int t, int n, int money[]);//���money�����еĺ�����

int main() {
    const int MAX = 100;    //�������
    int t, n, money[MAX];

    cout << "== ƴ��������� ==" << endl;
    if (!setpara(t, n, MAX)) {    //���ò�������ʧ�����˳�
        cout << "��������ʧ�ܣ����������" ;
        exit(1);
    }

    allocate (t, n, money);    //���������
    printout (t, n, money);    //��ӡ���
    return 0;
}

int setpara(int &t, int &n, int MAX){ //���ú���ܽ��t������ n��<=MAX��
    double total; //����ܽ�Ԫ��
    int errs = 0, ERRNUM = 3;
    do {
        cout << "���������ܽ��(Ԫ)��";
        cin >> total;
        cout << "��������������" ;
        cin >> n;
        if (n > MAX) {
            cout << "���������������� "<< MAX << endl;
            errs++;
        }

        t = total * 100;    //���ҵ�λ��Ԫת��Ϊ��
        if (t < n) { //�������ܽ�����С������
            cout << "���󣺺���ܽ�����С�����������������롣" << endl;
            errs++;
        }
    } while ((n > MAX || t < n) && errs <= ERRNUM);
    return (errs <= ERRNUM ? 1 : 0);
}

int allocate(int t, int n, int money[]){//�ܽ��t���䵽��Ϊn������money��
    int i, total = 0;
    int min = 0.5 * t / n, max = 1.5 * t / n;

    srand(time(0));
    for (i = 0; i < n; i++) {    //���� n �������
        money[i] = rand() % (max - min +1) + min;
        total += money[i];
    }

    //�Ժ�������й�һ����
    //Ϊ�˷�ֹ��ֵ��ֻ��ǰn-1�����й�һ�������һ���Լ�����ֵ
    int sum = 0;
    for (i = 0; i < n-1; i++) {    //ǰ n-1 �����й�һ��
        money[i] = double(money[i]) / total * t;
        sum += money[i];
    }
    money[n-1] = t - sum;

    //����������� 0 ֵ
	//���ԣ�ÿ�ҵ�һ�� 0 ֵ������������ҳ����ֵ���� 0 ֵƽ�֡�
    for (i = 0; i < n; i++) {    //���� 0 ֵ������
    	if (money[i] == 0) {	//�ҵ�һ�� 0 ֵ
    		int k = 0;	//�� k ������ֵ���±�
    		for (int j = 0; j < n; j++)	//�ҳ����ֵ
    			if (money[j] > money[k])
    				k = j;
	   		//���߽��Ƶ�ƽ��
			money[i] = money[k] /2;
    		money[k] = money[k] - money[i];
    	}
    }

    return 0;
}

void printout(int t, int n, int money[]){ //���money�����еĺ�����
    for (int i = 0; i < n; i++)
        cout << 0.01 * money[i]  << (i % 5 == 4? '\n':'\t');  //��λΪ"Ԫ"��
}

