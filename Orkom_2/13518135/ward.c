#include <stdio.h>

int func4(int a1, int a2, int a3){
    int v3; 
    int result;

    v3 = a2 + (a3 - a2) / 2;
    if (v3 > a1)
        return 2 * func4(a1, a2, v3 - 1);
    result = 0;
    if (v3 < a1)
        result = 2 * func4(a1, v3 + 1, a3) + 1;
    return result;
}

int main() {
    int Input1,Input2;

    scanf("%d %d",&Input1,&Input2);
    if (func4(Input1,0,14) != 3 || Input2 != 3) {
        bad_instruction();
        return 0;
    }
    return 1; // 1 jika jawaban benar
}

