#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int tot[10005],ac[10005],a[10005][6],s[10005],b[10005];

int compare(const void* a,const void* b)
{
	if(tot[*(int*)a]>tot[*(int*)b]) return -1;
	else if(tot[*(int*)a]==tot[*(int*)b]) {
		if(ac[*(int*)a]>ac[*(int*)b]) return -1;
		else if(ac[*(int*)a]==ac[*(int*)b]) return (*(int*)a-*(int*)b);
	}
	return 1;
}

int main(int argc, char const *argv[])
{
	int n,k,m,p[10],i,num,num2,score;
	scanf("%d%d%d",&n,&k,&m);
	for(i=1;i<=k;i++)
		scanf("%d",&p[i]);
	memset(tot,0,sizeof(tot));
	memset(ac,0,sizeof(ac));
	memset(a,-1,sizeof(a));
	memset(b,0,sizeof(b));
	for(i=1;i<=n;i++) s[i]=i;
	for(i=0;i<m;i++){
		scanf("%d%d%d",&num,&num2,&score);
		if(score!=-1){
			b[num]=1;
			if(score>a[num][num2]) {
				if(a[num][num2]==-1) a[num][num2]=0;
				tot[num]+=(score-a[num][num2]);
				a[num][num2]=score;
				if(p[num2]==score) ac[num]++;
			}
		}else if(a[num][num2]==-1) a[num][num2]=0;	
	}
	qsort(s+1,n,sizeof(int),compare);
	int cnt=1,tmp=1,score2=tot[s[1]];
	for(i=1;i<=n;i++)
		if(b[s[i]]){
			if(tot[s[i]]!=score2) {tmp=cnt;score2=tot[s[i]];}
			printf("%d %05d %d",tmp,s[i],tot[s[i]]);
			for(int j=1;j<=k;j++) {
				if(a[s[i]][j]!=-1)printf(" %d",a[s[i]][j]);
				else printf(" -");
			}
			printf("\n");
			cnt++;
		}
	return 0;
}
