/* EL2208 Praktikum Pemecahan Masalah dengan C 2019/2020
* MODUL 9 – TUGAS BESAR
* Kelompok : D-2
* Hari dan Tanggal : Sabtu, 11 April 2020
* Asisten (NIM) : Irfan Tito Kurniawan (18317019)
* Nama File : pushpopprint.h
* Deskripsi : Fungsi Push pop dan Print-
* Fungsi push mengambil pointer node *S char dengan keluaran pointer node *S
* Fungsi pop untuk mengeluarkan stack teratas
* Fungsi cetakList untuk mencetak list
*/


node* push(node* S, char c[20]){
    node *temp = (node*)malloc(sizeof(node));
    node *iter;
    strcpy(temp->kata, c);
    temp->next = NULL;
    if (S==NULL){
        S = temp;
    } else{
        iter = S;
        while (iter->next!=NULL){
            iter = iter->next;
        }
        iter->next = temp;
    }
    return S;
}

node* pop(node* S){
    node *temp;
    temp = S->next;
    return temp;
}

void cetaklist(node* S){
    node *temp = S;
    while (temp!=NULL){
        printf("%s ", temp->kata);
        temp = temp->next;
    }
    printf("\n");
}
