/* EL2208 Praktikum Pemecahan Masalah dengan C 2019/2020
* MODUL 9 – TUGAS BESAR
* Kelompok : D-2
* Hari dan Tanggal : Senin, 13 April 2020
* Asisten (NIM) : Irfan Tito Kurniawan (18317019)
* Nama File : cetakngram.h
* Deskripsi : menyetak tabel ngram
*/

void cetakngram(tabelngram *tabel, int row){
    int i, j;
    for(i=0; i<row; i++){
        printf("%s\n", tabel[i].key);
        j = 0;
        while(strcmp(tabel[i].value[j], " ")!= 0){
            printf("%s, ", tabel[i].value[j]);
            j++;
        }
        printf("\n");
    }
    printf("%d\n", row);
}
