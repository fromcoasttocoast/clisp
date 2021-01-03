#include <stdio.h>
#include <stdlib.h>

/* If we are compiling on Windows compile these functions */
#ifdef _WIN32
#include <string.h>

char str1[128] = "You are working under Windows\n";
static char buffer[2048];

/* Fake readline function */
char* readline(char* prompt) {
    fputs(prompt, stdout);
    fgets(buffer, 2048, stdin);
    char* cpy = malloc(strlen(buffer) + 1);
    strcpy(cpy, buffer);
    cpy[strlen(cpy) - 1] = '\0';
    return cpy;
}

/* Fake add_history function */
void add_history(char* unused) {}

/* Otherwise include the editline headers */
#elif defined __gnu_linux__
#include <editline/readline.h>
#include <editline/history.h>
char str1[128] = "You are working under Linux\n";
#endif

int main(int argc, char** argv) {

    puts("Lispy Version 0.0.0.0.1");
    puts("Press Ctrl+c to Exit");
    puts(str1);

    while (1) {

        /* Now in either case readline will be correctly defined */
        char* input = readline("lispy> ");
        add_history(input);

        printf("No you're a %s\n", input);
        free(input);

    }

    return 0;
}