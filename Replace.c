#include "MyFunctions.h"

char ArrayOption[MAX_OPTIONS]= {0};
char * ListOfOptions="bilf";



int main(int argc,char**argv){
	if(argc	< 4)
	{
	printf("Error Using %s: must take at least 4 Agruments \n",argv[0]);
	PrintUsage();
	return -1;
	}
	int i=0;
    while (i<MAX_OPTIONS)
    {
	 ArrayOption[i]= checkoption(argc, argv, ListOfOptions[i]);//parsing options
		i++;
    }
	if(argc<=NumOfFoundOptions+2){
	printf("Error Using %s: must specify \"from\" and \"to\" take at least one file \n",argv[0]);
	PrintUsage();
	return -2;
	}
	if(argc<=NumOfFoundOptions+3){
	printf("Error Using %s: must take at least one file \n",argv[0]);
	PrintUsage();
	return -2;
	}
	// now command line argument is correct
	char* StringToReplace=argv[NumOfFoundOptions+1];
	char* ReplacementString=argv[NumOfFoundOptions+2];
	char* WorkingFile;

	for(i=1;NumOfFoundOptions+2+i<argc;i++){//loop on input file
		WorkingFile=argv[NumOfFoundOptions+2+i];
		printf("Working on %s \n",WorkingFile);
		if(ArrayOption[0]=='b'){//option b exist
		BackUP(WorkingFile);
	
		}//end of option b
		size_t f_size=GetFileSize(WorkingFile);
		printf("Size of %s is %ld\n",WorkingFile,f_size);
		int fdescrip=0;
		if( (fdescrip=open(WorkingFile,O_RDONLY)) == -1 ){
             printf("error opening file %s: this file will be skipped\n",WorkingFile);
             continue;
        }
		char * InputFilePtr;char * OutputFilePtr;
		if((InputFilePtr=(char*)malloc(f_size))==NULL){	
			printf("Error in allocating memory to read %s:free some memory and retry \n",WorkingFile);
			return -3;
		}
		if((read(fdescrip,InputFilePtr,f_size))==f_size){
		close(fdescrip);
		if( (fdescrip=open(WorkingFile,O_WRONLY)) == -1 ){
             printf("error opening file %s: this file doesn't change\n",WorkingFile);
             continue;
        }
			
			if(ArrayOption[2]=='l'){//option l exist
				OutputFilePtr=StringReplaceLast(InputFilePtr, StringToReplace, ReplacementString,&f_size,ArrayOption[1]);
				if(ArrayOption[3]=='f'){//nest option for Memory optimization Aspects
					free(InputFilePtr);
					InputFilePtr=OutputFilePtr;
					//free(OutputFilePtr);
				OutputFilePtr=StringReplaceFirst(InputFilePtr, StringToReplace, ReplacementString,&f_size,ArrayOption[1]);	
			}
			}//end of option l
			else if(ArrayOption[3]=='f'){//option f exist
				OutputFilePtr=StringReplaceFirst(InputFilePtr, StringToReplace, ReplacementString,&f_size,ArrayOption[1]);
				if(ArrayOption[2]=='l'){//nest option for Memory optimization Aspects
					free(InputFilePtr);
					InputFilePtr=OutputFilePtr;
					//free(OutputFilePtr);
				OutputFilePtr=StringReplaceLast(InputFilePtr, StringToReplace, ReplacementString,&f_size,ArrayOption[1]);	
			}	
			}//end of option f
			else if((ArrayOption[2]==0)&&(ArrayOption[3]==0)){//no l or f exists
				OutputFilePtr=StringReplaceAll(InputFilePtr, StringToReplace, ReplacementString,&f_size,ArrayOption[1]);
			}////end of no l or f exists
	
		
		}//end of file not empty
		else printf( "%s is an empty file \n",WorkingFile);
		write(fdescrip,OutputFilePtr,f_size);
		close(fdescrip);
		free(InputFilePtr);
		free(OutputFilePtr);
		printf("%s is modified sucessfully \n",WorkingFile);
		}//end of files loop
	return 0;
}
