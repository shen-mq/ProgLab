/*********************************************************************
    ������: ex4-16 number-guessing game
    ��Ȩ:
    ����: 2021212577 ����ǫ
    ����: 2022-04-06 16:06
    ˵��:
*********************************************************************/
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
	int max, target, guess, ch;
	const int ERRNUM1 = 3, ERRNUM2 = 10;
	int err1 = 0, err2 = 0;

	cout << "Number-Guessing Game" << endl;
	//�趨���ֵ
	cout << "Choose a range [0, max]. Input max: ";
	while (!(cin >> max) || max <= 0) {
		err1++;
		if (err1 <= ERRNUM1) {
			cin.clear();
			cin.sync();
			cout << "Input again: ";
		} else {
			cout << "Too many input errors! Exit!" << endl;
			exit(1);
		}
	}
	cin.sync();
	cout << "max = " << max << endl;

	srand(time(0));
	do {
		target = rand() % (max + 1);
		cout << endl << "A new random number generated. " << endl;
		err2 = 0;
		while (1) {
			err1 = 0;
			cout << "Your guess: ";
			while (!(cin >> guess) || guess < 0 || guess > max) { //������������
				if (++err1 <= ERRNUM1) {
					cout << "Wrong! Need a number in [0, " << max << "]\n";
					cin.clear();
					cin.sync();
				} else {
					cout << "Too many input errors! Exit!" << endl;
					exit(1);
				}
				cout << "Yout guess: ";
			}
			cin.sync();

			//���۲²���
			if (guess > target) {
				cout << "Too large" << endl;
				err2++;
			} else if (guess < target) {
				cout << "Too small" << endl;
				err2++;
			} else {
				cout << "Congratulations! You win!" << endl << endl;
				break;
			}
			if (err2 > ERRNUM2) {
				cout << "Too many errors. Stop!" << endl;
				break;
			}
		} //����ѭ������
		//�Ƿ������Ϸ��
		cout << "Next game? (y/n): ";
		while ((ch = toupper(cin.get())) != 'Y' && ch != 'N');//cin.get()ֻ�õ�������ĵ�һ���ַ�
		cin.sync();
	} while (ch != 'N');

	cout << "Game over. THX for playing." << endl;

	return 0;
}

