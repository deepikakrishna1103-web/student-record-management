#include "student.h"

void stud_reverse(SLL **ptr)
{
    SLL *prev, *cur, *next;

    if(*ptr == 0)
    {
        printf("No student records available\n");
        return;
    }

    prev = 0;
    cur = *ptr;

    while(cur)
    {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }

    *ptr = prev;

    printf("Student records reversed successfully\n");
}