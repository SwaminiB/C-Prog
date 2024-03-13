void appendToFile(struct node *head)
{

    FILE *file;
    char ch;
    int count = 0;

    file = fopen("LinkedListFile.txt", "r");

    if (file == NULL)
    {
        printf("File \"%s\" does not exist!!!\n");
    }
    while ((ch = fgetc(file)) != EOF)
    {
        if (ch == '\n')
            count++;
    }

    printf("The number of lines in the program are: %d \n", count);
    fclose(file);

    file = fopen("LinkedListFile.txt", "a");

    if (file == NULL)
    {
        printf("File not found or cannot be opened.\n");
        return;
    }

    struct node *temp = head;
    count = count + 1;

    while (temp != NULL)
    {
        fprintf(file, "Employee No. %d\t", count);
        fprintf(file, "%s\t", temp->empName);
        fprintf(file, "%d\n", temp->empID);

        temp = temp->next;
        count++;
    }

    printf("Appendend successfully");

    fclose(file);
}
