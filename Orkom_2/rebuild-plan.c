#include <stdio.h>
#include <stdlib.h>
#include "support.h"
#include "phases.h"

FILE *infile;

int main(int argc, char *argv[]){
    
    char *input;
    
    if (argc == 1) {  
	    infile = stdin;
    } 

    /* Saat dijalankan dengan argumen berupa file, program akan membaca file sampai
    	EOF, kemudian akan membaca dari standar input. Jadi, setiap sudah berhasil menyelesaikan
    	satu level, password untuk memecahkan level tersebut dapat ditaruh ke dalam suatu file 
    	dan dapat menghindari untuk mengetik ulang */
    else if (argc == 2) {
        if (!(infile = fopen(argv[1], "r"))) {
            printf("%s: Error: Couldn't open %s\n", argv[0], argv[1]);
            exit(8);
        }
    }

    else {
        printf("Usage: %s [<input_file>]\n", argv[0]);
        exit(8);
    }

    
    chant_magic();

    printf("Welcome general, there are 6 major sections that needs to be repaired. We wish you best of luck.\n");
    
    input = read_line();             
    drawbridge(input);                  
    sector_repaired();
    printf("The drawbridge has been repaired. On to the next one, general.\n");

    
    input = read_line();
    castle_gate(input);
    sector_repaired();
    printf("The gate is now fully functional. Well done, general. The next section awaits.\n");

    
    input = read_line();
    castle_walls(input);
    sector_repaired();
    printf("The walls are looking sturdier than ever, general. How about the next section?\n");

    
    input = read_line();
    ward(input);
    sector_repaired();
    printf("Reparation of the castle ward is done. Start working on the next one, general.\n");
    
    
    input = read_line();
    keep(input);
    sector_repaired();
    printf("The keep looks even better than before. Can you fix the last section, general?\n");

    
    input = read_line();
    throne_room(input);
    sector_repaired();
    printf("The castle is fully repaired. We expect nothing less from you, general.\n");
    printf("By the way, some troops were talking about a treasure chamber hidden within the castle. Were you able to find it?");

    return 0;
}
