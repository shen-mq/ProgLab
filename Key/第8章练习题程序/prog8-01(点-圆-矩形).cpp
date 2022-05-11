/*********************************************************************
���������㡢Բ�;��εĽṹ������ 
��Ȩ�����GPL��ȨЭ�飬������ʹ�úʹ����������ϴ����շ��������Ŀ⣩
���ߣ�anbangli@foxmail.com
���ڣ�2019-07-24
˵����
8-1.	�붨��ƽ���ϵĵ㡢Բ�;��Σ�������εı����Ƿֱ�ƽ����X���Y�ᣬ
����ο������ϽǺ����ҽ�������������ʾ���Ľṹ�����ͣ�Ȼ��д�����¼���
ƽ���������ͼ��֮���ϵ�ĺ�������д��������Щ����������������
��1���ж�һ�����Ƿ���һ��Բ�ڣ�����ȡ��isInsideCircle);
��2���ж�һ�����Ƿ���һ�������ڲ�������ȡ��isInsideRect)��
��3���ж�һ��Բ����һ��Բ�Ƿ����ص�������ȡ��isCircleOnCircle��
��4���ж�һ��Բ��һ�������Ƿ����ص�������ȡ��isCircleOnRect����
��5���ж����������Ƿ����ص�������ȡ��isRectOnRect����	//�̲���û�� 
*********************************************************************/

#include <iostream>
#include <cmath>
using namespace std;

//ƽ���ṹ�塣ֱ��ʹ�ý̲��ϵ�ʾ��Դ���� 
typedef struct point {
    double x, y;
} point;

//ƽ��Բ�ṹ�塣���ս̲��ϵ�ʾ��Դ���벢�򻯳�Ա���� 
typedef struct circle {
    point ct;	//center
    double r;	//radius
} circle;

//ƽ����νṹ�塣������Ŀ˵�����ж��� 
typedef struct rectangle {
	point lu;	//left-up
	point rd;	//right-down
} rectangle;

//��1���ж�һ�����Ƿ���һ��Բ�ڣ�����ȡ��isInsideCircle);
int isInsideCircle(point dot, circle cir){
	//�ȼ������Բ�ĵľ��룬Ȼ����ݸþ����Ƿ�С��Բ�뾶�������ж� 
	double dist = sqrt((dot.x - cir.ct.x) * (dot.x - cir.ct.x) 
						+ (dot.y - cir.ct.y) * (dot.y - cir.ct.y) );
	return (dist < cir.r);	
}

//��2���ж�һ�����Ƿ���һ�������ڲ�������ȡ��isInsideRect)��
int isInsideRect(point dot, rectangle rect){
	//���ݵ�� x ����� y �����Ƿ��ھ����ڲ����ж� 
	return ((dot.x > rect.lu.x && dot.x < rect.rd.x)
			&& (dot.y < rect.lu.y && dot.y > rect.rd.y));
}

//��3���ж�һ��Բ����һ��Բ�Ƿ����ص�������ȡ��isCircleOnCircle��
int isCircleOnCircle(circle cir1, circle cir2){
	//�����Ƿ���һ��Բ��Բ������һ��Բ�ڶ��жϡ�
	//ʹ������������� isInsideCircle ����
	return (isInsideCircle (cir1.ct, cir2) || isInsideCircle(cir2.ct, cir1));
}
	
//��4���ж�һ��Բ��һ�������Ƿ����ص�������ȡ��isCircleOnRect����
int isCircleOnRect(circle cir, rectangle rect){
	//Բ������ھ����ڲ�������ж�Ϊ�ص���ʹ������� isInsideRect ������ 
	if (isInsideRect (cir.ct, rect)) 
		return true;
	
	//������ε��ĸ�����Բ���ڲ�������ж�Ϊ�ص���ʹ�� isInsideCircle ������ 
	//�ȿ����Ͻ������½� 
	if (isInsideCircle(rect.lu, cir) || isInsideCircle(rect.rd, cir))
		return true;
	//Ȼ�����½������Ͻ� 
	point ld = {rect.lu.x, rect.rd.y};	//left-down
	point ru = {rect.rd.x, rect.lu.y};	//right-up
	if (isInsideCircle(ld, cir)|| isInsideCircle(ru, cir) ) ;
		return true;
	
	//������������ж϶�Ϊ������ж�Ϊ���ص��� 
	return false;
}

//��5���ж����������Ƿ����ص�������ȡ��isRectOnRect����
int isRectOnRect(rectangle rect1, rectangle rect2) {
	//���һ�����ε��ĸ���֮һ����һ�������ڲ������ж�Ϊ�ص���
	//ʹ������� isInsideRect ������
	
	//�ȿ����Ͻ������½�
	if (isInsideRect(rect1.lu, rect2) || isInsideRect(rect1.rd, rect2))
		return true;
	//Ȼ�����½������Ͻ�
	point ld = {rect1.lu.x, rect1.rd.y};	//left-down
	point ru = {rect1.rd.x, rect1.lu.y};	//right-up
	if (isInsideRect(ld, rect2) || isInsideRect(ru, rect2));
		return true;
	
	return false;
}

int main() {
	//����һЩ��������ʼ�� 
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


