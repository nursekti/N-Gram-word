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

