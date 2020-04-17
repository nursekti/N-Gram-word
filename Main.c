/* EL2208 Praktikum Pemecahan Masalah dengan C 2019/2020
* MODUL 8 – TUGAS BESAR
* Kelompok : D-2
* Hari dan Tanggal : Minggu, 12 April 2020
* Asisten (NIM) : Irfan Tito Kurniawan (18317019)
* Nama File : main.c
* Deskripsi : Program Utama dan interface dari program yang berisi tampilan awal program serta perintah-perintah untuk
*             menjalankan program. Selain itu juga terdapat deklarasi Typedef Struct dan Pembagian header file dan library yang digunakan
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

//Deklarasi Typedef Struct node untuk Linked List
typedef struct tubes{
    char kata[100];
    struct tubes *next;
} node;

//Deklarasi Typedef Struct tabelngram untuk mengkonstruksi tabel NGram
typedef struct{
    char *key;
    char *value[20];
} tabelngram;

//Pemanggilan header file
#include "List.h"
#include "Input.h"
#include "Proses.h"
#include "Output.h"


//Fungsi untuk memanggil interface tampilan pertama saat menjalankan program
void Interface() {
    printf("Selamat Datang di Program N-Gram Processing\n");
    printf("Petunjuk penggunaan: \n");
    printf("1. Masukkan nama file dengan benar sesuai yang ada dalam folder penyimpanan program\n");
    printf("2. Masukkan nilai n yang digunakan untuk N-Gram Processing\n");
    printf("3. Masukkan jumlah kata yang ingin dicetak \n");
    printf("4. Jika Anda mengisi nilai -99 pada kolom jumlah kata yang ingin dicetak, \n");
    printf("   program akan kembali ke interface\n");
    printf("5. Untuk mengakhiri program masukkan input xxx pada masukan nama file \n");
    printf("----------------------------------------------------------------------------------------\n");
    return;}

//Program Utama
int main(){
    FILE *fileku;                           //Deklarasi File Ekstrenal
    node *isifile;
    char filename[50];
    int n, x, count, row, nhuruf;           //Deklarasi variable n, x, count, row, nhuruf
    tabelngram *tabel;                      // Deklarasi struct tabelngram bernama tabel
    system("cls");
    Interface();                            //Memanggil Interface()
    printf("Masukkan nama file: ");         
    scanf("%s", &filename);                 //Meminta masukkan nama file
    fileku = fopen(filename, "r");                   // Operasi read file
    system("cls");
    while(strcmp(filename, "xxx")!=0){               //Jika nama file ditemukan
        isifile = NULL;                              //isifile menjadi kosong(NULL)
        count = 0;                                   //count dimulai dari 0
        row = 0;                                     //row dimulai dari nol
        BacaFile(fileku, &isifile, &count);          //Memanggil fungsi BacaFile(fileku, &isifile, &count) untuk membaca file yang telah dimasukan
        printf("Masukkan nilai n untuk n-gram: ");    
        scanf("%d", &n);                            //Meminta masukan nilai n
        NGram(isifile, count, &tabel, n, &row);     //Memanggil fungsi NGram(isifile, count, &tabel, n, &row) untuk membuat tabel n-gram
        printf("Masukkan jumlah kata yang ingin dicetak: ");
        scanf("%d", &x);                            //Meminta masukkan nilai x yaitu jumlah kata yang ingin dicetak
        while(x!=-99){                              //Ketika x tidak sama dengan -99 maka
            CetakKata(tabel, n, x, row);            //Memanggil fungsi CetakKata(tabel, n, x, row) untuk mencetak kata sesuai hasil n gram sebanyak x kata
            printf("\n\n");
            printf("Masukkan jumlah kata yang ingin dicetak (-99 untuk kembali ke interface): ");
            scanf("%d", &x);                        //Meminta masukkan x jumlah kata kembali
        }
        system("cls");
        Interface();                                //Jika x jumlah kata yang dimasukan sama dengan -99 maka fungsi Interface() dipanggil
        printf("Masukkan nama file: ");             
        scanf("%s", &filename);                     //Meminta masukkan nama file kembali
        fileku = fopen(filename, "r");              //Operasi read file
        system("cls");
    }
    return 0;                                       //Jika nama file tidak ada dalam folder penyimpanan, program akan langsung mereturn 0
}
