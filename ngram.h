/* EL2208 Praktikum Pemecahan Masalah dengan C 2019/2020
* MODUL 9 – TUGAS BESAR
* Kelompok : D-2
* Hari dan Tanggal : Senin, 13 April 2020
* Asisten (NIM) : Irfan Tito Kurniawan (18317019)
* Nama File : ngram.h
* Deskripsi : membuat tabel ngram
*/

void ngram(node *S, long long int count, tabelngram **tabel, int n, long long int *row){
    int i, j, k, x;
    char help[20], *bantu;
    node *temp;
    *tabel = (tabelngram*)malloc((count)*sizeof(tabelngram));
    bantu = (char*)malloc((count*10)*sizeof(char));
    for(i=0;i<count;i++){
        (*tabel)[i].key = (char*)malloc((count*15)*sizeof(char));
        for(j=0; j<20; j++){
            (*tabel)[i].value[j] = (char*)malloc(15*sizeof(char));
            strcpy((*tabel)[i].value[j], " ");
        }
    }
    temp = (node*)malloc(sizeof(node));
    temp = S;
    for(i=0; i<count; i++){
        carilist(temp, i, help);
        strcpy(bantu, help);
        strcat(bantu, " ");
        for(j=1; j<n; j++){
            carilist(temp, ((i+j)%count), help);
            strcat(bantu, help);
            strcat(bantu, " ");
        }
        x = findwords(bantu, *tabel, *row);
        j = 0;
        carilist(temp, ((i+n)%count), help);
        if(x==0){
            strcpy((*tabel)[*row].key, bantu);
            strcpy((*tabel)[*row].value[0], help);
            (*row)++;
        } else{
            while((strcmp((*tabel)[x].value[j], " ") != 0)&&((strcmp((*tabel)[x].value[j], help) != 0))){
                j++;
            }
            strcpy((*tabel)[x].value[j], help);
        }
        pop(temp);
        printf("%d\n", i);
    }
}
