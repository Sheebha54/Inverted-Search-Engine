#include "header.h"

int create_database(hash_t *arr,Flist *head)
{
    Flist *temp=head;
    char input_word[20];
    int index;
    while(temp!=NULL)
    {
        FILE *fptr=fopen(temp->filename,"r");
        if(fptr == NULL)
            return FAILURE;
        while(fscanf(fptr,"%s",input_word)==1)
        {
            if(islower(input_word[0]))
            {
                index=input_word[0]-97;
            }
            else if(isupper(input_word[0]))
            {
                index=input_word[0]-65;
            }
            else
            {
                index=26;
            }
            //check index is null or not
            if(arr[index].link==NULL)
            {
                m_node *mnew=malloc(sizeof(m_node));
                if(mnew==NULL)
                {
                    return FAILURE;
                }
                s_node *snew=malloc(sizeof(s_node));
                if(snew==NULL)
                {
                    return FAILURE;
                }
                mnew->filecount=1;
                strcpy(mnew->word,input_word);
                mnew->slink=snew;
                mnew->mlink=NULL;

                snew->wordcount=1;
                strcpy(snew->filename,temp->filename);
                snew->sublink=NULL;
                arr[index].link=mnew;
            }
            else
            {
                //take 2 pointers ,temp,prev
                m_node *mtemp=arr[index].link;
                m_node *mprev=NULL;
                while(mtemp!=NULL){
                    if(strcmp(mtemp->word,input_word)==0){
                        //words equal
                        s_node *stemp=mtemp->slink;
                        s_node *sprev=NULL;
                        while(stemp!=NULL)
                        {
                            if(strcmp(temp->filename,stemp->filename)==0)
                            {
                                stemp->wordcount ++;
                                break;
                            }
                            else
                            {
                                sprev=stemp;
                                stemp=stemp->sublink;
                            }
                        }

                        if(stemp==NULL)
                        {
                        //file is diff
                            s_node *snew=malloc(sizeof(s_node));
                            if(snew==NULL)
                            {
                                return FAILURE;
                            }
                            snew->wordcount=1;
                            strcpy(snew->filename,temp->filename);
                            snew->sublink=NULL;
                            if(sprev==NULL)
                            {
                                mtemp->slink=snew;
                            }
                            else
                            {

                            sprev->sublink=snew;
                            }
                            (mtemp->filecount)++;
                        }
                            break;
                        
                    }
                    else
                    {
                        mprev=mtemp;
                        mtemp=mtemp->mlink;

                    }
                }
                //word is different
                //create mainnode,subnode
                if(mtemp==NULL)
                {
                    m_node *mnew=malloc(sizeof(m_node));
                    if(mnew==NULL)
                    {
                        return FAILURE;
                    }
                    s_node *snew=malloc(sizeof(s_node));
                    if(snew==NULL)
                    {
                        return FAILURE;
                    }
                    mnew->filecount=1;
                    strcpy(mnew->word,input_word);
                    mnew->slink=snew;
                    mnew->mlink=NULL;

                    snew->wordcount=1;
                    strcpy(snew->filename,temp->filename);
                    snew->sublink=NULL;
                    
                     if(mprev == NULL)
                        arr[index].link = mnew;
                    else
                        mprev->mlink = mnew;
                }

            }
        }
        fclose(fptr);
        temp=temp->link;
    }
    
    return SUCCESS;
}