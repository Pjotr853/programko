#include<stdio.h>

int main(){
	char vstup;
	int sum=0;
	int podiel=0;
	
	while ((vstup=getchar())!='\n')
    {
    		sum=sum+(vstup-48);
    		if (sum>9)
    		{
    			podiel=sum%10;
    			sum=sum/10+podiel;
    		}
    }
	printf("%d\n",sum);	
	return 0;
}
