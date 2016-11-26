#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define maxsize 100
#define YES 1
#define NO 0

typedef struct gnode *graph;
struct gnode{
	double x[maxsize];
	double y[maxsize];
	int nv;
};

graph g;
double d;
int answer,visited[maxsize];

int firstjump(int v)
{
	return ((d+7.5)>=sqrt(pow(g->x[v],2)+pow(g->y[v],2)));
}

int jump(int v,int w)
{
	return (d>=sqrt(pow(g->x[v]-g->x[w],2)+pow(g->y[v]-g->y[w],2)));
}

int issafe(int v)
{
	return (d>=(50-g->x[v])||d>=(g->x[v]+50)||d>=(50-g->y[v])||d>=(g->y[v]+50));
}

int DFS(int v)
{
	int w;
	visited[v]=1;
	if(issafe(v)) answer=YES;
	else{
		for(w=0;w<g->nv;w++)
			if(jump(v,w)&&!visited[w]){
				answer=DFS(w);
				if(answer==YES) break;
			}
	}
	return answer;
}

void save007(graph g)
{
	int v;
	for(v=0;v<g->nv;v++)
		if(firstjump(v)&&!visited[v]){
			answer=DFS(v);
			if(answer==YES) break;
		}
	if(answer==YES) printf("Yes");
	else printf("No");
}

int main(int argc, char const *argv[])
{
	int v;
	g=(graph)malloc(sizeof(struct gnode));
	answer=NO;
	scanf("%d %lf",&g->nv,&d);
	for(v=0;v<g->nv;v++)
		scanf("%lf %lf",&g->x[v],&g->y[v]);
	for(v=0;v<g->nv;v++)
		visited[v]=0;
	save007(g);
	return 0;
}

