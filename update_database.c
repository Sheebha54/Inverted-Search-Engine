#include "header.h"

int update_database(hash_t *arr, Flist **head)
{
    char fname[20];

    printf("Enter filename to update database: ");
    scanf("%19s", fname);

    int len = strlen(fname);

    if(len <= 4 || strcmp(fname + len - 4, ".txt") != 0)
    {
        printf("Invalid file extension\n");
        return FAILURE;
    }

    FILE *fptr = fopen(fname, "r");
    if(fptr == NULL)
    {
        printf("File not present\n");
        return FAILURE;
    }

    fseek(fptr, 0, SEEK_END);
    if(ftell(fptr) == 0)
    {
        printf("File is empty\n");
        fclose(fptr);
        return FAILURE;
    }

    fclose(fptr);

    // Insert into file list
    int ret = insert_last(head, fname);

    if(ret == DATA_ALREADY_PRESENT)
    {
        printf("File already exists in database\n");
        return FAILURE;
    }
    else if(ret == FAILURE)
    {
        return FAILURE;
    }

    // Move to last node
    Flist *temp = *head;
    while(temp->link != NULL)
        temp = temp->link;

    // Create database only for new file
    create_database(arr, temp);

    printf("Database updated successfully\n");

    return SUCCESS;
}