#include "header.h"

int insert_last(Flist **head,char *fname)
{
    Flist *new=malloc(sizeof(Flist));
    if(new==NULL)
    {
        return FAILURE;
    }
    strcpy(new->filename,fname);
    new->link=NULL;
    Flist *temp=*head;
    if(*head==NULL)
    {
        *head=new;
        return SUCCESS;
    }
    else
    {
        //check for dup file
            //if dup present return some value
        while(temp->link!=NULL){
            
            if(strcmp(new->filename,temp->filename)==0)
            {
               free(new);
               return DATA_ALREADY_PRESENT;
               
            }
            
             temp=temp->link;
            
                    
        }
        if(strcmp(new->filename,temp->filename)==0)
        {
               free(new);
               return DATA_ALREADY_PRESENT;
               
        }
        temp->link=new;

        return SUCCESS;
    }
}