#include <stdio.h>
#include <stdlib.h>
#include "chap6-1.h"
#include <ctype.h>
#include <string.h>
#define MAXWORD 100

TreeNode *addtree(TreeNode * t, char * word){
	int cond;

	if(t == NULL){
		t = createNode();
		t->left = t->right = NULL;
		t->count = 1;
		t->word = strdup(word);
	}else if((cond = strcmp(t->word, word)) == 0){
		t->count++;
	}else if(cond < 0){
		t->left = addtree(t->left, word);
	}else
		t->right = addtree(t->right, word);

	return t;
}

void treeprint(TreeNode * root){
	if(root != NULL){
		treeprint(root->left);
		printf("Word : %s and its count = %d", root->word, root->count);
		treeprint(root->right);
	}
}

int getword(char *, int);

TreeNode* createNode(){
	return (TreeNode*) malloc(sizeof(TreeNode));
}

char* strdup1(char* word){
	char* p;
	p = (char *) malloc(strlen(word) + 1);
	if(p != NULL)
		strcpy(p, word);
	return p;
}



int main(void){
	TreeNode* t = NULL;
	char word[MAXWORD];
	while(getword(word, MAXWORD) != EOF){
		if(isalpha(word[0]))
			t = addtree(t, word);
	}

	return EXIT_SUCCESS;
}
