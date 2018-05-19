#include <stdio.h>
#include <stdlib.h>
#include "chap6-1.h"
extern struct key keytab[];
Point makePoint(int x, int y){
	Point temp={x,y};
	return temp;
}
Point addpoint(Point p1, Point p2){
	p1.x += p2.x;
	p1.y += p2.y;
	return p1;
}
int ptinRect(Point p1, Rectangle r1){
	return p1.x >= r1.pt1.x && p1.x < r1.pt2.x && p1.y >= r1.pt1.y && p1.y < r1.pt2.y;
}

Rectangle canonrect(struct rect r)
{
	struct rect temp;
	temp.pt1.x = min(r.pt1.x, r.pt2.x);
	temp.pt1.y = min(r.pt1.y, r.pt2.y);
	temp.pt2.x = max(r.pt1.x, r.pt2.x);
	temp.pt2.y = max(r.pt1.y, r.pt2.y);
	return temp;
}
//
//int main(void){
//	Point a = { 0, 0};
//	Point b = {10, 10};
//	Rectangle rect = {a,b};
//	Rectangle* r = &rect;
//	printf("%d %d", r->pt1.x, r->pt2.x);
//	Point middle = makePoint(((double)a.x+b.x)/2, ((double)a.y+b.y)/2);
//	return EXIT_SUCCESS;
//}
