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
	printf("Time Remaining: %d hour(s) %d minute(s)\n",Hour(diff),Minute(diff));
	printf("Total aksi yang akan dilakukan: \n"); /* belum bikin stack eksekusi, WIP */
	printf("Total waktu yang dibutuhkan: \n"); /* belum bikin stack eksekusi, WIP */
	printf("Total uang yang dibutuhkan: \n"); /* belum bikin stack eksekusi, WIP */
}

BUILD(Stack *stack_aksi, int *durasi_stack, int *harga_stack, int remaining_time){
	/* I.S. sembarang */
	/* F.S. kalau build valid, menambahkan aksi ke stack_aksi */
	/* kalau tidak, menampilkan pesan kesalahan */
	/* KAMUS LOKAL */
	Tree wahana_pilihan;
	struct_aksi aksi_baru;
	/* ALGORITMA */
	printf("Ingin membangun wahana apa? (masukkan ID wahana)\n");
	PrintChild(T); /* T root tree wahana */
	printf("$ ");
	ADVKATA();
	wahana_pilihan = Search(T,ToInt(CKata)); /* note: gaada validasi int/bukan */
	if (wahana_pilihan!=Nil){
		if (BuildTime(InfoTree(wahana_pilihan))<=remaining_time){
			/* ada cukup waktu untuk build */
			/* note: belum cek bahan bangunan cukup/ga */
			aksi_baru = MakeAksiBuild(/*koordinat player*/, ID(InfoTree(wahana_pilihan)), Price(InfoTree(wahana_pilihan)),BuildTime(InfoTree(wahana_pilihan)));
			/* push aksi build ke stack */
			PushStack(stack_aksi,aksi_baru); /* note: 0 itu id aksi build */
			*durasi_stack += BuildTime(InfoTree(wahana_pilihan));
			/* note: belum cek duit cukup apa enggak */
			*harga_stack += Price(InfoTree(wahana_pilihan));
		}
		else{
			/* waktu gak cukup untuk build */
			printf("Tidak ada waktu untuk upgrade wahana!\n");
		}
	}
	else{
		/* perintah gak valid */
		printf("Command tidak valid\n");		
	}
}

UPGRADE(Stack *stack_aksi, int *durasi_stack, int *harga_stack, int remaining_time){
	/* I.S. sembarang */
	/* F.S. kalau upgrade valid, menambahkan aksi ke stack_aksi */
	/* kalau tidak, menampilkan pesan kesalahan */
	/* KAMUS LOKAL */
	Tree upgrade_pilihan;
	Tree wahana_upgrade;
	struct_aksi aksi_baru;
	/* ALGORITMA */
	printf("Ingin melakukan upgrade apa? (masukkan ID upgrade)\n");
	/* nyari wahana yang adjacent sama player, nunggu map, WIP, anggep aja ID wahananya ID*/
	wahana_upgrade = Search(T,ID); 
	PrintChild(wahana_upgrade);
	printf("$ ");
	ADVKATA();
	upgrade_pilihan = Search(wahana_upgrade,ToInt(CKata));
	if (upgrade_pilihan!=Nil){
		if (BuildTime(InfoTree(a))<=remaining_time){
			/* ada cukup waktu untuk upgrade */
			/* note: belum cak bahan bangunan cukup/ga */
			aksi_baru = MakeAksiUpgrade(/*koordinat player*/, ID(InfoTree(upgrade_pilihan)), Price(InfoTree(upgrade_pilihan)),BuildTime(InfoTree(upgrade_pilihan)));
			/* push aksi upgrade ke stack */
			PushStack(stack_aksi,aksi_baru); /* note: 1 itu id aksi upgrade */
			*durasi_stack += BuildTime(InfoTree(upgrade_pilihan));
			/* note: belum cek duit cukup apa enggak */
			*harga_stack += Price(InfoTree(upgrade_pilihan));
		}
		else{
			/* waktu gak cukup untuk build */
			printf("Tidak ada waktu untuk upgrade wahana!\n");
		}
	}
	else{
		/* perintah gak valid */
		printf("Command tidak valid\n");
	}
}

BUY(Stack *stack_aksi, int *durasi_stack, int *harga_stack, int remaining_time, int BUY_DURATION){
	/* I.S. sembarang */
	/* F.S. kalau buy valid, menambahkan aksi ke stack_aksi */
	/* kalau tidak, menampilkan pesan kesalahan */
	/* KAMUS LOKAL */
	/* ALGORITMA */
	if (BUY_DURATION<=remaining_time){
		/* ada cukup waktu untuk belanja */
		printf("Ingin membeli apa?\n");
		/* print list bahan bangunan */

	}
	else{
		/* waktu gak cukup untuk belanja */
	}
}

UNDO(Stack *stack_aksi, int *durasi_stack, int *harga_stack){
	/* I.S. sembarang */
	/* F.S. top stack_aksi terhapus jika ada */
	/* KAMUS LOKAL */
	struct_aksi del;
	/* ALGORITMA */
	if (!IsEmptyStack(*stack_aksi)){
		PopStack(stack_aksi,&del);
		if (IDAksi(del)==0){
			/* pop build */
			*durasi_stack -= DurasiBuild(del);
			*harga_stack -= HargaBuild(del);
		}
		else if (IDAksi(del)==1){
			/* pop upgrade */
			*durasi_stack -= DurasiUpgrade(del);
			*harga_stack -= HargaUpgrade(del);
		}
		else if (IDAksi(del)==2){
			/* pop buy */
			*durasi_stack -= DurasiBuy(del);
			*harga_stack -= HargaBuy(del);
		}
	}
	/* kalau stack kosong, tidak terjadi apa-apa */
}

EXECUTE(Stack *stack_aksi){
	/* I.S. sembarang */
	/* F.S. semua aksi di stack dijalankan, stack kosong, */
	/* player dipindah ke sel tanpa wahana */
	/* KAMUS LOKAL */
	struct_aksi cur_aksi;
	/* ALGORITMA */
	while (!IsEmptyStack(*stack_aksi)){
		PopStack(stack_aksi,&cur_aksi);
		if (IDAksi(del)==0){
			/* execute build, WIP */
			*durasi_stack -= DurasiBuild(del);
			*harga_stack -= HargaBuild(del);
		}
		else if (IDAksi(del)==1){
			/* execute upgrade, WIP */
			*durasi_stack -= DurasiUpgrade(del);
			*harga_stack -= HargaUpgrade(del);
		}
		else if (IDAksi(del)==2){
			/* execute buy, WIP */
			*durasi_stack -= DurasiBuy(del);
			*harga_stack -= HargaBuy(del);
		}
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
	/* konstanta kata */
	Kata W;
	Kata A;
	Kata S;
	Kata D;
	Kata Build;
	Kata Upgrade;
	Kata Buy;
	Kata Undo;
	Kata Execute;
	Kata Main;
	W.Length = 1;
	W.TabKata[0] = 'w';
	A.Length = 1;
	A.TabKata[0] = 'a';
	S.Length = 1;
	S.TabKata[0] = 's';
	D.Length = 1;
	D.TabKata[0] = 'd';
	Build.Length = 5;
	Build.TabKata[0] = 'b';
	Build.TabKata[1] = 'u';
	Build.TabKata[2] = 'i';
	Build.TabKata[3] = 'l';
	Build.TabKata[4] = 'd';
	Upgrade.Length = 7;
	Upgrade.TabKata[0] = 'u';
	Upgrade.TabKata[1] = 'p';
	Upgrade.TabKata[2] = 'g';
	Upgrade.TabKata[3] = 'r';
	Upgrade.TabKata[4] = 'a';
	Upgrade.TabKata[5] = 'd';
	Upgrade.TabKata[6] = 'e';
	Buy.Length = 3;
	Buy.TabKata[0] = 'b';
	Buy.TabKata[1] = 'u';
	Buy.TabKata[2] = 'y';
	Undo.Length = 4;
	Undo.TabKata[0] = 'u';
	Undo.TabKata[1] = 'n';
	Undo.TabKata[2] = 'd';
	Undo.TabKata[3] = 'o';
	Execute.Length = 7;
	Execute.TabKata[0] = 'e';
	Execute.TabKata[1] = 'x';
	Execute.TabKata[2] = 'e';
	Execute.TabKata[3] = 'c';
	Execute.TabKata[4] = 'u';
	Execute.TabKata[5] = 't';
	Execute.TabKata[6] = 'e';
	Main.Length = 4;
	Main.TabKata[0] = 'm';
	Main.TabKata[0] = 'a';
	Main.TabKata[0] = 'i';
	Main.TabKata[0] = 'n';
	/* variabel */
	boolean selesai;
	boolean udah_start_kata;
	Stack stack_aksi;
	int durasi_stack;
	int harga_stack;
	/* ALGORITMA */
	printf("Preparation phase day %d\n",day);
	/* init */
	Sekarang = START_JAM;
	selesai = false;
	udah_start_kata = false;
	CreateEmpty(&stack_aksi);
	durasi_stack = 0;
	harga_stack = 0;
	/* simulasi prep. phase, pakai do-while karena pasti jalan setidaknya sekali */
	do {
		ShowPrepPhaseState(Sekarang,END_JAM);
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
		else if (IsKataSama(CKata, Upgrade)) UPGRADE(&stack_aksi,&harga_stack,&durasi_stack,Durasi(cur_JAM,END_JAM));
		else if (IsKataSama(CKata, Buy)) BUY(&stack_aksi,&harga_stack,&durasi_stack,Durasi(cur_JAM,END_JAM),BUY_DURATION);
		else if (IsKataSama(CKata, Undo)) UNDO(&stack_aksi,&harga_stack,&durasi_stack);
		else if (IsKataSama(CKata, Execute)){
			EXECUTE(&stack_aksi);
			Sekarang = NextNDetik(Sekarang,durasi_stack*60);
			harga_stack = 0;
			durasi_stack = 0;
		}
		else if (IsKataSama(CKata, Main)){
			/* ngosongin stack_aksi */
			TopStack(stack_aksi) = Nil;
			harga_stack = 0;
			durasi_stack = 0;
			selesai = true;
		}
		else{
			/* input gak valid */
			printf("Perintah tidak valid.\n");
		}
	} while (!selesai);
}