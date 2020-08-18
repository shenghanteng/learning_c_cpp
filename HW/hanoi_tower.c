#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 
void hanoi (int n, char from, char mid, char to, int *v)
{
    if(n==0)
        return ;
    v[n-1]+=1;
    hanoi(n-1,from, to, mid, v);
    printf("plate %d from %c -> %c\n",n,from,to);
    hanoi(n-1,mid, from, to, v);
}
 
int main()
{
    int n,i;
    scanf("%d", &n);
    int *v=(int *)malloc(sizeof(int)*n);
    memset(v,0,sizeof(int)*n);
    hanoi(n, 'A','B','C', v);
    puts("");
    for (i=0; i<n; ++i){
        printf("plate %d = %d\n",i+1,v[i]);
    }
    free(v);
    return 0;
}
