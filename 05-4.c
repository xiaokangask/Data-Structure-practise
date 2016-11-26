#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct huffnode *huff;
struct huffnode{
	int weight;
	huff right;
	huff left;
};

typedef struct treenode *tree;
struct treenode{
	int status;
	tree right;
	tree left;
};

huff h[100];
int f[200];

void perdown(int n)
{
	int parent,child;
	int tmp=h[1]->weight;
	huff ptmp=h[1];
	for(parent=1;parent*2<=n;parent=child){
		child=parent*2;
		if(child+1<=n&&h[child]->weight>h[child+1]->weight) child++;
		if(h[child]->weight<tmp) h[parent]=h[child];
		else break;
	}
	h[parent]=ptmp;
}

void perup(int i)
{
	int j;
	int tmp=h[i]->weight;
	huff ptmp=h[i];
	for(j=i;j>1&&h[j/2]->weight>tmp;j/=2)
		h[j]=h[j/2];
	h[j]=ptmp;
}

int wpl(huff h,int d)
{
	if(!h->left&&!h->right) return d*(h->weight);
	else {
		return wpl(h->right,d+1)+wpl(h->left,d+1);
	}
}

int main(int argc, char const *argv[])
{
	int n,i,k,j,len,leni,lenj;
	huff tmp1,tmp2,tmp;
	scanf("%d\n",&n);
	for(i=1;i<=n;i++)
		h[i]=(huff)malloc(sizeof(struct huffnode));
	for(i=1;i<=n;i++){
		char ch;
		int x;
		if(i==n-1) scanf("%c %d\n",&ch,&x);
		else scanf("%c %d ",&ch,&x);
		f[ch]=x;
		h[i]->weight=f[ch];
		h[i]->right=h[i]->left=NULL;
		perup(i);
	}
	len=n;
	while(len>1){
		tmp1=h[1];
		h[1]=h[len--];
		perdown(len);
		tmp2=h[1];
		h[1]=h[len--];
		perdown(len);
		tmp=(huff)malloc(sizeof(struct huffnode));
		tmp->weight=tmp1->weight+tmp2->weight;
		tmp->left=tmp1;tmp->right=tmp2;
		h[++len]=tmp;
		perup(len);
	}
	/*int totalweight=wpl(h[1],0);
	int m;
	char s[100],ch;
	scanf("%d\n",&m);
	while(m--){
		tree t=(tree)malloc(sizeof(struct treenode));
		t->right=t->left=NULL;
		t->status=0;
		int weighti=0;
		int flag=0;
		for(k=0;k<n;k++){
			scanf("%c %s\n",&ch,s);
			len=strlen(s);
			if(flag==0&&len>=n) flag=1;
			if(flag==0){
				weighti+=len*f[ch];
				tree p=t;
				for(i=0;i<len&&flag==0;i++){
					if(s[i]=='0'){
						if(!p->right) {
							tree pt=(tree)malloc(sizeof(struct treenode));
							pt->status=0;
							pt->right=pt->left=NULL;
							p->right=pt;
						}else if(p->right->status) {flag=1;break;}
						p=p->right;
					}else{
						if(s[i]=='1'){
							tree pt=(tree)malloc(sizeof(struct treenode));
							pt->status=0;
							pt->right=pt->left=NULL;
							p->left=pt;
						}else if(p->left->status) {flag=1;break;}
						p=p->left;
					}
				}
				if(flag==0&&(p->right||p->left)) flag=1;
				else p->status=1;
			}
		}
		if(flag==0&&totalweight==weighti) printf("Yes\n");
		else printf("No\n");
	}*/
	int totalweight=wpl(h[1],0);
	int m;
	scanf("%d\n",&m);
	while(m--){
		char s[n][100],ch;
		int weighti=0,flag=0;
		for(i=0;i<n;i++){
			scanf("%c %s\n",&ch,s[i]);
			if(strlen(s[i])>=n) flag=1;
			if(flag==0) weighti+=strlen(s[i])*f[ch];
		}
		if(weighti==totalweight&&flag==0){
			for(i=0;i<n;i++){
				leni=strlen(s[i]);
				for(j=i+1;j<n;j++){
					lenj=strlen(s[j]);
					len=(leni<lenj?leni:lenj);
					for(k=0;k<len;k++) if(s[i][k]!=s[j][k]) break;
					if(k==len) {flag=1;break;}
				}
				if(flag) break;
			}
		}
		if(flag==0&&totalweight==weighti) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
