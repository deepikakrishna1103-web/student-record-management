#include "student.h"

void sort_records(SLL **ptr)
{
SLL *p1, *p2;
int temp_rollno;
float temp_percentage;
char temp_name[50];
char ch;

if(*ptr == 0)
{
    printf("No student records available\n");
    return;
}

printf("N/n : Sort with name\n");
printf("P/p : Sort with percentage\n");
printf("Enter your choice: ");
scanf(" %c", &ch);

switch(ch)
{
    /* ==================== Sort by Name ==================== */

    case 'N':
    case 'n':

        p1 = *ptr;

        while(p1)
        {
            p2 = p1->next;

            while(p2)
            {
                if(strcmp(p1->name, p2->name) > 0)
                {
                    temp_rollno = p1->rollno;
                    p1->rollno = p2->rollno;
                    p2->rollno = temp_rollno;

                    strcpy(temp_name, p1->name);
                    strcpy(p1->name, p2->name);
                    strcpy(p2->name, temp_name);

                    temp_percentage = p1->percentage;
                    p1->percentage = p2->percentage;
                    p2->percentage = temp_percentage;
                }

                p2 = p2->next;
            }

            p1 = p1->next;
        }

        printf("Records sorted alphabetically by name\n");
        break;


    /* ==================== Sort by Percentage ==================== */

    case 'P':
    case 'p':

        p1 = *ptr;

        while(p1)
        {
            p2 = p1->next;

            while(p2)
            {
                if(p1->percentage < p2->percentage)
                {
                    temp_rollno = p1->rollno;
                    p1->rollno = p2->rollno;
                    p2->rollno = temp_rollno;

                    strcpy(temp_name, p1->name);
                    strcpy(p1->name, p2->name);
                    strcpy(p2->name, temp_name);

                    temp_percentage = p1->percentage;
                    p1->percentage = p2->percentage;
                    p2->percentage = temp_percentage;
                }

                p2 = p2->next;
            }

            p1 = p1->next;
        }

        printf("Records sorted by percentage in descending order\n");
        break;


    default:
        printf("Invalid choice\n");
}

}
