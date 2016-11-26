#include <stdio.h>
#include <stdlib.h>
#define maxsize 10

typedef struct gnode *mgraph;
struct gnode{
	int nv;
	int ne;
	int g[maxsize][maxsize];
};

typedef struct qnode *queue;
struct qnode{
	int front;
	int rear;
	int data[maxsize+1];
};

queue createqueue()
{
	queue q;
	q=(queue)malloc(sizeof(struct qnode));
	q->front=0;
	q->rear=0;
	return q;
} 

void addq(queue q,int v)
{
	q->data[++q->rear]=v;
}

int deleteq(queue q)
{
	return q->data[++q->front];
}

int isempty(queue q)
{
	return (q->rear==q->front);
}

int visited[maxsize];

void DFS(mgraph graph,int v)
{
	int w;
	printf("%d ",v);
	visited[v]=1;
	for(w=0;w<graph->nv;w++)
		if(graph->g[v][w]==1&&visited[w]==0)
			DFS(graph,w);
}

void BFS(mgraph graph,int v)
{
	int w;
	queue q=createqueue();
	printf("%d ", v);
	visited[v]=1;
	addq(q,v);
	while(!isempty(q)){
		v=deleteq(q);
		for(w=0;w<graph->nv;w++)
			if(graph->g[v][w]==1&&visited[w]==0){
				printf("%d ", w);
				visited[w]=1;
				addq(q,w);
			}
	}
}

int main(int argc, char const *argv[])
{
	int i,v,w;
	mgraph graph;
	graph=(mgraph)malloc(sizeof(struct gnode));
	scanf("%d %d",&graph->nv,&graph->ne);
	for(v=0;v<graph->nv;v++)
		for(w=0;w<graph->nv;w++)
			graph->g[v][w]=0;
	for(i=0;i<graph->ne;i++){
		scanf("%d %d",&v,&w);
		graph->g[v][w]=graph->g[w][v]=1;	
	}
	for(i=0;i<graph->nv;i++)
		visited[i]=0;
	for(v=0;v<graph->nv;v++)
		if(!visited[v]){
			printf("{ ");
			DFS(graph,v);
			printf("}\n");
		}
	for(i=0;i<graph->nv;i++)
		visited[i]=0;
	for(v=0;v<graph->nv;v++)
		if(!visited[v]){
			printf("{ ");
			BFS(graph,v);
			printf("}\n");
		}
	return 0;
}
