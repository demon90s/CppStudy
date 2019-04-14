// Simple test of readline

#include <iostream>

#include "readline/readline.h"
#include "readline/history.h"

using namespace std;

int main(int argc, char** argv)
{
    char *line;
    while ((line = readline("> ")) != nullptr) {
        cout << "[" << line << "]" << endl; // echo
        if (*line) add_history(line);
        free(line);
    }
    printf("\n");

    return 0;
}