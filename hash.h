/*
 * hash.h
 *
 *  Created on: May 20, 2018
 *      Author: Shriram
 */

#ifndef HASH_H_
#define HASH_H_
#define HASHSIZE 101

struct nlist{
	struct nlist* next;
	char* name;
	char* replacement;
}; typedef struct nlist List;

extern unsigned hashvalue(char*);

extern List* lookup(char*);

extern List* install(char*, char*);

#endif /* HASH_H_ */
