#include <stdio.h>
#include "point.h"
#include "boolean.h"
#include <math.h>

POINT MakePOINT (int X, int Y){
/* Membentuk sebuah POINT dari komponen-komponennya */
    POINT P;
    Absis(P) = X;
    Ordinat(P) = Y;
    return P;
}

/* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS  *** */
void BacaPOINT (POINT * P){
/* Membaca nilai absis dan ordinat dari keyboard dan membentuk
   POINT P berdasarkan dari nilai absis dan ordinat tersebut */
/* Komponen X dan Y dibaca dalam 1 baris, dipisahkan 1 buah spasi */
/* Contoh: 1 2
   akan membentuk POINT <1,2> */
/* I.S. Sembarang */
/* F.S. P terdefinisi */
    int x,y;
    scanf("%f",&x);
    scanf("%f",&y);
    * P = MakePOINT(x, y);
}
void TulisPOINT (POINT P){
/* Nilai P ditulis ke layar dengan format "(X,Y)"
   tanpa spasi, enter, atau karakter lain di depan, belakang,
   atau di antaranya
   Output X dan Y harus dituliskan dalam bilangan riil dengan 2 angka di belakang koma.
*/
/* I.S. P terdefinisi */
/* F.S. P tertulis di layar dengan format "(X,Y)" */
    int x,y;
    y = Ordinat(P);
    x = Absis(P);
    printf("(%.2f,%.2f)",x,y);
}

/* *** Kelompok operasi relasional terhadap POINT *** */
boolean EQ (POINT P1, POINT P2){
/* Mengirimkan true jika P1 = P2 : absis dan ordinatnya sama */
    int x1,y1,x2,y2;
    x1 = Absis(P1); y1 = Ordinat(P1);
    x2 = Absis(P2); y2 = Ordinat(P2);
    return (x1==x2 && y1==y2);
}
boolean NEQ (POINT P1, POINT P2){
/* Mengirimkan true jika P1 tidak sama dengan P2 */
    int x1,y1,x2,y2;
    x1 = Absis(P1); y1 = Ordinat(P1);
    x2 = Absis(P2) ; y2 = Ordinat(P2);
    return (x1!=x2 || y1!=y2);
}

/* *** Kelompok menentukan di mana P berada *** */
boolean IsOrigin (POINT P){
/* Menghasilkan true jika P adalah titik origin */
    int x,y;
    x = Absis(P); y = Ordinat(P);
    return (x==0 && y==0);
}
boolean IsOnSbX (POINT P){
/* Menghasilkan true jika P terletak Pada sumbu X */
    int y;
    y = Ordinat(P);
    return (y==0);
}
boolean IsOnSbY (POINT P){
/* Menghasilkan true jika P terletak pada sumbu Y */
    int x;
    x = Absis(P);
    return (x==0);
}
int Kuadran (POINT P){
/* Menghasilkan kuadran dari P: 1, 2, 3, atau 4 */
/* Prekondisi : P bukan titik origin, */
/*              dan P tidak terletak di salah satu sumbu */
    int x,y;
    int k;
    x = Absis(P); y = Ordinat(P);
    if (x>0 && y!=0){
        if (y>0){k = 1;}
        else {k = 4;}
    }else if (x<0 && y!=0){
        if (y>0){k = 2;}
        else {k = 3;}
    }else {k = -1;}
    return k;
}

/* *** KELOMPOK OPERASI LAIN TERHADAP TYPE *** */
POINT NextX (POINT P){
/* Mengirim salinan P dengan absis ditambah satu */
    int x,y;
    x = Absis(P); y = Ordinat(P);
    return(MakePOINT(x+1,y));
}
POINT NextY (POINT P){
/* Mengirim salinan P dengan ordinat ditambah satu */
    int x,y;
    x = Absis(P); y = Ordinat(P);
    return(MakePOINT(x,y+1));
}
POINT PlusDelta (POINT P, int deltaX, int deltaY){
/* Mengirim salinan P yang absisnya adalah Absis(P) + deltaX dan ordinatnya adalah Ordinat(P) + deltaY */
    int x,y;
    x = Absis(P); y = Ordinat(P);
    return(MakePOINT(x+deltaX,y+deltaY));
}
POINT MirrorOf (POINT P, boolean SbX){
/* Menghasilkan salinan P yang dicerminkan terhadap salah satu sumbu */
/* Jika SbX bernilai true, maka dicerminkan terhadap sumbu X */
/* Jika SbX bernilai false, maka dicerminkan terhadap sumbu Y */
    int x,y;
    x = Absis(P); y = Ordinat(P);
    if (SbX){
        return(MakePOINT(x,-y));
    }else {
        return(MakePOINT(-x,y));
    }
}
int Jarak0 (POINT P){
/* Menghitung jarak P ke (0,0) */
    int x,y;
    int dist;
    x = Absis(P); y = Ordinat(P);
    dist = sqrt(pow((x),2) + pow((y),2));
    return(dist);
}
int Panjang (POINT P1, POINT P2){
/* Menghitung jarak antara P1 dan P2 */
    int x1,y1,x2,y2,dist;
    x1 = Absis(P1); y1 = Ordinat(P1);
    x2 = Absis(P2) ; y2 = Ordinat(P2);

    dist = sqrt(pow((x1-x2),2) + pow((y1-y2),2));
    return (dist);
}
void Geser (POINT *P, int deltaX, int deltaY){
/* I.S. P terdefinisi */
/* F.S. P digeser, absisnya sebesar deltaX dan ordinatnya sebesar deltaY */
    Absis(*P) +=deltaX;
    Ordinat(*P) +=deltaY;
}
void GeserKeSbX (POINT *P){
/* I.S. P terdefinisi */
/* F.S. P berada pada sumbu X dengan absis sama dengan absis semula. */
/* Proses : P digeser ke sumbu X. */
/* Contoh : Jika koordinat semula (9,9), maka menjadi (9,0) */
    Ordinat(*P) = 0;
}
void GeserKeSbY (POINT *P){
/* I.S. P terdefinisi*/
/* F.S. P berada pada sumbu Y dengan ordinat yang sama dengan semula. */
/* Proses : P digeser ke sumbu Y. */
/* Contoh : Jika koordinat semula (9,9), maka menjadi (0,9) */
    Absis(*P) = 0;
}
void Mirror (POINT *P, boolean SbX){
/* I.S. P terdefinisi */
/* F.S. P dicerminkan tergantung nilai SbX atau SbY */
/* Jika SbX true maka dicerminkan terhadap sumbu X */
/* Jika SbX false maka dicerminkan terhadap sumbu Y */
    if (SbX == true){
        Ordinat(*P) = -1*Ordinat(*P);
    }
    else {
        Absis(*P) = -1*Absis(*P);
    }
}
void Putar (POINT *P, int Sudut){
/* I.S. P terdefinisi */
/* F.S. P digeser sebesar Sudut derajat dengan sumbu titik (0,0) searah jarum jam*/
    const int convertRad=acos(-1)/180;
    int x,y,newx,newy,sudutRad;
    x = Absis(*P); y = Ordinat(*P); sudutRad = -Sudut*convertRad;
    newx = (cos(sudutRad)*x)-(sin(sudutRad)*y);
    newy = (sin(sudutRad)*x)+(cos(sudutRad)*y);
    Absis(*P)=newx;
    Ordinat(*P)=newy;
}
