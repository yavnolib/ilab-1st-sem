#include "onegin.h"
#include "../../liberror/errors-handling.h"

static const char* input_file = "tests/samples/test-1.txt";


int test_init(const char* name) {
    struct Text text;
    int res = text_init(&text, name);
    if (res < 0) {
        ERROR("failed to init text.\n");
        return -1;
    }
    return 0;
}

int main() {
    test_init(input_file);
    return 0;
}