void stud_exit(SLL **ptr)
{
    char ch;

    printf("S/s : Save and exit\n");
    printf("E/e : Exit without saving\n");
    printf("Enter your choice: ");
    scanf(" %c", &ch);

    switch(ch)
    {
        case 'S':
        case 's':
            stud_save(*ptr);
            delete_all(ptr);
            exit(0);

        case 'E':
        case 'e':
            delete_all(ptr);
            exit(0);

        default:
            printf("Invalid choice\n");
    }
}