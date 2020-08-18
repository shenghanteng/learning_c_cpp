#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 6
 
void print(int n, char p[][128])
{
    int i;
 
    for(i=0; i<n; i++)
    {
        printf("%s ", p[i]);
    }
    printf("\n");
}
 
int LinearSearch(int n, char p[][128], char value[])
{
    int i;
    for(i=0; i< n; i++)    {
        printf("%d: %s\n",i,p[i]);
        if(strcmp(p[i],value)==0)
            return i;
    }
    return -1;
}
 
int BinarySearch(int n, char p[][128], char value[])
{
    int low=0, high=n, mid;
    while(low <= high)
    {
        mid = (low + high) / 2;
        printf("%d: %s\n",mid,p[mid]);
        if(strcmp(p[mid],value)>0){
          high = mid - 1;
        }
        else if(strcmp(p[mid],value)<0){
          low = mid+1;
        }
        else{
          return mid;
        }
    }
    return -1;
}
 
void check(int c, char p[][128]){
    if (c==-1)
        puts("not found");
    else
        printf("found: %s\n", p[c]);
}
 
int main(){
    int i,j,c,mode;
    int n=0;
    char key[128],value[128];
    char ary[100][128];
 
    while(1){
        scanf("%d",&mode);
        if (mode==1){
            scanf(" %s", key);
            if (n==0)
                strcpy(ary[0],key);
            else{
                for(j=n-1; j>=0 && strcmp(ary[j],key)>0; j--)
                    strcpy(ary[j+1],ary[j]);
                strcpy(ary[j+1],key);
            }
            ++n;
        }
        else if (mode==2){
            scanf(" %s", value);
            c=LinearSearch(n, ary, value);
            check(c,ary);
        }
        else if (mode==3){
            scanf(" %s", value);
            c=BinarySearch(n, ary, value);
            check(c,ary);
        }
        else if (mode==4)
            print(n, ary);
        else if (mode==5)
            return 0;
    }
    return 0;
}
