void bacafile(FILE *S, node **x, int *count){
    char temp[20];
    while(!feof(S)){
        fscanf(S, "%s", temp);
        *x = push(*x, temp);
        (*count)++;
    }
    //cetak(x);
}

void carilist(node *S, int n, char x[20]){
    node *temp;
    int i;
    temp = (node*)malloc(sizeof(node));
    temp = S;
    //printf("sip\n");
    for(i=0; i<n; i++){
        //printf("%s", temp->kata);
        temp = temp->next;
    }
    //printf("sip\n");
    strcpy(x, temp->kata);
    //printf("%s", temp->kata);
}
