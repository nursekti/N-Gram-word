void ngram(node *S, int count, tabelngram *tabel, int n){
    int i, j;
    char help[20];
    node *temp;
    tabel = (tabelngram*)malloc(count*sizeof(tabelngram));
    for(i=0;i<count;i++){
        tabel[i].key = (char*)malloc(sizeof(char));
    }
    temp = (node*)malloc(sizeof(node));
    temp = S;
    printf("%s", help);
    carilist(temp, (8%count), help);
    printf("%s", help);*/
    for(i=0; i<count; i++){
        carilist(temp, i, help);
        strcpy(tabel[i].key, help);
        strcat(tabel[i].key, " ");
        for(j=1; j<n; j++){
            carilist(temp, ((i+j)%count), help);
            strcat(tabel[i].key, help);
            strcat(tabel[i].key, " ");
        }
        carilist(temp, ((i+n)%count), help);
        strcpy(tabel[i].value, help);
    }
}
