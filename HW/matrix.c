#include<stdio.h>
#define H 3
#define W 3
 
int main() {
 
  int a[H][W] = {1, 2, 3,
                 4, 5, 6,
                 7, 8, 9};
  int b[H][W] = {2, 4, 6,
                 8,10,12,
                14,16,18};
  int c[H][W] = {0, 0, 0,
                 0, 0, 0,
                 0, 0, 0};
 
  int i,j,k;
  for(i=0;i<H;i++){
    for(j=0;j<W;j++){
      for(k=0;k<W;k++){
        c[i][j]+=a[i][k]*b[k][j];
      }
      printf("%-5d", c[i][j]);
    }
    puts("");
  }
 
  return 0;
}
