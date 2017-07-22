#include "MyFunctions.h"

int cp (char* F1,char* F2){
	int fd1,fd2,n;
	char buf[BUFSIZE];
	if( (fd1=open(F1,O_RDONLY)) == -1 ){
             printf("error opening file %s\n",F2);
             return FAIL;
        }
        if( (fd2=creat(F2,CMODE)) == -1 ){
             printf("error creating file %s\n",F2);
             return FAIL;
        }
        while((n=read(fd1,buf,BUFSIZE)) > 0){
           write(fd2,buf,n);
        }
        close(fd1);
        close(fd2);
	return PASS;

}
