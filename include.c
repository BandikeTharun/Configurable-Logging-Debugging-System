#include<stdio.h>
#include<string.h>
#include "include.h"

void include_header(char *input, char *output)
{
    FILE *fp,*temp,*hf;
    char line[100];
    char filename[50];
    int i,j;

    fp=fopen(input,"r");
    temp=fopen(output,"w");

    while(fgets(line,100,fp))
    {
        if(strncmp(line,"#include",8)==0)
        {
            i=8;

            while(line[i]!='<' && line[i]!='"')
                i++;

            i++;
            j=0;

            while(line[i]!='>' && line[i]!='"')
            {
                filename[j]=line[i];
                i++;
                j++;
            }

            filename[j]='\0';

            hf=fopen(filename,"r");

            while(fgets(line,100,hf))
            {
                fputs(line,temp);
            }

            fclose(hf);
        }
        else
        {
            fputs(line,temp);
        }
    }

    fclose(fp);
    fclose(temp);
}
