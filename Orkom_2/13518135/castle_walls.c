#include <stdio.h>

int castle_walls() {
    signed int v1,v2, v3, v4, v5, v6, v7, v8;
    int Inp1,Inp2;
    scanf("%d %d",&Inp1,&Inp2);
    switch (Inp1)
    {
    case 0:
        v1 = 787;
        goto LABEL_1;
    case 1:
        v1 = 0;
    LABEL_1:
        v2 = v1 - 162;
        goto LABEL_2;
    case 2:
        v2 = 0;
    LABEL_2:
        v3 = v2 + 304;
        goto LABEL_3;
    case 3:
        v3 = 0;
    LABEL_3:
        v4 = v3 - 936;
        goto LABEL_4;
    case 4:
        v4 = 0;
    LABEL_4:
        v5 = v4 + 936;
        goto LABEL_5;
    case 5:
        v5 = 0;
    LABEL_5:
        v6 = v5 - 936;
        goto LABEL_6;
    case 6:
        v6 = 0;
    LABEL_6:
        v7 = v6 + 936;
        break;
    case 7:
        v7 = 0;
        break;
    default:
        bad_instruction();
        return 0;
    }
    v8 = v7 - 936;
    if (Inp1 > 5 || Inp2 != v8) {
        bad_instruction();
        return 0;
    }
    return 1; // 1 jika jawaban benar
}