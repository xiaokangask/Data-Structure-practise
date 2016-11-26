#include <stdio.h>
#include <string.h>
#define Maxsize 32
#define Null 0

struct nodetree
{
	int p;
	int l;
	int r;
} ;

int main(int argc, char const *argv[])
{
	int n,i,a,push,p1,p2;
	scanf("%d\n",&n);
	int check[n+1],read[n+1];
	for(i=1;i<=n;i++) check[i]=0;
	struct nodetree s1[n+1],last[n+1],t[n+1];
	struct nodetree s2;
	char s[10];
	for(i=1;i<=n;i++){
		t[i].l=Null;
		t[i].r=Null;
	}
	gets(s);
	if(strlen(s)==6) a=s[5]-'0';
	if(strlen(s)==7) a=10*(s[5]-'0')+s[6]-'0';
	t[a].p=a;
	push=1;
	s1[push]=t[a];
	for(i=2;i<=2*n;i++){
		gets(s);
		if(strlen(s)>3){
			if(strlen(s)==6) a=s[5]-'0';
			if(strlen(s)==7) a=10*(s[5]-'0')+s[6]-'0';
			t[a].p=a;
			if(push!=0&&s1[push].r==Null){
				t[s1[push].p].r=a;
				check[a]=1;
				s1[push].r=a;
				push++;
				s1[push]=t[a];
			}else{
				t[s2.p].l=a;
				s2.l=a;
				check[a]=1;
				push++;
				s1[push]=t[a];
			}
		}else {
			s2=s1[push];
			push--;
		}
	}
	for(i=1;i<=n;i++){
		if(!check[i]) break;
	}
	p1=i;
	p2=0;
	i=1;
	while(p2||p1){
		while(p1){
			p2++;
			last[p2]=t[p1];
			read[i]=p1;
			i++;
			p1=t[p1].l;
		}
		if(p2){
			p1=last[p2].p;
			p2--;
			p1=t[p1].r;
		}
	}
	printf("%d",read[n]);
	for(i=n-1;i>0;i--) printf(" %d", read[i]);
	return 0;
}