#include <stdio.h>
#include <stdlib.h>
#define maxsize 10000

typedef struct adjnode *ptoadjnode;
struct adjnode{
	int vertex;
	ptoadjnode next;
}; 

typedef struct gnode *lgraph;
struct gnode{
	int nv;
	int ne;
	ptoadjnode g[maxsize+1];
};

typedef struct qnode *queue;
struct qnode{
	int front;
	int rear;
	int data[maxsize+1];
};

lgraph graph;
int visited[maxsize+1];

void innitialised()
{
	int v;
	for(v=1;v<=graph->nv;v++)
		visited[v]=0;
}

queue createqueue()
{
	queue q;
	q=(queue)malloc(sizeof(struct qnode));
	q->front=0;
	q->rear=0;
	return q;
}

int isempty(queue q)
{
	return (q->front==q->rear);
}

void addq(queue q,int x)
{
	q->data[q->rear++]=x;
}

int deleteq(queue q)
{
	return q->data[q->front++];
}

int BFS(int v)
{
	ptoadjnode w;
	int level=0,tail,last,cnt=0;
	queue q;
	q=createqueue();
	visited[v]=1;
	last=v;
	addq(q,v);
	cnt++;
	while(!isempty(q)){
		v=deleteq(q);
		for(w=graph->g[v];w;w=w->next){
			if(visited[w->vertex]==0){
				visited[w->vertex]=1;
				addq(q,w->vertex);
				cnt++;
				tail=w->vertex;
			}
		}
		if(v==last) {
			level++;
			last=tail;
		}
		if(level==6) break;
	}
	return cnt;
}

int main(int argc, char const *argv[])
{
	int i,v,w;
	ptoadjnode p;
	graph=(lgraph)malloc(sizeof(struct gnode));
	scanf("%d %d",&graph->nv,&graph->ne);
	for(v=1;v<=graph->nv;v++)
		graph->g[v]=NULL;
	for(i=0;i<graph->ne;i++){
		scanf("%d %d",&v,&w);
		p=(ptoadjnode)malloc(sizeof(struct adjnode));
		p->vertex=w;
		p->next=graph->g[v];
		graph->g[v]=p;
		p=(ptoadjnode)malloc(sizeof(struct adjnode));
		p->vertex=v;
		p->next=graph->g[w];
		graph->g[w]=p;
	}
	for(v=1;v<=graph->nv;v++){
		innitialised();
		printf("%d: %.2f%c\n",v, 100.0*BFS(v)/graph->nv,37);
	}
	return 0;
}
