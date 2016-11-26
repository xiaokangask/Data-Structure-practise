#include <stdio.h>
#include <stdlib.h>
#define maxn 105
#define infinity 65535

struct node{
	int indegree;
	int earlist;
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

int g[maxn][maxn];

int main(int argc, char const *argv[])
{
	queue q;
	q=(queue)malloc(sizeof(struct qnode));
	q->front=q->rear=0;
	int n,m,v,w,weight,i,cnt=0,max=0;
	scanf("%d %d",&n,&m);
	for(v=0;v<n;v++){
		for(w=0;w<n;w++){
			if(v==w) g[v][w]=0;
			else g[v][w]=infinity;
		}
		points[v].indegree=0;
		points[v].earlist=0;
	}
	for(i=0;i<m;i++){
		scanf("%d %d %d",&v,&w,&weight);
		g[v][w]=weight;
		points[w].indegree++;
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
	for(v=0;v<n;v++)
		if(points[v].earlist>max) max=points[v].earlist;
	if(cnt<n) printf("Impossible\n");
	else printf("%d\n",max);
	return 0;
}