#include <stdio.h>
#define Null -1
struct nodetree
{
	int l;
	int r;
	int p;
}t[10],q[10];

int main(int argc, char const *argv[])
{
	int n,i,root,head=0,tail=0,flag=0;
	char chl,chr;
	scanf("%d\n",&n);
	int check[n];
	for(i=0;i<n;i++) check[i]=0;
	for(i=0;i<n;i++){
		t[i].p=i;
		scanf("%c %c\n",&chl,&chr);
		if(chl=='-') t[i].l=Null;
		else {
			t[i].l=chl-'0';
			check[t[i].l]=1;
		}
		if(chr=='-') t[i].r=Null;
		else{
			t[i].r=chr-'0';
			check[t[i].r]=1;
		}
	}
	for(i=0;i<n;i++){
		if(!check[i]) break;
	}
	root=i;
	q[head]=t[root];
	tail++;
	while(head!=tail){
		if((q[head].l==Null)&&(q[head].r==Null)) {
			if(flag) printf(" ");
			flag=1;
			printf("%d",q[head].p);
		}
		if(q[head].l!=Null){
			q[tail]=t[q[head].l];
			tail++;
		}
		if(q[head].r!=Null){
			q[tail]=t[q[head].r];
			tail++;
		}
		head++;
	}
	
	return 0;
}