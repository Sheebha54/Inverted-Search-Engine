#include "header.h"
int read_and_validation(int argc,char *argv[],Flist **head)
{
    //take cla one by one
    int success_count=0;
    for(int i=1;i<argc;i++){
        if(strstr(argv[i],".txt")!=NULL){
            //check the file is present or not
            FILE *fptr=fopen(argv[i],"r");
            if(fptr!=NULL)
            {
                fseek(fptr,0,SEEK_END);
                if(ftell(fptr)){
                    if(insert_last(head,argv[i])==SUCCESS)
                    {
                        printf("%s file successfully added in list\n",argv[i]);
                        success_count++;
                    }
                    else
                    {
                        printf("ERROR: %s is already present\n",argv[i]);
                        
                    }
                }
                else
                {
                    printf("ERROR: %s file is empty\n",argv[i]);
                    
                }
            }
            else
            {
                printf("ERROR: %s file is not present \n",argv[i]);
            }
            fclose(fptr);
        }

        else
        {
            printf("ERROR: %s is not .txt file\n",argv[i]);
        }
        
    }
    
    if(success_count)
        return SUCCESS;
    else
        return FAILURE;
}

