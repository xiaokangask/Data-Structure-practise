#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define maxsize 1000

int a[maxsize],t[maxsize];

void solve(int left,int right,int root);
int length(int N);
int compare(const void*a,const void*b);
int min(int a,int b);

int main(int argc, char const *argv[])
{
	int n,i,flag=0;
	scanf("%d\n",&n);
	for(i=0;i<n;i++) scanf("%d",&a[i]);
	qsort(a,n,sizeof(int),compare);
	solve(0,n-1,0);
	for(i=0;i<n;i++){
		if(flag) printf(" ");
		flag=1;
		printf("%d",t[i]);
	}
	return 0;
}

void solve(int left,int right,int root)
{
	if((right-left+1)==0) return;
	int l;
	l=length(right-left+1);
	t[root]=a[left+l];
	solve(left,(left+l-1),(root*2+1));
	solve((left+l+1),right,(root*2+2));
}

int length(int N)
{
	int h,x;
	h=log(N+1)/log(2);
	x=N+1-pow(2,h);
	x=min(x,pow(2,h-1));
	return (pow(2,h-1)-1+x);
}

int compare(const void*a,const void*b)
{
	return *(int*)a-*(int*)b;
}

int min(int a,int b)
{
	return a<b?a:b;
}
