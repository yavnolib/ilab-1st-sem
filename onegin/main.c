#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include "../liberror/errors-handling.h"

/* TODO:
1) Write a logger instead of printfs
2) Add list of errors
3) Upddate make with VPATH */
int main() {
    setlocale(LC_ALL, "ru_RU.cp1251");
    return 0;
}