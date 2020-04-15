/* EL2208 Praktikum Pemecahan Masalah dengan C 2019/2020
* MODUL 9 – TUGAS BESAR
* Kelompok : D-2
* Hari dan Tanggal : Rabu, 15 April 2020
* Asisten (NIM) : Irfan Tito Kurniawan (18317019)
* Nama File : Input.h
* Deskripsi : Membaca file eksternal (.txt) yang diinput oleh program utama dan memasukkannya ke dalam Linked-List
*             sebelum akhirnya dimasukkan ke dalam tabel NGram (array) oleh fungsi NGram().
*/

void BacaFile(FILE *S, node **x, int *count){
    char temp[100];
    while(!feof(S)){                    //While loop sampai mencapai end of file (feof)
        fscanf(S, "%s", temp);          //Memasukkan file ke dalam array temp (unruk wadah sementara) tiap stringnya
        *x = Push(*x, temp);            //Menge-push string dalam file temp tadi ke suatu linked-list x
        (*count)++;                     //Program juga menghitung banyaknya string yang ada untuk mencari tahu ukuran banyaknya string dalam file
    }
}
