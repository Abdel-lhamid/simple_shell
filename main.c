#include "shell.h"

/**
 *main - Entry point for the simple shell.
 *@argc: Argument count.
 *@argv: Argument vector.
 *
 *Return: Always 0 (success).
 */
int main(int ac, char **av)
{
	(void) ac;
	(void) av;

	size_t len;
	ssize_t read;
	char *line = NULL;

	len = 0;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "#cisfun$ ", 9);

	while ((read = getline(&line, &len, stdin)) != -1)
	{
		if (read > 1)
			execute_command(line);

		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "#cisfun$ ", 9);
	}

	free(line);
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "\n", 1);

	return 0;
}
