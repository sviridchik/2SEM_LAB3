#include <stdio.h>
#include <string.h>
//#include <conio.h>
#include "myheader.h"



int main()
{

    while (1)
    {
        printf("\nChoose the task or quit:\n");
        printf("task1\n");
        printf("task2\n");
        char c[125];
        int k,a;
        scanf("%s",c);
        if (strcmp(c,"task1")==0)
            task1();
        else if (strcmp(c,"task2")==0)
            task2();
        else if (strcmp(c,"quit")==0)
        {
            printf("Goodbye\n");
            break;
        }
        else
            printf("Error, try again\n");
    }

    return 0;
}