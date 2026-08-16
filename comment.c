#include<stdio.h>
#include "comment.h"

void remove_comments(char *input, char *output)
{
    FILE *fp,*temp;
    char ch,next;

    fp=fopen(input,"r");
    temp=fopen(output,"w");

    while((ch=fgetc(fp))!=EOF)
    {
        if(ch=='/')
        {
            next=fgetc(fp);

            if(next=='/')
            {
                while((ch=fgetc(fp))!=EOF && ch!='\n')
                    ;

                if(ch=='\n')
                    fputc('\n',temp);
            }

            else if(next=='*')
            {
                while((ch=fgetc(fp))!=EOF)
                {
                    if(ch=='*')
                    {
                        next=fgetc(fp);

                        if(next=='/')
                            break;
                    }
                }
            }

            else
            {
                fputc(ch,temp);

                if(next!=EOF)
                    fputc(next,temp);
            }
        }
        else
        {
            fputc(ch,temp);
        }
    }

    fclose(fp);
    fclose(temp);
}

