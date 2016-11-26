#include <stdio.h>

int a[100005];

void bubble_sort(int a[],int n)
{
	for(int p=n-1;p>=0;p--){
		int flag=0;
		for(int i=0;i<p;i++){
			if(a[i]>a[i+1]){
				int t=a[i];
				a[i]=a[i+1];
				a[i+1]=t;
				flag=1;
			}
		}
		if(flag==0) break;
	}
}

void insertion_sort(int a[],int n)
{
	for(int p=1;p<n;p++){
		int tmp=a[p];
		int i=p;
		for(;i>0&&a[i-1]>tmp;i--)
			a[i]=a[i-1];
		a[i]=tmp;
	}
}

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	x_sort(a,n);
	int flag=0;
	for(int i=0;i<n;i++){
		if(flag) printf(" ");
		flag=1;
		printf("%d",a[i]);
	}
	return 0;
}