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
	unsigned int lc = 0;
	char *str = NULL, *tok = NULL, *sp = " \n", *ff = argv[1];
	size_t len = 0;
	ssize_t reader;
	FILE *fp;
	stack_t *stack;
	int j = 0;

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
			gbn = atoi(tok);
			push(&stack, lc);
		}
/**
 *		else if (strncmp(tok, "pall", 4) == 0)
 *			pall(&stack, lc);
 */
		else
		{
			instruction_t ops[] = {
				{"push", push},
				{"pall", pall},
				{NULL, NULL}
			};

			for (j = 0; ops[j].opcode; j++)
				if (ops[j].opcode == tok)
					ops[j].f(&stack, lc);
		}
		free(str);
		str = NULL;
		lc++;
	}
	printf("Line count: %d\n", lc);
	fclose(fp);
	free(str);
	exit(EXIT_SUCCESS);
}
