#include "types.h"
#include "stat.h"
#include "user.h"

char buffer[1024]={'\\'};

void tail(int fd_one, char *file_name, int numOfLinesToRead) {

	int fd_two;	
	int n;
	int i;
	int line_count_one = 0;
	int remaining_line_count = 0;
	int line_count_two = 0;
	
	while((n = read(fd_one,buffer,sizeof(buffer))) > 0) { 	
		for(i = 0 ; i < n ; i++) {
			if(buffer[i]=='\n') {
				line_count_one++;
			} else {
			if(strcmp(file_name,"")==0){
				if(buffer[i] =='\0')  // Check end of file
				{
					exit();
				}
				if(buffer[i]!='\n')
				{
				 printf(1,"%c",buffer[i]);
				}
				else
				{
				 printf(1,"\n");}
				}

			}
		}
	}


	remaining_line_count = line_count_one - numOfLinesToRead;

	fd_two = open(file_name, 0);

	while((n = read(fd_two, buffer , sizeof(buffer))) > 0) {
		
		for(i = 0 ; i < n ; i++) {
			if(buffer[i]=='\n') {
				line_count_two++;
			}
			if(line_count_two >= remaining_line_count) {
				printf(1, "%c" , buffer[i]);
			}
		}


	}
	exit();

}


int
main(int argc,char *argv[])
{
	int fd = 0;

	if(argc <= 1) {
		tail(fd, "", 10);
				
	} else if(argc == 2) {
		fd = open(argv[1], 0);
		tail(fd , argv[1] , 10);

	} else {
			
		char c[1024];
		strcpy(c,argv[1]);
		char *numOfLines=c;
		numOfLines=numOfLines+1;
		int lineCount= atoi(numOfLines);
		fd = open(argv[2], 0);
		tail(fd,argv[2], lineCount);
	}

	
	
	exit();
}
