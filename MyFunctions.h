#ifndef MY_FUNOCTINS 
#define MY_FUNOCTINS
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <time.h>
#include <string.h>

#define   BUFSIZE  100
#define  CMODE      S_IRUSR|S_IWUSR  |S_IRGRP|S_IROTH
#define PASS 0
#define FAIL 1
#define MAX_OPTIONS 4
#define OPTION_NOT_FOUND 0
#define  MAX_CHARACTERS_IN_FILE_NAME 100

extern int  NumOfFoundOptions;
void PrintUsage();
char checkoption (int _argc,char** _argv,char option);
int cp(char* F1, char* F2);
int StringToLower(char * s,int n);
long int GetFileSize(char* File);
char *StringReplaceAll(const char *str, const char *FromString, const char* ToString,size_t *size);
char *StringReplaceFirst(const char *str, const char *FromString, const char* ToString,size_t *size);
char *StringReplaceLast(const char *str, const char *FromString, const char* ToString,size_t *size);
void BackUP(char* Filename);
#endif //MY_FUNOCTINS
