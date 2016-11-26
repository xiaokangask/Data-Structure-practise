#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define maxsize 100

struct gnode{
	double x;
	double y;
};

typedef struct qnode *queue;
struct qnode{
	int data[maxsize];
	int front;
	int rear;
};

double d;

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

int isjump(struct gnode g[],int m,int n)
{
	return (d>=sqrt(pow((g[m].x-g[n].x),2)+pow((g[m].y-g[n].y),2)));
}

int isfirstjump(struct gnode g[],int n)
{
	return (d+7.5>=sqrt(pow(g[n].x,2)+pow(g[n].y,2)));
}

int issave(struct gnode g[],int n)
{
	return (d>=50-g[n].x||d>=50+g[n].y||d>=50+g[n].x||d>=50-g[n].y);
}

int find(int path[],int x)
{
	while(path[x]!=-1){
		x=path[x];
	}
	return x;
}

int main(int argc, char const *argv[])
{
	int n,dist[maxsize],safepath[maxsize],v,w,path[maxsize],cnt=0;
	struct gnode g[maxsize];
	scanf("%d %lf",&n,&d);
	
	
		for(int i=0;i<n;i++)
			scanf("%lf %lf",&g[i].x,&g[i].y);
		for(int i=0;i<n;i++)
			dist[i]=0;
		queue q;
		q=(queue)malloc(sizeof(struct qnode));
		q->front=q->rear=0;
		for(int i=0;i<n;i++)
			if(isfirstjump(g,i)){
				addq(q,i);
				dist[i]++;
				path[i]=-1;
			}
		while(!isempty(q)){
			v=deleteq(q);
			for(int w=0;w<n;w++)
				if(dist[w]==0&&isjump(g,v,w)){
					path[w]=v;
					addq(q,w);
					dist[w]=dist[v]+1;
				}
		}
		int min=200,mini;
		for(int i=0;i<n;i++){
			if(issave(g,i)&&dist[i]!=0){
				if(dist[i]<min){
					min=dist[i];
					mini=i;
				}
				else if(dist[i]==min){
					int m,n;
					m=find(path,mini);
					n=find(path,i);
					if(pow(g[m].x,2)+pow(g[m].y,2)>pow(g[n].x,2)+pow(g[n].y,2)) mini=i;
				}
			}
		}
		if(d+7.5>=50.0) printf("1\n");
		else if(min==200) printf("0\n");
		else {
			min++;
			for(int i=0;i<min-1;i++){
				safepath[i]=mini;
				mini=path[mini];
			}
			printf("%d\n",min);
			for(int i=min-2;i>=0;i--)
				printf("%.0f %.0f\n",g[safepath[i]].x,g[safepath[i]].y);

	}	
	return 0;
}