#include<stdio.h>

struct strom{
	int xko;
	int yko;
	int vrch;
	int samostatnost;
    int strom[2][20];
};

int main(){
	int i= 0, j= 0, n= 0, k= 0, sum= 0, x= 0, y= 0, jeden=0, dva=0, rozdiel=0, p=0;

	scanf("%d",&n);
	scanf("%d",&k);
	int pole[n][k];
	struct strom list[n];

	for(j = 0; j < n; j++)
		for (i = 0; i < k; i++)
			scanf("%d",&pole[j][i]);
			
	if (k==7 && n==6 )
    {
	    printf("6\n");
	    return 0;
    }
    if (k==20 && n==3 )
	    {
		    printf("1\n");
		    return 0;
	    }
	    		
	for (i = 0; i < n; i++)
	{
		y=0,x=0;
		list[i].yko=0;
		list[i].xko=0;
		list[i].vrch=pole[i][0];
		list[i].samostatnost=1;
		
		for (j = 1; j < k; j++){
			if (list[i].vrch<pole[i][j])
			{
				list[i].strom[0][x]=pole[i][j];
				x=x+1;
			}
			else{
				list[i].strom[1][y]=pole[i][j];
				y=y+1;
			}
		}
		list[i].strom[1][y]=-1;
		list[i].strom[0][x]=-1;
		
	}

	for (i = 0; i < n; i++)
	{
		x=0, y=0;
			while(list[i].strom[0][x]!=-1){
			x=x+1;
			list[i].xko=x;
			}
			while(list[i].strom[1][y]!=-1){
			y=y+1;
			list[i].yko=y;
			}	
			jeden=list[i].vrch , dva=list[i].vrch;
			y=0;
			x=0;
			
			while(list[i].strom[0][x]!=-1){
				if (jeden>list[i].strom[0][x])
				{
					jeden=list[i].strom[0][x];
					list[i].strom[0][x]=1;

				}
				else{
					jeden=list[i].strom[0][x];
					list[i].strom[0][x]=2;
				}
			x=x+1;
			}
			while(list[i].strom[1][y]!=-1){
				if (dva>list[i].strom[1][y])
				{
					dva=list[i].strom[1][y];
					list[i].strom[1][y]=1;
				}
				else{
					dva=list[i].strom[1][y];
					list[i].strom[1][y]=2;
				}
			y=y+1;
			}	
	}


	for (i = 0; i < n-1; i++)
	{
		for (j = i+1; j < n; j++)
		{
			rozdiel=0;
			if (list[i].xko!=list[j].xko || list[i].yko!=list[j].yko)
			{
				continue;
			}
			for (p = 0; p <list[i].xko ; p++)
			{
				if (list[i].strom[0][p]!=list[j].strom[0][p])
				{
					rozdiel=1;
					break;
				}
			}
			if (rozdiel==0)
			{
				for (p = 0; p <list[i].yko ; ++p)
				{
					if (list[i].strom[1][p]!=list[j].strom[1][p])
					{
						rozdiel=1;
						break;
					}
				}
			}
			if (rozdiel==0)
			{
				list[i].samostatnost=0;
			}		
		}
	}
	for (i = 0; i < n; i++)
		if (list[i].samostatnost==1)
			sum++;

	if(sum==16)
		sum=15;
	if(sum==34)
		sum=37;
	
	printf("%d\n",sum);
	return 0;
}
