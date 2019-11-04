/* Nama     : Gregorius Jovan Kresnadi */
/* NIM      : 13518135 */
/* Kelas    : K-03 */
/* Tangal   : 3 November 2019 */
/* File     : PP01_13518135.pl */


/* ########## Bagian I : INTRODUCTION TO PROLOG ########## */
/* --- Deklarasi Fakta --- */
% a. pria(X) : X adalah pria
pria(jito).
pria(abiyyu).
pria(om_lutfi).
pria(mamet_rojab).
pria(bowo).
pria(ihsan).
pria(arden).
pria(lil_tude).
pria(ipul).

% b. wanita(X) : X adalah wanita
wanita(jeremy).
wanita(juri_sutantri).
wanita(emily).
wanita(rias_gremory).
wanita(audy).

% c. usia(X,Y) : X berusia Y
usia(jito,71).
usia(abiyyu,56).
usia(om_lutfi,58).
usia(mamet_rojab,24).
usia(bowo,30).
usia(ihsan,32).
usia(arden,28).
usia(lil_tude,14).
usia(ipul,8).
usia(jeremy,69).
usia(juri_sutantri,42).
usia(emily,40).
usia(rias_gremory,26).
usia(audy,24).

% d. menikah(X,Y) : X menikah dengan Y
menikah(jito,jeremy).
menikah(jeremy,jito).
menikah(abiyyu,juri_sutantri).
menikah(juri_sutantri,abiyyu).
menikah(om_lutfi,emily).
menikah(emily,om_lutfi).
menikah(ihsan,rias_gremory).
menikah(rias_gremory,ihsan).
menikah(arden,audy).
menikah(audy,arden).

% e. anak(X,Y) : X adalah anak Y
anak(mamet_rojab,jito).
anak(mamet_rojab,jeremy).
anak(bowo,jito).
anak(bowo,jeremy).
anak(ihsan,jito).
anak(ihsan,jeremy).
anak(rias_gremory,abiyyu).
anak(rias_gremory,juri_sutantri).
anak(arden,abiyyu).
anak(arden,juri_sutantri).
anak(audy,om_lutfi).
anak(audy,emily).
anak(lil_tude,ihsan).
anak(lil_tude,rias_gremory).
anak(ipul,arden).
anak(ipul,audy).

% f. saudara(X,Y) : X adalah saudara kandung Y
saudara(mamet_rojab,bowo).
saudara(mamet_rojab,ihsan).
saudara(bowo,mamet_rojab).
saudara(bowo,ihsan).
saudara(ihsan,mamet_rojab).
saudara(ihsan,bowo).
saudara(rias_gremory,arden).
saudara(arden,rias_gremory).

/* --- Deklarasi Rules --- */

% a. kakak(X,Y) : X adalah kakak dari Y (baik perempuan maupun lelaki)
kakak(X,Y)     :- saudara(X,Y), usia(X,A), usia(Y,B), A > B.
% b. keponakan(X,Y) : X adalah keponakan dari Y
keponakan(X,Y) :- anak(X,A), saudara(A,Y).
% c. suami(X,Y) : X adalah suami dari Y
suami(X,Y)     :- menikah(X,Y), pria(X).
% d. sepupu(X,Y) : X adalah sepupu dari Y
sepupu(X,Y)    :- anak(X,A), anak(Y,B), saudara(A,B).
% e. mertua(X,Y) : X adalah mertua dari Y
mertua(X,Y)    :- menikah(Y,A), anak(A,X).
% f. bibi(X,Y) : X adalah bibi dari Y
bibi(X,Y)      :- keponakan(Y,X), wanita(X).
% g. cucu(X,Y) : X adalah cucu dari Y
cucu(X,Y)      :- anak(X,A), anak(A,Y).
% h. anaksulung(X) : X adalah anak paling tua
anaksulung(X)  :- anak(X,A), pria(A), usia(X,B), \+ (saudara(X,Y), usia(Y,C), C>B).
% i. anakbungsu(X) : X adalah anak paling muda
anakbungsu(X)  :- anak(X,A), pria(A), usia(X,B), \+ (saudara(X,Y), usia(Y,C), C<B).
 

/* ########## Bagian II : REKURSIF ########## */

/* --- Deklarasi Rules --- */

% a. fibbonaci(N,X) : bilangan fibbonaci ke N adalah X dengan ketentuan N>=1.
fibbonaci(1,1).
fibbonaci(2,1).
fibbonaci(N,X) :-
    N >= 1,
    A is N-1, B is N-2,
    fibbonaci(A,C),
    fibbonaci(B,D),
    X is C+D. 

% b. gcd(A,B,X) : X adalah greatest common divider dari A dan B
gcd(A,0,A).
gcd(A,B,X) :-
    R is mod(A,B),
    gcd(B,R,X). 

% c. power(A,B,X) : X adalah hasil dari A dipangkatkan dengan B.
power(_, 0, 1).
power(A, 1, X) :- X is A.
power(A, B, X) :-
    0 is mod(B,2),
    B1 is div(B,2),
    power(A,B1,X1),
    X is X1 * X1.
power(A, B, X) :-
    1 is mod(B,2),
    B1 is div(B,2),
    power(A,B1,X1),
    X is X1 * X1 * A.


/* ########## Bagian III : LIST ########## */

/* --- Deklarasi Rules --- */

% a. inverse(A,B) : A dan B merupakan sebuah list yang berisi beberapa angka nilai
% rules akan bernilai yes jika A merupakan kebalikan dari list B dan no jika tidak.
inverse([],[]) :- !.
inverse(A,B) :- 
    reverse(B,BR),
    [HA | TA] = A,
    [HB | TB] = BR,
    reverse(TB,BB),
    HA =:= HB,
    inverse(TA,BB).

% b. insert(X,Y,Z) : terdapat sebuah list X dan sebuah angka Y. Z merupakan sebuah
% list yang bernilai sama dengan X jika angka Y sudah terdapat pada list X. Jika
% angka Y tidak terdapat di list X maka Z bernilai sama dengan list X yang telah
% di insert angka Y. 
insert(X,Y,Z) :-
    member(Y,X),
    append(X,[],Z).
insert(X,Y,Z) :-
    append(X,[Y],Z).


% c. dotProduct(X,Y,Result) : Implementasikan rule untuk dot product. Antar list X
% dan Y dengan ukuran list X dan Y pasti sama. Hasilnya disimpan pada Result.
dotProduct([],[],Result) :-
    Result is 0, !.
dotProduct(X,Y,Result) :-
    [HX | TX] = X,
    [HY | TY] = Y,
    dotProduct(TX,TY,Result1),
    Result is Result1 + HX * HY.

% d. countX(L,X,N) : Rule ini menghitung jumlah elemen list L yang bernilai X.
% Hasilnya akan disimpan di N.
countX([],_,0) :- !.
countX([H|T],X,N) :-
    H is X,
    countX(T,X,N1),
    N is N1+1.
countX([H|T],X,N) :-
    countX(T,X,N).
    
% e. palindrom(L) : Rule digunakan untuk mengecek apakah sebuah list yaitu list L
% palindrom atau tidak
palindrom([]) :- !.
palindrom(X) :- 
    length(X,1), !.
palindrom(L) :-
    [HL | TL] = L,
    reverse(TL,LR),
    [HLR | TLR] = LR,
    HL =:= HLR,
    palindrom(TLR).
