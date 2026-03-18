#include "header.h"

int save_database(hash_t *arr)
{
    char fname[20];

    printf("Enter filename to save database: ");
    scanf("%s", fname);

    // check extension
    if(strstr(fname, ".txt") == NULL)
    {
        printf("Invalid file extension\n");
        return FAILURE;
    }

    FILE *fptr = fopen(fname, "w");
    if(fptr == NULL)
   {
         printf("Unable to open file %s\n", fname);  // <- show exact filename
         return FAILURE;
   }
   else
   {
        printf("DEBUG: file opened successfully: %s\n", fname);
   }

    for(int i = 0; i < 27; i++)
    {
        if(arr[i].link != NULL)
        {
            m_node *mtemp = arr[i].link;

            while(mtemp != NULL)
            {
                fprintf(fptr, "%d %s %d ",
                        i,
                        mtemp->word,
                        mtemp->filecount);

                s_node *stemp = mtemp->slink;

                while(stemp != NULL)
                {
                    fprintf(fptr, "%s %d ",
                            stemp->filename,
                            stemp->wordcount);

                    stemp = stemp->sublink;
                }

                fprintf(fptr, "\n");

                mtemp = mtemp->mlink;
            }
        }
    }

    fclose(fptr);

    printf("Database saved successfully\n");
    return SUCCESS;
}