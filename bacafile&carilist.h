/* EL2208 Praktikum Pemecahan Masalah dengan C 2019/2020
* MODUL 9 – TUGAS BESAR
* Kelompok : D-2
* Hari dan Tanggal : Sabtu, 11 April 2020
* Asisten (NIM) : Irfan Tito Kurniawan (18317019)
* Nama File : bacafile&carilist.h
* Deskripsi : membaca file eksternal dan mencari kata di dalam linked list
*/

void bacafile(FILE *S, node **x, int *count){
    char temp[20];
    while(!feof(S)){
        fscanf(S, "%s", temp);
        *x = push(*x, temp);
        (*count)++;
    }
}

void carilist(node *S, int n, char x[20]){
    node *temp;
    int i;
    temp = (node*)malloc(sizeof(node));
    temp = S;
    for(i=0; i<n; i++){
        temp = temp->next;
    }
    strcpy(x, temp->kata);
}
