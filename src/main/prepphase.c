#include <stdio.h>
#include "prepphase.h"

void ShowPrepPhaseState(JAM cur_JAM, JAM END_JAM, int NbElmtAksi, int durasi_stack, int harga_stack){
	/* I.S.: sembarang
	 * F.S.: map, legend, dan state prep. phase tercetak
	 */
	/* KAMUS LOKAL */
	JAM diff;
	/* ALGORITMA */
	PrintCurrMap(GraphMap);
	/* print legend */
	printf("Legend:\nA = Antrian\nP = Player\nW = Wahana\nO = Office\n< ^ > V = Gerbang\n");
	printf("\n");
	/* print state prep. phase */
	printf("Name: %s\n",NamaPlayer); /* belum tau name disimpen di mana, WIP */
	printf("Money: %d\n",DuitPlayer); /* belum tau money disimpen di mana, WIP */
	printf("Current Time: \n"); TulisJAM(cur_JAM); printf("\n");
	printf("Opening Time: \n"); TulisJAM(END_JAM); printf("\n");
	diff = DetikToJAM(Durasi(cur_JAM,END_JAM));
	printf("Time Remaining: %d hour(s) %d minute(s)\n",Hour(diff),Minute(diff));
	printf("Total aksi yang akan dilakukan: %d\n",NbElmtAksi); 
	printf("Total waktu yang dibutuhkan: %d\n",durasi_stack); 
	printf("Total uang yang dibutuhkan: %d\n",harga_stack);
}

void BUILD(Stack *stack_aksi, int *harga_stack, int *durasi_stack, int remaining_time){
	/* I.S. sembarang */
	/* F.S. kalau build valid, menambahkan aksi ke stack_aksi */
	/* kalau tidak, menampilkan pesan kesalahan */
	/* KAMUS LOKAL */
	POINT pos_player;
	boolean ada_wahana;
	Tree wahana_pilihan;
	Wahana info_wahana_pilihan;
	struct_aksi aksi_baru;
	boolean bahan_cukup;
	int jumlah_bahan;
	int i, j, k;
	/* ALGORITMA */
	/* cek di sel sekarang ada wahana atau tidak */
	pos_player = PosPlayer(Map(SearchPlayer(GraphMap)));
	ada_wahana = false;
	for (i=0;i<=TopStack(*stack_aksi);i++){
		if (IDAksi((*stack_aksi).aksi[i])==0 && Absis(pos_player)==Absis(KoordBuild((*stack_aksi).aksi[i])) && Ordinat(pos_player)==Ordinat(KoordBuild((*stack_aksi).aksi[i])) && IdGraph(SearchPlayer(GraphMap))==IDNodeBuild((*stack_aksi).aksi[i])){
			ada_wahana = true;
		}
	}
	if (!ada_wahana){
		printInven(Inventory);
		printf("Ingin membangun wahana apa? (masukkan ID wahana)\n");
		PrintChild(DataWahana);
		printf("$ ");
		ADVKATA();
		printf("ID wahana pilihan: %s\n",CKata.TabKata);
		wahana_pilihan = SearchTree(DataWahana,ToInt(CKata)); /* note: gaada validasi int/bukan */
		if (wahana_pilihan!=Nil){
			info_wahana_pilihan = InfoTree(wahana_pilihan);
			if (BuildTime(info_wahana_pilihan)<=remaining_time){
				/* ada cukup waktu untuk build */
				if (Price(info_wahana_pilihan)<=DuitPlayer){
					bahan_cukup = true;
					i = GetFirstIdx(Resources(info_wahana_pilihan));
					while (i<=GetLastIdx(Resources(info_wahana_pilihan)) && bahan_cukup){
						j = Search1(Inventory,Info(Resources(info_wahana_pilihan),i));
						jumlah_bahan = Value(Resources(info_wahana_pilihan),i);
						for (j=0;j<=TopStack(*stack_aksi);j++){
							if (IDAksi((*stack_aksi).aksi[j])==0){
								k = Search1(BahanBuild((*stack_aksi).aksi[j]),Info(Resources(info_wahana_pilihan),i));
								if (k!=IdxUndef) jumlah_bahan += Value(BahanBuild((*stack_aksi).aksi[j]),k);
							}
							else if (IDAksi((*stack_aksi).aksi[j])==1){
								k = Search1(BahanUpgrade((*stack_aksi).aksi[j]),Info(Resources(info_wahana_pilihan),i));
								if (k!=IdxUndef) jumlah_bahan += Value(BahanUpgrade((*stack_aksi).aksi[j]),k);
							}
						}
						if (Value(Inventory,j)<jumlah_bahan){
							bahan_cukup = false;
						}
						i++;
					}
					if (bahan_cukup){
						aksi_baru = MakeAksiBuild(IdGraph(SearchPlayer(GraphMap)), pos_player, ID(InfoTree(wahana_pilihan)), Price(InfoTree(wahana_pilihan)),BuildTime(InfoTree(wahana_pilihan)));
						/* push aksi build ke stack */
						PushStack(stack_aksi,aksi_baru); /* note: 0 itu id aksi build */
						*durasi_stack += BuildTime(InfoTree(wahana_pilihan));
						*harga_stack += Price(InfoTree(wahana_pilihan));
					}
					else{
						/* bahan gak cukup */
						printf("Bahan bangunan yang ada tidak cukup untuk membangun wahana!\n");
					}
				}
				else{
					/* uang gak cukup untuk build */
					printf("Tidak cukup uang untuk membangun wahana!\n");
				}
			}
			else{
				/* waktu gak cukup untuk build */
				printf("Tidak ada waktu untuk build wahana!\n");
			}
		}
		else{
			/* perintah gak valid */
			printf("Command tidak valid\n");		
		}
	}
	else{
		/* ada wahana yang akan dibangun di sini */
		printf("Sudah ada wahana yang akan dibangun di sini!\n");
	}
}

void UPGRADE(Stack *stack_aksi, int *harga_stack, int *durasi_stack, int remaining_time){
	/* I.S. sembarang */
	/* F.S. kalau upgrade valid, menambahkan aksi ke stack_aksi */
	/* kalau tidak, menampilkan pesan kesalahan */
	/* KAMUS LOKAL */
	Tree upgrade_pilihan;
	Wahana info_upgrade_pilihan;
	Tree wahana_upgrade;
	struct_aksi aksi_baru;
	POINT koord_player;
	adrNode cur_node;
	POINT koord_upgrade;
	int manhattan_distance;
	int i, j, k;
	boolean bahan_cukup;
	int jumlah_bahan;
	/* ALGORITMA */
	cur_node = SearchPlayer(GraphMap);
	koord_player = PosPlayer(Map(cur_node)); /* cek aman apa nggak ntar */
	koord_upgrade = GetAdjWahana(GraphMap);
	for (i=0;i<nbWahana;i++){
		if (PosX(ActiveWahana[i])==Absis(koord_upgrade)&&PosY(ActiveWahana[i])==Ordinat(koord_upgrade)){
			wahana_upgrade = SearchTree(DataWahana,ID(ActiveWahana[i]));
		}
	}
	if (Absis(koord_upgrade)!=-1){
		printf("Ingin melakukan upgrade apa? (masukkan ID upgrade)\n");
		PrintChild(wahana_upgrade); 
		printf("$ ");
		ADVKATA();
		upgrade_pilihan = SearchTree(wahana_upgrade,ToInt(CKata));
		if (upgrade_pilihan!=Nil){
			info_upgrade_pilihan = InfoTree(upgrade_pilihan);
			if (BuildTime(info_upgrade_pilihan)<=remaining_time){
				/* ada cukup waktu untuk upgrade */
				if (Price(info_upgrade_pilihan)<=DuitPlayer){
					bahan_cukup = true;
					i = GetFirstIdx(Resources(info_upgrade_pilihan));
					while (i<=GetLastIdx(Resources(info_upgrade_pilihan)) && bahan_cukup){
						j = Search1(Inventory,Info(Resources(info_upgrade_pilihan),i));
						jumlah_bahan = Value(Resources(info_upgrade_pilihan),i);
						for (j=0;j<=TopStack(*stack_aksi);j++){
							if (IDAksi((*stack_aksi).aksi[j])==0){
								k = Search1(BahanBuild((*stack_aksi).aksi[j]),Info(Resources(info_upgrade_pilihan),i));
								if (k!=IdxUndef) jumlah_bahan += Value(BahanBuild((*stack_aksi).aksi[j]),k);
							}
							else if (IDAksi((*stack_aksi).aksi[j])==1){
								k = Search1(BahanUpgrade((*stack_aksi).aksi[j]),Info(Resources(info_upgrade_pilihan),i));
								if (k!=IdxUndef) jumlah_bahan += Value(BahanUpgrade((*stack_aksi).aksi[j]),k);
							}
						}
						if (Value(Inventory,j)<jumlah_bahan){
							bahan_cukup = false;
						}
						i++;
					}
					if (bahan_cukup){
						aksi_baru = MakeAksiUpgrade(IdGraph(SearchPlayer(GraphMap)), koord_upgrade, ID(InfoTree(upgrade_pilihan)), Price(InfoTree(upgrade_pilihan)), BuildTime(InfoTree(upgrade_pilihan)));
						/* push aksi upgrade ke stack */
						PushStack(stack_aksi,aksi_baru); /* note: 1 itu id aksi upgrade */
						*durasi_stack += BuildTime(InfoTree(upgrade_pilihan));
						*harga_stack += Price(InfoTree(upgrade_pilihan));
					}
					else{
						/* bahan gak cukup */
						printf("Bahan bangunan yang ada tidak cukup untuk upgrade wahana!\n");
					}
				}
				else{
					/* uang gak cukup untuk build */
					printf("Tidak cukup uang untuk upgrade wahana!\n");
				}
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
	else{
		/* tidak ada wahana di sekitar player */
		printf("Tidak ada wahana yang cukup dekat untuk upgrade!\n");
	}
}

void BUY(Stack *stack_aksi, int *harga_stack, int *durasi_stack, int remaining_time, int BUY_DURATION){
	/* I.S. sembarang */
	/* F.S. kalau buy valid, menambahkan aksi ke stack_aksi */
	/* kalau tidak, menampilkan pesan kesalahan */
	/* KAMUS LOKAL */
	IdxType idx_bahan_yang_mau_dibeli;
	int harga_total;
	int jumlah_barang;
	struct_aksi aksi_baru;
	/* ALGORITMA */
	if (BUY_DURATION<=remaining_time){
		/* ada cukup waktu untuk belanja */
		idx_bahan_yang_mau_dibeli = IdxUndef;
		printf("Ingin membeli apa?\n");
		printShop(Shop);
		printf("$ ");
		ADVKATA();
		idx_bahan_yang_mau_dibeli = Search1(Shop,CKata.TabKata);
		if (idx_bahan_yang_mau_dibeli != IdxUndef){
			/* bahan yang mau dibeli ada */
			printf("Beli berapa?\n$ ");
			ADVKATA();
			jumlah_barang = ToInt(CKata);
			harga_total = Value(Shop,idx_bahan_yang_mau_dibeli)*jumlah_barang;
			printf("harga barang: %d\njumlah barang: %d\ntotal harga: %d\n",Value(Shop,idx_bahan_yang_mau_dibeli),jumlah_barang,harga_total);
			if (harga_total<=DuitPlayer){
				aksi_baru = MakeAksiBuy(harga_total,BUY_DURATION,Info(Shop,idx_bahan_yang_mau_dibeli),jumlah_barang);
				PushStack(stack_aksi,aksi_baru);
				*durasi_stack += BUY_DURATION;
				*harga_stack += harga_total;
			}
			else{
				/* uang gak cukup untuk buy */
				printf("Tidak cukup uang untuk membeli!\n");
			}
		}
		else{
			/* bahan yang mau dibeli gaada */
			printf("Tidak ada barang dengan nama itu!\n");
		}
	}
	else{
		/* waktu gak cukup untuk belanja */
		printf("Tidak ada cukup waktu untuk belanja!\n");
	}
}

void UNDO(Stack *stack_aksi, int *harga_stack, int *durasi_stack){
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

void EXECUTE(Stack *stack_aksi){
	/* I.S. sembarang */
	/* F.S. semua aksi di stack dijalankan, stack kosong, */
	/* player dipindah ke sel tanpa wahana */
	/* KAMUS LOKAL */
	struct_aksi cur_aksi;
	Wahana wahana_baru;
	int idx_upgrade;
	int i;
	/* ALGORITMA */
	while (!IsEmptyStack(*stack_aksi)){
		PopStack(stack_aksi,&cur_aksi);
		if (IDAksi(cur_aksi)==0){
			BuildWMap(&GraphMap,KoordBuild(cur_aksi),IDNodeBuild(cur_aksi));
			ActiveWahana[nbWahana] = InfoTree(SearchTree(DataWahana,IDBuild(cur_aksi)));
			PosX(ActiveWahana[nbWahana]) = Absis(KoordBuild(cur_aksi));
			PosY(ActiveWahana[nbWahana]) = Ordinat(KoordBuild(cur_aksi));
			TotalRide(ActiveWahana[nbWahana]) = 0;
			TotalGold(ActiveWahana[nbWahana]) = 0;
			DayRide(ActiveWahana[nbWahana]) = 0;
			DayGold(ActiveWahana[nbWahana]) = 0;
			IsRusak(ActiveWahana[nbWahana]) = 0;
			MapWahana(ActiveWahana[nbWahana]) = IDNodeBuild(cur_aksi);
			nbWahana++;
			Sekarang = NextNDetik(Sekarang,DurasiBuild(cur_aksi));
			DuitPlayer -= HargaBuild(cur_aksi);
			for (i=GetFirstIdx(BahanBuild(cur_aksi));i<=GetLastIdx(BahanBuild(cur_aksi));i++){
				updateInvenMinus(&Inventory,Info(BahanBuild(cur_aksi),i),Value(BahanBuild(cur_aksi),i));
			}
		}
		else if (IDAksi(cur_aksi)==1){
			/* search wahana di active wahana */
			idx_upgrade = -1;
			i = 0;
			while (i<nbWahana && idx_upgrade==-1){
				if (PosX(ActiveWahana[i])==Absis(KoordUpgrade(cur_aksi)) && PosY(ActiveWahana[i])==Ordinat(KoordUpgrade(cur_aksi))){
					idx_upgrade = i;
				}
				else i++;
			}
			/* upgrade wahana */
			ActiveWahana[idx_upgrade] = InfoTree(SearchTree(DataWahana,IDUpgrade(cur_aksi)));
			Sekarang = NextNDetik(Sekarang,DurasiUpgrade(cur_aksi));
			DuitPlayer -= HargaUpgrade(cur_aksi);
			for (i=GetFirstIdx(BahanUpgrade(cur_aksi));i<=GetLastIdx(BahanUpgrade(cur_aksi));i++){
				updateInvenMinus(&Inventory,Info(BahanUpgrade(cur_aksi),i),Value(BahanUpgrade(cur_aksi),i));
			}
		}
		else if (IDAksi(cur_aksi)==2){
			if (SearchB(Inventory,NamaBarangBuy(cur_aksi))) updateInvenPlus(&Inventory,NamaBarangBuy(cur_aksi),JumlahBarangBuy(cur_aksi));
			else 
			Sekarang = NextNDetik(Sekarang,DurasiBuy(cur_aksi));
			DuitPlayer -= HargaBuy(cur_aksi);
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
	int BUY_DURATION = 1800;
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
	Main.TabKata[1] = 'a';
	Main.TabKata[2] = 'i';
	Main.TabKata[3] = 'n';
	/* variabel */
	boolean selesai;
	Stack stack_aksi;
	int durasi_stack;
	int harga_stack;
	boolean udah_start_kata;
	/* ALGORITMA */
	printf("Preparation phase day %d\n",day);
	/* init */
	Sekarang = START_JAM;
	selesai = false;
	CreateEmptyStack(&stack_aksi);
	durasi_stack = 0;
	harga_stack = 0;
	udah_start_kata = false;
	/* simulasi prep. phase, pakai do-while karena pasti jalan setidaknya sekali */
	do {
		ShowPrepPhaseState(Sekarang,END_JAM,TopStack(stack_aksi)+1,durasi_stack,harga_stack);
		printf("Masukkan perintah:\n$ ");
		if (!udah_start_kata){
			STARTKATAKEYBOARD();
			udah_start_kata = true;
		}
		else ADVKATA();
		if (IsKataSama(CKata, W)){
			/* mindah koordinat player ke atas */
			move('w',&GraphMap);
		} 
		else if (IsKataSama(CKata, A)){
			/* mindah koordinat player ke kiri */
			move('a',&GraphMap);
		} 
		else if (IsKataSama(CKata, S)){
			/* mindah koordinat player ke bawah */
			move('s',&GraphMap);
		} 
		else if (IsKataSama(CKata, D)){
			/* mindah koordinat player ke kanan */
			move('d',&GraphMap);
		} 
		else if (IsKataSama(CKata, Build)) BUILD(&stack_aksi,&harga_stack,&durasi_stack,Durasi(Sekarang,END_JAM));
		else if (IsKataSama(CKata, Upgrade)) UPGRADE(&stack_aksi,&harga_stack,&durasi_stack,Durasi(Sekarang,END_JAM));
		else if (IsKataSama(CKata, Buy)) BUY(&stack_aksi,&harga_stack,&durasi_stack,Durasi(Sekarang,END_JAM),BUY_DURATION);
		else if (IsKataSama(CKata, Undo)) UNDO(&stack_aksi,&harga_stack,&durasi_stack);
		else if (IsKataSama(CKata, Execute)){
			EXECUTE(&stack_aksi);
			Sekarang = NextNDetik(Sekarang,durasi_stack*60);
			harga_stack = 0;
			durasi_stack = 0;
		}
		else if (IsKataSama(CKata, Main)){
			/* ngosongin stack_aksi */
			TopStack(stack_aksi) = Undef;
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