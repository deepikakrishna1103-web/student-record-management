#include "student.h"

void stud_save(SLL *ptr)
{
    FILE *fp;

    fp = fopen("student.dat", "w");

    if(fp == 0)
    {
        printf("Unable to open student.dat\n");
        return;
    }

    while(ptr)
    {
        fprintf(fp, "%d %s %.2f\n",
                ptr->rollno,
                ptr->name,
                ptr->percentage);

        ptr = ptr->next;
    }

    fclose(fp);

    printf("Student records saved successfully\n");
}