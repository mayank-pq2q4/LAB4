#include <stdio.h>
int main(int argc, char const *argv[])
{
	FILE *fp;
	char command[40];
	printf("length of argv = %d\n", argc);
	for (int i = 1; i < argc; i++)
	{
		printf("FILE CONTENTS OF %s:\n", argv[i]);
		fp = fopen(argv[i], "r");
		while (fgets(command, 40, fp))
		{
			printf("%s\n", command);
		}
		fclose(fp);
	}
	return 0;
}