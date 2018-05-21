/*
 * chap6-1.h
 *
 *  Created on: May 19, 2018
 *      Author: Shriram
 */

#ifndef CHAP6_1_H_
#define CHAP6_1_H_

#define MAXWORD 100
#define min(a, b) ((a>b) ? b : a)
#define max(a, b) ((a>b) ? a : b)

struct point{ int x; int y;};
typedef struct point Point;

struct rect { Point pt1; Point pt2;};
typedef struct rect Rectangle;

extern Point makePoint(int, int);

extern Point addpoint(Point, Point);

extern int ptinRect(Point, Rectangle);

extern Rectangle canonrect(Rectangle r);

extern int getword(char *word, int lim);

struct key { char *word; int count; };

extern int binsearch(char *word, struct key tab[], int n);

struct tNode {
	char* word;
	struct tNode* left;
	struct tNode* right;
	int count;
};
typedef struct tNode TreeNode;

extern void treeprint(TreeNode *);

extern TreeNode *addtree(TreeNode *, char *);

extern char* strdup1(char* word);

extern TreeNode* createNode();

#endif /* CHAP6_1_H_ */
