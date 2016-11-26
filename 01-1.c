#include <stdio.h>
int maxsub(int a[],int left,int right);
int main(int argc, char const *argv[])
{
	int k;
	scanf("%d",&k);
	int a[k];
	for(int i = 0;i<k;i++){
		scanf("%d",&a[i]);
	}
	printf("%d",maxsub(a,0,k-1));
	return 0;
}

int maxsub(int a[],int left,int right)
{
	int maxleftsum,maxrightsum,maxcenter,max;
	int maxleftbsum=0,maxrightbsum=0;
	int leftbsum=0,rightbsum=0;
	int center,i;
	if(left==right){
		if(a[left]>0) return a[left];
		else return 0;
	}
	center=(left + right)/2;
	maxleftsum=maxsub(a,left,center);
	maxrightsum=maxsub(a,center+1,right);
	for(i=center;i>=left;i--){
		leftbsum+=a[i];
		if(leftbsum>maxleftbsum) maxleftbsum=leftbsum;
	}

	for(i=center+1;i<=right;i++){
		rightbsum+=a[i];
		if(rightbsum>maxrightbsum) maxrightbsum=rightbsum;
	}

	maxcenter=maxleftbsum+maxrightbsum;

	if(maxleftsum>maxcenter) {
		if(maxleftsum>maxrightsum) max=maxleftsum;
		else max=maxrightsum;
	}else{
		if(maxcenter>maxrightsum) max=maxcenter;
		else max=maxrightsum;
	}
	return max;
}

































