#include <stdio.h>
#define infinity 100000
#define maxsize 100


 
int main(int argc, char const *argv[])
{
	int n,m;
	int d[maxsize][maxsize],maxd[maxsize];
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++){
			if(i==j) d[i][j]=0;
			else d[i][j]=infinity;
		}
	for(int i=0;i<m;i++){
		int a,b,x;
		scanf("%d %d %d",&a,&b,&x);
		d[a-1][b-1]=x;
		d[b-1][a-1]=x;
	}
	for(int k=0;k<n;k++)
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				if(d[i][k]+d[k][j]<d[i][j])
					d[i][j]=d[i][k]+d[k][j];
	for(int i=0;i<n;i++){
		maxd[i]=0;
		for(int j=0;j<n;j++){
			if(d[i][j]>maxd[i])
				maxd[i]=d[i][j];
		}
	}
	int min=infinity,mini;
	for(int i=0;i<n;i++)
		if(maxd[i]<min){
			min=maxd[i];
			mini=i;
		}
	if(min<infinity) printf("%d %d\n",mini+1,min);
	else printf("0\n");
	return 0;
}