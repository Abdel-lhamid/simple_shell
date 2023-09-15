#include "shell.h"

/**
 *execute_command - Executes a single-word command.
 *@command: The command to execute.
 */
void execute_command(char *command)
{
	char *args[2];
	pid_t pid;
	int status;

	/*Remove newline character from the command */
	size_t len = _strlen(command);
	if (command[len - 1] == '\n')
		command[len - 1] = '\0';

	/*Check if command is empty */
	if (_strlen(command) == 0)
		return;

	args[0] = command;
	args[1] = NULL;

	pid = fork();
	if (pid == 0)
	{
		/*Child process */
		if (execve(args[0], args, NULL) == -1)
		{
			perror(args[0]);
			exit(EXIT_FAILURE);
		}
	}
	else if (pid < 0)
	{
		/*Forking failed */
		perror("Error");
	}
	else
	{
		/*Parent process */
		do { 	wait(&status);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
}
