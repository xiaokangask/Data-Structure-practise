#include <stdio.h>
void maxsub(int a[],int b[],int k);
int main(int argc, char const *argv[])
{
	int k;
	scanf("%d", &k);
	int a[k],b[3]={0,0,0};
	for(int i=0;i<k;i++){
		scanf("%d",&a[i]);
	}
 	maxsub(a,b,k);
 	printf("%d %d %d", b[0],b[1],b[2]);
	return 0;
}
void maxsub(int a[],int b[],int k)
{
	int i,thisnumber=0,t=-1,m=0,n=0;
	for(i=0;i<k;i++){
		if(a[i]>0) {
			m=1;
			break;
		}
	}
	if(m){
	    for(i=0;i<k;i++){
		    thisnumber+=a[i];
		    if(a[i]!=0){
		    	if(thisnumber>b[0]){
					b[0]=thisnumber;
					b[1]=a[t+1];
		  			b[2]=a[i];
		    	}else if(thisnumber<0){
		    		thisnumber=0;
		    		t=i;
		    	}
		    }else{
		    	t=i;
		    	while(!a[++i]);
		    	i--;
		    }
	    }
	}else{
		for(i=0;i<k;i++){
			if(a[i]==0) {
				n=1;
				break;
			}
		}
		if(n){
			b[0]=b[1]=b[2]=0;
		}else{
			b[0]=0;
			b[1]=a[0];
			b[2]=a[k-1];
		}
		
	}
}



















