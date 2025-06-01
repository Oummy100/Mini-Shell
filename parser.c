#include <stdlib.h>
#include <string.h>
#include "parser.h"

#define MAX_ARGS 64

char **parse_input(char *line) {
    char **args = malloc(MAX_ARGS * sizeof(char *));
    int i = 0;
    char *token = strtok(line, " ");

    while (token != NULL && i < MAX_ARGS - 1) {
        args[i++] = strdup(token);
        token = strtok(NULL, " ");
    }
    args[i] = NULL;
    return args;
}

void free_args(char **args) {
    for (int i = 0; args[i]; i++) {
        free(args[i]);
    }
    free(args);
}
