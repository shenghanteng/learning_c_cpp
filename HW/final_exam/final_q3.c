#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 
struct stack_node
{
    int x;
    struct stack_node *next;
};
typedef struct stack_node node;

node *init(node *s, int n);
void isort(int *data, int n);
void print_stacks(node *s[3], int nmax);
void hanoi (int n, char from, char mid, char to, int *v, node *s[3], int nmax);
node *push(node *stack, int x);
node *pop(node *stack, int *x);

int main()
{
    int n,i;
    // input number
    printf("Please input the number of plates: ");
    scanf("%d", &n);
    // initialize
    int nmax=n;
    int *v=(int *)malloc(sizeof(int)*n);
    node *s[3];
    s[0] =(node *)malloc(sizeof(node));
    s[1] =(node *)malloc(sizeof(node));
    s[2] =(node *)malloc(sizeof(node));
    memset(v,0,sizeof(int)*n);
    s[0]=init(s[0], n);
    // start
    printf("Start!\n");
    print_stacks(s, nmax);
    puts("");
    hanoi(n, 'A','B','C', v, s, n);
    printf("Statistics:\n");
    for (i=0; i<n; ++i){
        printf("plate %d = %d\n",i+1,v[i]);
    }
    free(v);
    for (i=0; i<3; ++i) free(s[i]);
    return 0;
}

node *init(node *s, int n)
{
    int i;
    for (i=n; i>=1; --i){
        s=push(s, i);
    }
    return s;
}

void isort(int *data, int n)
{
    int i, j;
    int key;
    int *cur, *keyp;
    for( i=1; i<n; i++)
    {
        key=data[i];
        keyp = &data[i];
        for(j=i-1; j>=0 && data[j]>key; j--)
        {
            cur = &data[j];
            data[j+1] = data[j];
            cur = &data[j+1];
        }
        data[j+1] = key;
    }
}

void print_stacks(node *s[3], int nmax)
{
    int i, j;
    int **ary;
    ary = (int **)malloc(sizeof(int *)*3);
    for (i=0; i<3; ++i) ary[i] = (int *)malloc(sizeof(int)*nmax);
    node *ptr[3];
    for (i=0; i<3; ++i) ptr[i] = s[i];
    // load data from stack
    for (i=0; i<nmax; ++i){
        for (j=0; j<3; ++j){
            if (ptr[j]->next!=NULL) {
                ary[j][i] = ptr[j]->x;
                //printf("%d\t", ptr[j]->x);
                ptr[j] = ptr[j]->next;
            }
        }
    }
    // sort ary
    for (i=0; i<3; ++i){
        isort(ary[i], nmax);
    }
    // print result
    for (i=0; i<nmax; ++i){
        for (j=0; j<3; ++j){
            if (ary[j][i]>0)
                printf("%d\t", ary[j][i]);
            else
                printf(" \t");
        }puts("");
    }
    printf("A\tB\tC\n");
}

void hanoi (int n, char from, char mid, char to, int *v, node *s[3], int nmax)
{
    if(n==0)
        return ;
    v[n-1]+=1;
    hanoi(n-1, from, to, mid, v, s, nmax);
    printf("plate %d from %c -> %c\n",n,from,to);

    int f,t;
    // from
    if (from=='A')
        f=0;
    else if (from=='B')
        f=1;
    else if (from=='C')
        f=2;
    // to
    if (to=='A')
        t=0;
    else if (to=='B')
        t=1;
    else if (to=='C')
        t=2;
    // move
    s[f] = pop(s[f], &n);
    s[t] = push(s[t], n);
    print_stacks(s, nmax);
    puts("");

    hanoi(n-1, mid, from, to, v, s, nmax);
}

node *push(node *stack, int x)
{
 
    node *new_node;
    new_node = (node *)malloc(sizeof(node));   
 
    if(new_node==NULL)
    {
        printf("out of memory!\n");
    }
 
    new_node->x = x;
    new_node->next = stack;
    stack = new_node;
 
    return stack;
 
}
 
node *pop(node *stack, int *x)
{
    node *top;
 
    if( stack != NULL ) 
    {
        top = stack;
        stack = stack->next;
        *x = top->x;
        free(top);
    }
    else
    {
        *x = -1;
    }
    return stack;
}
