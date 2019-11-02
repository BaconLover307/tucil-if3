#include <stdio.h>

int castle_gate() {
    int Input[6];
    for (int i=0; i<=5; i++) {
        scanf("%d",&Input[i]);
    }
    if (Input[0] < 0) {
        bad_instruction();
        return 0;
    }
    for (int i = 1; i <= 5; i++) {
        if (Input[i] != Input[i-1]+i) {
        bad_instruction();
        return 0;
        }
    }
    return 1; // 1 jika jawaban benar
}
