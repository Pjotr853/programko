#include<stdio.h>
#include<stdbool.h>
#include <string.h>

#include "hof.h"

bool save(const struct player list[], const int size);
bool add_player(struct player list[], int* size, const struct player player);
int load(struct player list[]);



bool save(const struct player list[], const int size){

	FILE* fw=fopen("score","w");
	if (fw==NULL)
	{
		return false;
	}
	int i=0;

	for (i = 0; i < size; i++)
	{
		fprintf(fw, "%s %d\n", list[i].name, list[i].score);
	}
	
	fclose(fw);

	return true;
}

int load(struct player list[]){
	FILE* fp=fopen("score","r");

	if (fp==NULL)
	{
		return -1;
	}

	int size=0;
	int i=0, j=0;
	
	while((fscanf(fp, "%s %d", list[size].name, &list[size].score))!= EOF){
		size=size+1;
		if (size==10)	break;
	}
	fclose(fp);

	for (i=0;i<size-1;i++)
		for (j=0;j<size-1;j++)
		{
			if (list[j].score<list[j+1].score)
			{
				
				char slovo[30];
				
				strcpy(slovo,list[j].name);
				strcpy(list[j].name,list[j+1].name);
				strcpy(list[j+1].name,slovo);

				int skore=0;
				skore=list[j].score;
				list[j].score=list[j+1].score;
				list[j+1].score=skore;
			}
		}
	
	
	return size;
}




bool add_player(struct player list[], int* size, const struct player player){
	int velkost_stringu=(int)strlen(player.name);
	

	if (velkost_stringu>30)
	{
		return false;
	}
	if ((&player.name==NULL) || (&player.score==NULL))
	{
		return false;
	}
	if (player.score < 0) {  
        return false;
    }

    int velkost= *size;
	if (velkost==0)
	{
		strcpy(list[0].name,player.name);
		list[0].score=player.score;	
		*size=*size+1;
		return true;
	}

	if (velkost == 10) {
        int i=0, j=0;
        for (i = 0; i < velkost; ++i) {
            if (list[i].score <= player.score) {
             
                for ( j = velkost - 1; j > i; --j) {
                    list[j] = list[j - 1];
                }
                
                strcpy(list[i].name, player.name);
                list[i].score = player.score;
                return true;
            }
        }
    } else {
    	int i=0;
        *size = *size + 1;
        for (i = velkost - 1; i >= 0; --i) {
            if (list[i].score <= player.score) {
                list[i + 1] = list[i];
            } else {
                strcpy(list[i + 1].name, player.name);
                list[i + 1].score = player.score;
                return true;
            }
        }
        strcpy(list[0].name, player.name);
        list[0].score = player.score;
        return true;
    }

	return false;
}
