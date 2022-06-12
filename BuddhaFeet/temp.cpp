#include <iostream>
using namespace std;

int main()
{

	string str2 = "Hello, World!";
	cout << str2[1] << endl; // OK
	// cout << *(str2) << endl; //Fail

	char str1[] = "Hello, World!";
	cout << str1[1] << endl; // OK
	cout << *(str1) << endl; // OK

	return 0;
}
