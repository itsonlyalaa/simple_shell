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


void execute(char *c)
{
	pid_t child_pid = fork();

	if (child_pid == -1)
	{
		perror("fork");
		exit(EXIT_SUCCESS);
	}
	else if (child_pid == 0)
	{
		char **argv = (char **)malloc(2 * sizeof(char *));

		if (argv == NULL)
		{
		perror("malloc");
		exit(EXIT_FAILURE);
		}
			argv[0] = (char *)c;
			argv[1] = NULL;
			execve(c, argv, NULL);
			if (execve(c, argv, NULL) == -1)
			{
				perror("execve");
				exit(EXIT_FAILURE);
				free(argv); 
			}
			free(argv);
	}
	else
	{
		wait(NULL);
	}
}
