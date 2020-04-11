/* EL2208 Praktikum Pemecahan Masalah dengan C 2019/2020
* MODUL 9 – TUGAS BESAR - Soal 2 Ngram
* Kelompok : D-2
* Hari dan Tanggal : Sabtu, 11 April 2020
* Asisten (NIM) : Irfan Tito (18317019)
* Nama File : Searching + Ambil N word.h
* Deskripsi : Library ini berisi dua fungsi, yang pertama adalah searching / findword yang digunakan untuk mencari indeks dari key yang sesuai dengan n kata 
* yang dimasukkan. N kata tersebut terlebih dahulu diambil dari susunan kata dari keluaran yang sedang di generate.
* Sementara itu fungsi kedua adalah ambil N word yang digunakan untuk mengambil N word kata dari keluaran yang sedang di generate untuk 
* dapat dimasukkan ke dalam fungsi findword.
*/

int findword(char *nword, tabelngram *tabel, int panjang)
{
    int i = 0;
    len = strlen(nword);
    //tabel = (tabelngram*)malloc(panjang*sizeof(tabelngram));
    //nword = (char*)malloc(len*sizeof(char));

    while (i <= panjang || (strncmp(nword, tabel[i].key, len) != 0)
    {
        return 0;
        i = i + 1;
    }
    return i;
}

char* AmbilNWord(char* Hasil, int n) //Ambil n word terakhir untuk sekti
{
    int count = 0;
    int k = 0;
    int j = strlen(Hasil);

    Hasil = (char*)malloc(len*sizeof(char));
    char* temp = (char*)malloc(len*sizeof(char));
    char* Key = (char*)malloc(len*sizeof(char));

    while((j >= 0) || (count != n))
    {
        if(Hasil[j] == ' ')
        {
            if (count < n)
            {
                strcpy(temp[k]," ");
                k = k + 1;
            }
            count = count + 1;
        }
        else
        {
            strcpy(temp[k], Hasil[j]);
            k = k + 1;
        }
        j = j - 1;
    }

    int l = 0;
    while(k >= 0)
    {
        strcpy(Key[l], temp[k];
        l = l + 1;
        k = k - 1;
    }
}

