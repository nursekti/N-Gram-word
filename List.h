/* EL2208 Praktikum Pemecahan Masalah dengan C 2019/2020
* MODUL 9 – TUGAS BESAR
* Kelompok : D-2
* Hari dan Tanggal : Sabtu, 15 April 2020
* Asisten (NIM) : Irfan Tito Kurniawan (18317019)
* Nama File : List.h
* Deskripsi : Bagian ini berisi fungsi untuk memproses Linked List
* Push berfungsi untuk menge-push tiap string dari file masukan ke sebuah Linked List
* CariList berfungsi untuk mencari kata pada List untuk dimasukkan ke Key dari tabel NGram
*/

node* Push(node* S, char c[20]){
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

void CariList(node *S, int n, char x[20]){
    node *temp;
    int i;
    temp = (node*)malloc(sizeof(node));
    temp = S;
    for(i=0; i<n; i++){
        temp = temp->next;
    }
    strcpy(x, temp->kata);
}
