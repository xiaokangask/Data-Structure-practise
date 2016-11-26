#include <stdio.h>
#define infinity 65535
#define maxn 1005

int g[maxn][maxn],dist[maxn];

int getmin(int n)
{
	int min=infinity,mini,v;
	for(v=0;v<n;v++)
		if(dist[v]!=0&&dist[v]<min){
			min=dist[v];
			mini=v;
		}
	if(min<infinity) return mini;
	else return -1;
}

int main(int argc, char const *argv[])
{
	int n,m,v,w,weight,i,totalweight=0;
	scanf("%d %d",&n,&m);
	for(int v=0;v<n;v++)
		for(int w=0;w<n;w++){
			if(v==w) g[v][w]=0;
			else g[v][w]=infinity;
		}
	for(int v=0;v<n;v++)
		dist[v]=infinity;
	dist[0]=0;
	for(i=0;i<m;i++){
		scanf("%d %d %d",&v,&w,&weight);
		g[v-1][w-1]=g[w-1][v-1]=weight;
		if(v==1) dist[w-1]=weight;
		if(w==1) dist[v-1]=weight;
	}
	for(i=0;i<n-1;i++){
		v=getmin(n);
		if(v==-1) break;
		totalweight+=dist[v];
		dist[v]=0;
		for(int w=0;w<n;w++){
			if(dist[w]!=0&&g[v][w]<infinity)
				if(g[v][w]<dist[w])
					dist[w]=g[v][w];
		}
	}
	if(i<n-1) printf("-1\n");
	else printf("%d\n",totalweight);
	return 0;
}