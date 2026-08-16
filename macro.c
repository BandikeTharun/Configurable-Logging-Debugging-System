#include<stdio.h>
#include<string.h>
#include "macro.h"
#include "common.h"

void macro_substitute(char *input, char *output)
{
    FILE *fp,*temp;
    char line[100];
    char word[50];

    struct macro m[20];

    int count=0;
    int i,j,k;

    fp=fopen(input,"r");
    temp=fopen(output,"w");

    while(fgets(line,100,fp))
    {
        if(strncmp(line,"#define",7)==0)
        {
            i=7;

            while(line[i]==' ')
                i++;

            j=0;

            while(line[i]!=' ')
            {
                m[count].name[j]=line[i];
                i++;
                j++;
            }

            m[count].name[j]='\0';

            while(line[i]==' ')
                i++;

            j=0;

            while(line[i]!='\n' && line[i]!='\0')
            {
                m[count].value[j]=line[i];
                i++;
                j++;
            }

            m[count].value[j]='\0';

            count++;
        }
        else
        {
            i=0;

            while(line[i]!='\0')
            {
                if((line[i]>='a' && line[i]<='z') ||
                   (line[i]>='A' && line[i]<='Z') ||
                   (line[i]=='_'))
                {
                    j=0;

                    while((line[i]>='a' && line[i]<='z') ||
                          (line[i]>='A' && line[i]<='Z') ||
                          (line[i]>='0' && line[i]<='9') ||
                          (line[i]=='_'))
                    {
                        word[j]=line[i];
                        i++;
                        j++;
                    }

                    word[j]='\0';

                    k=0;

                    while(k<count)
                    {
                        if(strcmp(word,m[k].name)==0)
                        {
                            fputs(m[k].value,temp);
                            break;
                        }

                        k++;
                    }

                    if(k==count)
                        fputs(word,temp);
                }
                else
                {
                    fputc(line[i],temp);
                    i++;
                }
            }
        }
    }

    fclose(fp);
    fclose(temp);
}
