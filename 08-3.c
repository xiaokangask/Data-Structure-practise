#include <stdio.h>
#include <stdlib.h>
#define maxn 105
#define infinity 65535

struct node{
	int indegree;
	int earlist;
	int latest;
	int outdegree;
}points[maxn];

typedef struct qnode *queue;
struct qnode{
	int front,rear;
	int a[maxn];
};

void add(queue q,int n)
{
	q->a[(q->rear)++]=n;
}

int deleteq(queue q)
{
	return (q->a[(q->front)++]);
}

int isempty(queue q)
{
	return (q->rear==q->front);
}

int g[maxn][maxn],sort[maxn][maxn];

int main(int argc, char const *argv[])
{
	queue q;
	q=(queue)malloc(sizeof(struct qnode));
	q->front=q->rear=0;
	int n,m,v,w,weight,i,cnt=0,max=0,maxv;
	scanf("%d %d",&n,&m);
	for(v=0;v<n;v++){
		for(w=0;w<n;w++){
			if(v==w) g[v][w]=0;
			else g[v][w]=infinity;
		}
		points[v].indegree=0;
		points[v].outdegree=0;
		points[v].earlist=0;
		points[v].latest=infinity;
	}
	for(v=0;v<n;v++)
		sort[v][n]=-1;
	for(i=0;i<m;i++){
		scanf("%d %d %d",&v,&w,&weight);
		sort[v-1][n]++;
		sort[v-1][(sort[v-1][n])]=w-1;
		g[v-1][w-1]=weight;
		points[w-1].indegree++;
		points[v-1].outdegree++;
	}
	for(v=0;v<n;v++)
		if(points[v].indegree==0)
			add(q,v);
	while(!isempty(q)){
		v=deleteq(q);
		cnt++;
		for(w=0;w<n;w++)
			if(g[v][w]<infinity&&v!=w){
				points[w].indegree--;
				if(points[w].indegree==0) add(q,w);
				if(points[v].earlist+g[v][w]>points[w].earlist)
					points[w].earlist=points[v].earlist+g[v][w];
			}
	}
	if(cnt<n) printf("0\n");
	else {
		for(v=0;v<n;v++)
			if(points[v].earlist>max) max=points[v].earlist;
		printf("%d\n",max);
		q->front=q->rear=0;
		for(v=0;v<n;v++)
			if(points[v].outdegree==0){
				add(q,v);
				points[v].latest=max;
			}
		while(!isempty(q)){
			v=deleteq(q);
			for(w=0;w<n;w++)
				if(g[w][v]<infinity&&w!=v){
					points[w].outdegree--;
					if(points[w].outdegree==0) add(q,w);
					if(points[v].latest-g[w][v]<points[w].latest)
						points[w].latest=points[v].latest-g[w][v];
				}
		}
		for(v=0;v<n;v++)
				for(i=sort[v][n];i>=0;i--){
					w=sort[v][i];
					if(points[w].latest-points[v].earlist<=g[v][w])
						printf("%d->%d\n",v+1,w+1);
				}
	}
}