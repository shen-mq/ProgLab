#include <iostream>
using namespace std;

int *pmax3(int *pa, int *pb, int *pc)
{
    int *p = pa; //定义局部指针变量并赋值为形参 pa所指向的变量地址值
    if (*p < *pb)
        p = pb;
    if (*p < *pc)
        p = pc;
    return p;
}

int main()
{
    int a = 5, b = 10, c = 3;
    //调用 pmax3，返回值赋给局部变量pm
    int *pm = pmax3(&a, &b, &c);
    cout << "Max = " << *pm << endl;
    /*
    指针的好处：没有新建一个变量！节省了内存空间
     */
    return 0;
}