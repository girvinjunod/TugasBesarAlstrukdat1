#include <stdio.h>
#include "matriks.h"
#include "boolean.h"


void MakeMATRIKS (int NB, int NK, MATRIKS * M){
/* Membentuk sebuah MATRIKS "kosong" yang siap diisi berukuran NB x NK di "ujung kiri" memori */
/* I.S. NB dan NK adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks M sesuai dengan definisi di atas terbentuk */
    (*M).NBrsEff = NB;
    (*M).NKolEff = NK;
    int i,j;
    for (i = 0; i < NB; i++){
        for (j = 0; j < NK; j++){
            (*M).Mem[i][j] = 0;
        }
    }
}

/* *** Selektor "DUNIA MATRIKS" *** */
boolean IsIdxValid (int i, int j){
/* Mengirimkan true jika i, j adalah indeks yang valid untuk matriks apa pun */
	return (i >= BrsMin && i <= BrsMax && j >= KolMin && j <= KolMax);
}
/* *** Selektor: Untuk sebuah matriks M yang terdefinisi: *** */
indeks GetFirstIdxBrs (MATRIKS M){
/* Mengirimkan indeks baris terkecil M */
	return BrsMin;
}
indeks GetFirstIdxKol (MATRIKS M){
/* Mengirimkan indeks kolom terkecil M */
	return KolMin;
}
indeks GetLastIdxBrs (MATRIKS M){
/* Mengirimkan indeks baris terbesar M */
	return M.NBrsEff - 1;
}
indeks GetLastIdxKol (MATRIKS M){
/* Mengirimkan indeks kolom terbesar M */
	return M.NKolEff - 1;
}
boolean IsIdxEff (MATRIKS M, indeks i, indeks j){
/* Mengirimkan true jika i, j adalah indeks efektif bagi M */
	return (i >= GetFirstIdxBrs(M) && i <= GetLastIdxBrs(M) && j >= GetFirstIdxKol(M) && j <= GetLastIdxKol(M));
}
ElType GetElmtDiagonal (MATRIKS M, indeks i){
/* Mengirimkan elemen M(i,i) */
	return M.Mem[i][i];
}

/* ********** Assignment  MATRIKS ********** */
void CopyMATRIKS (MATRIKS MIn, MATRIKS * MHsl){
/* Melakukan assignment MHsl  MIn */
	MakeMATRIKS(MIn.NBrsEff, MIn.NKolEff, MHsl);
    int i,j;
    for (i = GetFirstIdxBrs(*MHsl); i <= GetLastIdxBrs(*MHsl); i++) for (j = GetFirstIdxKol(*MHsl); j <= GetLastIdxKol(*MHsl); j++)(*MHsl).Mem[i][j] = MIn.Mem[i][j];
}

/* ********** KELOMPOK BACA/TULIS ********** */ 
void BacaMATRIKS (MATRIKS * M, int NB, int NK){
/* I.S. IsIdxValid(NB,NK) */ 
/* F.S. M terdefinisi nilai elemen efektifnya, berukuran NB x NK */
/* Proses: Melakukan MakeMATRIKS(M,NB,NK) dan mengisi nilai efektifnya */
/* Selanjutnya membaca nilai elemen per baris dan kolom */
/* Contoh: Jika NB = 3 dan NK = 3, maka contoh cara membaca isi matriks :
1 2 3
4 5 6
8 9 10 
*/
    MakeMATRIKS(NB, NK, M);
    int i,j;
    for (i = GetFirstIdxBrs(*M); i <= GetLastIdxBrs(*M); i++)for (j = GetFirstIdxKol(*M); j <= GetLastIdxKol(*M); j++) scanf("%d", &((*M).Mem[i][j]));
}
void TulisMATRIKS (MATRIKS M){
/* I.S. M terdefinisi */
/* F.S. Nilai M(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris 
   dipisahkan sebuah spasi */
/* Proses: Menulis nilai setiap elemen M ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/
	int i,j;
    for (i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++){
        for (j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++){
            if (j != GetLastIdxKol(M)) printf("%d ", M.Mem[i][j]);
            else {
            	if (i != GetLastIdxBrs(M)) printf("%d\n", M.Mem[i][j]);
            	else printf("%d", M.Mem[i][j]);
			}
        }
    }
}
/* ********** KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE ********** */                                  
MATRIKS TambahMATRIKS (MATRIKS M1, MATRIKS M2){
/* Prekondisi : M1  berukuran sama dengan M2 */
/* Mengirim hasil penjumlahan matriks: M1 + M2 */
    MATRIKS M3;
    MakeMATRIKS(M1.NBrsEff, M1.NKolEff, &M3);
    int i,j;
    for (i = GetFirstIdxBrs(M3); i <= GetLastIdxBrs(M3); i++) for (j = GetFirstIdxKol(M3); j <= GetLastIdxKol(M3); j++) M3.Mem[i][j] = M1.Mem[i][j] + M2.Mem[i][j];
    return M3;
}
MATRIKS KurangMATRIKS (MATRIKS M1, MATRIKS M2){
/* Prekondisi : M berukuran sama dengan M */
/* Mengirim hasil pengurangan matriks: salinan M1 – M2 */ 
    MATRIKS M3;
    MakeMATRIKS(M1.NBrsEff, M1.NKolEff, &M3);
    int i,j;
    for (i = GetFirstIdxBrs(M3); i <= GetLastIdxBrs(M3); i++) for (j = GetFirstIdxKol(M3); j <= GetLastIdxKol(M3); j++) M3.Mem[i][j] = M1.Mem[i][j] - M2.Mem[i][j];
    return M3;
}
MATRIKS KaliMATRIKS (MATRIKS M1, MATRIKS M2){
/* Prekondisi : Ukuran kolom efektif M1 = ukuran baris efektif M2 */
/* Mengirim hasil perkalian matriks: salinan M1 * M2 */
    MATRIKS M3;
    MakeMATRIKS(M1.NBrsEff, M2.NKolEff, &M3);
    int i, j, k;
    for(i = GetFirstIdxBrs(M1); i <= GetLastIdxBrs(M1); i++){
        for(j = GetFirstIdxKol(M2); j <= GetLastIdxKol(M2); j++){
            for(k = GetFirstIdxKol(M1); k <= GetLastIdxKol(M1); k++){
                M3.Mem[i][j] += (M1.Mem[i][k]*M2.Mem[k][j]);
            }
        }
    }
    return M3;
}
MATRIKS KaliKons (MATRIKS M, ElType X){
/* Mengirim hasil perkalian setiap elemen M dengan X */
    MATRIKS M1;
    MakeMATRIKS(M.NBrsEff, M.NKolEff, &M1);
    int i,j;
    for (i = GetFirstIdxBrs(M1); i <= GetLastIdxBrs(M1); i++)for (j = GetFirstIdxKol(M1); j <= GetLastIdxKol(M1); j++) M1.Mem[i][j] = X*M.Mem[i][j];
    return M1;
}
void PKaliKons (MATRIKS * M, ElType K){
/* I.S. M terdefinisi, K terdefinisi */
/* F.S. Mengalikan setiap elemen M dengan K */
	*M = KaliKons(*M, K);
}
/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP MATRIKS ********** */
boolean EQ (MATRIKS M1, MATRIKS M2){
/* Mengirimkan true jika M1 = M2, yaitu NBElmt(M1) = NBElmt(M2) dan */
/* untuk setiap i,j yang merupakan indeks baris dan kolom M1(i,j) = M2(i,j) */
/* Juga merupakan strong EQ karena GetFirstIdxBrs(M1) = GetFirstIdxBrs(M2) 
   dan GetLastIdxKol(M1) = GetLastIdxKol(M2) */ 
    if (NBElmt(M1) != NBElmt(M2)) return false;
	else {
        int i,j;
        for (i = GetFirstIdxBrs(M1); i <= GetLastIdxBrs(M1); i++)for (j = GetFirstIdxKol(M1); j <= GetLastIdxKol(M1); j++) if (M1.Mem[i][j] != M2.Mem[i][j]) return false;
	}
    return true;
}
boolean NEQ (MATRIKS M1, MATRIKS M2){
/* Mengirimkan true jika M1 tidak sama dengan M2 */
	return (!EQ(M1, M2));
}
boolean EQSize (MATRIKS M1, MATRIKS M2){
/* Mengirimkan true jika ukuran efektif matriks M1 sama dengan ukuran efektif M2 */
/* yaitu GetBrsEff(M1) = GetNBrsEff (M2) dan GetNKolEff (M1) = GetNKolEff (M2) */
    return (M1.NBrsEff == M2.NBrsEff && M1.NKolEff == M2.NKolEff);
}
/* ********** Operasi lain ********** */
int NBElmt (MATRIKS M){
/* Mengirimkan banyaknya elemen M */
	return (M.NBrsEff*M.NKolEff);
}
/* ********** KELOMPOK TEST TERHADAP MATRIKS ********** */
boolean IsBujurSangkar (MATRIKS M){
/* Mengirimkan true jika M adalah matriks dg ukuran baris dan kolom sama */
    return (M.NBrsEff == M.NKolEff);
}
boolean IsSimetri (MATRIKS M){
/* Mengirimkan true jika M adalah matriks simetri : IsBujurSangkar(M) 
   dan untuk setiap elemen M, M(i,j)=M(j,i) */
    if (!IsBujurSangkar(M)) return false;
	else {
        int i,j;
        for (i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++) for (j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++) if (M.Mem[i][j] != M.Mem[j][i]) return false;
	}
    return true;
}
boolean IsSatuan (MATRIKS M){
/* Mengirimkan true jika M adalah matriks satuan: IsBujurSangkar(M) dan 
   setiap elemen diagonal M bernilai 1 dan elemen yang bukan diagonal bernilai 0 */ 
    if (IsBujurSangkar(M)){
        int i,j;
        for (i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++){
            for (j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++){
                if (i != j){
					if (M.Mem[i][j] != 0) return false;
				}
                else {
					if (M.Mem[i][j] != 1) return false; 
				}
            }
        }
    }
    else return false;
    return true;
}
boolean IsSparse (MATRIKS M){
/* Mengirimkan true jika M adalah matriks sparse: mariks “jarang” dengan definisi: 
   hanya maksimal 5% dari memori matriks yang efektif bukan bernilai 0 */
    int count = 0;
	int i;
	int j;
    for (i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++) for (j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++) if (M.Mem[i][j] != 0 ) count += 1;
    return (20*count <= NBElmt(M));
}
MATRIKS Inverse1 (MATRIKS M){
/* Menghasilkan salinan M dengan setiap elemen "di-invers", yaitu dinegasikan (dikalikan -1) */
	return KaliKons(M, -1);
}
float Determinan (MATRIKS M){
/* Prekondisi: IsBujurSangkar(M) */
/* Menghitung nilai determinan M */
    int size = NBrsEff(M);
    float m[size][size];
    int i, j;

    for (i = 0; i < size; i++) for (j = 0; j < size; j++) m[i][j] = Elmt(M, i, j);

    float result = 1;
    int swapped = 0;

    while (size > 0){
        boolean swap = false;
        i = 0;
        if (m[size-1][size-1] == 0){
            while (i < (size-1) && (!swap)){
                if (m[i][size-1] == 0) i++;
                else swap = true;
            }
        }
        if (i == (size-1) && (size > 1)) return 0;
		else if (swap){
            for(j = 0; j < size; j++){
                float temp = m[size-1][j];
                m[size-1][j] = m[i][j];
                m[i][j] = temp;
            }
        }
        for (i = 0; i < (size-1); i++){
            for(j=0; j<size; j++){
                m[i][j] -= m[size-1][j]*(m[i][size-1]/m[size-1][size-1]);
            }
        }
        result *= m[size-1][size-1];
        if (swap) swapped = (swapped + 1)%2;
        else swapped = swapped %2;
        size--;
    }
    float finalresult;
    if (swapped == 0) finalresult = result * 1.0f;
    else finalresult = result * -1.0f;
    if (finalresult <1 && finalresult >-1) return 0.0f;
    else return finalresult;
}
void PInverse1 (MATRIKS * M){
/* I.S. M terdefinisi */
/* F.S. M di-invers, yaitu setiap elemennya dinegasikan (dikalikan -1) */
	*M = Inverse1(*M);
}
void Transpose (MATRIKS * M){
/* I.S. M terdefinisi dan IsBujursangkar(M) */
/* F.S. M "di-transpose", yaitu setiap elemen M(i,j) ditukar nilainya dengan elemen M(j,i) */
    MATRIKS M1;
    MakeMATRIKS((*M).NBrsEff, (*M).NKolEff, &M1);

    int i,j;
    for (i = GetFirstIdxBrs(M1); i <= GetLastIdxBrs(M1); i++){
        for (j = GetFirstIdxKol(M1); j <= GetLastIdxKol(M1); j++){
            M1.Mem[i][j] = (*M).Mem[j][i];
        }
    }
    *M = M1;
}
/* Operasi berbasis baris dan per kolom */

float RataBrs (MATRIKS M, indeks i){
/* Menghasilkan rata-rata dari elemen pada baris ke-i */
/* Prekondisi: i adalah indeks baris efektif dari M */
	int sum = 0;
	int count = 0;
	int j;
	for (j = GetFirstIdxKol(M); j<=GetLastIdxKol(M);j++){
		sum = sum + Elmt(M,i,j);
		count = count +1; 
	}
	float average = sum/(count * 1.0f);
	return average;
}
float RataKol (MATRIKS M, indeks j){
/* Menghasilkan rata-rata dari elemen pada kolom ke-j */
/* Prekondisi: j adalah indeks kolom efektif dari M */
	int sum = 0;
	int count = 0;
	int i;
	for (i= GetFirstIdxBrs(M); i<=GetLastIdxBrs(M);i++){
		sum = sum + Elmt(M,i,j);
		count = count +1; 
	}
	float average = sum/(count * 1.0f);
	return average;
}
void MaxMinBrs (MATRIKS M, indeks i, ElType * max, ElType * min){
/* I.S. i adalah indeks baris efektif dari M, M terdefinisi */
/* F.S. max berisi elemen maksimum pada baris i dari M
           min berisi elemen minimum pada baris i dari M */
	int j = GetFirstIdxKol(M);
  	*max = Elmt(M, i, j);
  	*min = Elmt(M, i, j);
  	for(j; j <= GetLastIdxKol(M); j++){
   		if(Elmt(M, i, j) > *max) *max = Elmt(M, i, j); 
    	if(Elmt(M, i, j) < *min) *min = Elmt(M, i, j); 
  }
}
void MaxMinKol (MATRIKS M, indeks j, ElType * max, ElType * min){
/* I.S. j adalah indeks kolom efektif dari M, M terdefinisi */
/* F.S. max berisi elemen maksimum pada kolom j dari M
           min berisi elemen minimum pada kolom j dari M */
    int i = GetFirstIdxBrs(M);
  	*max = Elmt(M, i, j);
  	*min = Elmt(M, i, j);
  	for(i; i <= GetLastIdxBrs(M); i++){
   		if(Elmt(M, i, j) > *max) *max = Elmt(M, i, j); 
    	if(Elmt(M, i, j) < *min) *min = Elmt(M, i, j); 
  }     
}
int CountXBrs (MATRIKS M, indeks i, ElType X){
/* Menghasilkan banyaknya kemunculan X pada baris i dari M */
	int count = 0;
	int j;
	for (j= GetFirstIdxKol(M); j<= GetLastIdxKol(M); j++){
		if (Elmt(M,i,j) == X) count += 1;
	}
	return count;
}
int CountXKol (MATRIKS M, indeks j, ElType X){
/* Menghasilkan banyaknya kemunculan X pada kolom j dari M */
	int count = 0;
	int i;
	for (i = GetFirstIdxBrs(M); i<= GetLastIdxBrs(M); i++){
		if (Elmt(M,i,j) == X) count += 1;
	}
	return count;
}

