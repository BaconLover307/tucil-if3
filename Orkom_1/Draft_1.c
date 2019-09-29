#include <stdio.h>

// $ #1
int itomori(int x, int y) {
    // ? return x xor y hanya menggunakan operator & dan ~
    // ? Contoh: itomori(4,5) = 1
    // ? Legal ops: ~ &
    // ? Max ops: 14
    // ? Rating: 1
    return (~(x&y)&~(~x&~y)); // Jawaban
    // ~(0000 0100 & 0000 0101) & ~(1111 1011 & 1111 1010)
    // 1111 1011 & 0000 0101
}

// $ #2
int tokyo(void) {
    // ? return Tmin ( nilai terkecil signed )
    // ? Legal ops: ! ~ & ^ | + << >>
    // ? Max ops: 4
    // ? Rating: 1
    int x = 0;
    return (~x)<<31;
} 

// $ #3
int musubi(int x, int n, int m) {
    // ? return tukar byte ke n dengan byte ke m
    // ?            0 <= n <= 3, 0 <= m <= 3
    // ? Contoh: musubi(0x12345678, 1, 3) = 0x56341278
    // ?         musubi(0xDEADBEEF, 0, 2) = 0xDEEFBEAD 
    // ? Legal ops: ! ~ & ^ | + << >>
    // ? Max ops: 25
    // ? Rating: 2
    int filter = 0xFF;
    int x_n = x >> (n<<3); 
    int x_m = x >> (m<<3); 
    int Fn = x_n & filter; 
    int Fm = x_m & filter; 
    int x_unswap = Fn<<(n<<3) | Fm<<(m<<3);
    int x_ori = x ^ x_unswap;
    int x_swap = Fn<<(m<<3) | Fm<<(n<<3);
    return x_ori | x_swap;
}

// $ #4
int kuchikamizake(int x) {
    // ? return 1 jika semua bit dengan posisi ganjil
    // ?          dalam satu word bernilai 1. Posisi 1 dihitung dari MSB
    // ? Contoh: kuchikamizake(0xFFFFFFFD) = 0
    // ?         kuchikamizake(0xAAAAAAAA) = 1
    // ? Legal ops: ! ~ & ^ | + << >>
    // ? Max ops: 12
    // ? Rating: 2

}
// $ #7
int koi(int x)
{
    // ? Kembalikan 1 jika x bukan nol menggunakan
    // ?  operator integer selain !
    // ?  Contoh: koi(3) = 1, koi(0) = 0
    // ?  Legal ops: ~ & ^ | + << >>
    // ?  Max ops: 10
    // ?  Rating: 4
    int hasil = ((x | (~x + 1)) >> 31) & 0x1 ;
    return hasil;
}

int main () {
    printf("=============================================================================================\n");
    int itomoriJ = itomori(4,5);
    printf("itomori\n");
    printf("=> %d\n",itomoriJ);

    printf("==============================================================================================\n");
    int tokyoJ = tokyo();
    printf("tokyo\n");
    printf("=> %d\n",tokyoJ);

    printf("==============================================================================================\n");
    int musubiJ = musubi(0x12345678,3,1);
    printf("musubi\n");
    printf("=> %x\n",musubiJ);

    printf("==============================================================================================\n");
    printf("kuchikamimaze\n");
    int Z4 = 1;
    
    
    printf("=> %d\n",Z4);
    
    printf("==============================================================================================\n");
    // ? return representasi bit untuk nilai absolute dari f.
    // ?  Argumen dan hasil fungsi memiliki tipe unsigned int, namun akan
    // ?  diinterpretasikan sebagai representasi bit dari floating-point
    // ?  single-precision.
    // ?  Kembalikan argumen jika argumen tersebut adalah NaN
    // ?  Legal ops: seluruh ops int/uns ditambah ||, &&, if, dan while
    // ?  Max ops: 10
    // ?  Rating: 2
    printf("katawaredoki\n");
    int Z5 = 5;



    printf("=> %d\n",Z5);

    printf("==============================================================================================\n");
    // ? balik urutan byte pada x
    // ?  Contoh: tessi
    // ?  diinterpretasikan sebagai representasi bit dari floating-point
    // ?  single-precision.
    // ?  Kembalikan argumen jika argumen tersebut adalah NaN
    // ?  Legal ops: seluruh ops int/uns ditambah ||, &&, if, dan while
    // ?  Max ops: 10
    // ?  Rating: 2
    printf("tessie\n");
    int x6 = 0x01020304;
    int filter6 = 0xFF;
    int x6_b3 = x6 >> (3<<3);
    int x6_b2 = x6 >> (2<<3);
    int x6_b1 = x6 >> (1<<3);
    int x6_B3 = x6_b3 & filter6;
    int x6_B2 = x6_b2 & filter6;
    int x6_B1 = x6_b1 & filter6;
    int x6_B0 = x6 & filter6;
    int B3 = x6_B0 << (3<<3);
    int B2 = x6_B1 << (2<<3);
    int B1 = x6_B2 << (1<<3);
    int B0 = x6_B3;
    int Z6 = B3 | B2 | B1 | B0;
    printf("=> %x\n",Z6);

    printf("==============================================================================================\n");
    // ? mengalikan x dengan 3/4 dibulatkan menuju 0,
    // ?  Hasil sesuai dengan ekspresi (x * 3/4) pada bahasa C,
    // ?  sehingga akan menghasilkan overflow jika bilangan
    // ?  terlalu besar saat dikalikan 3.
    // ?  Contoh: sayaka(11) = 8;
    // ?          sayaka(-9) = -6;
    // ?          sayaka(1073741824) = -268435456 (overflow);
    // ?  Max ops: 10
    // ?  Rating: 2
    printf("sayaka\n");
    int x7 = -6;
    int pembilang = (x7<<1) + x7;
    int isNegative = (pembilang>>31) & 3;
    int hasil = (isNegative + pembilang) >>2;
    int Z7 = hasil;
    printf("=> %d\n",Z7);


    printf("==============================================================================================\n");
    int koiJ = koi(-50);
    printf("koi\n");
    printf("=> %x\n",koiJ);



    return 0;
}


