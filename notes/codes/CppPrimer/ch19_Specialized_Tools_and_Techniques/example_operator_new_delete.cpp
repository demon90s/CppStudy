#include "example_operator_new_delete.h"

int main()
{
    char *cp = new char('A');
    delete cp;

    char *carr = new char[12]{};
    delete[] carr;

    return 0;
}