#include <stdio.h>
#include <string.h>

int a[1000][1000],b[1000],indegree[1000];

int findmini(int n)
{
	int i;
	for(i=0;i<n;i++)
		if(indegree[i]>=0) break;
	if(i==n) return -1;
	else{
		int min=indegree[i],mini=i;
		for(int j=i+1;j<n;j++){
			if(indegree[j]>=0){
				if((indegree[j]<min)||(indegree[j]==min&&b[j]<b[mini])) {min=indegree[j];mini=j;}
			}		
		}
		return mini;
	}
}

int main(int argc, char const *argv[])
{
	int n,cnt=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&b[i]);
	memset(a,0,sizeof(a));
	memset(indegree,0,sizeof(indegree));
	for(int i=0;i<n;i++){
		if(b[i]>=0){
			int x=b[i]%n;
			cnt++;
			while(b[x]!=b[i]){
				indegree[i]++;
				a[x][i]=1;
				x=(x+1)%n;
			}
		}else indegree[i]=-1;
	}
	int flag=0,mini;
	for(int j=0;j<cnt;j++){
		mini=findmini(n);
		if(flag) printf(" ");
		flag=1;
		printf("%d",b[mini]);
		indegree[mini]=-1;
		for(int i=0;i<n;i++)
			if(a[mini][i]==1) indegree[i]--;
	}
	return 0;
}