#include "student.h"

void stud_mod(SLL *ptr)
{
    SLL *temp;
    int rn;
    int count;
    int found;
    float per;
    char name[50];
    char ch;

    if(ptr == 0)
    {
        printf("No student records available\n");
        return;
    }

    printf("Enter which record to search for modification\n");
    printf("R/r : Search by roll number\n");
    printf("N/n : Search by name\n");
    printf("P/p : Search by percentage\n");
    printf("Enter your choice: ");
    scanf(" %c", &ch);

    switch(ch)
    {
    /* ==================== Search by Roll Number ==================== */

    case 'R':
    case 'r':

        printf("Enter roll number: ");
        scanf("%d", &rn);

        temp = ptr;
        found = 0;

        while(temp)
        {
            if(temp->rollno == rn)
            {
                found = 1;
                break;
            }
            temp = temp->next;
        }

        if(found == 0)
        {
            printf("Roll number %d not found\n", rn);
            return;
        }

        printf("Current details\n");
        printf("Roll No. : %d\n", temp->rollno);
        printf("Name     : %s\n", temp->name);
        printf("Percentage : %.2f\n", temp->percentage);

        do
        {
            printf("Enter updated name: ");
            scanf(" %49[^\n]", temp->name);

            if(strlen(temp->name) == 0)
                printf("Name cannot be empty\n");

        } while(strlen(temp->name) == 0);

        do
        {
            printf("Enter updated percentage: ");
            scanf("%f", &temp->percentage);

            if(temp->percentage < 0 || temp->percentage > 100)
                printf("Percentage must be between 0 and 100\n");

        } while(temp->percentage < 0 || temp->percentage > 100);

        printf("Record modified successfully\n");
        break;


    /* ==================== Search by Name ==================== */

    case 'N':
    case 'n':

        do
        {
            printf("Enter name to search: ");
            scanf(" %49[^\n]", name);

            if(strlen(name) == 0)
                printf("Name cannot be empty\n");

        } while(strlen(name) == 0);

        temp = ptr;
        count = 0;

        while(temp)
        {
            if(strcmp(temp->name, name) == 0)
                count++;

            temp = temp->next;
        }

        if(count == 0)
        {
            printf("Name %s not found\n", name);
            return;
        }

        /* -------- Only one record found -------- */

        if(count == 1)
        {
            temp = ptr;

            while(temp)
            {
                if(strcmp(temp->name, name) == 0)
                    break;

                temp = temp->next;
            }

            printf("Current details\n");
            printf("Roll No. : %d\n", temp->rollno);
            printf("Name     : %s\n", temp->name);
            printf("Percentage : %.2f\n", temp->percentage);

            do
            {
                printf("Enter updated name: ");
                scanf(" %49[^\n]", temp->name);

                if(strlen(temp->name) == 0)
                    printf("Name cannot be empty\n");

            } while(strlen(temp->name) == 0);

            do
            {
                printf("Enter updated percentage: ");
                scanf("%f", &temp->percentage);

                if(temp->percentage < 0 || temp->percentage > 100)
                    printf("Percentage must be between 0 and 100\n");

            } while(temp->percentage < 0 || temp->percentage > 100);

            printf("Record modified successfully\n");
        }

        /* -------- Multiple records found -------- */

        else
        {
            printf("Multiple records found with name %s\n", name);
            printf("------------------------------------------------------------\n");
            printf("Roll No.   Name                 Percentage\n");
            printf("------------------------------------------------------------\n");

            temp = ptr;

            while(temp)
            {
                if(strcmp(temp->name, name) == 0)
                {
                    printf("%-10d %-20s %.2f\n",
                           temp->rollno, temp->name, temp->percentage);
                }
                temp = temp->next;
            }

            printf("------------------------------------------------------------\n");

            printf("Enter roll number of the record to modify: ");
            scanf("%d", &rn);

            temp = ptr;
            found = 0;

            while(temp)
            {
                if(temp->rollno == rn &&
                   strcmp(temp->name, name) == 0)
                {
                    found = 1;
                    break;
                }
                temp = temp->next;
            }

            if(found == 0)
            {
                printf("Roll number %d not found for name %s\n", rn, name);
                return;
            }

            printf("Current details\n");
            printf("Roll No. : %d\n", temp->rollno);
            printf("Name     : %s\n", temp->name);
            printf("Percentage : %.2f\n", temp->percentage);

            do
            {
                printf("Enter updated name: ");
                scanf(" %49[^\n]", temp->name);

                if(strlen(temp->name) == 0)
                    printf("Name cannot be empty\n");

            } while(strlen(temp->name) == 0);

            do
            {
                printf("Enter updated percentage: ");
                scanf("%f", &temp->percentage);

                if(temp->percentage < 0 || temp->percentage > 100)
                    printf("Percentage must be between 0 and 100\n");

            } while(temp->percentage < 0 || temp->percentage > 100);

            printf("Record modified successfully\n");
        }

        break;


    /* ==================== Search by Percentage ==================== */

    case 'P':
    case 'p':

        printf("Enter percentage: ");
        scanf("%f", &per);

        temp = ptr;
        count = 0;

        while(temp)
        {
            if(temp->percentage == per)
                count++;

            temp = temp->next;
        }

        if(count == 0)
        {
            printf("Percentage %.2f not found\n", per);
            return;
        }

        /* -------- Only one record found -------- */

        if(count == 1)
        {
            temp = ptr;

            while(temp)
            {
                if(temp->percentage == per)
                    break;

                temp = temp->next;
            }

            printf("Current details\n");
            printf("Roll No. : %d\n", temp->rollno);
            printf("Name     : %s\n", temp->name);
            printf("Percentage : %.2f\n", temp->percentage);

            do
            {
                printf("Enter updated name: ");
                scanf(" %49[^\n]", temp->name);

                if(strlen(temp->name) == 0)
                    printf("Name cannot be empty\n");

            } while(strlen(temp->name) == 0);

            do
            {
                printf("Enter updated percentage: ");
                scanf("%f", &temp->percentage);

                if(temp->percentage < 0 || temp->percentage > 100)
                    printf("Percentage must be between 0 and 100\n");

            } while(temp->percentage < 0 || temp->percentage > 100);

            printf("Record modified successfully\n");
        }

        /* -------- Multiple records found -------- */

        else
        {
            printf("Multiple records found with percentage %.2f\n", per);
            printf("------------------------------------------------------------\n");
            printf("Roll No.   Name                 Percentage\n");
            printf("------------------------------------------------------------\n");

            temp = ptr;

            while(temp)
            {
                if(temp->percentage == per)
                {
                    printf("%-10d %-20s %.2f\n",
                           temp->rollno, temp->name, temp->percentage);
                }
                temp = temp->next;
            }

            printf("------------------------------------------------------------\n");

            printf("Enter roll number of the record to modify: ");
            scanf("%d", &rn);

            temp = ptr;
            found = 0;

            while(temp)
            {
                if(temp->rollno == rn &&
                   temp->percentage == per)
                {
                    found = 1;
                    break;
                }
                temp = temp->next;
            }

            if(found == 0)
            {
                printf("Roll number %d not found for percentage %.2f\n", rn, per);
                return;
            }

            printf("Current details\n");
            printf("Roll No. : %d\n", temp->rollno);
            printf("Name     : %s\n", temp->name);
            printf("Percentage : %.2f\n", temp->percentage);

            do
            {
                printf("Enter updated name: ");
                scanf(" %49[^\n]", temp->name);

                if(strlen(temp->name) == 0)
                    printf("Name cannot be empty\n");

            } while(strlen(temp->name) == 0);

            do
            {
                printf("Enter updated percentage: ");
                scanf("%f", &temp->percentage);

                if(temp->percentage < 0 || temp->percentage > 100)
                    printf("Percentage must be between 0 and 100\n");

            } while(temp->percentage < 0 || temp->percentage > 100);

            printf("Record modified successfully\n");
        }

        break;


    default:
        printf("Invalid choice\n");
    }
}