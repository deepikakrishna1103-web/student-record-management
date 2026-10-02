#include "student.h"

void delete_all(SLL **ptr)
{
SLL *del;

if(*ptr == 0)
{
    printf("No student records available\n");
    return;
}

del = *ptr;

while(del)
{
    *ptr = del->next;
    free(del);
    del = *ptr;
}

printf("All student records deleted successfully\n");

}
