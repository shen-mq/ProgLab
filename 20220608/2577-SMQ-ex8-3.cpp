/*********************************************************************
    程序名:ex8-3
    版权:
    作者: 2021212577 沈鸣谦
    日期: 2022-06-08 16:06
    说明:
*********************************************************************/
#include <iostream>
#include <ctime>
using namespace std;

typedef struct Dot {
	double x, y;
} Dot, *PrtDot;

int main() {
	const int NUM = 100;
	Dot dot[NUM] = {{0, 0}};
	Dot cent = {0, 0};

	srand(time(0));
	for (int i = 0; i < NUM; i++) {
		dot[i].x = 1.*rand() / RAND_MAX * 100;
		dot[i].y = 1.*rand() / RAND_MAX * 100;
		cout << i << ": (" << dot[i].x << ", " << dot[i].y << ")" << endl;
	}

	for (int i = 0; i < NUM; i++) {
		cent.x += dot[i].x;
		cent.y += dot[i].y;
		//cout
	}
	cent.x /= NUM;
	cent.y /= NUM;
	cout << "center : (" << cent.x << ", " << cent.y << ")" << endl;

	return 0;
}

