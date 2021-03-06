#include "monty.h"

/**
 * filefail - error message & exits if a file doesn't open
 * @ff: filename
 */
void filefail(char *ff)
{
	write(STDERR_FILENO, "Error: can't open file ", 23);
	write(STDERR_FILENO, ff, strlen(ff));
	write(STDERR_FILENO, "\n", 1);
	exit(EXIT_FAILURE);
}

/**
 * wrongargc - error message & exits if wrong argument count
 */
void wrongargc(void)
{
	write(STDERR_FILENO, "USAGE: monty file\n", 18);
	exit(EXIT_FAILURE);
}

/**
 * badinst - bad instruction error
 * @lc: line count
 * @tok: attempted opcode
 */
void badinst(unsigned int lc, char *tok)
{
	fprintf(stderr, "L%d: unknown instruction %s\n", lc, tok);
	gbn = -1;

}
