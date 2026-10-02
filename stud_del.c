#include "student.h"

void stud_del(SLL **ptr)
{
SLL *del, *prev;
int rn;
int found, count;
char name[50];
char ch;

if(*ptr == 0)
{
    printf("No records found\n");
    return;
}

printf("R/r : Delete by roll number\n");
printf("N/n : Delete by name\n");
printf("Enter your choice: ");
scanf(" %c", &ch);

switch(ch)
{
    case 'R':
    case 'r':

        printf("Enter roll number to delete: ");
        scanf("%d", &rn);

        del = *ptr;
        prev = 0;
        found = 0;

        while(del)
        {
            if(del->rollno == rn)
            {
                found = 1;
                break;
            }

            prev = del;
            del = del->next;
        }

        if(found == 0)
        {
            printf("Roll number %d not found\n", rn);
            return;
        }

        if(prev == 0)
            *ptr = del->next;
        else
            prev->next = del->next;

        free(del);

        printf("Record with roll number %d deleted successfully\n", rn);
        break;

    case 'N':
    case 'n':

      do
{
    printf("Enter name to delete: ");
    scanf(" %49[^\n]", name);

    if(strlen(name) == 0)
        printf("Name cannot be empty\n");

}while(strlen(name) == 0);

        del = *ptr;
        count = 0;

        while(del)
        {
            if(strcmp(del->name, name) == 0)
                count++;

            del = del->next;
        }

        if(count == 0)
        {
            printf("Name %s not found\n", name);
            return;
        }


        if(count == 1)
        {
            del = *ptr;
            prev = 0;

            while(del)
            {
                if(strcmp(del->name, name) == 0)
                    break;

                prev = del;
                del = del->next;
            }

            if(prev == 0)
                *ptr = del->next;
            else
                prev->next = del->next;

            free(del);

            printf("Record with name %s deleted successfully\n", name);
        }

        else
        {
            printf("Multiple records found with name %s\n", name);
            printf("------------------------------------------------------------\n");
            printf("Roll No.   Name                 Percentage\n");
            printf("------------------------------------------------------------\n");

            del = *ptr;

            while(del)
            {
                if(strcmp(del->name, name) == 0)
                {
                    printf("%-10d %-20s %.2f\n",
                           del->rollno, del->name, del->percentage);
                }

                del = del->next;
            }

            printf("------------------------------------------------------------\n");

            printf("Enter roll number of the record to delete: ");
            scanf("%d", &rn);

            del = *ptr;
            prev = 0;
            found = 0;

            while(del)
            {
                if(del->rollno == rn &&
                   strcmp(del->name, name) == 0)
                {
                    found = 1;
                    break;
                }

                prev = del;
                del = del->next;
            }

            if(found == 0)
            {
                printf("Roll number %d not found for name %s\n",
                       rn, name);
                return;
            }

            if(prev == 0)
                *ptr = del->next;
            else
                prev->next = del->next;

            free(del);

            printf("Record with roll number %d deleted successfully\n",
                   rn);
        }

        break;


    default:
        printf("Invalid choice\n");
}
}
