#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student
{
    int rollno;
    char name[50];
    float percentage;
    struct student *next;
}SLL;

void stud_add(SLL **);
void stud_del(SLL **);
void stud_show(SLL *);
void stud_mod(SLL *);
void stud_save(SLL *);
void stud_load(SLL **);
void sort_records(SLL **);
void delete_all(SLL **);
void reverse_list(SLL **);
void stud_exit(SLL **);
