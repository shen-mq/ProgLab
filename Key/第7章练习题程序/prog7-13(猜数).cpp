/*********************************************************************
���������µ���
��Ȩ�����GPL��ȨЭ�飬������ʹ�úʹ����������ϴ����շ��������Ŀ⣩
���ߣ�anbangli@foxmail.com
���ڣ�2019-08-09
˵����
7-13.��*���޸ĵ����µĲ�������ͨ�������в���Ϊ���ṩ���ķ�Χ��

��𣺶�ԭ�г���ֻ��Ҫ���޸�������伴�ɣ�1��main ��������Ҫ��Ӧ�Ĳ�����
2��������Χ���ֵ max ������ getrange �����ṩ�����Ǹ��������в��� argv[1] �ṩ��
**********************************************************************/
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int next();
int getrange();
int getnumber(int limit);

//int main() {
int main(int argc, char *argv[]) {	//!!!����������Ҫ������
//Ҫ���Դ˺�����Ч��������Ҫ�Ѵ˳�����б��������ɿ�ִ���ļ���Ȼ���������д�����
//�ֹ�����ÿ�ִ���ļ����ļ���������������
//��ע������������ɵĿ�ִ���ļ��������д������ţ����磺prog7-09(����).exe����
//�������п����޷�ʶ����ļ����������Ҫ�ڸ��ļ����������Ӣ��˫���š�����д�ɣ�
//   "prog7-09(����).exe"  20

    int max, unknown, guess;

    cout << "== Number-Guessing Game ==" << endl;
    if (argc == 1) { //!!!δ������ִ�У�argc Ϊ 1��argv[0] Ϊ������������ʹ��ԭ�еĺ���
    	cout << "��ǰ��δ������ִ�У���ʹ��ԭ�еĺ������趨������Χ\n";
    	if ((max = getrange()) < 0) return 1;//����������Χ�����������̫�����˳�
    } else	//!!!������ִ�У��������в����ṩ������Χ
		max = atoi(argv[1]);	//!!!������Χ���ֵ max ���������в��� argv[1] �ṩ
    	//���� atoi ����Դ��Ӣ�ġ�ascii to integer��)�ǰ��ַ���ת�����������ĺ�����
    cout << "range max = " << max << endl;

    srand(time(0));
    do {
        unknown = rand() % (max + 1);
        cout << "\nA new random number generated. \n";
        while (1) {
            if ((guess = getnumber(max)) < 0) {    //�´����̫�����˳�
                cout << "Too many errors. Stop!";
                return 2;
            }
            if (guess > unknown) cout <<"Too big!\n";
            else if (guess < unknown) cout <<"Too small!\n";
            else {
                cout << "Congratulation! You win!\n";
                break;
            }
        }
    } while (next());

    cout<< "Game over.\nThanks for playing!\n";
    return 0;
}

const int ERRORNUM = 5;

int getrange() {
    int i, m;
    for (i = 0; i < ERRORNUM; ++i) {
        cout << "Choose a range [0, max]. Input max: ";
        if ( !(cin >> m) || m < 2 || m > RAND_MAX) {
            cout << "Wrong number. Need a number in 2~" << RAND_MAX << endl;
            cin.clear(); //���������
            cin.sync();  //��ջ�����
            cout << "Input again: ";
        } else
            return m;
    }
    return -1;
}

int getnumber(int m) {
    int i, n;
    for (i = 0; i < ERRORNUM; ++i) {
        cout << "Your guess: ";
        if (!(cin >> n) || n < 0 || n > m) {
            cout<< "Wrong number. Need a number in 0~ " << m << ".\n";
            cin.clear();
            cin.sync();
        } else
            return n;
    }
    return -1;
}

int next() {
    int ch;
    cout << "Next game? (y/n): ";
    while ((ch = toupper(cin.get())) != 'Y' && ch != 'N')
        ;    //��ѭ����
    cin.clear();
    cin.sync();
    return (ch == 'Y' ? 1 : 0);
}
