#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "builtins.h"

int handle_builtin(char **args) {
    if (strcmp(args[0], "exit") == 0) {
        exit(0);
    } else if (strcmp(args[0], "cd") == 0) {
        if (args[1] == NULL) {
            fprintf(stderr, "cd: chemin manquant\n");
        } else if (chdir(args[1]) != 0) {
            perror("cd");
        }
        return 1;
    } else if (strcmp(args[0], "help") == 0) {
        printf("Commandes internes : cd, exit, help\n");
        return 1;
    }

    return 0; // pas une commande interne
}
