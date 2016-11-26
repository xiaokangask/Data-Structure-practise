#include <stdio.h>

void perdown(int a[],int n)
{
	int parent,child;
	int tmp=a[0];
	for(parent=0;parent*2+1<n;parent=child){
		child=parent*2+1;
		if(child+1<n&&a[child]<a[child+1]) child++;
		if(a[child]>tmp) a[parent]=a[child];
		else break; 
	}
	a[parent]=tmp;
}

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
		printf("Heap Sort\n");
		for(i=n-1;i>0;i--){
			if(b[0]>b[i]) break;
		}
		tmp=b[i];
		b[i]=b[0];
		b[0]=tmp;
		perdown(b,i);
	}
	flag=0;
	for(i=0;i<n;i++){
		if(flag) printf(" ");
		flag=1;
		printf("%d",b[i]);
	}
	return 0;
}