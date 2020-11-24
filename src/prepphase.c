#include <stdio.h>
#include ""

void ShowPrepPhaseState(JAM cur_jam, JAM END_JAM){
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
	printf("Ingin membangun wahana apa? (masukkan ID wahana)\n");
	PrintChild(T);
	printf("$ ");
	ADVKATA();
	Tree cur_wahana = Search(T,ToInt(CKata));
	if (BuildTime(Info(cur_wahana))<=remaining_time){
		// ada cukup waktu untuk build
		/* ganti map somehow, WIP */
		/* push aksi build ke stack */
		PushStack(stack_aksi,0); /* note: 0 itu id aksi build */
		*durasi_stack += BuildTime(Info(cur_wahana));
		*harga_stack += Price(Info(cur_wahana));
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
	address a = Search(T,ToInt(CKata));
	if (BuildTime(Info(a))<=remaining_time){
		// ada cukup waktu untuk build
		/* ganti map somehow, WIP */
		/* push aksi build ke stack */
		PushStack(stack_aksi,0); /* note: 0 itu id aksi build */
		*durasi_stack += BuildTime(Info(cur_wahana));
		*harga_stack += Price(Info(cur_wahana));
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
	JAM cur_jam;
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
	do {
		ShowPrepPhaseState(cur_JAM,END_JAM);
		printf("Masukkan perintah:\n$ ");
		/* input pake Mesin Karakter + Mesin Kata */
		/* NOTE: SEMENTARA ASSUME MESINKATA PUNYA START_PERINTAH */
		/* NOTE: SEMENTARA ASSUME NAMA VARIABEL MESINKATA CKata */ 
		/* diasumsikan gaada serangan buffer overflow */
		if (udah_start_kata) ADVKATA();
		else{
			START();
			udah_start_kata = true;
		}
		if (CKata == "W"){
			/* mindah koordinat player ke atas */
		} 
		else if (CKata == "A"){
			/* mindah koordinat player ke kiri */
		} 
		else if (CKata == "S"){
			/* mindah koordinat player ke bawah */
		} 
		else if (CKata == "D"){
			/* mindah koordinat player ke kanan */
		} 
		else if (CKata == "BUILD") BUILD(&stack_aksi,&harga_stack,&durasi_stack,Durasi(cur_jam,END_JAM));
		else if (CKata == "UPGRADE"){
			if (Durasi(cur_JAM,END_JAM)>=UPGRADE_DURATION){
				/* ada cukup waktu untuk build */
				/* nge-upgrade, WIP */
				NextNDetik(cur_jam,UPGRADE_DURATION);
			} 
			else{
				/* waktu gak cukup untuk build */
				printf("Tidak ada waktu untuk upgrade wahana!\n");
			}
		} 
		else if (CKata == "BUY"){
			if (Durasi(cur_JAM,END_JAM)>=BUY_DURATION){
				/* ada cukup waktu untuk build */
				/* buy, WIP */
				NextNDetik(cur_jam,BUY_DURATION);
			} 
			else{
				/* waktu gak cukup untuk build */
				printf("Tidak ada waktu untuk berbelanja!\n");
			}
		} 
		else if (CKata == "UNDO"){
			/* undo, WIP */
		} 
		else if (CKata == "EXECUTE"){
			/* execute, WIP */
		} 
		else if (CKata == "MAIN"){
			selesai = true;
		} 
		else{
			/* input gak valid */
			printf("Perintah tidak valid.\n");
		}
	} while (!selesai);
}