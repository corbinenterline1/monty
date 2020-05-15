#include "monty.h"
int gbn;
/**
 * main - Main function for monty program.
 * Takes in one argument, which is a filepath to a monty file
 * @argc: argument count
 * @argv: array of argument string
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(int argc, char *argv[])
{
	unsigned int lc = 1;
	char *str = NULL, *tok = NULL, *sp = " ", *ff = argv[1];
	size_t len = 0;
	ssize_t reader;
	FILE *fp;
	stack_t *stack;

	if (argc != 2)/* If argument count is wrong */
		wrongargc();
	fp = fopen(ff, "r");
	if (fp == NULL)/* If file failed to open */
		filefail(ff);
	while ((reader = getline(&str, &len, fp)) != -1)
	{
		tok = strtok(str, sp);
		if (strncmp(tok, "push", 4) == 0)
		{
			tok = strtok(NULL, sp);
			if (tok == NULL)
				gbn = -1;
			else
				gbn = atoi(tok);
			push(&stack, lc);
		}
		else if (strncmp(tok, "pall", 4) == 0)
			pall(&stack, lc);
		else if (strncmp(tok, "pint", 4) == 0)
			pint(&stack, lc);
		free(str);
		str = NULL;
		lc++;
		if (gbn == -1)
			break;
	}
	fclose(fp);
	free(str);
	if (gbn == -1)
		exit(EXIT_FAILURE);
	exit(EXIT_SUCCESS);
}
