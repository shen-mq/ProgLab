/*********************************************************************
    ������:ex7-8
    ��Ȩ:
    ����: 2021212577 ����ǫ
    ����: 2022-06-08 16:06
    ˵��:
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

	cout << "������һ��ƽ���(x y): ";
	cin >> x >> y;
	dot1 = mkDot(x, y);

	cout << "������һ��Բ��Բ������Ͱ뾶(x y r): ";
	cin >> x >> y >> r;
	cir1 = mkCircle(x, y, r);

	dist = dist2(dot1, cir1);
	cout << "���룺" << dist << endl;
	dist = dist3(dot1, cir1);
	cout << "���룺" << dist << endl;
	dist = dist4(&dot1, &cir1);
	cout << "���룺" << dist << endl;

	cout << (dist <= cir1.radius ? "��Բ��" : "��Բ��") << endl;
	return 0;
}

