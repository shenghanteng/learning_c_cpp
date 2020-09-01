#include<stdio.h>
#include<stdlib.h>
#include <string.h>
 
struct BTreeNode
{
    char name[128];
    int phone;
    struct BTreeNode *left;
    struct BTreeNode *right;
};
typedef struct BTreeNode node;
 
node *find_parent(node *ptr, char name[], int *pos);
node *delete_node(node *root, char name[]);
node *find_node(node *ptr, char name[]);
node *insert_node(node *root, node input);
void print_preorder(node *ptr);
void print_inorder(node *ptr);
void print_postorder(node *ptr);
 
int main()
{
    char op;
    char name[128];
    int phone;
    node n;
    node *ptr;
    node *root=NULL;
 
    while(1){
        scanf(" %c", &op);
        if(op=='i'){
            scanf(" %s", n.name);
            scanf(" %d", &n.phone);
            root=insert_node(root, n);
        }
        else if(op=='d'){
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
            scanf(" %s", name);
            ptr=find_node(root, name);
            if (root!=NULL){
                printf("found:\n");
                printf("Name: %s\n", ptr->name);
                printf("Phone: %d\n\n", ptr->phone);
            }
            else{
                printf("not found\n");
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
 
node *insert_node(node *root, node input)
{
    node *new_node;
    node *current;
    node *parent;
 
    new_node = (node *)malloc(sizeof(node));
    strcpy(new_node->name, input.name);
    new_node->phone = input.phone;
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
        printf("Name: %s\n", ptr->name);
        printf("Phone: %d\n\n", ptr->phone);
        print_inorder(ptr->right);
    }
}
 
void print_preorder(node *ptr)
{
    if(ptr != NULL)
    {
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
        printf("Name: %s\n", ptr->name);
        printf("Phone: %d\n\n", ptr->phone);
    }
}
