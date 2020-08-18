#include<stdio.h>
#include<stdlib.h>
 
struct _node{
    int data;
    struct _node *next;
};
typedef struct _node node;
 
int main()
{
    int i;
    node *head,*ptr;
    ptr = (node *)malloc(sizeof(node));
    ptr->next = NULL;
    while(1){
        scanf("%d",&(ptr->data));
        if(ptr->data==-1) break;
        else {head = (node *)malloc(sizeof(node)); head->next = ptr;}
        ptr = head;
    }
    ptr = head;
    while(ptr!=NULL){
        if (ptr->data!=-1) printf("%d ",ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}
