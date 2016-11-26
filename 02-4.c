#include <stdio.h>
#include <string.h>

int  main(int argc, char const *argv[])
{
	int m,n,k,pa,pb,j,x,flag;
	scanf("%d%d%d", &m,&n,&k);
	int b[m];
	char yn[k][4];
	for(int i=0;i<k;i++){
		strcpy(yn[i],"YES");
	}
	for(int i=0;i<k;i++){
		j=0;
		pa=0;
		pb=0;
		flag=0;
		for(;j<n;j++){
			scanf("%d",&x);
			if(j==0){
				while(x!=pa+1){
					if(pb>=m){
						flag=1;
						break;
					}
					b[pb]=pa+1;
					pb++;
					if(pb>=m){
						flag=1;
						break;
					}
					pa++;
				}
				pa++;
			}else{
				if(pb>0&&b[pb-1]>x){
					flag=1;
					j++;
					break;
				}else if(pb>0&&b[pb-1]==x){
					pb--;
				}else {
					while(x!=pa+1){
						if(pb>=m){
							flag=1;
							break;
					
						}
						b[pb]=pa+1;
						pb++;
						if(pb>=m){
							flag=1;
							break;
						}
						pa++;
					}
					pa++;

				}
			}
			if(flag==1){
				j++;
				break;
			}
			
		}
		if(flag==1){
			strcpy(yn[i],"NO");
		}
		for(;j<n;j++){
			scanf("%d",&x);
		}
	}
	for(int i=0;i<k;i++){
		printf("%s\n",yn[i]);
	}
	return 0;
}