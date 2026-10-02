#include "student.h"

void stud_load(SLL **ptr)
{
    FILE *fp;
    SLL *new, *last;

    fp = fopen("student.dat", "r");

    if(fp == 0)
    {
        return;
    }

    while(1)
    {
        new = malloc(sizeof(SLL));

        if(new == 0)
        {
            printf("Memory allocation failed\n");
            fclose(fp);
            return;
        }

        if(fscanf(fp, "%d %s %f",
                  &new->rollno,
                  new->name,
                  &new->percentage) != 3)
        {
            free(new);
            break;
        }

        new->next = 0;

        if(*ptr == 0)
        {
            *ptr = new;
        }
        else
        {
            last = *ptr;

            while(last->next)
                last = last->next;

            last->next = new;
        }
    }

    fclose(fp);

    printf("Student records loaded successfully\n");
}