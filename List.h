/* EL2208 Praktikum Pemecahan Masalah dengan C 2019/2020
* MODUL 9 – TUGAS BESAR
* Kelompok : D-2
* Hari dan Tanggal : Kamis, 16 April 2020
* Asisten (NIM) : Irfan Tito Kurniawan (18317019)
* Nama File : List.h
* Deskripsi : Bagian ini berisi fungsi untuk memproses Linked List
* Push berfungsi untuk menge-push tiap string dari file masukan ke sebuah Linked List
* CariList berfungsi untuk mencari kata pada List untuk dimasukkan ke Key dari tabel NGram
*/

//Fungsi push dengan tipe variable node
node* Push(node* S, char c[20]){                //Deklarasi fungsi node* Push dengan masukkan node* S, dan string c berisi 20 karakter
    node *temp = (node*)malloc(sizeof(node));   //Pengalokasian node* temp
    node *iter;                                 //Deklarasi node *iter
    strcpy(temp->kata, c);                      //mencopy string C ke kata       
    temp->next = NULL;                          //mengkosongkan next
    if (S==NULL){                               // jika node *S sama kosong
        S = temp;                               // S=temp
    } else{                                     // Jika node *S tidak kosong
        iter = S;                               // iter = S
        while (iter->next!=NULL){               // ketika node *iter next tidak kosong
            iter = iter->next;                  // pointer iter = next
        }
        iter->next = temp;                      // mengisi nilai temp ke pointer next
    }
    return S;                                   // return S
}


//Fungsi CariList dengan masukkan node *S, integer n dan string x dengan 20 karakter
void CariList(node *S, int n, char x[20]){
    node *temp;                             //Deklarasi variable node *temp
    int i;                                  //Deklarasi integer i
    temp = (node*)malloc(sizeof(node));     //Pengalokasian temp
    temp = S;                               //temp =S
    for(i=0; i<n; i++){                     //Jika i<n
        temp = temp->next;                  //temp akan berisi data pada pointer next
    }
    strcpy(x, temp->kata);                  //mencopy data dari pointer temp variable kata ke variable x
}
