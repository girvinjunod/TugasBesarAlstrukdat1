#include <stdio.h>
#include <stdlib.h>
#include "../main/mainphase.h"
#include "../queue/prioqueuePengunjung.h"

void MinuteUpdate(){
    Sekarang = NextNDetik(Sekarang, 60);
    int Detik = JAMToDetik(Sekarang);
    //Tentang antrian, belum dirandom
    int TambahAntrian = rand() % 50;
    if(TambahAntrian == 0 && !IsFullQ(Antrian)){
        Pengunjung P = generatePengunjung();
        infotypeQ Q;
        Q.infoqueue = P;
        Q.prio = P.kesabaran;
        Enqueue(&Antrian, Q);
    }
    //Ngecek tiap wahana
    int i;
    for(i=0; i<nbWahana; i++){
        if(!IsEmptyQ(PQ[i])){
            while(Detik == Prio(InfoHeadQ(PQ[i]))){
                infotypeQ Q;
                Dequeue(&PQ[i], &Q);
                ServeWahana(&(Q.infoqueue), i);
                if(IsEmptyQ(Antrian)){
                    Q.infoqueue.kesabaran -= Duration(ActiveWahana[i]);
                    Q.prio = Q.infoqueue.kesabaran;
                }else{
                    Q.infoqueue.kesabaran = Prio(InfoHeadQ(Antrian))-1;
                    Q.prio = Q.infoqueue.kesabaran;
                }
                if(Q.infoqueue.nbActiveWahana > 0){
                    Enqueue(&Antrian, Q);
                }
                //Update Laporan Wahana
                TotalGold(ActiveWahana[i]) += Price(ActiveWahana[i]);
                TotalRide(ActiveWahana[i])++;
                DayGold(ActiveWahana[i]) += Price(ActiveWahana[i]);
                DayRide(ActiveWahana[i])++;
                DuitPlayer += Price(ActiveWahana[i]);
            }
            int Rusak = rand() % (1000000);
            if(Rusak < ChanceRusak(ActiveWahana[i])){
                while(!IsEmptyQ(PQ[i])){
                    infotypeQ Q;
                    Dequeue(&PQ[i], &Q);
                    Q.infoqueue.kesabaran = Prio(InfoHeadQ(Antrian))-1;
                    Q.prio = Q.infoqueue.kesabaran;
                    Enqueue(&Antrian, Q);
                }
                IsRusak(ActiveWahana[i]) = 1;
            }
        }
    }
    //Mengurangi kesabaran
    if (!IsEmptyQ(Antrian)){
        for(i = HeadQ(Antrian); i!= TailQ(Antrian); i = (i+1)%10){
            Antrian.T[i].prio--;
            Antrian.T[i].infoqueue.kesabaran--;
        }
        Antrian.T[i].prio--;
        Antrian.T[i].infoqueue.kesabaran--;
        infotypeQ Q;
        while(!IsEmptyQ(Antrian) && Prio(InfoHeadQ(Antrian))<=0){
            Dequeue(&Antrian, &Q);
        }
    }
}

void NMinuteUpdate(int N){
    int i;
    for(i=0; i<N; i++){
        MinuteUpdate();
    }
}


void generateAntrian(){
    int BanyakAntrian = (rand() % 10) + 1;
    int i;
    for(i=0; i<BanyakAntrian; i++){
        Pengunjung P = generatePengunjung();
        infotypeQ Q;
        Q.infoqueue = P;
        Q.prio = P.kesabaran;
        Enqueue(&Antrian, Q);
    }
}

void InitializeMainPhase(){
    MakeEmptyQ(&Antrian, 10);
    generateAntrian();
    int i;
    for(i=0; i<nbWahana; i++){
        MakeEmptyQ(&PQ[i], Capacity(ActiveWahana[i]));
        DayGold(ActiveWahana[i]) = 0;
        DayRide(ActiveWahana[i]) = 0;
    }
}

void ShowMainPhaseState(JAM cur_JAM, JAM END_JAM){
	/* I.S.: sembarang
	 * F.S.: map, legend, dan state prep. phase tercetak
	 */
	/* KAMUS LOKAL */
	JAM diff;
    PrintCurrMap(GraphMap);
	/* ALGORITMA */
	/* ngeprint area map sekarang somehow, WIP */
	/* print legend */
	printf("Legend:\nA = Antrian\nP = Player\nW = Wahana\nO = Office\n< ^ > V = Gerbang\n");
	printf("\n");
	/* print state prep. phase */
    printf("Name: %s\n",NamaPlayer); /* belum tau name disimpen di mana, WIP */
	printf("Money: %d\n",DuitPlayer); /* belum tau money disimpen di mana, WIP */
	printf("Current Time: "); TulisJAM(cur_JAM); printf("\n");
	printf("Opening Time: "); TulisJAM(END_JAM); printf("\n");
	diff = DetikToJAM(Durasi(cur_JAM,END_JAM));
	printf("Time Remaining: %d hour(s) %d minute(s)\n",Hour(diff),Minute(diff));
    PrintPrioQueuePengunjung(Antrian);
    int i, broken = 0;
    for(i=0; i<nbWahana; i++){
        if(IsRusak(ActiveWahana[i]) == 1){
            broken++;
        }
    }
    if(broken>0){
        printf("Broken:\n");
        for(i=0; i<nbWahana; i++){
            if(IsRusak(ActiveWahana[i]) == 1){
                PrintName(ActiveWahana[i]);
            }
            printf("\n");
        }
    }
}


void SERVE(Kata K){
    boolean notfound = true;
    int i=0;
    int Detik = JAMToDetik(Sekarang);
    while(i<nbWahana && notfound){
        if(NbElmtQ(PQ[i])<Capacity(ActiveWahana[i]) && IsKataSama(Name(ActiveWahana[i]), K) && IsRusak(ActiveWahana[i])==0){
            notfound = false;
        }
        i++;
    }
    i--;
    if(notfound){
        printf("Semua wahana dengan nama tersebut penuh/rusak/bahkan tidak ada\n");
    }else{
        infotypeQ Q;
        Dequeue(&Antrian, &Q);
        boolean foundonlist = false;
        int j;
        for(j=0; j<Q.infoqueue.nbListWahana; j++){
            if(Q.infoqueue.wahana[j] == i && !Q.infoqueue.done[j]){
                foundonlist = true;
            }
        }
        if(foundonlist){
            NMinuteUpdate(5);
            Q.prio = Duration(ActiveWahana[i]) + JAMToDetik(Sekarang);
            Enqueue(&PQ[i], Q);
        }else{
            Enqueue(&Antrian, Q);
            printf("Wahana tersebut tidak ada dalam list wahana pengunjung anda\n");
        }
    }
}
void PrintDetailWahana(Wahana W){
    addrNode P = SearchTree(DataWahana, ID(W));
    printf("Melihat detail wahana \n");
    printf("Nama: ");
    PrintName(W);
    printf("\n");
    printf("Lokasi: (%d,%d)\n", PosX(W), PosY(W));
    printf("Upgrade: ");
    PrintChildrenName(P);
    printf("\nHistory: ");
    PrintHistory(P);
    printf("\n");
}

void PrintListActiveWahana(){
    int i;
    for(i=0; i<nbWahana; i++){
        printf("%d. ", i+1);
        PrintName(ActiveWahana[i]);
        printf("\n");
    }
}

void REPAIR(){
    adrNode P = SearchPlayer(GraphMap);
    MAP M = Map(P);
    POINT Q = PosPlayer(M);
    int MapID = IdGraph(P);
    int i=0, j=0;
    int RepairCandidate[4];
    for(i=0; i<nbWahana; i++){
        if(IsRusak(ActiveWahana[i]) == 1){
            if(ActiveWahana[i].MapWahana == MapID && PosX(ActiveWahana[i]) == Q.X + 1 && PosY(ActiveWahana[i]) == Q.Y){
                RepairCandidate[j] = i;
                j++;
            }
            if(ActiveWahana[i].MapWahana == MapID && PosX(ActiveWahana[i]) == Q.X && PosY(ActiveWahana[i]) == Q.Y + 1){
                RepairCandidate[j] = i;
                j++;
            }
            if(ActiveWahana[i].MapWahana == MapID && PosX(ActiveWahana[i]) == Q.X - 1 && PosY(ActiveWahana[i]) == Q.Y){
                RepairCandidate[j] = i;
                j++;
            }
            if(ActiveWahana[i].MapWahana == MapID && PosX(ActiveWahana[i]) == Q.X && PosY(ActiveWahana[i]) == Q.Y - 1){
                RepairCandidate[j] = i;
                j++;
            }
        }
    }
    if(j==0){
        printf("Tidak ada wahana didekat anda yang bisa di repair!\n");
    }else{
        printf("List wahana yang bisa di repair:\n");
        for(i=0; i<j; i++){
            printf("%d. ", i+1);
            PrintName(ActiveWahana[RepairCandidate[i]]);
            printf("\n");
        }
        printf("Masukkan nomor wahana yang ingin di repair:\n");
        ADVKATA();
        i = RepairCandidate[ToInt(CKata)-1];
        if(DuitPlayer < 50){
            printf("Anda membutuhkan 50 gold untuk melakukan repair");
        }else{
            DuitPlayer -= 50;
            IsRusak(ActiveWahana[i]) = 0;
            NMinuteUpdate(10);
        }
    }
}
void DETAIL(){
    adrNode P = SearchPlayer(GraphMap);
    MAP M = Map(P);
    POINT Q = PosPlayer(M);
    int MapID = IdGraph(P);
    int i=0, j=0;
    int DetailCandidate[4];
    for(i=0; i<nbWahana; i++){
        if(ActiveWahana[i].MapWahana == MapID && PosX(ActiveWahana[i]) == Q.X + 1 && PosY(ActiveWahana[i]) == Q.Y){
            DetailCandidate[j] = i;
            j++;
        }
        if(ActiveWahana[i].MapWahana == MapID && PosX(ActiveWahana[i]) == Q.X && PosY(ActiveWahana[i]) == Q.Y + 1){
            DetailCandidate[j] = i;
            j++;
        }
        if(ActiveWahana[i].MapWahana == MapID && PosX(ActiveWahana[i]) == Q.X - 1 && PosY(ActiveWahana[i]) == Q.Y){
            DetailCandidate[j] = i;
            j++;
        }
        if(ActiveWahana[i].MapWahana == MapID && PosX(ActiveWahana[i]) == Q.X && PosY(ActiveWahana[i]) == Q.Y - 1){
            DetailCandidate[j] = i;
            j++;
        }
    }
    if(j==0){
        printf("Tidak ada wahana didekat anda!\n");
    }else{
        printf("List wahana yang bisa dilihat detailnya:\n");
        for(i=0; i<j; i++){
            printf("%d. ", i+1);
            PrintName(ActiveWahana[i]);
            printf("\n");
        }
        printf("Masukkan nomor wahana yang ingin dilihat:\n");
        ADVKATA();
        i = DetailCandidate[ToInt(CKata)-1];
        PrintDetailWahana(ActiveWahana[i]);
    }
}


void OFFICE(){
    Kata Details;
	Kata Report;
    Kata Exit;
    Details.Length = 7;
    Details.TabKata[0] = 'd';
    Details.TabKata[1] = 'e';
    Details.TabKata[2] = 't';
    Details.TabKata[3] = 'a';
    Details.TabKata[4] = 'i';
    Details.TabKata[5] = 'l';
    Details.TabKata[6] = 's';
	Report.Length = 6;
    Report.TabKata[0] = 'r';
    Report.TabKata[1] = 'e';
    Report.TabKata[2] = 'p';
    Report.TabKata[3] = 'o';
    Report.TabKata[4] = 'r';
    Report.TabKata[5] = 't';
    Exit.Length = 4;
    Exit.TabKata[0] = 'e';
    Exit.TabKata[1] = 'x';
    Exit.TabKata[2] = 'i';
    Exit.TabKata[3] = 't';
    boolean dalamOffice = true;
    do{
        printf("// Memasuki office mode //\n");
        printf("Masukkan perintah (Details / Report / Exit):\n");
        ADVKATA();
        if(IsKataSama(CKata, Details)){
            printf("Masukkan nomor wahana yang ingin dilihat detailnya:\n");
            PrintListActiveWahana();
            ADVKATA();
            PrintDetailWahana(ActiveWahana[ToInt(CKata)-1]);
        }
        else if(IsKataSama(CKata, Report)){
            printf("Masukkan nomor wahana yang ingin dilihat reportnya:\n");
            PrintListActiveWahana();
            ADVKATA();
            LaporanWahana(ActiveWahana[ToInt(CKata)-1]);
        }
        else if(IsKataSama(CKata, Exit)){
            dalamOffice = false;
        }
        else{
            printf("Perintah tidak valid.\n");
        }
    }while(dalamOffice);
}

void MainPhase(int day){
	/* I.S.: sembarang
	 * F.S.: state game berubah sesuai aksi player pada prep. phase
	 * proses: mensimulasikan prep. phase
	 */
	/* KAMUS LOKAL */
	/* konstanta yang bisa diganti-ganti */
	/* konstanta kata */
	Kata W;
	Kata A;
	Kata S;
	Kata D;
	Kata Serve;
	Kata Repair;
	Kata Detail;
	Kata Office;
    Kata Prepare;
	W.Length = 1;
	W.TabKata[0] = 'w';
	A.Length = 1;
	A.TabKata[0] = 'a';
	S.Length = 1;
	S.TabKata[0] = 's';
	D.Length = 1;
	D.TabKata[0] = 'd';
    Serve.Length = 5;
    Serve.TabKata[0] = 's';
    Serve.TabKata[1] = 'e';
    Serve.TabKata[2] = 'r';
    Serve.TabKata[3] = 'v';
    Serve.TabKata[4] = 'e';
    Repair.Length = 6;
    Repair.TabKata[0] = 'r';
    Repair.TabKata[1] = 'e';
    Repair.TabKata[2] = 'p';
    Repair.TabKata[3] = 'a';
    Repair.TabKata[4] = 'i';
    Repair.TabKata[5] = 'r';
    Detail.Length = 6;
    Detail.TabKata[0] = 'd';
    Detail.TabKata[1] = 'e';
    Detail.TabKata[2] = 't';
    Detail.TabKata[3] = 'a';
    Detail.TabKata[4] = 'i';
    Detail.TabKata[5] = 'l';
    Office.Length = 6;
    Office.TabKata[0] = 'o';
    Office.TabKata[1] = 'f';
    Office.TabKata[2] = 'f';
    Office.TabKata[3] = 'i';
    Office.TabKata[4] = 'c';
    Office.TabKata[5] = 'e';
    Prepare.Length = 7;
    Prepare.TabKata[0] = 'p';
    Prepare.TabKata[1] = 'r';
    Prepare.TabKata[2] = 'e';
    Prepare.TabKata[3] = 'p';
    Prepare.TabKata[4] = 'a';
    Prepare.TabKata[5] = 'r';
    Prepare.TabKata[6] = 'e';
	/* variabel */
	JAM START_JAM = MakeJAM(9,0,0); /* jam mulai prep. phase */
	JAM END_JAM = MakeJAM(21,0,0); /* jam selesai prep. phase */
    Sekarang = START_JAM;
	/* ALGORITMA */
	/* init */
	InitializeMainPhase();
	boolean selesai = false;
	/* simulasi prep. phase, pakai do-while karena pasti jalan setidaknya sekali */
	do {
        printf("\nMain phase day %d\n", day);
		ShowMainPhaseState(Sekarang, END_JAM);
		printf("Masukkan perintah:\n$ ");
		ADVKATA();
        if (IsKataSama(CKata, W)){
			/* mindah koordinat player ke atas */
			move('w',&GraphMap);
            MinuteUpdate();
		} 
		else if (IsKataSama(CKata, A)){
			/* mindah koordinat player ke kiri */
			move('a',&GraphMap);
            MinuteUpdate();
		} 
		else if (IsKataSama(CKata, S)){
			/* mindah koordinat player ke bawah */
			move('s',&GraphMap);
            MinuteUpdate();
		} 
		else if (IsKataSama(CKata, D)){
			/* mindah koordinat player ke kanan */
			move('d',&GraphMap);
            MinuteUpdate();
		} 
		else if (IsKataSama(CKata, Serve)){
            ADVKATA();
            if(Durasi(Sekarang,END_JAM)<600){
                 printf("Waktu anda kurang untuk aksi ini");
            }else if(CheckAntrianAdj(GraphMap)){
                SERVE(CKata);
            }else{
                printf("Anda tidak di dekat antrian\n");
            }
        }
        else if (IsKataSama(CKata, Detail)){
            DETAIL();
        }
        else if (IsKataSama(CKata, Office)){
            if(IsInOffice(GraphMap)){
                OFFICE();
            }else{
                printf("Anda tidak di dalam office\n");
            }
        }
        else if (IsKataSama(CKata, Repair)){
            if(Durasi(Sekarang,END_JAM)<600){
                printf("Waktu anda kurang untuk aksi ini");
            }else{
                REPAIR();
            }
        }
        else if (IsKataSama(CKata, Prepare)){
            selesai = true;
        }
        else{
            printf("Perintah tidak valid.\n");
        }
	} while (!selesai && JLT(Sekarang, END_JAM));
}