/*********************************************************************
程序名：点、圆和矩形的结构体类型 
版权：遵从GPL版权协议，可自由使用和传播（请勿上传到收费性网络文库）
作者：anbangli@foxmail.com
日期：2019-07-24
说明：
8-1.	请定义平面上的点、圆和矩形（假设矩形的边总是分别平行于X轴和Y轴，
则矩形可用左上角和下右角两个点的坐标表示）的结构体类型，然后写出如下计算
平面点与其它图形之间关系的函数（并写出测试这些函数的主函数）：
（1）判断一个点是否在一个圆内（函数取名isInsideCircle);
（2）判断一个点是否在一个矩形内部（函数取名isInsideRect)；
（3）判断一个圆与另一个圆是否有重叠（函数取名isCircleOnCircle）
（4）判断一个圆与一个矩形是否有重叠（函数取名isCircleOnRect）；
（5）判断两个矩形是否有重叠（函数取名isRectOnRect）。	//教材上没有 
*********************************************************************/

#include <iostream>
#include <cmath>
using namespace std;

//平面点结构体。直接使用教材上的示例源代码 
typedef struct point {
    double x, y;
} point;

//平面圆结构体。仿照教材上的示例源代码并简化成员名称 
typedef struct circle {
    point ct;	//center
    double r;	//radius
} circle;

//平面矩形结构体。根据题目说明进行定义 
typedef struct rectangle {
	point lu;	//left-up
	point rd;	//right-down
} rectangle;

//（1）判断一个点是否在一个圆内（函数取名isInsideCircle);
int isInsideCircle(point dot, circle cir){
	//先计算点与圆心的距离，然后根据该距离是否小于圆半径而作出判断 
	double dist = sqrt((dot.x - cir.ct.x) * (dot.x - cir.ct.x) 
						+ (dot.y - cir.ct.y) * (dot.y - cir.ct.y) );
	return (dist < cir.r);	
}

//（2）判断一个点是否在一个矩形内部（函数取名isInsideRect)；
int isInsideRect(point dot, rectangle rect){
	//根据点的 x 坐标和 y 坐标是否在矩形内部而判断 
	return ((dot.x > rect.lu.x && dot.x < rect.rd.x)
			&& (dot.y < rect.lu.y && dot.y > rect.rd.y));
}

//（3）判断一个圆与另一个圆是否有重叠（函数取名isCircleOnCircle）
int isCircleOnCircle(circle cir1, circle cir2){
	//根据是否有一个圆的圆心在另一个圆内而判断。
	//使用上面所定义的 isInsideCircle 函数
	return (isInsideCircle (cir1.ct, cir2) || isInsideCircle(cir2.ct, cir1));
}
	
//（4）判断一个圆与一个矩形是否有重叠（函数取名isCircleOnRect）；
int isCircleOnRect(circle cir, rectangle rect){
	//圆心如果在矩形内部，则可判断为重叠。使用上面的 isInsideRect 函数。 
	if (isInsideRect (cir.ct, rect)) 
		return true;
	
	//如果矩形的四个角在圆的内部，则可判断为重叠。使用 isInsideCircle 函数。 
	//先看左上角与右下角 
	if (isInsideCircle(rect.lu, cir) || isInsideCircle(rect.rd, cir))
		return true;
	//然后看左下角与右上角 
	point ld = {rect.lu.x, rect.rd.y};	//left-down
	point ru = {rect.rd.x, rect.lu.y};	//right-up
	if (isInsideCircle(ld, cir)|| isInsideCircle(ru, cir) ) ;
		return true;
	
	//如果所有上述判断都为否，则可判断为非重叠。 
	return false;
}

//（5）判断两个矩形是否有重叠（函数取名isRectOnRect）。
int isRectOnRect(rectangle rect1, rectangle rect2) {
	//如果一个矩形的四个角之一在另一个矩形内部，则判断为重叠。
	//使用上面的 isInsideRect 函数。
	
	//先看左上角与右下角
	if (isInsideRect(rect1.lu, rect2) || isInsideRect(rect1.rd, rect2))
		return true;
	//然后看左下角与右上角
	point ld = {rect1.lu.x, rect1.rd.y};	//left-down
	point ru = {rect1.rd.x, rect1.lu.y};	//right-up
	if (isInsideRect(ld, rect2) || isInsideRect(ru, rect2));
		return true;
	
	return false;
}

int main() {
	//定义一些变量并初始化 
	point dot1 = {0, 0}, dot2 = {2, 2};
	circle cir1 = {{-2, 0}, 2.5}, cir2 = {{0, 0}, 2}, cir3 = {{4, 0}, 3};
	rectangle rect1 = {{0, -1}, {2, 3}}, rect2 = {{1, 5}, {6, -3}};
	
	cout << "dot1 in cir1? : " << isInsideCircle(dot1, cir1) << endl;
	cout << "dot1 in cir3? : " << isInsideCircle(dot1, cir3) << endl;
	
	cout << "dot1 in rect1? : " << isInsideRect(dot1, rect1) <<endl;
	cout << "dot2 in rect2? : " << isInsideRect(dot2, rect2) <<endl;
	
	cout << "cir1 on cir2? : " << isCircleOnCircle(cir1, cir2) << endl;
	cout << "cir1 on cir3? : " << isCircleOnCircle(cir1, cir3) << endl;
	
	return 0;
}


