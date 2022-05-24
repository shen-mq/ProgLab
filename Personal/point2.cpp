#include <iostream>
using namespace std;

int main()
{
    int a = 3;
    int *pa = &a;
    void *gp = pa;

    // if (pa == (double *)gp)//直接报错... error: comparison between distinct pointer types 'int*' and 'double*' lacks a cast [-fpermissive]
    if (pa == gp)
        cout << "same" << endl;
    else
        cout << "different" << endl;
}