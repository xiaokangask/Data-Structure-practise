#include <stdio.h>
#define maxsize 10000

int s[maxsize];

int find(int x)
{
	if(s[x]<0) return x;
	else return s[x]=find(s[x]);
}

void unionnetwork(int root1,int root2)
{
	if(s[root1]>s[root2]) s[root1]=root2;
	else{
		if(s[root1]==s[root2]) s[root1]--;
		s[root2]=root1;
	}
}

void input_connections()
{
	int c1,c2;
	scanf("%d %d",&c1,&c2);
	int root1=find(c1-1);
	int root2=find(c2-1);
	if(root1!=root2) unionnetwork(root1,root2); 
}

void check_connections()
{
	int c1,c2;
	scanf("%d %d",&c1,&c2);
	int root1=find(c1-1);
	int root2=find(c2-1);
	if(root1==root2) printf("yes\n");
	else printf("no\n");
}

void check_network(int n)
{
	int i=0,j=0;
	for(;i<n;i++)
		if(s[i]<0) j++;
	if(j==1) printf("The network is connected.\n");
	else printf("There are %d components.\n", j);
}

int main(int argc, char const *argv[])
{
	int i,n;
	char in;
	scanf("%d",&n);
	for(i=0;i<n;i++) s[i]=-1;
	do{
		scanf("%c",&in);
		switch(in){
			case 'I' :input_connections(); break;
			case 'C' :check_connections(); break;
			case 'S' :check_network(n); break;
		}
	}while(in!='S');
	return 0;
}