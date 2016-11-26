#include <stdio.h>
#include <stdlib.h>
struct node{
	int c;
	int e;
	struct node *next;
};
typedef struct node *pnode;
pnode getp();
pnode addp(pnode p1,pnode p2);
pnode mulp(pnode p1,pnode p2);
void printp(pnode p);
void cop(pnode *pp,int a, int b);
int main(int argc, char const *argv[])
{
	pnode pa,pm,p1, p2;
	p1=getp();
	p2=getp();
	pm=mulp(p1,p2);
	printp(pm);
	printf("\n");
	pa=addp(p1,p2);
	printp(pa);
	return 0;
}

pnode getp()
{
	int m,a,b;
	pnode p,temp,t;
	scanf("%d", &m);
	if(!m){
		return NULL;
	}
	p=(pnode)malloc(sizeof(struct node));
	p->next=NULL;
	temp=p;
	for(int i=0;i<m;i++){
		scanf("%d %d", &a,&b);
		cop(&temp,a,b);
	}
	t=p;
	p=p->next;
	free(t);
	return p;
}

pnode addp(pnode p1,pnode p2)
{
	if(!p1) return p2;
	pnode p,t,temp;
	p=(pnode)malloc(sizeof(struct node));
	p->next=NULL;
	temp=p;
	while(p2&&p1){
		if(p1->e>p2->e){
			cop(&temp,p1->c,p1->e);
			p1=p1->next;
		}else if(p1->e<p2->e){
			cop(&temp,p2->c,p2->e);
			p2=p2->next;
		}else {
			if(p1->c+p2->c){
				cop(&temp,p1->c+p2->c,p2->e);
			}
			p1=p1->next;
			p2=p2->next;
		}
	}
	while(p1){
		cop(&temp,p1->c,p1->e);
		p1=p1->next;
	}
	while(p2){
		cop(&temp,p2->c,p1->e);
		p2=p2->next;
	}
	t=p;
	p=p->next;
	free(t);
	return p;
}

pnode mulp(pnode p1,pnode p2)
{
	pnode temp,p,t1,t2,t;
	int c0,e0;
	if(!p1||!p2) return NULL;
	t1=p1;
	t2=p2;
	p=(pnode)malloc(sizeof(struct node));
	p->next=NULL;
	temp=p;
	while(t2){
		cop(&temp,t1->c*t2->c,t1->e+t2->e);
		t2=t2->next;
	}
	t1=t1->next;
	while(t1){
		temp=p;
		t2=p2;
		while(t2){
			c0=t1->c*t2->c;
			e0=t1->e+t2->e;
			while(temp->next&&e0<temp->next->e){
				temp=temp->next;
			}
			if(temp->next&&e0==temp->next->e){
				if(c0+temp->next->c){
					temp->next->c+=c0;
				}else{
					t=temp->next;
					temp->next=t->next;
					free(t);
				}
			}else{
				t=(pnode)malloc(sizeof(struct node));
				t->c=c0;
				t->e=e0;
				t->next=temp->next;
				temp->next=t;
				temp=temp->next;
			}

			t2=t2->next;
		}
		t1=t1->next;
	}
	t2=p;
	p=p->next;
	free(t2);
	return p;
}

void printp(pnode p)
{
	int flag=0;
	if(!p) printf("0 0");
	while(p){
		if(flag) printf(" ");
		flag=1;
		printf("%d %d",p->c,p->e);
		p=p->next;
	}
}

void cop(pnode *pp,int a,int b)
{
	 pnode p;
	 p=(pnode)malloc(sizeof(struct node));
	 p->c=a;
	 p->e=b;
	 p->next=NULL;
	 (*pp)->next=p;
	 *pp=p;
}