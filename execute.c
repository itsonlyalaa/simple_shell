#include"shell.h"

/**
 * execute :This function creates a child process and uses execve to
 * execute the specified command.
 * @c : the command that we want to execute.
 * return : 0 always success.
 *
 * This function creates a child process and uses execve to
 * execute the specified command.
 * The parent process waits for the child process to complete.
 */


void execute(const char *cmd)
{
	pid_t child_pid = fork();

	if (child_pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (child_pid == 0)
	{
			execlp(cmd, cmd, (char*)NULL);
			perror("execlp");
			exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
	}
}
