/*********************************************************************
    ������:prog6-2
    ��Ȩ:
    ����: 2021212577 ����ǫ
    ����: 2022-05-11 16:22
    ˵��:
*********************************************************************/
#include <iostream>
using namespace std;

int main() {
	int ch, cnt[26] = {0};

	cout << "Input some chars (<C-z> to end): ";
	while ((ch = toupper(getchar())) != EOF) {
//		if (isupper(ch)) {
//			ch = ch - 'A' + 'a';
//		}
//		cout << ch << endl;
		if (isalpha(ch)) {

			cnt[ch - 'A']++;
		}
	}
	for (int i = 'A'; i < 'A' + 26; i++) {
		cout << "Number of " << (char)i << " : " << cnt[i - 'A'] << endl;
	}

	return 0;
}

