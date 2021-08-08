#include <stdio.h>


struct Text {
    FILE* file;
    int size;
    char* buffer;

    struct String* strings;
    int strings_count;
};

struct String {
    char* data;
    int size;
};

typedef int (*comparator)(const void*, const void*);

//======================================================================
int text_init(struct Text* text, const char* name);

//======================================================================
int text_cleanup(struct Text* text);

//======================================================================
int text_get_strings(struct Text* text);

//======================================================================
void text_print_strings(struct Text* text);

//======================================================================
void text_sort(struct Text* text, comparator comp);

//======================================================================
int direct_comparator(const void* lhs, const void* rhs);

//======================================================================
int sort(struct Text* text, comparator comp);









