#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct inode* pnode;
struct inode{
	long num;
	char sec[20];
	pnode next;
};


pnode lists[100000];

long hash(long a)
{
	return (a/100000+a%100000)%100000;
}

pnode find(long num)
{
 	long pos=hash(num);
 	pnode p=lists[pos];
 	while(p&&p->num!=num){
 		p=p->next;
 	}
 	return p;
}

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d\n",&n);
	memset(lists,NULL,sizeof(lists));
	while(n--){
		char op,sec[20];
		long num;
		scanf("%c %ld %s\n",&op,&num,sec);
		//printf("%c\n",op);
		if(op=='N'){
			if(find(num)) printf("ERROR: Exist\n");
			else {
				long pos=hash(num);
				pnode p=(pnode)malloc(sizeof(struct inode));
				strcpy(p->sec,sec);
				p->num=num;
				p->next=lists[pos];
				lists[pos]=p;
				printf("New: OK\n");
			}
		}else{
			pnode p=find(num);
			if(p){
				if(strcmp(p->sec,sec)==0) printf("Login: OK\n");
				else printf("ERROR: Wrong PW\n");
			}else printf("ERROR: Not Exist\n");
		}
	}
	return 0;
}
