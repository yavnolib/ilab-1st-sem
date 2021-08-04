#include "onegin.h"
#include "../../liberror/errors-handling.h"
#include <assert.h>
#include <locale.h>

static const char* input_file = "tests/samples/test.txt";



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
    struct Text text;

    ret = test_init(input_file, &text, 43);
    assert(ret >= 0);

    ret = test_get_strings(&text, 3);
    assert(ret >= 0);

    struct String str1;
    struct String str2;

    str1.data = "... && ?? This a comparator test";
    str2.data = "?>   with whitespace and punctuation";
    ret = test_direct_comparator(&str1, &str2, -1);
    assert(ret >= 0);

    str1.data = "String test";
    str2.data = "String test";
    ret = test_direct_comparator(&str1, &str2, 0);
    assert(ret >= 0);

    str1.data = "Lesser string";
    str2.data = "Lesser;;;   but bigger";
    ret = test_direct_comparator(&str1, &str2, 1);
    assert(ret >= 0);



    return 0;
}




