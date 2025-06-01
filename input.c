#ifndef INPUT_H
#define INPUT_H

#define MAX_INPUT 1024
#define MAX_ARGS 100

// Lit une ligne entrée par l'utilisateur
char* read_input();

// Découpe une ligne en arguments
char** parse_input(char* input);

#endif
