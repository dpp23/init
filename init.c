#include <stdio.h>	
#include <stdlib.h>	
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>	

int main(int argc, char **argv, char **envp)
{
   	char c = '\0';
   	char *tmp = (char *)malloc(sizeof(char) * 100);
   	printf("\n[psh] %s $", get_current_dir_name());
   	while (c != EOF)
	{
      		c = getchar();
       	      	switch(c) {
			 case '\n':
				if(tmp[0]=='c' && tmp[1]=='d')
				{
					tmp=tmp+3;
					chdir(tmp);
			  		bzero(tmp, sizeof(tmp));   /* erase the temporary string */
            				printf("\n[psh] %s $", get_current_dir_name());
            				break;
				}
			    	if (fork() == 0) 
				{   /* fork a new process to run the command in */
			       		int i = execvp(tmp, argv);  /* run it */
			       		if (i < 0) {
				  		printf("%s: command not found. Trying to execute from initial dir...\n", tmp);
				  		char *temp = (char *)malloc(sizeof(char) * 100);
						temp[0] = '/';
						i = execvp( strcat(temp, tmp) , argv);  /* run it */
						if(i < 0)
						{
							printf("%s: command not found.", tmp);
							exit(1);
						}
			       		}
			    	} 
				else 
				{
			       		wait(NULL);
			    	}
			    	bzero(tmp, sizeof(tmp));   /* erase the temporary string */
			    	printf("\n[psh] %s $", get_current_dir_name());
			    	break;
			 default:
			    	strncat(tmp, &c, 1);    /* append the letter to the string */
			    	break;
		      }

   }
   printf("\n");
   return 0;
}
