#include "shell.h"

int main(void)
{
	char cmd[1024];

    	while (1)
	{
		display_p();
		user_input(cmd, sizeof(cmd));
		execute(cmd);
	}
	return (0);
}
