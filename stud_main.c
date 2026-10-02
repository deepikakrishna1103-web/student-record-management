#include "student.h"

int main()
{
    SLL *headptr = 0;
    char ch;

    stud_load(&headptr);

    while(1)
    {
        printf("\n******** STUDENT RECORD MENU ********\n");
        printf("a/A : Add new record\n");
        printf("d/D : Delete a record\n");
        printf("s/S : Show the list\n");
        printf("m/M : Modify a record\n");
        printf("v/V : Save records\n");
        printf("e/E : Exit\n");
        printf("t/T : Sort the list\n");
        printf("l/L : Delete all the records\n");
        printf("r/R : Reverse the list\n");

        printf("Enter your choice: ");
        scanf(" %c", &ch);

        switch(ch)
        {
            case 'a':
            case 'A':
                stud_add(&headptr);
                break;

            case 'd':
            case 'D':
                stud_del(&headptr);
                break;

            case 's':
            case 'S':
                stud_show(headptr);
                break;

            case 'm':
            case 'M':
                stud_mod(headptr);
                break;

            case 'v':
            case 'V':
                stud_save(headptr);
                break;

            case 't':
            case 'T':
                stud_sort(&headptr);
                break;

            case 'l':
            case 'L':
                stud_delete_all(&headptr);
                break;

            case 'r':
            case 'R':
                stud_reverse(&headptr);
                break;

            case 'e':
            case 'E':
                  stud_exit(&headptr);
                break;

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}