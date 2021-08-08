#include "onegin.h"
#include "../../liberror/errors-handling.h"
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>

//======================================================================
int text_init(struct Text* text, const char* name) {

    int ret = 0;
    assert(text != NULL);
    assert(name != NULL);

    text->file = fopen(name, "r");
    if (text->file == NULL) {
        ERROR("could not open file %s", name);
        return -1;
    }

    ret = fseek(text->file, 0, SEEK_END);
    if (ret != 0) {
        ERROR("failed to find end of file.");
        return -1;
    }
    text->size = ftell(text->file);

    text->buffer = (char*) calloc(text->size, sizeof(char));
    assert(text->buffer);

    // should check errno, no return value
    rewind(text->file);

    ret = fread(text->buffer, sizeof(char), text->size, text->file);
    if (ret != text->size) {
        ERROR("could not read data from file.");
        return -1;
    }

    return 0;
}

//======================================================================
int text_cleanup(struct Text* text) {
    assert(text != NULL);
    assert(text->file != NULL);
    fclose(text->file);
    free(text->buffer);
    return 0;
}


//======================================================================
void text_print_strings(struct Text* text) {
    for (int i = 0; i < text->strings_count; ++i) {
        printf("String[%d] = %s\n", i, text->strings[i].data);
    }
}

//======================================================================
int text_get_strings(struct Text* text) {
    assert(text != NULL);
    char* current_position = text->buffer;
    char* previous_position = NULL;
    int strings_count = 0;

    while ((current_position = strchr(current_position, '\n')) != NULL) {
        *current_position = '\0';
        current_position++;
        strings_count++;
    }

    struct String* strings = (struct String*) calloc(strings_count, sizeof(struct String));
    if (strings == NULL) {
        ERROR("could not allocate %d strings.", strings_count);
    }
    text->strings_count = strings_count;
    text->strings = strings;

    current_position = text->buffer;
    previous_position = text->buffer;
    int string_size = 0;
    int strings_index = 0;

   for (int i = 0; i < text->strings_count; ++i) {
        current_position = strchr(current_position, '\0');
        string_size = current_position - previous_position;
        current_position++;
        strings[strings_index].size = string_size;
        strings[strings_index].data = previous_position;
        strings[strings_index].size = string_size;
        strings_index++;
        previous_position = current_position;
    }

    return 0;
}

//======================================================================
int is_whitespace(char symbol) {
    if (isspace(symbol) || ispunct(symbol) || isdigit(symbol)) {
        return 1;
    } else if (isalpha(symbol) || isalnum(symbol)) {
        return 0;
    } else {
        ERROR("No character recognized");
        return -1;
    }
}

//======================================================================
int direct_comparator(const void* lhs, const void* rhs) {
    struct String* str1 = (struct String*) lhs;
    struct String* str2 = (struct String*) rhs;

    char* pos1 = str1->data;
    char* pos2 = str2->data;
    int char_status_lhs = 0;
    int char_status_rhs = 0;

    while (*pos1 != '\0' && *pos2 != '\0') {
        char_status_lhs = is_whitespace(*pos1);
        if (char_status_lhs == 1) {
            ++pos1;
        }
        char_status_rhs = is_whitespace(*pos2);
        if (char_status_rhs == 1) {
            ++pos2;
        }

        if (*pos1 == *pos2 && char_status_rhs == 0 && char_status_lhs == 0) {
            ++pos1;
            ++pos2;
            continue;
        }

        if (char_status_lhs == 0 && char_status_rhs == 0 && *pos1 != *pos2) {
            return *pos1 < *pos2 ? -1 : 1;
        }
    }
    return 0;
}

//======================================================================
int sort(struct Text* text, comparator comp) {
    qsort(text->strings, text->strings_count, sizeof(struct String), comp);
    text_print_strings(text);
    return 0;
}








