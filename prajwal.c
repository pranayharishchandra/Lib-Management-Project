#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

struct library
{
    char bookname[50];
    char author[50];
    int noofpages;
    int price;
};

int main()
{
    struct library lib[100];
    char bookname[30];
    int i, j, keepcount;
    i = j = keepcount = 0;
    while (j != 6)
    {
        printf("\n1. Add book information");
        printf("\n2. Display book information");
        printf("\n3. No of books in the library");
        printf("\n4. Exit");
        printf("\nEnter one of the above : ");
        scanf("%d", &j);

        switch (j)
        {
        /* Add book */
        case 1:
            printf("\nEnter book name = ");
            scanf("%s", lib[i].bookname);
            printf("Enter author name = ");
            scanf("%s", lib[i].author);
            printf("Enter pages = ");
            scanf("%d", &lib[i].noofpages);
            printf("Enter price = ");
            scanf("%d", &lib[i].price);
            keepcount++;
            i++;
            break;
        case 2:
            printf("you have entered the following information\n");
            printf("==============================================");
            for (i = 0; i < keepcount; i++)
            {
                printf("\nSl no. = %d\n",i+1);
                printf("book name = %s \n", lib[i].bookname);
                printf("author name = %s \n", lib[i].author);
                printf("pages = %d \n", lib[i].noofpages);
                printf("price = %d \n", lib[i].price);
            }
            printf("==============================================\n");

            break;
        case 3:
            printf("\n=>No of books in library : %d \n", keepcount);
            break;
        case 4:
            exit(0);
        }
    }
    return 0;
}
