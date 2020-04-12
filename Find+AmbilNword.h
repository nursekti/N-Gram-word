/* EL2208 Praktikum Pemecahan Masalah dengan C 2019/2020
* MODUL 9 – TUGAS BESAR - Soal 2 Ngram
* Kelompok : D-2
* Hari dan Tanggal : Minggu, 12 April 2020
* Asisten (NIM) : Irfan Tito Kurniawan (18317019)
* Nama File : Find+AmbilNword.h
* Deskripsi : Library ini berisi dua fungsi, yang pertama adalah findword yang digunakan untuk mencari indeks dari key yang sesuai dengan n kata 
* yang dimasukkan. N kata tersebut terlebih dahulu diambil dari susunan kata dari keluaran yang sedang di generate.
* Sementara itu fungsi kedua adalah ambil N word yang digunakan untuk mengambil N word kata dari keluaran yang sedang di generate untuk 
* dapat dimasukkan ke dalam fungsi findword.
*/

int findword(char *nword, tabelngram *tabel, int panjang)
{
    int i = 0;
    while (i <= panjang)
    {
        if (strcmp(nword, tabel[i].key) == 0)
        {
            return i;
        } 
        else
        {
            i = i + 1;
        }
    }
    return 0;
}

void AmbilNWord(char* Hasil[], int n)
{
    int count = 0;
    int k = 0;
    int j = strlen(Hasil);

    char* temp = (char*)malloc(len*sizeof(char));
    char* Key = (char*)malloc(len*sizeof(char));

    while((j >= 0) && (count != n))
    {
        if(Hasil[j - 1] == ' ')
        {
            count = count + 1;
            if (count < n)
            {
                temp[k] = ' ';
                k = k + 1;
            }
        }
        else
        {
            temp[k] = (*Hasil)[j - 1];
            k = k + 1;
        }
        j = j - 1;
    }

    int l = 0;
    while(k > 0)
    {
        Key[l] = temp[k - 1];
        l = l + 1;
        k = k - 1;
    }
    strcpy((*Hasil), Key);
}

