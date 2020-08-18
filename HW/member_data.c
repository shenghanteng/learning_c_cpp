#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
struct _node{
    char name[128];
    char email[128];
    int phone;
    struct _node *next;
};
typedef struct _node node;
 
node *getnode() {
  node *p;
  p = (node *) malloc(sizeof(node));
  if (p == NULL) {
    printf("out of memory");
    exit(1);
  }
  return p;
}
 
void freenode (node *p) {
    free(p);
}
 
node *insert_node(node *head, node *ptr, node input) {
  node *new_node;
  new_node = getnode();
  *new_node = input;
  new_node->next = NULL;
  if (ptr == NULL) {
 
    new_node->next = head;
    head = new_node;
  } else {
    if (ptr->next == NULL)
      ptr->next = new_node;
    else {
      new_node->next = ptr->next;
      ptr->next = new_node;
    }
  }
  return head;
}
 
void printList(node *ptr){
    //ptr = head;
    while(ptr!=NULL){
        printf("%s\n",ptr->name);
        printf("%s\n",ptr->email);
        printf("%010d\n\n",ptr->phone);
        ptr=ptr->next;
    }
}
 
node *find_node(node *head, char name[]) {
  node *ptr;
  ptr = head;
  while (ptr != NULL) {
    if (strcmp(ptr->name, name) == 0)
      return ptr;
    ptr = ptr -> next;
  }
  return ptr;
}
 
node *delete_node(node *head, node *ptr) {
    node *previous;
    if (ptr == head) {
        head = head -> next;
    } else {
        previous = head;
        while (previous -> next != ptr)
            previous = previous -> next;
        if (ptr -> next == NULL)
            previous -> next = NULL;
        else
            previous -> next = ptr -> next;
    }
    freenode(ptr);
    return (head);
}
 
int length(node *head){
    int num=0;
    node *ptr = head;
    while(ptr!=NULL){
        num++;
        ptr=ptr->next;
    }
    return num;
}
 
int main(){
    node *head, *ptr;
    node n;
    char key, name[128], email[128];
    int phone;
    head = NULL;
    while(1){
        scanf(" %c", &key);
        if(key=='i'){
            scanf(" %s", n.name);
            scanf(" %s", n.email);
            scanf(" %d", &n.phone);
            ptr = head;
            if (head == NULL) {
                 head = insert_node(head, NULL, n);
            }
            else {
                  while (ptr -> next != NULL)
                    ptr = ptr -> next;
                  head = insert_node(head, ptr, n);
            }
        }
        else if(key=='f'){
            scanf(" %s", name);
            ptr=find_node(head, name);
            if(ptr!=NULL){
                printf("found\n");
                printf("%s\n",ptr->name);
                printf("%s\n",ptr->email);
                printf("%010d\n\n",ptr->phone);
            }
            else
                printf("Not found\n");
        }
        else if(key=='d'){
            scanf(" %s", name);
            ptr=find_node(head, name);
            if(ptr!=NULL){
                head = delete_node(head, ptr);
                printf("Delete ok\n");
            }
            else
                printf("Can not delete\n");
        }
        else if(key=='l'){
            printList(head);
        }
        else if(key=='q'){
            exit(0);
        }
        //system("pause");
        //system("cls");
    }
    return 0;
}
