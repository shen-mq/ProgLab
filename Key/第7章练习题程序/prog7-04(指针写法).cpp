/*********************************************************************
程序名：把数组写法改写为指针写法
版权：遵从GPL版权协议，可自由使用和传播（请勿上传到收费性网络文库）
作者：anbangli@foxmail.com
日期：2019-07-24
说明：
7-4. 把上一章中用数组方式定义的函数【例6-9】（数组元素排序）和【例6-14】
（字符串复制）改写为用指针运算的方式定义。
*********************************************************************/
#include <iostream>
using namespace std;

//【例6-9】数组元素排序
void insertsort(int n, int a[]) { //对整型数组按照递增序直接插入排序
    int i, j;
    int t;

    for (i = 1; i < n; ++i ) {
        for (t = a[i], j = i - 1; j >= 0 && t < a[j]; --j)
            a[j + 1] = a[j];  //大元素依次后移
        if (j != i - 1)
            a[j + 1] = t;
    }
}

void insertsort_ptr(int n, int *a) { //指针写法，把参数 a[] 改为 *a
    int i, j;
    int t;
    //以下循环中所有数组写法都改为指针写法
    for (i = 1; i < n; ++i ) {
        for (t = *(a + i), j = i - 1; j >= 0 && t < * (a + j); --j)
            *(a + j + 1) = *(a + j);    //大元素依次后移
        if (j != i - 1)
            *(a + j + 1) = t;
    }
}


//【例6-14】字符串复制
void str_copy (char s[], const char t[]) {  //数组写法 版本3
    int i = 0;
    while (s[i] = t[i])
        ++i;
}

void str_copy_ptr (char *s, const char *t) {//指针写法：参数s[]改为*s，t[]改为*t
    int i = 0;
    while (*(s + i) = *(t + i))		//把 s[i] 和 t[i] 改为指针写法
        ++i;
}


void printall(int n, int *a) {	//指针写法：参数 int a[] 等价于 int *a
    for (int i = 0; i < n; ++i)
        cout << *(a + i) << '\t';
    cout << endl;
}


int main() {
    cout << "\n测试【例6-9】数组元素排序\n";
    int array[] = {3, 2, 5, 1, 7, 8, 10, 6, 5 };//定义数组并以示例数据初始化
    int len = sizeof(array) / sizeof(array[0]);

    cout << "before sorting:" << endl;
    printall(len, array);

    insertsort_ptr(len, array);    //!!!

    cout << "after sorting:" << endl;
    printall(len, array);

    cout << "\n测试 【例6-14】字符串复制\n";
    const int LEN = 200;
    char s[LEN] = "";
    char t[LEN] = "Welcome to programming kingdom!";

    cout << "t: " << t << endl;
    str_copy_ptr(s, t);    //!!!
    cout << "s: " << s << endl;

    return 0;
}




