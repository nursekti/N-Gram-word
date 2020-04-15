/* EL2208 Praktikum Pemecahan Masalah dengan C 2019/2020
* MODUL 8 – TUGAS BESAR
* Kelompok : D-2
* Hari dan Tanggal : Sabtu, 15 April 2020
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

int main(){
    FILE *fileku;
    node *isifile;
    char filename[50];
    int n, x, count, row, nhuruf;
    tabelngram *tabel;
    system("cls");
    Interface();
    printf("Masukkan nama file: ");
    scanf("%s", &filename);
    fileku = fopen(filename, "r");
    system("cls");
    while(strcmp(filename, "xxx")!=0){
        isifile = NULL;
        count = 0;
        row = 0;
        BacaFile(fileku, &isifile, &count);
        printf("Masukkan nilai n untuk n-gram: ");
        scanf("%d", &n);
        NGram(isifile, count, &tabel, n, &row);
        printf("Masukkan jumlah kata yang ingin dicetak: ");
        scanf("%d", &x);
        while(x!=-99){
            CetakKata(tabel, n, x, row);
            printf("\n\n");
            printf("Masukkan jumlah kata yang ingin dicetak (-99 untuk kembali ke interface): ");
            scanf("%d", &x);
        }
        system("cls");
        Interface();
        printf("Masukkan nama file: ");
        scanf("%s", &filename);
        fileku = fopen(filename, "r");
        system("cls");
    }
    return 0;
}
