#include "shell.h"

/**
 * main - shell entry point
 * Return: Always 0
 */
int main(void)
{
    size_t i = 0;
    char *lineptr = NULL;
    char **args;
    ssize_t rc = 0;
    int r_status = 0;

    while (1)
    {
        if (isatty(STDIN_FILENO) == 1)
            write(STDOUT_FILENO, "$ ", 2);

        rc = getline(&lineptr, &i, stdin);
        if (rc == -1)
        {
            if (isatty(STDIN_FILENO) == 1)
                write(STDOUT_FILENO, "\n", 1);
            free(lineptr);
            break;
        }

        // Remove newline character from the input
        lineptr[strcspn(lineptr, "\n")] = '\0';

        if (_strcmp(lineptr, "exit") == 0)
        {
            free(lineptr);
            exit_sshell();
        }

        if (_strcmp(lineptr, "env") == 0)
        {
            free(lineptr);
            print_env();
        }

        args = split_tok(lineptr);
        if (args != NULL)
        {
            r_status = exec(args);
            free_args(args);
        }
        else
        {
            perror("Error");
        }

        free(lineptr);
    }
    return (r_status);
}

// Rest of the functions remain unchanged...
