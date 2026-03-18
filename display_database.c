#include "header.h"

int display_database(hash_t *arr)
{
printf("+-------+------------+-----------+\n");
printf("|Index  | Word       | Filecount |\n");
printf("+-------+------------+-----------+\n");

    for(int i=0;i<27;i++)
    {
        if(arr[i].link!=NULL)
        {
            m_node *mtemp=arr[i].link;
            while(mtemp!=NULL)
            {
                printf("|%-6d | %-10s | %-9d |\n",i,mtemp->word,mtemp->filecount);
                s_node *stemp=mtemp->slink;
                while(stemp!=NULL)
                {
                    
                    printf("|       | -> %-8s | %-9d |\n",stemp->filename, stemp->wordcount);
                    stemp=stemp->sublink;
                }
                 printf("+-------+------------+-----------+\n");
                mtemp=mtemp->mlink;
            }
        }
    }
}