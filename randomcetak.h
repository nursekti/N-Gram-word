/* EL2208 Praktikum Pemecahan Masalah dengan C 2019/2020
* MODUL 9 – TUGAS BESAR - Soal 2 Ngram
* Kelompok : D-2
* Hari dan Tanggal : Sabtu, 11 April 2020
* Asisten (NIM) : Irfan Tito Kurniawan (18317019)
* Nama File : randomcetak.h
* Deskripsi : Library ini berisi dua fungsi, yang pertama adalah random yang berguna untuk merandom indeks dari Key pada N-gram ketika akan 
* mengambil key pertama untuk menyusun keluaran.
* Sementara itu fungsi (prosedur) kedua adalah cetak kata yang berguna untuk mencetak keluar kata dari N-gram (menyusun keluaran)
*/

int random(int *n, int count){
    *n = (rand()%20);
    return *n;
}

void cetakkata(tabelngram *tabel, int n, int x, int row){
    int i, j, nkata, p;
    char *help;
    help = (char*)malloc((n*50)*sizeof(char));
    p = 0;
    random(&i, row);
    printf("%s", tabel[i].key);
    strcpy(help, tabel[i].key);
    nkata = n+1;
   
    while(nkata <= x)
    {
        i = findwords(help, tabel, row);
        p = nvalue(tabel, i, &p);
        random(&j, p);
        
        printf("%s ", tabel[i].value[j]);
        strcat(help, tabel[i].value[j]);
        AmbilNWord(&help, n);
        strcat(help, " ");
        nkata++;
    }
}
