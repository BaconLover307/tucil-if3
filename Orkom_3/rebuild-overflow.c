#include <stdio.h>
#include <stdlib.h>
#include "jawaban.h"

unsigned int potion, explode, to_rubble, keep_destroying_phrase;
char token[12];
char jawaban[200];

/* void redacted_function() {
    redacted_body
} */

void destroy_drawbridge() {
    generate_jawaban(0, jawaban, token);
    fprintf(stdout, "%s\n", jawaban);
}

void destroy_castle_gate() {
    generate_jawaban(1, jawaban, token);
    fprintf(stdout, "%s\n", jawaban);
}

void destroy_castle_walls(unsigned int phrase) {
    if (phrase == 0 /*---NILAI ASLI REDACTED---*/) {
        generate_jawaban(2, jawaban, token);
        fprintf(stdout, "%s\n", jawaban);
    } else {
        fprintf(stdout, "Not strong enough to destroy castle walls...\n");
    }
}

void destroy_ward() {
    if (explode == 0 /*---NILAI ASLI REDACTED---*/ && to_rubble == 0 /*---NILAI ASLI REDACTED---*/) {
        generate_jawaban(3, jawaban, token);
        fprintf(stdout, "%s\n", jawaban);
    } else {
        fprintf(stdout, "Not strong enough to destroy the ward...\n");
    }
}

void destroy_keep() {
    if (keep_destroying_phrase == 0 /*---NILAI ASLI REDACTED---*/) {
        generate_jawaban(4, jawaban, token);
        fprintf(stdout, "%s\n", jawaban);
    } else {
        fprintf(stdout, "Not strong enough to destroy the keep...\n");
    }
}

void ekusupuroshion_magic() {
    volatile int local = potion;
    char buff[24];

    fprintf(stdout, "Your potion is 0x%08x\n", potion);
    fprintf(stdout, "Here is your ekusupuroshion_magic address %p\n", ekusupuroshion_magic);
    fprintf(stdout, "Here is your buffer address %p\n\n", buff);
    fprintf(stdout, "Your spell : ");
 
    gets(buff);
 
    if (local == 0 /*---NILAI ASLI REDACTED---*/){
        destroy_castle_gate();
        exit(0);
    } else if (local != potion) {
        destroy_drawbridge();
        exit(0);
    }
   	fprintf(stdout, "Nothing happens?\n");
}

int main(int argc, char const *argv[]){
    fprintf(stdout, "Your token : ");
    memset(token, 0, 12);
    fgets(token, 12, stdin);
    strncpy(token, strtok(token, "\n"), 10);

    /**********************************************
       Perhatikan bahwa potion yang dihasilkan
       di local machine kalian merupakan sebuah
       placeholder bernilai 0x12345678
   
       JANGAN gunakan potion tersebut dalam input
       kalian ke server. Gunakan potion yang
       DIHASILKAN KETIKA CONNECT KE BINARY SERVER.
       Potion yang dihasilkan oleh binary server tidak
       akan berubah kecuali ada pemberitahuan
       yang mengatakan hal lain. 
    ***********************************************/
    generate_potion(&potion, token);

    ekusupuroshion_magic();
    return 0;
}

