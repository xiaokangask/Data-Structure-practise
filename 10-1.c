#include <stdio.h>

int a[100005];

int main(int argc, char const *argv[])
{
	int n,i,tot=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(i=0;i<n;i++){
		if(a[i]!=i){
			int flag=0;
			int p=i,cnt=1;
			if(a[p]==0) flag=1;
			while(a[p]!=i){
				int tmp2=p;
				p=a[p];
				a[tmp2]=tmp2;
				cnt++;
				if(a[p]==0) flag=1;
			}
			a[p]=p;
			if(flag) cnt--;
			else cnt++;
			tot+=cnt;
		}
	}
	printf("%d\n",tot);
	return 0;
}