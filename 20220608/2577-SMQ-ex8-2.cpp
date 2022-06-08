/*********************************************************************
    程序名:ex7-8
    版权:
    作者: 2021212577 沈鸣谦
    日期: 2022-06-08 16:06
    说明:
*********************************************************************/
#include <iostream>
#include <cmath>
using namespace std;

typedef struct Dot {
	double x, y;
} Dot, *PrtDot;

typedef struct Circle {
	Dot center;
	double radius;
} Circle, *PrtCircle;

//struct Dot mkDot(double x, double y);

Dot mkDot(double x, double y) {
	Dot temp;
	temp.x = x;
	temp.y = y;
	return temp;
}

Circle mkCircle(double x, double y, double r) {
	Circle temp;
	temp.center.x = x;
	temp.center.y = y;
	temp.radius = r;
	return temp;
}

double dist2(Dot dot, Circle circ) {
	double dist;
	dist = sqrt((dot.x - circ.center.x) * (dot.x - circ.center.x) + (dot.y - circ.center.y) * (dot.y - circ.center.y));
	return dist;
}

double dist3(Dot &dot, Circle &circ) {
	return sqrt((dot.x - circ.center.x) * (dot.x - circ.center.x) + (dot.y - circ.center.y) * (dot.y - circ.center.y));
}

double dist4(Dot *dot, Circle *circ) {
	return sqrt( (dot->x - circ->center.x) * (dot->x - circ->center.x) +  (dot->y - circ->center.y) *
	             (dot->y - circ->center.y));
}

int main() {
	Dot dot1;
	Circle cir1;
	double x, y, r, dist;

	cout << "请输入一个平面点(x y): ";
	cin >> x >> y;
	dot1 = mkDot(x, y);

	cout << "请输入一个圆的圆心坐标和半径(x y r): ";
	cin >> x >> y >> r;
	cir1 = mkCircle(x, y, r);

	dist = dist2(dot1, cir1);
	cout << "距离：" << dist << endl;
	dist = dist3(dot1, cir1);
	cout << "距离：" << dist << endl;
	dist = dist4(&dot1, &cir1);
	cout << "距离：" << dist << endl;

	cout << (dist <= cir1.radius ? "在圆内" : "在圆外") << endl;
	return 0;
}

