#include "MyFunctions.h"
 
int NumOfFoundOptions=0;

void PrintUsage()
{
    printf( "Usage : Replace -<option> from to >LOF>\n");
	printf("option is one of the following.\n");
    printf( "\t-i   : case insensetive\n");
    printf( "\t-f   : Replace only First\n");
    printf( "\t-b   : Back up before replacement\n");
    printf( "\t-l   : Discover Resources\n");
	printf( "from : String that replace to\n");
	printf( "to   : String that were replaced with from\n");
	printf( "LOF  : List of files the command works on\n");
    
}

int cp(char* F1, char* F2){
		int fd1,fd2;
        int n;
        char buf[BUFSIZE];
        if( (fd1=open(F1,O_RDONLY)) == -1 ){
             printf("error opening file %s\n",F1);
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

char checkoption (int _argc,char** _argv,char option){
	int i=0;
	while(i<_argc){
	if(_argv[i][0]=='-'){
		if(_argv[i][1]==option){
			if(_argv[i][2]=='\0'){
				NumOfFoundOptions++;
				return option;		
			}
		}
	}
	i++;
	}
	return  OPTION_NOT_FOUND;		
}

int StringToLower(char * s,int n)
{
	int i;
	for (i=0;(i<n)&&(s[i]!='\0');i++)
		s[i]=tolower(s[i]);
	if(i!=n)
	return i;
	return n;
}

long int GetFileSize(char* File){
	int fd=0;	
	if( (fd=open(File,O_RDONLY)) == -1 ){

             printf("error calculating size of file %s\n",File);
             return -1;
        }
		char buf[BUFSIZE];long int FileSize=0;int n=0;
		while((n=read(fd,buf,BUFSIZE))==BUFSIZE)
			FileSize+=BUFSIZE;
		FileSize+=n;
		close(fd);
		return FileSize;
}

char *StringReplaceAll(const char *str, const char *FromString, const char* ToString,size_t *size)
{
    char *ReturnPtr;
    int i, count = 0;
    int ToStringlen = strlen(ToString);
    int FromStringlen = strlen(FromString);
 
    for (i = 0; i<*size; i++)    
    {
        if (strstr(&str[i], FromString) == &str[i]) 
        {
            count++;
            i += FromStringlen - 1;
        }
    }
	*size=*size+ count * (ToStringlen - FromStringlen);
    if((ReturnPtr = (char *)malloc(*size))==NULL){	
			printf("Error in allocating memory to edit :free some memory and retry \n");
			exit (10);
		}

    i = 0;
    while (*str)
    {
        if (strstr(str, FromString) == str) //compare the substring with the ToStringstring
        {
            strcpy(&ReturnPtr[i], ToString);
            i += ToStringlen; //adding ToStringlength to the ToString string
            str += FromStringlen;//adding the same FromString length the FromString string
        }
        else
        ReturnPtr[i++] = *str++;
    }
 
    return ReturnPtr;
}

char *StringReplaceFirst(const char *str, const char *FromString, const char* ToString,size_t*size)
{
    char *ReturnPtr;
    int ToStringlen = strlen(ToString);
    int FromStringlen = strlen(FromString);
    int i=0;
	char* first=strstr(&str[0], FromString);
	*size =*size+ToStringlen - FromStringlen;
    if((ReturnPtr = (char *)malloc(*size))==NULL){	
			printf("Error in allocating memory to edit :free some memory and retry \n");
			exit (10);
		}

    while (*str)
    {
        if (first== str) //compare the substring with the first ToStringstring
        {
            strcpy(&ReturnPtr[i], ToString);
            i += ToStringlen; //adding ToStringlength to the ToString string
            str += FromStringlen;//adding the same FromString length the FromString string
        }
        else
        ReturnPtr[i++] = *str++;
    }
    return ReturnPtr;
}

char *StringReplaceLast(const char *str, const char *FromString, const char* ToString,size_t *size)
{
    char *ReturnPtr;
    int i, last = 0;
    int ToStringlen = strlen(ToString);
    int FromStringlen = strlen(FromString);
 
    for (i = 0; i<*size; i++)    
    {
        if (strstr(&str[i], FromString) == &str[i]) 
        {
            last=i;
            i += FromStringlen - 1;
        }
    }
	*size=*size+ ToStringlen - FromStringlen;
    if((ReturnPtr = (char *)malloc(*size))==NULL){	
			printf("Error in allocating memory to edit :free some memory and retry \n");
			exit (10);
		}


    i = 0;
    while (*str)
    {
        if (i==last) //compare the substring with the ToStringstring
        {
            strcpy(&ReturnPtr[i], ToString);
            i += ToStringlen; //adding ToStringlength to the ToString string
            str += FromStringlen;//adding the same FromString length the FromString string
        }
        else
        ReturnPtr[i++] = *str++;
    }
 
    return ReturnPtr;
}

void BackUP(char* Filename){
			char backupname[MAX_CHARACTERS_IN_FILE_NAME+20];	
			char* backuptime;
			time_t backupt;			
			time(&backupt);
			backuptime=ctime(&backupt);
			strcpy(backupname,Filename);
			strcat(backupname,"_");
			strncat(backupname,&backuptime[4],15);
			strcat(backupname,".BU");
			if(strlen(Filename)>MAX_CHARACTERS_IN_FILE_NAME)
				printf("Error back up of ""%s"" large file name \n",Filename);	
			else if(cp(Filename,backupname)!=PASS)
			printf("Error back up of while copying: %s\n",Filename);
			else printf( "%s backed up sucessfully in %s\n",Filename,backupname);
}
