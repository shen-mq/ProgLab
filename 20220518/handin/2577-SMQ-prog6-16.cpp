/*********************************************************************
    ??????:prog6-16 squeeze
    ???:
    ????: 2021212577 ?????
    ????: 2022-05-18 16:19
    ???:
*********************************************************************/
#include <iostream>
#include <cstring>
using namespace std;

void squeeze(char s1[], const char s2[]) {
	int len = strlen(s1);
	int flag[len] = {0};

	for (int i = 0; s2[i]; i++) {
		for (int j = 0; s1[j]; j++) {
			if (s2[i] == s1[j]) {
				flag[j] = 1;
			}
		}
	}

	char tmp[len] = "";//????????????????????????????????????????? tmp ????????????¦Ë????? '\0' ????
	for (int i = 0, j = 0; s1[i]; i++) {
		if (!flag[i]) {
			tmp[j] = s1[i];
			j++;
		}
	}
	strcpy(s1, tmp);
}

int main() {
	char s1[] = "hello, world! ", s2[] = "lo";

	cout << "delete \"" << s2 << "\" from:  " << s1 << endl;

//	cout << s1 <<  endl;
	squeeze(s1, s2);
	cout << s1 << endl;

	return 0;
}
