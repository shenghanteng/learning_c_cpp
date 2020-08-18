#include <stdio.h>
#include <stdlib.h>

int comb(int n, int m, int N, int *ct);

int main(int argc, char *argv[]){
	int i, n, m, N, M, ans;
	int *ct;
	scanf("%d", &n);
	scanf("%d", &m);
	N=n;
	ct = (int *)malloc(sizeof(int)*n*m);
	for(i=0; i<sizeof(int)*n*m; ++i) *(ct+i)=0;
	if(ct==NULL){
		exit(0);
	}
	if(n>=m){
		ans=comb(n,m,N,ct);
		printf("%d\n", ans);
	}
	else{
		printf("input error\n");
	}
	return 0;
}

int comb(int n, int m, int N, int *ct){
	int a=0, b=0;
	int nm, mm;
	nm = n-1;
	mm = m-1;
	if(m==0 || n==m)
		return 1;
	if(*(ct+N*nm+mm))
		return *(ct+N*nm+mm);
	else{
		a = comb(n-1, m, N, ct);
		*(ct+N*(nm-1)+mm) = a;
		b = comb(n-1, m-1, N, ct);
		*(ct+N*(nm-1)+mm-1) = b;
	}
	return a + b;
}
