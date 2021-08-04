#include "onegin.h"
#include "../../liberror/errors-handling.h"
#include <assert.h>
#include <locale.h>

static const char* input_file_1 = "tests/samples/test-1.txt";
static const char* input_file_2 = "tests/samples/test-2.txt";


//======================================================================
int test_init(const char* name, struct Text* text, int text_size) {
    printf("TEST: INITIALIZING TEXT\n");
    int res = text_init(text, name);
    if (res < 0) {
        ERROR("failed to init text.\n");
        return -1;
    }

    printf("Expected file size: %d\n", text_size);
    printf("File size counted with ftell: %d\n", text->size);
    if (text->size != text_size) {
        ERROR("text size invalid.");
        return -1;
    }

    printf("TEST: INITIALIZING TEXT: SUCCESS\n");
    return 0;
}

//======================================================================
int test_get_strings(struct Text* text, int strings_count) {
    printf("TEST: GET STRINGS FROM TEXT\n");
    text_get_strings(text);
    if (text->strings_count != strings_count) {
        ERROR("expected string size: %d, but counted: %d", strings_count, text->strings_count);
    }
    text_print_strings(text);
    printf("TEST: GET STRINGS FROM TEXT: SUCCESS\n");
    return 0;
}


//======================================================================
int test_direct_comparator(struct String* lhs, struct String* rhs, int ret_val) {
    printf("TEST: DIRECT COMPARATOR TEST\n");
    assert(lhs);
    assert(rhs);

    int ret = direct_comparator(lhs, rhs);
    if (ret != ret_val) {
        ERROR("comparator failure, returned: %d", ret);
        return -1;
    }
    printf("TEST: DIRECT COMPARATOR TEST: SUCCESS\n");
    return 0;
}



int main() {
    setlocale(LC_ALL, "ru_RU.cp1251");

    int ret = 0;
    struct Text text_1;
    ret = test_init(input_file_1, &text_1, 43);
    assert(ret >= 0);
    ret = test_get_strings(&text_1, 3);
    assert(ret >= 0);

    struct Text text_2;
    ret = test_init(input_file_2, &text_2, 86);
    assert(ret >= 0);
    ret = test_get_strings(&text_2, 3);
    assert(ret >= 0);
    ret = test_direct_comparator(&text_2.strings[0], &text_2.strings[1], -1);
    assert(ret >= 0);

    return 0;
}




