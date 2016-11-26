#include <stdio.h>
#define maxsize 1001
#define minvalue -10001

int h[maxsize],size;

int main(int argc, char const *argv[])
{
	int i,n,m,j;
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++){
		scanf("%d",&h[i]);
		int tmp=h[i];
		for(j=i;j>1&&tmp<h[j/2];j/=2)
			h[j]=h[j/2];
		h[j]=tmp;
	}
	for(i=0;i<m;i++){
		scanf("%d",&j);
		printf("%d",h[j]);
		for(;j>1;j/=2){
			printf(" %d", h[j/2]);
		}
		printf("\n");
	}
	return 0;
}