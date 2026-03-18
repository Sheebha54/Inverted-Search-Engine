#include "header.h"

int main(int argc,char *argv[])
{
    Flist *head=NULL;
    int opt;
    hash_t arr[27];
    for(int i=0;i<27;i++)
    {
        arr[i].index=i;
        arr[i].link=NULL;

    }
    char word[20];
    //check cla is passd or not
        //=>if passed
    if(read_and_validation(argc,argv,&head)==SUCCESS){
        printf("Read and validation is successfully done\n");
    
        //Display menu
        while(1)
        {
            printf("1.Create Database\n2.Display Database\n3.Search Database\n4.Save Database \n5.Update database\n6.Exit\n");
            //read option
            scanf("%d",&opt);

            switch (opt)
            {
            

                case 1:
                    if(create_database(arr,head)==SUCCESS){
                        printf("\n-----Database created successfully-----\n");

                    }
                    else{
                        printf("\n-----Database creation Failed-----\n");
                    }
                    break;
                case 2:
                    printf("\n------ DATABASE ------\n");
                    display_database(arr);
                    break;
                case 3:
                    printf("Enter the word to be searched\n");
                    scanf("%s",word);
                    search_database(arr,word);
                    break;
                case 4:
                    save_database(arr);
                    break;
                case 5:
                    update_database(arr, &head);
                    break;
                case 6:
                    printf("Exiting program...\n");
                    exit(0);
                default:
                    printf("Invalid Option\n");
                    exit(0);
            }
        }
    }
        //=>not passed=>print error and usage msg
    else
    {
        printf("Error:Read and validation failed\n");
    }

        

}