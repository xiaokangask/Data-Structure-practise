#include <stdio.h>

int main(int argc, char const *argv[])
{
	int a[100],b[100],n,i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(i=0;i<n;i++)
		scanf("%d",&b[i]);
	for(i=1;i<n&&b[i]>=b[i-1];i++);
	int tmp=i,flag=0,v=b[i];
	for(;i<n;i++)
		if(a[i]!=b[i]) break;
	if(i==n){
		printf("Insertion Sort\n");
		for(i=tmp;i>0&&b[i-1]>v;i--)
			b[i]=b[i-1];
		b[i]=v;
	}else{
		int len;
		printf("Merge Sort\n");
		for(len=1;len<=tmp+1;len*=2);
		len/=2;
		for(;len>=1;len/=2){
			flag=0;
			for(i=1;i<n;i++){
				for(int j=1;j<len&&i<n;j++,i++){
					if(flag==0&&b[i]<b[i-1]) flag=1;
				}
			}
			if(flag==0) break;
		}
		int left,right,leftend,rightend,p;
		for(i=0;i+len<n;i+=2*len){
			p=i,left=i;right=i+len;leftend=right-1;rightend=((i+2*len-1)<(n-1)?(i+2*len-1):(n-1));
			while(left<=leftend&&right<=rightend){
				if(b[left]>b[right]) a[p++]=b[right++];
				else a[p++]=b[left++];
			}
			while(left<=leftend) a[p++]=b[left++];
			while(right<=rightend) a[p++]=b[right++];
		}
		for(i=0;i<p;i++)
			b[i]=a[i];
	}
	flag=0;
	for(i=0;i<n;i++){
		if(flag) printf(" ");
		flag=1;
		printf("%d",b[i]);
	}
	return 0;
}