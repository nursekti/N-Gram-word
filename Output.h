/* EL2208 Praktikum Pemecahan Masalah dengan C 2019/2020
* MODUL 9 – TUGAS BESAR - Soal 2 Ngram
* Kelompok : D-2
* Hari dan Tanggal : Rabu, 15 April 2020
* Asisten (NIM) : Irfan Tito Kurniawan (18317019)
* Nama File : Output.h
* Deskripsi : Library ini berisi empat fungsi yang arahnya untuk mengeluarkan output. 
* Yang Pertama adalah Random yang berguna untuk merandom indeks dari Key pada N-gram ketika akan mengambil key pertama untuk 
* menyusun keluaran dan indeks dari value yang akan dicetak pada key tertentu.
* Yang kedua adalah NValue yang menghitung banyaknya value dari suatu key.
* Yang ketiga adalah AmbilNWord yang mengambil N kata terakhir dari suatu string, dalam implemantasinya yang diambil selalu satu 
* kurangnya dari banyak kata, kecuali kata pertama (menghapus kata pertama).
* Yang keempat adalah CetakKata yang digunakan untuk mencetak kata sebanyak yang diminta pengguna berdasarkan tabel ngram yang telah 
* dibuat sebelumnya.
*/

void Random(int *n, int count){
    srand(time(0)); //merandom seed
    *n = (rand()%count); //menghasilkan kata random dari 0 hingga (count-1)
}

void NValue(tabelngram *tabel, int i, int *p){
    while(strcmp(tabel[i].value[*p], " ") != 0){    //value yang ada isinya adalah yang bukan " " (spasi) saja
        (*p)++; 
    }
}

void AmbilNWord(char *Hasil[])
{
    int len;
    len = strlen(*Hasil);
    char temp[len];
    char* y;
    y = strtok((*Hasil), " ");  //mengambil kata pertama
    y = strtok(NULL, " ");  //mengambil kata kedua
    strcpy(temp, y);    //menyimpan kata kedua ke variabel temp
    while(y!=NULL){     //menyimpan kata ketiga hingga kata terakhir dalam variabel temp
        y = strtok(NULL, " ");
        if(y!=NULL){
            strcat(temp, " ");
            strcat(temp, y);
        }
    }
    strcpy((*Hasil), temp);
}

void CetakKata(tabelngram *tabel, int n, int x, int row){
    int i, j, nkata, p;
    char *help;
    help = (char*)malloc(((n+1)*100)*sizeof(char));
    Random(&i, row);
    printf("... %s", tabel[i].key);
    strcpy(help, tabel[i].key);
    nkata = n+1;
    while(nkata<=x){
        p = 0;
        i = CariWords(help, tabel, row);    //mencari indeks key yang kata-katanya sama dengan string pada variabel help
        NValue(tabel, i, &p);   //menghitung banyak value pada key dengan indeks i
        Random(&j, p);  //merandom indeks value yang akan dicetak
        printf("%s ", tabel[i].value[j]);
        strcat(help, tabel[i].value[j]);
        AmbilNWord(&help);  //menghapus kata pertama dari string di variabel help
        strcat(help, " ");
        nkata++;
    }
    printf("...");
}
