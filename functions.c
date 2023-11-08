#include "shell.h"
/**
 * print_p - prints texts to the screen
 * @text : the text we want to print to the stdout
 * Return : void no return value
*/

void print_p(const char *text)
{
	write(STDOUT_FILENO, text, strlen(text));
}

/**
 * display_p - display the prompt on the screen
 * Return : void no return value
*/

void display_p(void)
{
	print_p("($) ");
}

/**
 * user_input - function for the user to type commands
 * @cmd: thw user input
 * @size: the size of the command
 * Return : void no return value
*/

void user_input(char *cmd, size_t size)
{
	if (fgets(cmd, size, stdin) == NULL)
	{
	if (feof(stdin))
	{
		print_p("\n");
		exit(EXIT_SUCCESS);
	}
	else
	{
		print_p("Error: not found\n");
		exit(EXIT_FAILURE);
	}
	}
	cmd[strcspn(cmd, "/n")] = '\0';
}
