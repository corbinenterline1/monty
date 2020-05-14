#include "monty.h"

/**
 * main - Main function for monty program.
 * Takes in one argument, which is a filepath to a monty file
 * 
 *
 */
int main(int argc, char *argv[])
{
	int lc = 0;/* line counter */
	char *str = NULL;/* Line read by getline from file, used in loop */
	size_t len = 0;/* len of line from getline */
	ssize_t read;
	FILE *fp;/* file pointer for return from fopen */

	if (argc != 2)/* If argument count is wrong */
	{
		write(STDERR_FILENO, "USAGE: monty file\n", 18);
		exit(EXIT_FAILURE);
	}
	fp = fopen(argv[1], "r");
	if (fp == NULL)/* If file failed to open */
	{
		write(STDERR_FILENO, "Error: Can't open file ", 23);
		write(STDERR_FILENO, argv[1], _strlen(argv[1]));
		write(STDERR_FILENO, "\n", 1);
		exit(EXIT_FAILURE);
	}
	while ((read = getline(&str, &len, fp)) != -1)
	{
		write(STDOUT_FILENO, str, _strlen(str));
		free(str);
		str = NULL;
		lc++;
	}
	printf("Line count: %d\n", lc);
	fclose(fp);
	free(str);
	exit(EXIT_SUCCESS);
}
