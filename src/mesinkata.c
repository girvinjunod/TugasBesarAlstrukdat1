/* File: mesinkata.h */
/* Implementasi Mesin Kata */

#include <stdio.h>
#include "boolean.h"
#include "mesinkata.h"
#include "mesinkar.h"

/* State Mesin Kata */
boolean EndKata;
Kata CKata;

void IgnoreBlank(){
    while(CC == BLANK || CC == BLANK2){
        ADV();
    }
}

void CREATEEMPTYKATA(){
    int i;
    for (i=0;i<NMax;i++) CKata.TabKata[i]='\0'; 
}

void STARTKATAKEYBOARD(){
    CREATEEMPTYKATA();
    STARTKEYBOARD();
    IgnoreBlank();
    EndKata = false;
    if(CC == MARK){
        EndKata = true;
    }else{
        SalinKata();
    }
}

void STARTKATAFILE(char *namafile){
    CREATEEMPTYKATA();
    STARTFILE(namafile);
    IgnoreBlank();
    EndKata = false;
    if(CC == MARK){
        EndKata = true;
    }else{
        SalinKata();
    }
}

void ADVKATA(){
    CREATEEMPTYKATA();
    IgnoreBlank();
    if(CC == MARK){
        EndKata = true;
    }else{
        SalinKata();
        IgnoreBlank();
    }
}
void SalinKata(){
    int i=0;
    while(CC != BLANK && CC!= BLANK2 && CC != MARK && i<NMax){
        CKata.TabKata[i] = CC;
        i++;
        ADV();
    }
    CKata.Length = i;
}
int ToInt(Kata C){
    int result = 0;
    int add;
    for(int i=0; i<C.Length; i++){
        add = C.TabKata[i] - '0';
        result = result*10 + add;
    }
    return result;
}

boolean IsKataSama(Kata A, Kata B){
    boolean ret = A.Length == B.Length;
    if(ret){
        for(int i=0; i<A.Length; i++){
            ret = ret && (A.TabKata[i] == B.TabKata[i]);
        }
    }
    return ret;
}