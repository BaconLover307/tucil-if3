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
    int odd1 = 0xAA;
    int odd2 = (odd1 | (odd1 << 8));
    int odd3 = (odd2 | (odd2 << 16));
    int check1 = odd3 & x;
    int check2 = check1 ^ odd3;
    return (!check2);
}
// $ #5
unsigned katawaredoki(unsigned uf) {
    // ? return representasi bit untuk nilai absolute dari f.
    // ?  Argumen dan hasil fungsi memiliki tipe unsigned int, namun akan
    // ?  diinterpretasikan sebagai representasi bit dari floating-point
    // ?  single-precision.
    // ?  Kembalikan argumen jika argumen tersebut adalah NaN
    // ?  Legal ops: seluruh ops int/uns ditambah ||, &&, if, dan while
    // ?  Max ops: 10
    // ?  Rating: 2
    unsigned iris = 0x7FFFFFFF & uf;
    if (iris >= 0x7F800001)
        return uf;
    else
        return iris;
}

// $ #6
int tessie(int x) {
    // ? balik urutan byte pada x
    // ?  Contoh: tessi(0x01020304) = 0x04030201
    // ?  Legal ops: ! ~ & ^ | + << >>
    // ?  Max ops: 25
    // ?  Rating: 3

    int cut = 0xFF;
    int b0 = x >> (3<<3);
    int b1 = x >> (2<<3);
    int b2 = x >> (1<<3);
    int byte0 = b0 & cut;
    int byte1 = (b1 & cut) << 8;
    int byte2 = (b2 & cut) << 26;
    int byte3 = (x  & cut) << 24;
    return (byte3 | byte2 | byte1 | byte0);
}
//$ #7
int sayaka(int x) {
    // ? mengalikan x dengan 3/4 dibulatkan menuju 0,
    // ?  Hasil sesuai dengan ekspresi (x * 3/4) pada bahasa C,
    // ?  sehingga akan menghasilkan overflow jika bilangan
    // ?  terlalu besar saat dikalikan 3.
    // ?  Contoh: sayaka(11) = 8;
    // ?          sayaka(-9) = -6;
    // ?          sayaka(1073741824) = -268435456 (overflow);
    // ?  Max ops: 10
    // ?  Rating: 2
    int pembilang = (x<<1) + x;
    int isNegative = (pembilang>>31) & 3;
    return (isNegative + pembilang) >>2;
}

// $ #8
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
// $ #9
int mitsuha(int x)
{
    // ? 
    // ?  
    // ?  
    // ?  Legal ops: ~ & ^ | + << >>
    // ?  Max ops: 20
    // ?  Rating: 4
    int hasil = ((x | (~x + 1)) >> 31) & 0x1 ;
    return hasil;
}
// $ #10
int taki(int x)
{
    // ? 
    // ? 
    // ? 
    // ? Legal ops: ~ & ^ | + << >>
    // ? Max ops: 10
    // ? Rating: 4
    int hasil = ((x | (~x + 1)) >> 31) & 0x1 ;
    return hasil;
}

int main () {
    printf("=============================================================================================\n");
    int x = 15;
    int y = x >> 3;
    printf("%d\n",y);
    int z = y<<3;
    printf("%d\n",z);
/*
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
    
    int kuchikamimazeJ = kuchikamimaze(0xFFFFFFFD);
    printf("kuchikamimaze\n");
    printf("=> %d\n",kuchikamimazeJ);
    
    printf("==============================================================================================\n");
    //int katawaredokiJ = katawaredoki();
    printf("katawaredoki\n");
    //printf("=> %d\n",katawaredokiJ);

    printf("==============================================================================================\n");
    
    int tessieJ = tessie(0x01020304);
    printf("tessie\n");
    printf("=> %x\n",tessieJ);

    printf("==============================================================================================\n");
    int sayakaJ = sayaka(-9);
    printf("sayaka\n");
    printf("=> %d\n",sayakaJ);


    printf("==============================================================================================\n");
    
    int koiJ = koi(-50);
    printf("koi\n");
    printf("=> %x\n",koiJ);

    printf("==============================================================================================\n");
    
    //int mitsuhaJ = mitsuha(-50);
    printf("mitsuha\n");
    //printf("=> %x\n",mitsuhaJ);

    printf("==============================================================================================\n");
    
    //int takiJ = taki();
    printf("taki\n");
    //printf("=> %x\n",takiJ);
*/
    return 0;
}


