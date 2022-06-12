# ReadingTheF**kTextbook——佛脚合集

## c++常用函数与常量

- `cout`, `cin`, `endl`... 常用屏幕输入输出
- `include <cmath>` **(书P34)**
  - `sin`, `cos`, `tan`.
  - `asin`, `acos`, `atan`. 反三角函数
  - `sinh`, `cosh`, `tanh`. 双曲函数
  - `exp` 以 $ e $ 为底的指数函数
  - `log` 平时说的 $ \ln $
  - `log10` 以 10 为底的对数
  - `fabs` `sqrt` `ceil` `floor` `round` 都是输入double型, 输出double型.
  - `double pow(double, double)` `double fmod(double, double)`
- `include <ctime>` **(书P106)**
- `include <cstdlib>` (貌似很多地方不用这个头文件也可以)

## 基本语句
### if

```c++
if (<条件>) <语句1> else <语句2>
```
注意多条语句用大括号

### for

```cpp
for (表达式1; 表达式2; 表达式3) 语句
```
执行（语义）：
（1）求值表达式1（只做一次），用于设变量初值;
（2）求值表达式2，值为 0 时循环结束（循环条件）;
（3）执行语句;
（4）求值表达式3，通常用于循环变量更新;
（5）转到（2）.

<div align = center>
<img src="./fig/for.png" width="70%">
</div>

> 注意：表达式2在进入循环前会进行一次判断（如果第一次就不满足，则循环内的语句一次都不做）

### while

```cpp
while (条件) 语句
```
以及`do-while`:
```cpp
do 语句 while(条件);
```
> `do-while`循环内的语句至少做一次

### swich

```cpp
switch (整型表达式) {
 case 整型常量表达式: 语句序列; break;
 case 整型常量表达式: 语句序列; break;
 .... ....
 default: 语句序列 ; break;
}
```
注意：
- 如果不加`break`就会一路执行到底；
- 一定是**整型常量表达式**。


## 常见程序片段

### 排序
书上只有一个插入排序

```cpp
void insertsort(int n, int a[])
{ //整型数组按照递增序直接插入排序
    int i, j;
    int t;
    for (i = 1; i < n; ++i)
    {
        for (t = a[i], j = i - 1; j >= 0 && t < a[j]; --j)
            a[j + 1] = a[j]; //大元素依次后移
        if (j != i - 1)
            a[j + 1] = t;
    }
}
```
经过向LAB询问，确认最后那个`if`语句不是必须的，不加的话就是多做几次赋值操作

### 字符输入输出 *书P117*
把键盘上输入的每个字符（包括空格和回车键）都作为一个输入字符给字符型变量时的办法：
- 使用标准库函数中专门用于输入字符 `getchar` 函数；
- 使用标准输入流对象 `cin` 的成员函数 `get`，它也专门用于输入字符的函数，在使用时写成 `cin.get` 的形式。
- 输入字符：`getchar` 和 `cin.get` 都是没有参数的函数（简称“无参函数”），它们都能从标准输入读一个字符，返回该字符的编码值。其类型特征描述为：
```cpp
int getchar(void)
int cin.get(void)
```
- 标准库定义了一个符号常量 EOF（意为“End Of File”，文件结束），`getchar` 和 `cin.get` 在读字符时如果遇到文件结束（或输入结束），就返回EOF的值，说明已经没有输入了。在实际运行程序时，通常用组合键 `Ctrl+Z` 输入EOF。

输出字符：标准库中的 `putchar` 和`cout`的成员函数 `put` （写作 `cout.put` ）专门用于输出字符。它们的功能基本上等价，用户在实际应用中可以任选一种方式。例如：
```cpp
putchar('O');
cout.put('K');
```

---
**Might Be Very Useful**

用户从键盘上输入一系列字符（以键入EOF结束）:
```cpp
while ((ch = cin.get()) != EOF)
{
    ...
}
```

---

### 随机数生成
产生一个`0`到`max`的随机整数
```cpp
rand() % (max + 1); //产生新的待猜数字(注意取模的数为max+1)
```


### 输入输出流（字符串读取、文件读取） *书P112*
#### 字符串流式输入
要想把字符串类的变量用作输入输出，需要把它们绑定为**输入输出字符串流（string stream）**
- istringstream类——输入; 
- ostringstream类——输出;
- strstream类——输入输出.

程序中需要包含头文件 `sstream`: 
```cpp 
#include <sstream>
```
把一个字符串类的变量绑定为字符串输入流: 
```cpp
istringstream inss(str);
```
inss就成为了一个输入流，可以类似于cin一样用提取运算
符“>>”进行输入操作。例如：
```cpp
inss >> n; //从inss中读取一个数据并赋给整型变量n
```

完整例子
```cpp
#include <iostream>
#include <sstream>
using namespace std;
int main()
{
	int i, n;
	double x, sum;
	string str = "8 1.2 3.5 6.4 4.7 8.9 10.5 5.8 9.4"; //示例数据
	istringstream inss(str);//定义字符串输入流变量并绑定到字符串变量
	inss >> n;
	cout << "number of data items: " << n << endl;
	for (i = 1, sum = 0; i <= n; ++i)
	{
		inss >> x;
		cout << i << " : " << x << endl;
		sum += x;
	}
	cout << "Sum= " << sum << endl;
	return 0;
}
```
#### 文件流输入
在C++程序中，要使用计算机中的文件作为读取数据的来源或输出数据的目标，需要把相应的文件绑定为文件输入输出流。
C++引入了相关的类型：
- ifstream类——文件流输入；
- ofstream类——文件流输出；
- fstream类——输入输出。

程序中必须包含头文件 `<fstream>`：
```cpp
#include <fstream>
```
要想通过一个文件输入流对象打开一个纯文本文件，需要使用它的成员函数`open()` ：
```cpp
infile.open(“data.txt”) // “data.txt”为纯文本文件
```
也可以直接定义文件输入流并同时绑定纯文本文件：
```cpp
ifstream infile("data.txt");
```
然后就可以像使用 cin 一样从文件输入流读取数据：
```cpp
infile >> n; infile >> x;
```

类似的，定义一个文件输出流、并绑定纯文本文件：
```cpp
ofstream outfile("output.txt");
```
然后就可以把 `outfile` 类似于 `cout` 一样使用插入运算符`<<`进行输出操作。例如：
```cpp
outfile << n; //把整型变量n的值输出到outfile
```
打开的文件使用完成后一定要关闭，`fstream`提供了成员函数`close()`来完成此操作：
```cpp
infile.close();
outfile.close();
```

## 数组使用注意点

## 指针使用注意点 <!-- 上机考试我还是能不用就不用了吧…实在是不会 -->

## 结构体使用注意点 <!-- 同前，不会 -->

## 经典例题

## something ~~interesting~~ difficult
### 尾递归（不会）
### 汉诺塔（不会）

## 零散注意点

```cpp
	string str2 = "Hello, World!";
	cout << str2[1] << endl; // OK
	// cout << *(str2) << endl; //Fail

	char str1[] = "Hello, World!";
	cout << str1[1] << endl; // OK
	cout << *(str1) << endl; // OK
```


##### 考试的时候拿来馋人的照片…
<div align = center>
<img src="./fig/DunYau.jpg" width="80%">
</div>