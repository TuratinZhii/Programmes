void DELETE_STRING(char str_d[],char ch_d)
{
    int i=0;
    for (int j=0; str_d[j]!='\0'; j++)
    {
        if (str_d[j]!=ch_d)
            str_d[i++]=str_d[j];
        str_d[i]='\0';
    }
}