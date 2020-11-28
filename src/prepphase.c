#include <stdio.h>
#include "prepphase.h"

void ShowPrepPhaseState(JAM cur_JAM, JAM END_JAM){
	/* I.S.: sembarang
	 * F.S.: map, legend, dan state prep. phase tercetak
	 */
	/* KAMUS LOKAL */
	JAM diff;
	/* ALGORITMA */
	/* ngeprint area map sekarang somehow, WIP */
	/* print legend */
	printf("Legend:\nA = Antrian\nP = Player\nW = Wahana\nO = Office\n< ^ > V = Gerbang\n");
	printf("\n");
	/* print state prep. phase */
	printf("Name: \n"); /* belum tau name disimpen di mana, WIP */
	printf("Money: \n"); /* belum tau money disimpen di mana, WIP */
	printf("Current Time: \n"); TulisJAM(cur_JAM); printf("\n");
	printf("Opening Time: \n"); TulisJAM(END_JAM); printf("\n");
	diff = DetikToJAM(Durasi(cur_JAM,END_JAM));
	printf("Time Remaining: %d hour(s) %d minute(s) %d seconds\n",Hour(diff),Minute(diff),Second(diff));
	printf("Total aksi yang akan dilakukan: \n"); /* belum bikin stack eksekusi, WIP */
	printf("Total waktu yang dibutuhkan: \n"); /* belum bikin stack eksekusi, WIP */
	printf("Total uang yang dibutuhkan: \n"); /* belum bikin stack eksekusi, WIP */
}

BUILD(Stack *stack_aksi, int *durasi_stack, int *harga_stack, int remaining_time){
	/* I.S. sembarang */
	/* F.S. kalau build valid, menambahkan aksi ke stack_aksi */
	/* kalau tidak, menampilkan pesan kesalahan */
	printf("Ingin membangun wahana apa? (masukkan ID wahana)\n");
	PrintChild(T); /* T root tree wahana */
	printf("$ ");
	ADVKATA();
	Tree cur_wahana = Search(T,ToInt(CKata));
	/* belum validasi input, ntar */
	if (BuildTime(InfoTree(cur_wahana))<=remaining_time){
		/* ada cukup waktu untuk build */
		/* push aksi build ke stack */
		struct_aksi aksi_baru = MakeAksiBuild(/*koordinat player*/, ID(InfoTree(cur_wahana)), Price(InfoTree(cur_wahana)),BuildTime(InfoTree(cur_wahana)));
		PushStack(stack_aksi,aksi_baru); /* note: 0 itu id aksi build */
		*durasi_stack += BuildTime(InfoTree(cur_wahana));
		*harga_stack += Price(InfoTree(cur_wahana));
	}
	else{
		// waktu gak cukup untuk build
		printf("Tidak ada waktu untuk upgrade wahana!\n");
	}
}

UPGRADE(Stack *stack_aksi, int *durasi_stack, int *harga_stack, int remaining_time){
	printf("Ingin melakukan upgrade apa? (masukkan ID upgrade)\n");
	/* nyari wahana yang adjacent sama player, nunggu map, WIP, anggep aja ID wahananya ID*/
	Tree cur_wahana = Search(T,ID);
	PrintChild(cur_wahana);
	printf("$ ");
	ADVKATA();
	addrNode a = Search(T,ToInt(CKata));
	if (BuildTime(InfoTree(a))<=remaining_time){
		// ada cukup waktu untuk build
		/* ganti map somehow, WIP */
		/* push aksi build ke stack */
		PushStack(stack_aksi, 0); /* note: 0 itu id aksi build */
		*durasi_stack += BuildTime(InfoTree(cur_wahana));
		*harga_stack += Price(InfoTree(cur_wahana));
	}
	else{
		// waktu gak cukup untuk build
		printf("Tidak ada waktu untuk upgrade wahana!\n");
	}
}
void PrepPhase(int day){
	/* I.S.: sembarang
	 * F.S.: state game berubah sesuai aksi player pada prep. phase
	 * proses: mensimulasikan prep. phase
	 */
	/* KAMUS LOKAL */
	/* konstanta yang bisa diganti-ganti */
	JAM START_JAM = MakeJAM(21,0,0); /* jam mulai prep. phase */
	JAM END_JAM = MakeJAM(9,0,0); /* jam selesai prep. phase */
	int WALKING_DURATION = 0;
	int BUY_DURATION = 10;
	/* variabel */
	JAM cur_JAM;
	boolean selesai;
	boolean udah_start_kata;
	Stack stack_aksi;
	int durasi_stack;
	int harga_stack;
	/* ALGORITMA */
	printf("Preparation phase day %d\n",day);
	/* init */
	cur_JAM = START_JAM;
	selesai = false;
	udah_start_kata = false;
	CreateEmpty(&stack_aksi);
	durasi_stack = 0;
	harga_stack = 0;
	/* simulasi prep. phase, pakai do-while karena pasti jalan setidaknya sekali */
	Kata W;
	W.Length = 1;
	W.TabKata[0] = 'w';
	Kata A;
	A.Length = 1;
	A.TabKata[0] = 'a';
	Kata S;
	S.Length = 1;
	S.TabKata[0] = 's';
	Kata D;
	D.Length = 1;
	D.TabKata[0] = 'd';
	Kata Build;
	Build.Length = 5;
	Build.TabKata[0] = 'b';
	Build.TabKata[1] = 'u';
	Build.TabKata[2] = 'i';
	Build.TabKata[3] = 'l';
	Build.TabKata[4] = 'd';
	Kata Upgrade;
	Upgrade.Length = 7;
	Upgrade.TabKata[0] = 'u';
	Upgrade.TabKata[1] = 'p';
	Upgrade.TabKata[2] = 'g';
	Upgrade.TabKata[3] = 'r';
	Upgrade.TabKata[4] = 'a';
	Upgrade.TabKata[5] = 'd';
	Upgrade.TabKata[6] = 'e';
	Kata Buy;
	Buy.Length = 3;
	Buy.TabKata[0] = 'b';
	Buy.TabKata[1] = 'u';
	Buy.TabKata[2] = 'y';
	Kata Undo;
	Undo.Length = 4;
	Undo.TabKata[0] = 'u';
	Undo.TabKata[1] = 'n';
	Undo.TabKata[2] = 'd';
	Undo.TabKata[3] = 'o';
	Kata Execute;
	Execute.Length = 7;
	Execute.TabKata[0] = 'e';
	Execute.TabKata[1] = 'x';
	Execute.TabKata[2] = 'e';
	Execute.TabKata[3] = 'c';
	Execute.TabKata[4] = 'u';
	Execute.TabKata[5] = 't';
	Execute.TabKata[6] = 'e';
	Kata Main;
	Main.Length = 4;
	Main.TabKata[0] = 'm';
	Main.TabKata[0] = 'a';
	Main.TabKata[0] = 'i';
	Main.TabKata[0] = 'n';
	do {
		ShowPrepPhaseState(cur_JAM,END_JAM);
		printf("Masukkan perintah:\n$ ");
		/* input pake Mesin Karakter + Mesin Kata */
		/* NOTE: SEMENTARA ASSUME MESINKATA PUNYA START_PERINTAH */
		/* NOTE: SEMENTARA ASSUME NAMA VARIABEL MESINKATA CKata */ 
		/* diasumsikan gaada serangan buffer overflow */
		if (udah_start_kata) ADVKATA();
		else{
			STARTKATA();
			udah_start_kata = true;
		}
		if (IsKataSama(CKata, W)){
			/* mindah koordinat player ke atas */
		} 
		else if (IsKataSama(CKata, A)){
			/* mindah koordinat player ke kiri */
		} 
		else if (IsKataSama(CKata, S)){
			/* mindah koordinat player ke bawah */
		} 
		else if (IsKataSama(CKata, D)){
			/* mindah koordinat player ke kanan */
		} 
		else if (IsKataSama(CKata, Build)) BUILD(&stack_aksi,&harga_stack,&durasi_stack,Durasi(cur_JAM,END_JAM));
		else if (IsKataSama(CKata, Upgrade)){
			if (Durasi(cur_JAM,END_JAM)>=UPGRADE_DURATION){
				/* ada cukup waktu untuk build */
				/* nge-upgrade, WIP */
				NextNDetik(cur_JAM,UPGRADE_DURATION);
			} 
			else{
				/* waktu gak cukup untuk build */
				printf("Tidak ada waktu untuk upgrade wahana!\n");
			}
		} 
		else if (IsKataSama(CKata, Buy)){
			if (Durasi(cur_JAM,END_JAM)>=BUY_DURATION){
				/* ada cukup waktu untuk build */
				/* buy, WIP */
				NextNDetik(cur_JAM,BUY_DURATION);
			} 
			else{
				/* waktu gak cukup untuk build */
				printf("Tidak ada waktu untuk berbelanja!\n");
			}
		} 
		else if (IsKataSama(CKata, Undo)){
			/* undo, WIP */
		} 
		else if (IsKataSama(CKata, Execute)){
			/* execute, WIP */
		} 
		else if (IsKataSama(CKata, Main)){
			selesai = true;
		}
		else{
			/* input gak valid */
			printf("Perintah tidak valid.\n");
		}
	} while (!selesai);
}