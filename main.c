#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"
#include "executor.h"
#include "builtins.h"

int main() {
    char *line = NULL;
    size_t len = 0;
    char **args;

    while (1) {
        printf("minishell$ ");
        if (getline(&line, &len, stdin) == -1) {
            perror("getline");
            break;
        }

        // Supprimer le saut de ligne
        line[strcspn(line, "\n")] = '\0';

        args = parse_input(line);

        if (args[0] == NULL) {
            free_args(args);
            continue;
        }

        if (!handle_builtin(args)) {
            execute_command(args);
        }

        free_args(args);
    }

    free(line);
    return 0;
}
