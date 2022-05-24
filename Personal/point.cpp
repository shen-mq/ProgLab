#include <iostream>
using namespace std;
int main()
{
    int *pn;
    int n = 13, m = 169;

    pn = &n;
    cout << pn << '\t' << *pn << endl;
    // pn += 0x4;
    pn+=4;
    cout << pn << '\t' << *pn << endl;

    cout << sizeof(pn) << endl;
    return 0;
}
