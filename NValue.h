/* EL2208 Praktikum Pemecahan Masalah dengan C 2019/2020
* MODUL 9 – TUGAS BESAR - Soal 2 Ngram
* Kelompok : D-2
* Hari dan Tanggal : Minggu, 12 April 2020
* Asisten (NIM) : Irfan Tito Kurniawan (18317019)
* Nama File : NValue.h
* Deskripsi : Fungsi dalam library ini berfungsi untuk memastikan suatu value dalam suatu key sudah terisi atau belum dengan 
* sebuah string, jika sudah maka string akan disimpan di value berikutnya, jika belum maka string akan disimpan pada value tersebut.
*/

int nvalue(tabelngram *tabel, int i, int *p)
{
    while(strcmp(tabel[i].value[*p], " ") != 0)
    {
        (*p)++;
    }
    return (*p);
}
