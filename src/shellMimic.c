// 8b    d8    db    Yb  dP    db    88b 88 88  dP     8888b.  888888 .dP"Y8 88  88 88""Yb    db    88b 88 8888b.  888888
// 88b  d88   dPYb    YbdP    dPYb   88Yb88 88odP       8I  Yb 88__   `Ybo." 88  88 88__dP   dPYb   88Yb88  8I  Yb 88__
// 88YbdP88  dP__Yb    8P    dP__Yb  88 Y88 88"Yb       8I  dY 88""   o.`Y8b 888888 88"""   dP__Yb  88 Y88  8I  dY 88""
// 88 YY 88 dP""""Yb  dP    dP""""Yb 88  Y8 88  Yb     8888Y"  888888 8bodP' 88  88 88     dP""""Yb 88  Y8 8888Y"  888888

//   .d .dP"o. Yb  dP  88888   .d    db     dP"Yb  888888 oP"Yb. dP""Yb
// .d88 `8b.d'  YbdP      88 .d88   dPYb   dP   Yb 88oo." "' dP' Ybood8
//   88 d'`Y8b  dPYb  o.  88   88  dP__Yb  Yb   dP    `8b   dP'    .8P'
//   88 `bodP' dP  Yb "bodP'   88 dP""""Yb  YbodP  8888P' .d8888  .dP'

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include <time.h>
#include <linux/limits.h>
#include <ctype.h>
#include "linkedlist.h"

int main(int argc, char const *argv[])
{
	FILE *fp;
	pid_t pid;
	List *historyFull = makelist();
	List *historyBrief = makelist();
	char command[200];
	char buffer[200];
	//writing the child C file

	/*########## FORKED INTO 2 ############*/

	pid = fork();
	if (pid < 0)
	{
		printf("\n Error: Fork failed. \n exiting ");
		exit(1);
	}
	/*########## child ############*/
	else if (pid == 0)
	{
		printf("CHILD PROCESS HERE \n");
		printf("Pid is %d \n", getpid());
		char resolved_path[PATH_MAX];
		realpath("./", resolved_path);
		strcat(resolved_path, "/child529");
		char *args[] = {resolved_path, argv[1], argv[2], NULL};
		if (execvp(args[0], args) == -1)
		{
			perror("\nfailed connection\n");
			exit(0);
		}
		exit(0);
	}

	/*########## parent ############*/

	else
	{
		wait(0);
		for (int i = 1; i < argc; i++)
		{
			fp = fopen(argv[i], "r");
			while (fgets(command, 40, fp))
			{
				add(command, historyFull);
				system(command);
				brief(command);
				add(command, historyBrief);
			}
			fclose(fp);
		}

		printf("\n PARENT PROCESS HERE \n");
		printf("\n Actual pid is %d \n \n", getpid());
		printf("\nPost-batch processing interactive mode:\n");
		while (1)
		{
			printf("\nPlease enter your command:\n");
			scanf("%[^\n]%*c", command);
			strcpy(buffer, command);
			if (strstr(buffer, "EXEC ") != NULL)
			{
				strremove(buffer, "EXEC ");
				printf("executing %s\n", buffer);
				system(buffer);
			}
			if (!strcmp(buffer, "STOP") || !strcmp(buffer, "exit") || !strcmp(buffer, "quit"))
			{
				break;
			}

			strcpy(command, buffer);
			add(command, historyFull);
			brief(command);
			add(command, historyBrief);

			if (!strcmp(buffer, "HISTORY FULL") || !strcmp(buffer, "history"))
			{
				display(historyFull);
			}
			if (!strcmp(buffer, "HISTORY BRIEF") || !strcmp(buffer, "histbr"))
			{
				display(historyBrief);
			}
		}
		destroy(historyFull);
		destroy(historyBrief);
		exit(0);
	}
}