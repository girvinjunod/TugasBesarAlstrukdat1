//driver_matriks

#include <stdio.h>
#include "matriks.h"
//#include "matriks.c"
#include "boolean.h"
#include <math.h>

int main(){
	MATRIKS M;
	int X,Y;
	printf("X = ");
	scanf("%d",&X);
	printf("Y = ");
	scanf("%d",&Y);
	printf("MakeMATRIKS (X,Y,&M)\n");
	MakeMATRIKS (X,Y,&M);
	printf("BacaMATRIKS (&M,X,Y);\n");
	BacaMATRIKS (&M,X,Y);
	printf("TulisMATRIKS (M);\n");
	TulisMATRIKS (M);
	printf("\n");
	int i,j;
	printf("i = ");
	scanf("%d",&i);
	printf("j = ");
	scanf("%d",&j);
	printf(" IsIdxValid(i, j) = %d\n", IsIdxValid(i, j));
	printf(" IsIdxEff (MATRIKS M, indeks i, indeks j) = %d\n", IsIdxValid(i, j));
	
	printf("GetFirstIdxBrs (M) = %d\n", GetFirstIdxBrs (M));
	printf("GetFirstIdxKol (M) = %d\n", GetFirstIdxKol (M));
	printf("GetLastIdxBrs (M) = %d\n", GetLastIdxBrs (M));
	printf("GetLastIdxKol (M) = %d\n", GetLastIdxKol (M));
	int k;
	printf("k = ");
	scanf("%d",&k);
	printf("GetElmtDiagonal (M, k) = %d\n", GetElmtDiagonal (M, k));
	MATRIKS MH;
	
	printf("CopyMATRIKS (M, &MH)\n");
	CopyMATRIKS (M, &MH);
	printf("TulisMATRIKS (MH);\n");
	TulisMATRIKS (MH);
	printf("\n");
	MATRIKS M3;
	printf("M3 = TambahMATRIKS (M,MH);\n");
	M3 = TambahMATRIKS (M,MH);
	printf("TulisMATRIKS (M3);\n");
	TulisMATRIKS (M3);
	printf("\n");
	printf("M3 = KurangMATRIKS (M,MH);\n");
	M3 = KurangMATRIKS (M,MH);
	printf("TulisMATRIKS (M3);\n");
	TulisMATRIKS (M3);
	printf("\n");
	printf("M3 = KaliMATRIKS (M,MH);\n");
	M3 = KaliMATRIKS (M,MH);
	printf("TulisMATRIKS (M3);\n");
	TulisMATRIKS (M3);
	printf("\n");
	int a;
	printf("a = ");
	scanf("%d",&a);
	printf("M3 = KaliKons (M,a);\n");
	M3 = KaliKons (M,a);
	printf("TulisMATRIKS (M3);\n");
	TulisMATRIKS (M3);
	printf("\n");
	printf("PKaliKons (&M3,a)\n");
	PKaliKons (&M3,a);
	printf("TulisMATRIKS (M3);\n");
	TulisMATRIKS (M3);
	printf("\n");

	printf("EQ (M,M3) = %d\n",EQ (M, M3));
	printf("NEQ (M,M3) = %d\n",NEQ (M, M3));
	printf("EQSize (M,M3) = %d\n",EQSize (M, M3));
	printf("NBElmt (M) = %d\n",NBElmt (M));
	printf("IsBujurSangkar (M) = %d\n",IsBujurSangkar (M));
	printf("IsSimetri (M) = %d\n",IsSimetri (M));
	printf("IsSatuan (M) = %d\n",IsSatuan (M));
	printf("IsSparse (M) = %d\n",IsSparse (M));
	
	printf("M3 = Inverse1 (M);\n");
	M3 = Inverse1 (M);
	printf("TulisMATRIKS (M3);\n");
	TulisMATRIKS (M3);printf("\n");
	
	printf("Determinan (M) = %f\n",Determinan (M));
	
	
	printf("PInverse1 (&M3)\n");
	PInverse1 (&M3);
	printf("TulisMATRIKS (M3);\n");
	TulisMATRIKS (M3);
	printf("\n");
	
	printf("Transpose (&M3)\n");
	Transpose (&M3);
	printf("TulisMATRIKS (M3);\n");
	TulisMATRIKS (M3);printf("\n");
	
	printf("i = ");scanf("%d",&i);
	printf("RataBrs (M,i) = %f\n", RataBrs (M,i));
	printf("RataKol (M,i) = %f\n", RataKol (M,i));
	int max,min;
	printf("MaxMinBrs(M,i,&max,&min);\n");
	MaxMinBrs(M,i,&max,&min);
	printf("max = %d\n",max);
	printf("min = %d\n",min);
	
	printf("MaxMinKol(M,i,&max,&min);\n");
	MaxMinKol(M,i,&max,&min);
	printf("max = %d\n",max);
	printf("min = %d\n",min);
	int C;
	printf("C = ");
	scanf("%d",&C);
	printf("CountXBrs (M, i, C) = %d\n", CountXBrs (M, i, C));
	printf("CountXKol (M, i, C) = %d\n", CountXKol (M, i, C));
	return 0;
}
