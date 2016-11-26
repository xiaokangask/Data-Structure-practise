#include <stdio.h>
#define infinity 1000000
#define maxsize 500

struct node{
	int l;
	int f;
};

int findmin(int collected[],int dist[],int n)
{
	int minv,min=infinity;
	for(int i=0;i<n;i++){
		if(collected[i]==0)
			if(dist[i]<min){
				min=dist[i];
				minv=i;
			}
	}
	if(min==infinity) return -1;
	else return minv;
}

int main(int argc, char const *argv[])
{
	int n,m,s,d,v,w;
	int dist[maxsize],cost[maxsize],collected[maxsize];
	struct node g[maxsize][maxsize];
	scanf("%d %d %d %d",&n,&m,&s,&d);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(i==j) g[i][j].l=g[i][j].f=0;
			else g[i][j].l=g[i][j].f=infinity;
	for(int i=0;i<m;i++){
		int n1,n2,l,f;
		scanf("%d %d %d %d",&n1,&n2,&l,&f);
		g[n1][n2].l=g[n2][n1].l=l;
		g[n1][n2].f=g[n2][n1].f=f;
	}
	for(int i=0;i<n;i++){
		dist[i]=g[s][i].l;
		cost[i]=g[s][i].f;
	}
	for(int i=0;i<n;i++)
		collected[i]=0;
	collected[s]=1;
	while(1){
		v=findmin(collected,dist,n);
		if(v!=-1) collected[v]=1;
		else break;
		for(int w=0;w<n;w++)
			if(collected[w]==0&&g[v][w].l<infinity){
				if(dist[v]+g[v][w].l<dist[w]){
					dist[w]=dist[v]+g[v][w].l;
					cost[w]=cost[v]+g[v][w].f;
				}
				else if(dist[v]+g[v][w].l==dist[w]&&cost[v]+g[v][w].f<cost[w])
					cost[w]=cost[v]+g[v][w].f;
			}
	}
	printf("%d %d\n",dist[d],cost[d]);
	return 0;
}