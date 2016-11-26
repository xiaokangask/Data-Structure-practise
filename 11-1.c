#include <stdio.h>
#include <stdlib.h>

int compare(const void* a,const void* b)
{
	if(*(double*)a-*(double*)b>0.5) return 1;
	else return -1;
}

double a[200005];

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<2*n;i++)
		scanf("%lf",&a[i]);
	qsort(a,2*n,sizeof(double),compare);
	int max=1,maxi=0,tmp=1,cnt=1;
	for(int i=1;i<2*n;i++){
		if(a[i]-a[i-1]<=0.5&&a[i]-a[i-1]>=(-0.5)&&i<2*n-1) tmp++;
		else{
			if(i==2*n-1) tmp++;
			if(tmp>max) {maxi=i-1,max=tmp;cnt=1;}
			else if(tmp==max) cnt++;
			tmp=1;
		}
		//printf("%d\n",cnt );
	}
	printf("%.0f %d",a[maxi],max);
	if(cnt>1) printf(" %d\n",cnt);
	return 0;
}
