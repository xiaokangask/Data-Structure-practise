#include <stdio.h>
#include <stdlib.h>

typedef struct avltreenode *tree;
struct avltreenode
{
	int v;
	tree left;
	tree right;
	int height;
};

tree insert(tree t,int v);
int max(int a,int b);
tree singleleftrotation(tree t);
tree siglerightrotation(tree t);
tree doubleleftrightrotation(tree t);
tree doublerightleftrotation(tree t);
int getheight(tree t);

int main(int argc, char const *argv[])
{
	int n,i;
	int v;
	tree t;
	t=(tree)malloc(sizeof(struct avltreenode));
	scanf("%d\n", &n);
	for(i=0;i<n;i++){
		scanf("%d",&v);
		if(i==0) {
			t->v=v;
			t->left=t->right=NULL;
			t->height=1;
		}
		else t=insert(t,v);
		//printf("%d\n",t->v);
	}
	printf("%d",t->v);
	return 0;
}

tree insert(tree t,int v)
{
	if(!t){
		t=(tree)malloc(sizeof(struct avltreenode));
		t->right=t->left=NULL;
		t->v=v;
		t->height=0;
	}
	else if(v<t->v){
		t->left=insert(t->left,v);
		if((getheight(t->left)-getheight(t->right))==2){
			if(v<t->left->v) t=singleleftrotation(t);
			else t=doubleleftrightrotation(t);
		}
	}else if(v>t->v){
		t->right=insert(t->right,v);
		if((getheight(t->left)-getheight(t->right))==-2){
			if(v>t->right->v) t=siglerightrotation(t);
			else t=doublerightleftrotation(t);
		}
	}
	t->height=max(getheight(t->right),getheight(t->left))+1;
	return t;
}

int max(int a,int b)
{
	return a>b?a:b;
}

tree singleleftrotation(tree t)
{
	tree b=t->left;
	t->left=b->right;
	b->right=t;
	t->height=max(getheight(t->left),getheight(t->right))+1;
	b->height=max(getheight(b->left),t->height)+1;
	return b;
}

tree siglerightrotation(tree t)
{
	tree b=t->right;
	t->right=b->left;
	b->left=t;
	t->height=max(getheight(t->left),getheight(t->right))+1;
	b->height=max(getheight(b->right),t->height)+1;
	return b;
}

tree doublerightleftrotation(tree t)
{
	t->right=singleleftrotation(t->right);
	return siglerightrotation(t);
}

tree doubleleftrightrotation(tree t)
{
	t->left=siglerightrotation(t->left);
	return singleleftrotation(t);
}

int getheight(tree t)
{
	if(!t) return 0;
	else return (max(getheight(t->right),getheight(t->left))+1);
}
