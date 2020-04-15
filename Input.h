/* EL2208 Praktikum Pemecahan Masalah dengan C 2019/2020
* MODUL 9 – TUGAS BESAR
* Kelompok : D-2
* Hari dan Tanggal : Rabu, 15 April 2020
* Asisten (NIM) : Irfan Tito Kurniawan (18317019)
* Nama File : Input.h
* Deskripsi : Membaca file eksternal (.txt) yang diinput oleh program utama supaya dapat
*             dimasukkan ke dalam tabel NGram.
*/

void BacaFile(FILE *S, node **x, int *count){
    char temp[100];
    while(!feof(S)){
        fscanf(S, "%s", temp);
        *x = Push(*x, temp);
        (*count)++;
    }
}
