#include "onegin.h"
#include "../../liberror/errors-handling.h"
#include <assert.h>

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

    int text_size = 43;

    text->size = ftell(text->file);
    printf("Expected file size: %d\n", text_size);
    printf("File size counted with ftell: %d\n", text->size);
    if (text->size != text_size) {
        ERROR("text size invalid.");
        return -1;
    }

    return 0;

}