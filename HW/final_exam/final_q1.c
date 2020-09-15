#include <stdio.h>
#include <stdlib.h>

struct _node {
    int data;
    struct _node *prev;
    struct _node *next;
};
typedef struct _node node;

int isprime(int val);
void print_isprime(int val);
void print_factors(node *ptr, int m);

int main(){
    int i, n, m;
    node *L, *ptr, *head, *tail;
    head = (node *)malloc(sizeof(node));
    head->prev = NULL;
    L = (node *)malloc(sizeof(node));
    L->prev = head;
    L->next = NULL;
    head->next = L;
    // input number
    printf("input number: ");
    scanf("%d", &n);
    printf("n: %d\n", n);
    for (i=1; i<=n; ++i){
        if (n%i==0) {
            L->data = i;
            L->next = (node *)malloc(sizeof(node));
            ptr = L;
            L = L->next;
            L->prev = ptr;
            L->next = NULL;
        }
    }
    tail = L;
    // print factors
    printf("factors: ");
    print_factors(head->next, 0);
    // print mode
    while(1){
        printf("menu (1=forward, 2=backward, 3=quit): ");
        scanf("%d", &m);
        if (m==1)
            ptr = head->next;
        else if (m==2)
            ptr = tail->prev;
        else
            break;
        print_factors(ptr, m);
    }
    return 0;
}

int isprime(int val){
    int i, c=0;
    for (i=2; i<=val; ++i){
        if (val%i==0)
            c+=1;
    }
    return (c==1)? 1:0;
}

void print_isprime(int val){
    printf("%d ", val);
    if (isprime(val))
        printf("P\n");
    else
        printf("N\n");
}

void print_factors(node *ptr, int m){
    while(1){
        if (m==0)
            printf("%d ", ptr->data);
        else
            print_isprime(ptr->data);
        if (m<=1){
            ptr = ptr->next;
            if (ptr->next==NULL)
                break;
        }
        else if (m==2){
            ptr = ptr->prev;
            if (ptr->prev==NULL)
                break;
        }
    }puts("");
}
