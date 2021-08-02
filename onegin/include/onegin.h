#include <stdio.h>


struct Text {
    FILE* file;
    int size;
};

int text_init(struct Text* text, const char* name);

int text_cleanup(struct Text* text);
