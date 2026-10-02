#include "student.h"

void stud_show(SLL *ptr)
{
if(ptr == 0)
{
printf("No student records available\n");
return;
}

printf("------------------------------------------------------------\n");
printf("Roll No.   Name                 Percentage\n");
printf("------------------------------------------------------------\n");

while(ptr)
{
    printf("%-10d %-20s %.2f\n",
           ptr->rollno, ptr->name, ptr->percentage);

    ptr = ptr->next;
}

printf("------------------------------------------------------------\n");

}