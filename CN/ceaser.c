#include<stdio.h>
#define size 30
void main()
{
    char input[size],output[size],ch;
    int key,i,j;
    FILE *fin,*fout;

    fin=fopen("input.txt","w");
    printf("enter a plain text\n");
    scanf("%s",input);
    fprintf(fin,"%s",input);
    fclose(fin);

    printf("enter a key = ");
    scanf("%d",&key);

    fin=fopen("input.txt","r");
    fout=fopen("output.txt","w");

    i=0;
    while((ch=fgetc(fin))!=EOF)
    {
        if(isupper(ch))
        {
            j=(int)ch+key-65;
            j=j%26+65;
            output[i]=(char)j;
            fputc(output[i],fout);
        }
        else
        {
            j=(int)ch+key-97;
            j=j%26+97;
            output[i]=(char)j;
            fputc(output[i],fout);
        }
        i++;
    }
    output[i]='\0';

    fclose(fin);
    fclose(fout);

    fout=fopen("output.txt","r");
    printf("output string\n");
    while((ch=fgetc(fout))!=EOF)
        printf("%c",ch);
    fclose(fout);

    //decryption starts

    fin=fopen("output.txt","r");
    fout=fopen("input.txt","w");

    i=0;
    while((ch=fgetc(fin))!=EOF)
    {
        if(isupper(ch))
        {
            j=(int)ch-key-65;
            if(j<0)
                j=j+26;
            j=j%26+65;
            input[i]=(char)j;
            fputc(input[i],fout);
        }
        else
        {
            j=(int)ch-key-97;
            if(j<0)
                j=j+26;
            j=j%26+97;
            input[i]=(char)j;
            fputc(input[i],fout);
        }
        i++;
    }
    input[i]='\0';

    fclose(fin);
    fclose(fout);

    fout=fopen("input.txt","r");
    printf("\n\noutput string = ");
    while((ch=fgetc(fout))!=EOF)
        printf("%c",ch);
    printf("\n");
    fclose(fout);
}
