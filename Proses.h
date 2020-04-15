/* EL2208 Praktikum Pemecahan Masalah dengan C 2019/2020
* MODUL 9 – TUGAS BESAR
* Kelompok : D-2
* Hari dan Tanggal : Rabu, 15 April 2020
* Asisten (NIM) : Irfan Tito Kurniawan (18317019)
* Nama File : Proses.h
* Deskripsi : Terdiri dari dua fungsi-prosedur yaitu CariWords() dan NGram()
*             - CariWords() berguna untuk mencari indeks dari key yang sesuai dengan n kata yang dimasukkan. 
*               N kata tersebut terlebih dahulu diambil dari susunan kata dari keluaran yang sedang di generate.
*             - NGram() berguna untuk memasukkan kata-kata dari Linked List yang berisi string dari file eksternal,
*               ke dalam suatu NGram dengan jumlah N kata key yang bergantung pada masukan N di Main.c
*/

int CariWords(char* nword, tabelngram *tabel, int panjang)
{
    int i;
    i = 0;
    while (i <= panjang){                           //While loop sampai akhir array (indeks terakhir)
        if (strcmp(nword, tabel[i].key) == 0){      //Membandingkan nword yang dicari dengan key per indeks
            return i;                               //Mengembalikan nilai indeks jika ditemukan kecocokan string
        } else{
            i++;                                    //Jika tidak ditemukan, lanjut mencari di indeks selanjutnya
        }
    }
    return 0;
}

void NGram(node *S, int count, tabelngram **tabel, int n, int *row){
    int i, j, k, x;
    char help[100], *bantu;
    node *temp;
    *tabel = (tabelngram*)malloc(count*sizeof(tabelngram));
    bantu = (char*)malloc((n*50)*sizeof(char));
    for(i = 0; i < count; i++){                                       //mengalokasi memori key dan value pada tabel
        (*tabel)[i].key = (char*)malloc((n*50)*sizeof(char));
        for(j = 0; j < 20; j++){
            (*tabel)[i].value[j] = (char*)malloc(15*sizeof(char));
            strcpy((*tabel)[i].value[j], " ");                      //menginiasialisasi semua value dengan " "
        }
    }
    temp = (node*)malloc(sizeof(node));
    temp = S;
    for(i = 0; i < count; i++){
        CariList(temp, i, help);            //mancari kata urutan ke-i dari list temp, lalu disimpan ke variabel help
        strcpy(bantu, help);                //mengkopi string pada help ke variabel bantu
        strcat(bantu, " ");
        for(j = 1; j < n; j++){             //mengulangi pembacaan list dan disimpan ke temp hingga n kata tersimpan
            CariList(temp, ((i+j)%count), help);
            strcat(bantu, help);
            strcat(bantu, " ");
        }
         x = CariWords(bantu, *tabel, *row);    //mengecek apakah sudah ada string bantu pada key, jika ada, x merujuk ke indeks tersebut
        j = 0;
        CariList(temp, ((i+n)%count), help);    //mancari kata urutan ke-((i+n)%count) dari list temp, lalu disimpan ke variabel help
        if(x == 0){                             //jika tidak ada string bantu yang tersimpan pada key
            strcpy((*tabel)[*row].key, bantu);
            strcpy((*tabel)[*row].value[0], help);
            (*row)++;
        } else{                                 //jika ada string bantu yang tersimpan pada key
            while((strcmp((*tabel)[x].value[j], " ") != 0)&&(strcmp((*tabel)[x].value[j], help) != 0)){
                j++;    //mencari posisi value kosong pada row ke x dari tabel
            }
            strcpy((*tabel)[x].value[j], help);
        }
    }
}
