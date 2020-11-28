//Driver_point


#include <stdio.h>
#include "point.h"
//#include "point.c"
#include "boolean.h"
#include <math.h>

int main(){
	POINT P1,P2;
	printf("baca P1\n");
	BacaPOINT(&P1);
	printf("P1 = "); TulisPOINT(P1);printf("\n");
	printf("\n");
	printf("baca P2\n");
	BacaPOINT(&P2);
	printf("P2 = "); TulisPOINT(P2);printf("\n");
	printf("\n");
	printf("EQ(P1,P2) = %d",EQ(P1,P2));
	printf("\n");	 
	printf("NEQ(P1,P2) = %d",NEQ(P1,P2));	 
	printf("\n");
	printf("IsOrigin(P1) = %d",IsOrigin(P1));
	printf("\n");
	printf("IsOnSbX(P1) = %d",IsOnSbX(P1));
	printf("\n");
	printf("IsOnSbY(P1) = %d",IsOnSbY(P1));
	printf("\n");
	printf("Kuadran(P1) = %d",Kuadran(P1));
	printf("\n");
	printf("P2 = NextX(P1)\n"); P2 = NextX(P1);
	printf("P1 = "); TulisPOINT(P1);printf("\n");
	printf("P2 = "); TulisPOINT(P2);printf("\n");
	printf("P2 = NextY(P1)\n"); P2 = NextY(P1);
	printf("P1 = "); TulisPOINT(P1);printf("\n");
	printf("P2 = "); TulisPOINT(P2);printf("\n");
	int X,Y;
	printf("X = ");scanf("%d",&X);
	printf("Y = ");scanf("%d",&Y);
	printf("P2 = PlusDelta(P1,X,Y)\n");
	P2 = PlusDelta(P1,X,Y);
	printf("P1 = "); TulisPOINT(P1);printf("\n");
	printf("P2 = "); TulisPOINT(P2);printf("\n");
	
	printf("P2 = MirrorOf(P1,1)\n");
	P2 = MirrorOf(P1,1);
	printf("P1 = "); TulisPOINT(P1);printf("\n");
	printf("P2 = "); TulisPOINT(P2);printf("\n");
	printf("P2 = MirrorOf(P1,0)\n");
	P2 = MirrorOf(P1,0);
	printf("P1 = "); TulisPOINT(P1);printf("\n");
	printf("P2 = "); TulisPOINT(P2);printf("\n");
	printf("Jarak0(P1) = %d\n",Jarak0(P1));
	printf("Panjang(P1,P2) = %d\n",Panjang(P1,P2));
	Geser(&P2,X,Y);
	printf("Geser (*P2,X,Y)\n");
	printf("P2 = "); TulisPOINT(P2);printf("\n");
	GeserKeSbX(&P2);
	printf("GeserKeSbX(*P2)\n");
	printf("P2 = "); TulisPOINT(P2);printf("\n");
	GeserKeSbY(&P2);
	printf("GeserKeSbY(*P2)\n");
	printf("P2 = "); TulisPOINT(P2);printf("\n");
	Putar(&P1,90);
	printf("Putar(*P1,90);\n");
	printf("P1 = "); TulisPOINT(P1);printf("\n");
	return 0;
}
