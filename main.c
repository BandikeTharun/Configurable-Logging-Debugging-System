#include<stdio.h>
#include<string.h>

#include "comment.h"
#include "include.h"
#include "macro.h"

int main(int argc, char *argv[])
{
    char temp1[] = "temp1";
    char temp2[] = "temp2";

    if(argc != 2)
    {
        printf("Usage: ./my_Preprocessor filename\n");
        return 1;
    }

    remove_comments(argv[1], temp1);

    include_header(temp1, temp2);

    macro_substitute(temp2, "abc.i");

    remove(temp1);
    remove(temp2);

    return 0;
}
