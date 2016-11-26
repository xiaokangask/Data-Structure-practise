#include <stdio.h>
#include <math.h>
#include <string.h>

int a[10000];

int nextprime(int m)
{
	int i=(m/2)*2+1;
	if(i<=2) return 2;
	for(;;i+=2){
		int j,flag=0;
		for(j=2;j<=sqrt(i);j++)
			if(i%j==0) {flag=1;break;}
		if(flag==0) return i;
	}
}


int main(int argc, char const *argv[])
{
	int m,n,key,flag=0;
	scanf("%d%d",&m,&n);
	memset(a,0,sizeof(a));
	int t=nextprime(m);
	//printf("%d\n",t);
	for(int i=0;i<n;i++){
		if(flag) printf(" ");
		flag=1;
		scanf("%d",&key);
		int pos=key%t,j=0;
		int tpos=pos;
		while(a[tpos]!=0&&j<=t){
			j++;
			tpos=(pos+j*j)%t;
		}
		if(a[tpos]) printf("-");
		else{
			a[tpos]=1;
			printf("%d",tpos);
		}
	}
	return 0;
}
