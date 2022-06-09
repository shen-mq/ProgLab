#include <iostream>
using namespace std;

int main()
{
    char sa[20] = "0123456789012345678", sb[20] = "";
    scanf("%s", sa);
    // sync.clear();
    scanf("%s", sb);

    cout << sa << endl;
    cout << sb << endl;

    for (int i = 0; i < 20; i++)
    {
        cout << sa[i] << '\n';
    }

    return 0;
}
