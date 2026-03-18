#include "header.h"

int search_database(hash_t *arr, char *word)
{
    int index;

    if(islower(word[0]))
        index = word[0] - 'a';
    else if(isupper(word[0]))
        index = word[0] - 'A';
    else
        index = 26;

    if(arr[index].link == NULL)
    {
        printf("Word not found\n");
        return FAILURE;
    }

    m_node *mtemp = arr[index].link;

    while(mtemp != NULL)
    {
        if(strcmp(mtemp->word, word) == 0)
        {
             printf("+-------+------------+-----------+\n");
            printf("|Index  | Word       | Filecount |\n");
            printf("+-------+------------+-----------+\n");

            printf("|%-6d | %-10s | %-9d |\n",index, mtemp->word, mtemp->filecount);

            s_node *stemp = mtemp->slink;
            while(stemp != NULL)
            {
                printf("|       | -> %-8s | %-9d |\n",stemp->filename, stemp->wordcount);
                stemp = stemp->sublink;
            }
            printf("+-------+------------+-----------+\n");
            return SUCCESS;
        }

        mtemp = mtemp->mlink;
    }

    printf("Word not found\n");
    return FAILURE;
}