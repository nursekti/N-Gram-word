int nvalue(tabelngram *tabel, int i, int *p)
{
    while(strcmp(tabel[i].value[*p], " ") != 0)
    {
        (*p)++;
    }
    return (*p);
}
