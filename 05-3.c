#include <stdio.h>
#include <stdlib.h>
#define maxsize 64

typedef Huffmantree *ph;

int size;

struct Huffmantree
{
	int f;
	ph right;
	ph left;
	int flag;
} h[maxsize];

void create_heap()
{
	int i=size/2;
}

void 

int main(int argc, char const *argv[])
{
	int i,n;
	char ch;
	scanf("%d", &n);
	size=n;
	h[0].f=-1;
	h[0].right=h[0].left=NULL;
	h[i].flag=0;
	for(i=0;i<n;i++){
		scanf("%c %d", &ch,&h[i+1].f);
		h[i+1].right=h[i+1].left=NULL;
		h[i].flag=0;
	}
	create_heap();
	return 0;
}