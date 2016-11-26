#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
	 int data;
	 char add[6];
	 char nadd[6];
	 struct node *next;
};

typedef struct node *pnode;

int main(int argc, char const *argv[])
{
	int n,k,k0,k1,n0=1;
	pnode t,p,temp,head,p1,p2,h,t0;
	char str[6];
	scanf("%s%d%d", str,&n,&k);
	p=(pnode)malloc(sizeof(struct node));
	p->next=NULL;
	temp=p;
	for(int i=0;i<n;i++){
		t=(pnode)malloc(sizeof(struct node));
		scanf("%s%d%s", t->add,&t->data,t->nadd);
		t->next=NULL;
		temp->next=t;
		temp=t;
	}

	temp=p;
	while(temp->next){
		if(!strcmp(str,temp->next->add)){
			head=temp->next;
			temp->next=head->next;
			head->next=p->next;
			free(p);
			break;
		}
		temp=temp->next;
	}
	

	p=temp=head;
	for(int i=0;i<n-1;i++){
		while(temp->next){
			if(!strcmp(p->nadd,temp->next->add)){
				t=temp->next;
				temp->next=t->next;
				t->next=p->next;
				p->next=t;
				temp=p=p->next;
				n0++;
				break;
			}
			temp=temp->next;
		}
	}

	p=head;
	h=(pnode)malloc(sizeof(struct node));
	h->next=NULL;
	p1=p2=h;
	k0=n0/k;
	for(int i=0;i<k0;i++){
		for(int j=0;j<k;j++){
			t=p;
			p=p->next;
			t->next=p1->next;
			if(p1->next){
				strcpy(t->nadd,p1->next->add);
			}else{
				strcpy(t->nadd,"-1");
			}
			p1->next=t;
			strcpy(p1->nadd,t->add);
			if(j==0){
				p2=t;
				p2->next=NULL;
			}
		}
		p1=p2;
	}
	if (p){
		p2->next=p;
		strcpy(p2->nadd,p->add);
	}
	t=h;
	h=h->next;
	free(t);

	temp=h;
	for(int i=0;i<n0;i++){
		printf("%s %d %s\n",temp->add,temp->data,temp->nadd);
		temp=temp->next;
	}

	return 0;
}