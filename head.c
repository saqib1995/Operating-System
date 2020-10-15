#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

char bufferArray [512];

void head(int fptr , int linecount)
{
	int i;
	int k;
	int count = 0;	
	
  	while((k = read(fptr, bufferArray, sizeof(bufferArray))) > 0 )
  	{
    		for (i = 0; i<k; i++) 
    		{
      			if(bufferArray[i] == '\n')
				{
					count++;
				}
				if(count <= linecount)
				{
        			printf(1,"%c",bufferArray[i]);
      			}
			}
	}

	if( k < 0 )
	{
		printf(1,"head error");
		exit();
	}
}

int main(int argc,char *args[]) {

	int fptr;
	int noOfLines = 10;
	int j;

	if(argc <= 1) {
		head(0 , 10);
		exit();
	} else {
		for(j = 1 ; j < argc ; j++)
		{
			if(*args[j] == '-')
			{
				args[j]++;
				noOfLines = atoi(args[j]++);
			}
			fptr = open(args[j] , 0);
		  
		}
		head(fptr, noOfLines);
		close(fptr);
		exit();
	}
}
