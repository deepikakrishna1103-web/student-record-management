#include "student.h"

void stud_add(SLL **ptr)
{
SLL *new, *temp;
int rn = 1;

new = malloc(sizeof(SLL));

if(new == 0)
{
    printf("Memory allocation failed\n");
    return;
}


while(1)
{
    temp = *ptr;

    while(temp)
    {
        if(temp->rollno == rn)
            break;

        temp = temp->next;
    }

    if(temp == 0)
        break;

    rn++;
}

new->rollno = rn;



do
{
    printf("Enter student name: ");
    scanf(" %49[^\n]", new->name);

    if(strlen(new->name) == 0)
        printf("Name cannot be empty\n");

}while(strlen(new->name) == 0);

do
{
    printf("Enter percentage: ");
    scanf("%f", &new->percentage);

    if(new->percentage < 0 || new->percentage > 100)
        printf("Percentage must be between 0 and 100\n");

}while(new->percentage < 0 || new->percentage > 100);


new->next = *ptr;
*ptr = new;

printf("Record added successfully\n");
printf("Roll No : %d\n", new->rollno);


}