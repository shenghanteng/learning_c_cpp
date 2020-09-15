#include<stdio.h>
#include<stdlib.h>
#include <string.h>
 
struct BTreeNode
{
    int id;
    char name[128];
    int phone;
    struct BTreeNode *left;
    struct BTreeNode *right;
};
typedef struct BTreeNode node;
 
node *find_node(node *ptr, char name[]);
node *delete_node(node *root, char name[]);
node *find_parent(node *ptr, char name[], int *pos);
node *find_id(node *ptr, int id);
node *remove_node(node *root, int id);
node *insert_node(node *root, node input);
void print_preorder(node *ptr);
void print_inorder(node *ptr);
void print_postorder(node *ptr);
 
int main()
{
    char op;
    int id, pid=1;
    char name[128];
    int phone;
    node n;
    node *ptr;
    node *root=NULL;
    printf("=== Menu ===\ni: insert\nd: delete (name)\nr: remove (id)\nf: find\nl: inorder\nm: preorder\nn: postorder\nq: quit\n");
 
    while(1){
        printf(">> ");
        scanf(" %c", &op);
        if(op=='i'){
            printf("=== Insertion ===\n");
            printf("name: ");
            scanf(" %s", n.name);
            printf("phone: ");
            scanf("%d", &n.phone);
            n.id = pid;
            root=insert_node(root, n);
            ++pid;
        }
        else if(op=='d'){
            printf("=== Delete ===\n");
            printf("name-> ");
            scanf(" %s",name);
            root=delete_node(root, name);
            if (root!=NULL){
                printf("delete %s ok\n\n",name);
            }
            else{
                printf("cannot delete\n");
            }
        }
        else if(op=='f'){
            printf("=== Find ===\n");
            printf("name-> ");
            scanf(" %s", name);
            ptr=find_node(root, name);
            if (ptr!=NULL){
                printf("found:\n");
                printf("ID: %d\n", ptr->id);
                printf("Name: %s\n", ptr->name);
                printf("Phone: %d\n\n", ptr->phone);
            }
            else{
                printf("not found\n");
            }
        }
        else if(op=='r'){
            printf("=== Remove ===\n");
            printf("id-> ");
            scanf("%d",&id);
            ptr=find_id(root, id);
            if (ptr!=NULL){
                root=remove_node(root, id);
                printf("remove %d ok\n",id);
            }
            else{
                printf("cannot remove\n");
            }
        }
        else if(op=='l'){
            print_inorder(root);
        }
        else if(op=='m'){
            print_preorder(root);
        }
        else if(op=='n'){
            print_postorder(root);
        }
        else if(op=='q'){
            break;
        }
    }
}
 
node *find_id(node *ptr, int id)
{
    if(ptr!=NULL){
        if (ptr->id==id)
            return ptr;
        find_id(ptr->left, id);
        find_id(ptr->right, id);
    }
}

node *find_node(node *ptr, char name[]){
    while(ptr!=NULL){
        if (strcmp(ptr->name, name) == 0){
            return ptr;
        }
        else {
            if (strcmp(ptr->name, name) > 0){
                ptr=ptr->left;
            }
            else{
                ptr=ptr->right;
            }
        }
    }
    return NULL;
}
 
node *find_parent(node *ptr, char name[], int *pos)
{
    node *parent;
    parent = ptr;
    *pos = 0;
    while(ptr != NULL)   
    {
        if(strcmp(ptr->name, name) == 0)
            return parent;
        else
        {
            parent = ptr;
            if(strcmp(ptr->name, name) > 0)
            {
                *pos = -1;
                ptr = ptr->left;
            }
            else
            {
                *pos = 1;
                ptr = ptr->right;
            }
        }
    }
    return NULL;
}

node *delete_node(node *root, char name[])
{
    node *parent;
    node *ptr;
    node *next;
    int pos;
 
    parent = find_parent(root, name, &pos);
    if(parent != NULL)
    {
        switch(pos)   
        {
            case -1:
                ptr = parent->left;
                break;
            case 1:
                ptr = parent->right;
                break;
            case 0:
                ptr = parent;
                break;
        }
        if(ptr->left == NULL)
        {
            if(parent == ptr)
                root = root->right;
            else
            {
                if( pos == 1 )
                {
 
                    parent->right = ptr->right;
                }
                else
                {
 
                    parent->left = ptr->right;
                }
            }
            free(ptr);
        }
        else if(ptr->right == NULL)
        {
            if(parent != ptr)
            {
                if( pos == 1 )
                {
 
                    parent->right = ptr->left;
                }
                else
                {
 
                    parent->left = ptr->left;
                }
            }
            else
                root = root->left;
            free(ptr);
        }
        else                       
        {
            parent = ptr;
            next = ptr->left;
            if (next->right!=NULL){
                while(next->right != NULL)   
                {
                    parent = next;   
                    next = next->right;
                }
                parent->right = next->left;
            }
            else {
                parent->left = next ->left;
            }
            strcpy(ptr->name, next->name);
            ptr->phone = next->phone;
 
            free(next);   
        }
    }
    return root;
}

node *remove_node(node *root, int id)
{
    node *ptr;
    ptr = find_id(root, id);
    root = delete_node(root, ptr->name);
    return root;
}
 
node *insert_node(node *root, node input)
{
    node *new_node;
    node *current;
    node *parent;
 
    new_node = (node *)malloc(sizeof(node));
    strcpy(new_node->name, input.name);
    new_node->phone = input.phone;
    new_node->id = input.id;
    new_node->left = NULL;
    new_node->right = NULL;
    if(root == NULL)
    {
        root = new_node; //return new_node;
    }
    else
    {
        current = root;
        while(current != NULL)
        {
            parent = current;
            if(strcmp(current->name, new_node->name) > 0)
                current = current->left;
            else
                current = current->right;
        }
        if(strcmp(parent->name, new_node->name) > 0)
            parent->left = new_node;
        else
            parent->right = new_node;
    }
    return root;
}
 
void print_inorder(node *ptr)
{
    if(ptr != NULL)
    {
        print_inorder(ptr->left);
        printf("ID: %d\n", ptr->id);
        printf("Name: %s\n", ptr->name);
        printf("Phone: %d\n\n", ptr->phone);
        print_inorder(ptr->right);
    }
}
 
void print_preorder(node *ptr)
{
    if(ptr != NULL)
    {
        printf("ID: %d\n", ptr->id);
        printf("Name: %s\n", ptr->name);
        printf("Phone: %d\n\n", ptr->phone);
        print_preorder(ptr->left);
        print_preorder(ptr->right);
    }
}
 
void print_postorder(node *ptr)
{
    if(ptr != NULL)
    {
        print_postorder(ptr->left);
        print_postorder(ptr->right);
        printf("ID: %d\n", ptr->id);
        printf("Name: %s\n", ptr->name);
        printf("Phone: %d\n\n", ptr->phone);
    }
}
