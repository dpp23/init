#include <sys/types.h>

#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {

	DIR *dp;
	struct dirent *dirp;

	dp = opendir(".");

	while ((dirp = readdir(dp)) != NULL )
		printf("%s\n", dirp->d_name);

	closedir(dp);
	return(0);
}

