#include <stdio.h>
#include <stdlib.h>
#include "string.h"

int drawbridge() {
    char input[1000];
    int result;
    scanf("%s",&input);

    result = strings_not_equal(input, "A knight must never run away, no matter how mighty the enemy.");

    if (result) {
        bad_instruction();
        return 0;
    }
        return 1; // 1 jika jawaban benar
}