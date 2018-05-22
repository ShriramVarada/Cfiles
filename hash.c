#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"

static List* hashtable[HASHSIZE];

unsigned hashvalue(char* s){
	unsigned hashval;

	for(hashval = 0; *s != '\0'; s++){
		hashval = *s + 31 * hashval;
	}

	return hashval % HASHSIZE;
}

List* lookup(char* s){
	List* np;
	for(np = hashtable[hashvalue(s)]; np != NULL; np = np->next){
		if(strcmp(np->name, s) == 0)
			return np;
	}
	return NULL;
}

List* install(char* name, char* defn){
	unsigned hash = hashvalue(name);
	List* np;
	if((np = lookup(name)) == NULL){
		np = (List*) malloc(sizeof(List));
		np->next = hashtable[hash];
		hashtable[hash] = np;
	}else
		free((void *) np->replacement);
	np->replacement = strdup(defn);
	return np;
}

int main(void){

	return EXIT_SUCCESS;
}
