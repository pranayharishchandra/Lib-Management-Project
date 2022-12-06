/* LIBRARY MANAGEMENT */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 30

int i = 1;
int j = 1;

typedef struct /* Date Of Issuing */
{
    int date;
    int month;
    int year;
} DOI;

typedef struct
{
    int Slno;
    char book[20];
    int bookNo;
    char student_name[20];
    DOI doi;
    // char returned[5]; /* YES , NO */
    int returned;
} Node;

Node student[N];

void addStudent()
{
    printf("How many students you want to add:");
    int n;
    scanf("%d", &n);

    int p = i + n -1;
    // printf("\np value is %d \n",p);
    for (i; i <= p; i++) {
        printf("\nEnter : Book Name, Book No, Student Name : ");
        student[i].Slno = i;
        scanf("%s%d%s", &student[i].book, &student[i].bookNo, &student[i].student_name);
        printf("Enter Date-Month-Year (space seperated) : ");
        scanf("%d %d %d", &student[i].doi.date, &student[i].doi.month, &student[i].doi.year);
        // student[i].returned = "NO";        
        student[i].returned = 0;        
    }
}

void printStudent()
{
    int k;
    printf("Slno | Date of issuing book |  Book No  | Student Name | Book Name | Returned");

    for (k = 1; k < i; k++) {

        printf("    %d |",student[k].Slno);
        printf("     %d - %d - %d     |",student[k].doi.date,student[k].doi.month,student[k].doi.year);
        printf("    %d   |",student[k].bookNo); /* 4 digit */
        printf("  %s   |",student[k].student_name); 
        printf(" %s  |",student[k].book);

        if (student[k].returned) {
            printf("YES");
        } else {
            printf("NO");
        }

        printf("\n");
        
        
    }
}

void updateStatus() {
    int n;
    printf("\n\nNo of Books You want to update : ");
    scanf("%d",&n);

    int search[n];

    printf("\nEnter Book Numbers : ");    
    for (j = 0; j < n ; j++ ) {
        scanf("%d",&search[j]);
    }

    // int bookNumber;
    // printf("Enter book no : ");
    // scanf("%d",&bookNumber);

    int s = 1;
    int e = i; 
    for ( s = i - 1 ; s != 0 ; s-- ) {
        for ( j = 0; j < n; j++) {
            if (student[s].bookNo == search[j]){
                student[s].returned = 1;
            }
        }
    }
}


int main()
{
    while (1)
    {
        printf("\n\nchoice : \n1 : Add Students \n2 : Update Returned status \n3 : Print Students \n4: Exit \n==>");
        int choice;
        scanf("%d",&choice);  

        switch (choice)
        {
        case 1:
            addStudent();
            break;
        case 2:
            updateStatus();
            break;
        case 3:
            printStudent();
            break;
        case 4:
            exit(0);
        default:
            printf("Enter Valid Choice \n");
            break;
        }

    }
    return 0;    
}
