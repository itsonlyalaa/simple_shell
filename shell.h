#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/**
 * functions used in the shell project
*/

void display_p(void);
void print_p(const char *text);
void user_input(char *cmd, size_t size);

#endif