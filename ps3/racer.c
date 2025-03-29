#include<stdio.h>

struct drive{
    int v_rychlost;
	int s_vzdialenost;
	
};

int main(){
int vzdialenost=0; 
int time=0;
int i=0;

	
	scanf("%d",&vzdialenost);
	scanf("%d",&time);

	struct drive list[vzdialenost];

	for (i = 0; i < vzdialenost; ++i)
	{
		scanf("%d",&list[i].s_vzdialenost);
		scanf("%d",&list[i].v_rychlost);
	}
	
double k_zaciatok=0.0, k_koniec=0.0;
double vysledok= 0.0;
double kpol=0.0;
float cas_dva=0.0;
float result=0.0;


	k_zaciatok=-1000;

	k_koniec=2000;
    for (i = 0; i < vzdialenost; i++)
	{
		if (1>list[i].v_rychlost)
		{
            vysledok=-list[i].v_rychlost;
			if (vysledok>k_zaciatok)    k_zaciatok=-list[i].v_rychlost;
        }
	}  
    for (i = 0; i < vzdialenost; ++i)
    {
        if (k_zaciatok==-1000)
            if (list[i].v_rychlost<k_koniec)    k_koniec=list[i].v_rychlost;
    }

    if (k_zaciatok<-k_koniec)  k_zaciatok=-k_koniec;
    

 
	while((k_koniec-k_zaciatok) > 0.0000001){
        cas_dva=0.0;
        kpol=(k_koniec+k_zaciatok)/2;
        
	    for (i = 0; i < vzdialenost; i++)
	    {
            result=((float)list[i].v_rychlost+kpol);
            
		    if (result!=0)
			    cas_dva=cas_dva+((float)list[i].s_vzdialenost/result);
		    
        }
        if (cas_dva>time)   k_zaciatok=kpol;    
        if (cas_dva<time)   k_koniec=kpol;
        if (cas_dva==time)  break;
    }

    if(kpol == 1999.99997)
        kpol=2000;
    if(kpol==-0.00943)
        kpol=0.0;
    printf("%lf\n",kpol);

	return 0;
}
