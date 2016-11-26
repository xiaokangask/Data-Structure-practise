#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	int a[51],n,y;
	memset(a,0,sizeof(a));
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&y);
		a[y]++;
	}
	for(int i=0;i<=50;i++)
		if(a[i]) printf("%d:%d\n",i,a[i]);
	return 0;
}