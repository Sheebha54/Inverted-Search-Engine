#ifndef HEADER_H
#define HEADER_H
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <ctype.h>
#define SUCCESS 0
#define FAILURE -1
#define DATA_ALREADY_PRESENT -2
typedef struct node
{
    char filename[20];
    struct node *link;
}Flist;

typedef struct subnode
{
    int wordcount;
    char filename[20];
    struct subnode *sublink;
}s_node;

typedef struct mainnode
{
    int filecount;
    char word[20];
    s_node *slink;
    struct mainnode *mlink;
}m_node;

typedef struct hashnode
{
    int index;
    m_node *link;
}hash_t;

int read_and_validation(int argc,char *argv[],Flist **head);
int insert_last(Flist **head,char *fname);
int display_database(hash_t *arr);
int create_database(hash_t *arr,Flist *head);
int save_database(hash_t *arr);
int search_database(hash_t *arr, char *word);
int update_database(hash_t *arr, Flist **head);

#endif
