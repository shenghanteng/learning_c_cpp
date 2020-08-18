#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 6

void swap(char a[], char b[])
{
    char temp[128];
    strcpy(temp,a);
    strcpy(a,b);
    strcpy(b,temp);
}
 
void print(int n, char p[][128])
{
    int i;
    for(i=0; i<n; i++)
    {
        printf("%s ", p[i]);
    }
    printf("\n");
}

void bsort(char data[][128], int n)
{
    int i, j;
    for(i=n; i>1; i--)
    {
        for(j=0; j<i-1; j++)
        {
            if(strcmp(data[j+1],data[j])>0)
            {
               swap(data[j+1], data[j]);
            }
        }
        print(n, data);
    }
    print(n, data);
}
 
void ssort(char data[][128], int n)
{
    int i, j;
    int max, pos;
    for(i=0; i<n-1; i++)
    {
        max = i;
        for(j=i+1; j<n; j++)
        {
            pos = j;
            if(strcmp(data[pos],data[max])>0)
                max = pos;
        }
        swap(data[i], data[max]);
        print(n, data);
    }
    print(n, data);
}
 
void isort(char data[][128], int n)
{
    int i, j;
    char key[128];
    for( i=1; i<n; i++)
    {
        strcpy(key,data[i]);
        for(j=i-1; j>=0 && strcmp(data[j],key)<0; j--)
        {
            strcpy(data[j+1],data[j]);
        }
        strcpy(data[j+1],key);
        print(n, data);
    }
    print(n, data);
}

int main(){
    int i,mode;
    char data[N][128];
    for (i=0; i<N; ++i){
        scanf("%s", data[i]);
    }
    scanf("%d",&mode);
    if (mode==1)
        bsort(data,N);
    else if (mode==2)
        ssort(data,N);
    else if (mode==3)
        isort(data,N);
    return 0;
}
