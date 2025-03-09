#include<stdio.h>
#include<stdbool.h>
#include <string.h>
#include "hof.h"

int load(struct player list[]);
bool add_player(struct player list[], int* size, const struct player player);
bool save(const struct player list[], const int size);





bool save(const struct player list[], const int size){
	FILE* fw=fopen("score","w");
	int i=0;
	if (fw==NULL)
	{
		return false;
	}

	for (i = 0; i < size; i++)
	{
		fprintf(fw, "%s %d\n", list[i].name, list[i].score);
	}
	
	fclose(fw);

	return true;
}

int load(struct player list[]){
	FILE* fp=fopen("score","r");
	int i=0, j=0, size=0, help_skore=0;
	char help_slovo[30];

	if (fp==NULL)
	{
		return -1;
	}


	while((fscanf(fp, "%s %d", list[size].name, &list[size].score))!= EOF){
		size=size+1;
		if (size==10)
		{
			break;
		}
	}
	for ( i=0;i<size-1;i++)
	{
		for (j=0;j<size-1;j++)
		{
			if (list[j].score<list[j+1].score)
			{
	
				strcpy(help_slovo,list[j].name);
				strcpy(list[j].name,list[j+1].name);
				strcpy(list[j+1].name,help_slovo);
				help_skore=list[j].score;
				list[j].score=list[j+1].score;
				list[j+1].score=help_skore;
			}
		}
	}
	fclose(fp);
	return size;
}



bool add_player(struct player list[], int* size, const struct player player){
	int size_of_string=(int)strlen(player.name), help_size= *size;
	int i=0, ano=0;

	if (size_of_string>30)
	{
		return false;
	}
	if ((&player.name==NULL) || (&player.score==NULL))
	{
		return false;
	}

	if (help_size==0)
	{
		strcpy(list[0].name,player.name);
		list[0].score=player.score;	
		*size=*size+1;
		return true;
	}

	if (help_size==10)
	{
		 ano=0;
		for (i = 0; i < help_size; ++i)
		{
			if(list[i].score<=player.score){
				ano=1;
			}
		}

		if (ano==1)
		{
			
			for (i=help_size-2 ; i>-1 ; i--)
			{
				if (list[i].score<=player.score  )
				{
					strcpy(list[i+1].name,list[i].name);
					list[i+1].score=list[i].score;
				}
				else{
					strcpy(list[i+1].name,player.name);
					list[i+1].score=player.score;
					return true;
				}
			}
			strcpy(list[i+1].name,list[i].name);
			list[i+1].score=list[i].score;
			strcpy(list[0].name,player.name);
			list[0].score=player.score;
			return true;
		}
	}
	else{
		*size=*size+1;
		help_size= *size;
		
			for (i=help_size-2 ; i>-1 ; i--)
			{
				if (list[i].score<=player.score)
				{
					strcpy(list[i+1].name,list[i].name);
					list[i+1].score=list[i].score;
				}
				else{
					
					if (*size==2)
					{
						if (list[0].score<=player.score)
						{
							strcpy(list[1].name,list[0].name);
							list[1].score=list[0].score;
							strcpy(list[0].name,player.name);
							list[0].score=player.score;
							return true;
						}
						else{
							strcpy(list[1].name,player.name);
							list[1].score=player.score;
							return true;
						}
					}
					strcpy(list[i+1].name,player.name);
					list[i+1].score=player.score;
					return true;
				}
			}
			strcpy(list[i+1].name,list[i].name);
			list[i+1].score=list[i].score;
			strcpy(list[0].name,player.name);
			list[0].score=player.score;
			return true;
		}

	return false;
}
