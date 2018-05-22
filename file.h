/*
 * file.h
 *
 *  Created on: May 22, 2018
 *      Author: Shriram
 */

#ifndef FILE_H_
#define FILE_H_

extern void filecopy(FILE*, FILE*);

extern char* fgetc2(char* s, int n, FILE* in);

extern int fputs2(char*, FILE*);

#endif /* FILE_H_ */
