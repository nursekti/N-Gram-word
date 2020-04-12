/* EL2208 Praktikum Pemecahan Masalah dengan C 2019/2020
* MODUL 8 – TUGAS BESAR
* Kelompok : D-2
* Hari dan Tanggal : Sabtu, 11 April 2020
* Asisten (NIM) : Irfan Tito Kurniawan (18317019)
* Nama File : main.c
* Deskripsi : N-gram
*/



#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "ngram.h"
#include "Find+AmbilNword.h"
#include "pushpopprint.h"
#include "bacafile&carilist.h"
#include "randomcetak.h"
#include "Nvalue.h"

typedef struct tubes{
    char kata[20];
    struct tubes *next;
} node;

typedef struct{
    char *key;
    char value[20];
} tabelngram;

int main(){
    FILE *fileku;
    node *isifile;
    char filename[50];
    int n, x, count;
    tabelngram *tabel;
    isifile = NULL;
    count = 0;

    printf("Masukkan nama file: ");
    scanf("%s", &filename);
    fileku = fopen(filename, "r");

    while(strcmp(filename, "xxx")!=0){
        bacafile(fileku, &isifile, &count);
        cetaklist(isifile);
        printf("%d\n", count);
        printf("Masukkan nilai n untuk n-gram: ");
        scanf("%d", &n);

        do{
            ngram(isifile, count, tabel, n);
            printf("Masukkan jumlah kata yang ingin dicetak: ");
            scanf("%d", &x);
            cetakkata(tabel,n, x, count);
        } while(x!=-99);

        printf("Masukkan nama file: ");
        scanf("%s", &filename);
        fileku = fopen(filename, "r");
    }
}
