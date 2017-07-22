#ifndef USED_FUNCTIONS
#define USED_FUNCTIONS

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

#define  BUFSIZE  100
#define  CMODE      S_IRUSR|S_IWUSR  |S_IRGRP|S_IROTH
#define  PASS 1
#define  FAIL 0
/* cp is copy file F1 in F2*/
int cp (char* F1,char* F2); 

#endif //USED_FUNCTIONS
