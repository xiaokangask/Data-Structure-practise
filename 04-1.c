#include <stdio.h>
#include <stdlib.h>

typedef struct treenode *tree;
struct treenode
{
	int v;
	tree left;
	tree right;
	int flag;
};

tree maketree(int n);
tree newnode(int v);
tree insert(tree t,int v);
int judge(tree t,int n);
int check(tree t,int v);
void reset(tree t);
void freetree(tree t);

int main(int argc, char const *argv[])
{
	int i,n,l;
	tree t;
	scanf("%d", &n);
	while(n){
		scanf("%d",&l);
		t=maketree(n);
		for(i=0;i<l;i++){
			if(judge(t,n)) printf("Yes\n");
			else printf("No\n");
			reset(t);
		}
		freetree(t);
		scanf("%d",&n);
	}
	return 0;
}

tree maketree(int n)
{
	int i,v;
	tree t;
	scanf("%d",&v);
	t=newnode(v);
	for(i=1;i<n;i++){
		scanf("%d",&v);
		t=insert(t,v);
	}
	return t;
}

tree newnode(int v)
{
	tree t;
	t=(tree)malloc(sizeof(struct treenode));
	t->v=v;
	t->flag=0;
	t->left=NULL;
	t->right=NULL;
	return t;
}

tree insert(tree t,int v)
{
	if(!t) t=newnode(v);
	else{
		if(v<t->v) t->left=insert(t->left,v);
		else t->right=insert(t->right,v);
	}
	return t;
}

int judge(tree t,int n){
	int i,v,flag=0;
	scanf("%d",&v);
	if(v!=t->v) flag=1;
	else t->flag=1;
	for(i=1;i<n;i++){
		scanf("%d",&v);
		if((!flag)&&(!check(t,v))) flag=1;
	}
	if(flag) return 0;
	else return 1;
}

int check(tree t,int v)
{
	if(t->flag){
		if(v<t->v) return check(t->left,v);
		else if(v>t->v) return check(t->right,v);
		else return 0;
	}
	else{
		if(v==t->v){
			t->flag=1;
			return 1;
		} 
		else return 0;
	}
}

void reset(tree t)
{
	if(t->left) reset(t->left);
	if(t->right) reset(t->right);
	t->flag=0;
}

void freetree(tree t)
{
	
	if(t->left) freetree(t->left);
	if(t->right) freetree(t->right);
	free(t);
}


















