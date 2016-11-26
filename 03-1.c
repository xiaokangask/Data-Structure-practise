#include <stdio.h>

struct treenode
{
	char ch;
	int left;
	int right;
} t1[10],t2[10];

int createtree(struct treenode t[])
{	
	int N,r=-1,i;
	char chl,chr;
	scanf("%d\n",&N);
	int a[N];
	if(N){
		for(i=0;i<N;i++) a[i]=0;
		for(i=0;i<N;i++){
			if(i!=N-1)	
				scanf("%c %c %c\n", &t[i].ch,&chl,&chr);
			else
				scanf("%c %c %c", &t[i].ch,&chl,&chr);
			if(chl=='-') 
				t[i].left=-1;
			else {
				t[i].left=chl-'0';
				a[t[i].left]=1;
			}
			if(chr=='-') 
				t[i].right=-1;
			else {
				t[i].right=chr-'0';
				a[t[i].right]=1;
			}
		}
		for(i=0;i<N;i++) if(!a[i]) break;
		r=i;
	}
	return r;
}

int issame(int r1,int r2)
{
	if((r1==-1)&&(r2==-1)) return 1;
	if(((r1==-1)&&(r2!=-1))||((r1!=-1)&&(r2==-1))) return 0;
	if(t1[r1].ch!=t2[r2].ch) return 0;
	if(t1[r1].right==-1&&t2[r2].right==-1) return issame(t1[r1].left,t2[r2].left);
	if((t1[r1].right!=-1)&&(t2[r2].right!=-1)&&((t1[t1[r1].right].ch)==(t2[t2[r2].right].ch))) {
		return (issame(t1[r1].left,t2[r2].left)&&issame(t1[r1].right,t2[r2].right));
	} else
		return (issame(t1[r1].left,t2[r2].right)&&issame(t1[r1].right,t2[r2].left));
	
}

int main(int argc, char const *argv[])
{
	int r1,r2;
	r1=createtree(t1);
	r2=createtree(t2);
	if(issame(r1,r2)) printf("Yes\n");
	else printf("No\n");
	return 0;
}