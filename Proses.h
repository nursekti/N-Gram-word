/* EL2208 Praktikum Pemecahan Masalah dengan C 2019/2020
* MODUL 9 – TUGAS BESAR
* Kelompok : D-2
* Hari dan Tanggal : Senin, 13 April 2020
* Asisten (NIM) : Irfan Tito Kurniawan (18317019)
* Nama File : Proses.h
* Deskripsi : Terdiri dari dua fungsi-prosedur yaitu CariWords() dan NGram()
*             - CariWords() berguna untuk mencari indeks dari key yang sesuai dengan n kata yang dimasukkan. 
*               N kata tersebut terlebih dahulu diambil dari susunan kata dari keluaran yang sedang di generate.
*             - NGram() berguna untuk memasukkan kata-kata dari file eksternal ke dalam suatu NGram dengan jumlah N yang
*               bergantung pada masukan N di Main.c
*/

int CariWords(char* nword, tabelngram *tabel, int panjang)
{
    int i;
    i = 0;
    while (i <= panjang){
        if (strcmp(nword, tabel[i].key) == 0){
            return i;
        } else{
            i++;
        }
    }
    return 0;
}

void NGram(node *S, int count, tabelngram **tabel, int n, int *row){
    int i, j, k, x;
    char help[100], *bantu;
    node *temp;
    *tabel = (tabelngram*)malloc(count*sizeof(tabelngram));
    bantu = (char*)malloc((n*50)*sizeof(char));
    for(i = 0; i < count; i++){
        (*tabel)[i].key = (char*)malloc((n*50)*sizeof(char));
        for(j = 0; j < 20; j++){
            (*tabel)[i].value[j] = (char*)malloc(15*sizeof(char));
            strcpy((*tabel)[i].value[j], " ");
        }
    }
    temp = (node*)malloc(sizeof(node));
    temp = S;
    for(i = 0; i < count; i++){
        CariList(temp, i, help);
        strcpy(bantu, help);
        strcat(bantu, " ");
        for(j = 1; j < n; j++){
            CariList(temp, ((i+j)%count), help);
            strcat(bantu, help);
            strcat(bantu, " ");
        }
         x = CariWords(bantu, *tabel, *row);
        j = 0;
        CariList(temp, ((i+n)%count), help);
        if(x == 0){
            strcpy((*tabel)[*row].key, bantu);
            strcpy((*tabel)[*row].value[0], help);
            (*row)++;
        } else{
            while((strcmp((*tabel)[x].value[j], " ") != 0)&&(strcmp((*tabel)[x].value[j], help) != 0)){
                j++;
            }
            strcpy((*tabel)[x].value[j], help);
        }
    }
}
